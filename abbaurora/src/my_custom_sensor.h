#include "esphome.h"
#include <ABBAurora.h>

#define INVERTER_ADDRESS 2

class MyCustomSensor : public PollingComponent {
 public:
  ABBAurora *inverter;
  Sensor *power_sensor = new Sensor();
  Sensor *power_sensor1 = new Sensor();
  Sensor *power_sensor2 = new Sensor();
  Sensor *voltage_sensor1 = new Sensor();
  Sensor *voltage_sensor2 = new Sensor();
  Sensor *energy_sensorD = new Sensor();
  Sensor *energy_sensorT = new Sensor();

  MyCustomSensor() : PollingComponent(60000) { }

  void setup() override {
    ABBAurora::setup(Serial);
    inverter = new ABBAurora(INVERTER_ADDRESS);
  }

  void update() override {
    // This is the actual sensor reading logic.
    if (inverter->ReadDSPValue(GRID_POWER, GLOBAL_MESSUREMENT)) {
      float power = inverter->DSP.Value;
      power_sensor->publish_state(power);
    }
    if (inverter->ReadDSPValue(POWER_IN_1, MODULE_MESSUREMENT)) {
      float power1 = inverter->DSP.Value;
      power_sensor1->publish_state(power1);
    }
    if (inverter->ReadDSPValue(POWER_IN_2, MODULE_MESSUREMENT)) {
      float power2 = inverter->DSP.Value;
      power_sensor2->publish_state(power2);
    }
    if (inverter->ReadDSPValue(V_IN_1, MODULE_MESSUREMENT)) {
      float vin1 = inverter->DSP.Value;
      voltage_sensor1->publish_state(vin1);
    }
    if (inverter->ReadDSPValue(V_IN_2, MODULE_MESSUREMENT)) {
      float vin2 = inverter->DSP.Value;
      voltage_sensor2->publish_state(vin2);
    }
    if (inverter->ReadCumulatedEnergy(CURRENT_DAY)) {
      unsigned long energyD = inverter->CumulatedEnergy.Energy;
      energy_sensorD->publish_state(energyD/1000.0);
    }
    if (inverter->ReadCumulatedEnergy(TOTAL)) {
      unsigned long energyT = inverter->CumulatedEnergy.Energy;
      energy_sensorT->publish_state(energyT/1000.0);
    }
  }
};
