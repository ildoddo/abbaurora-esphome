#include "esphome.h"
#include <ABBAurora.h>
#include <ABBAuroraStrings.h>

#define INVERTER_ADDRESS 2

class MyCustomTextSensor : public PollingComponent, public TextSensor {
 public:
  ABBAurora *inverter2;
  ABBAuroraStrings *inverterStrings;
  TextSensor *versione_tsensor = new TextSensor();
  TextSensor *inverterState_tsensor = new TextSensor();
  TextSensor *globalState_tsensor = new TextSensor();
  TextSensor *channel1_tsensor = new TextSensor();
  TextSensor *channel2_tsensor = new TextSensor();
  TextSensor *alarm_tsensor = new TextSensor();

  // constructor
  MyCustomTextSensor() : PollingComponent(120000) {}

  void setup() override {
    ABBAurora::setup(Serial);
    inverter2 = new ABBAurora(INVERTER_ADDRESS);
    inverterStrings = new ABBAuroraStrings();
  }
  void update() override {
    if (inverter2->ReadVersion()) {
      String versione = String(inverter2->Version.Par1 + " " + inverter2->Version.Par2 + " " + inverter2->Version.Par3 + " " + inverter2->Version.Par4);
      versione_tsensor->publish_state(versione.c_str());
    }
    if (inverter2->ReadState()) {
      String inverterState = String(inverterStrings->InverterState(inverter2->State.InverterState));
      String globalState = String(inverterStrings->GlobalState(inverter2->State.GlobalState));
      String channel1 = String(inverterStrings->DcDcState(inverter2->State.Channel1State));
      String channel2 = String(inverterStrings->DcDcState(inverter2->State.Channel2State));
      String alarm = String(inverterStrings->AlarmState(inverter2->State.AlarmState));
      inverterState_tsensor->publish_state(inverterState.c_str());
      globalState_tsensor->publish_state(globalState.c_str());
      channel1_tsensor->publish_state(channel1.c_str());
      channel2_tsensor->publish_state(channel2.c_str());
      alarm_tsensor->publish_state(alarm.c_str());
    }
  }
};