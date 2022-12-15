#include "esphome.h"
#include <ABBAurora.h>

#define INVERTER_ADDRESS 2

class MyCustomSensor : public PollingComponent {
 public:
  ABBAurora *inverter;
  Sensor *power_sensor = new Sensor();
  Sensor *voltage_sensor = new Sensor();
  Sensor *current_sensor = new Sensor();
  Sensor *frequency_sensor = new Sensor();
  Sensor *riso_sensor = new Sensor();
  Sensor *ileak_sensor = new Sensor();
  Sensor *powerpeak_sensor = new Sensor();
  Sensor *powerpeaktoday_sensor = new Sensor();
  Sensor *tempinverter_sensor = new Sensor();
  Sensor *tempbooster_sensor = new Sensor();
  Sensor *power_sensor1 = new Sensor();
  Sensor *power_sensor2 = new Sensor();
  Sensor *voltage_sensor1 = new Sensor();
  Sensor *voltage_sensor2 = new Sensor();
  Sensor *current_sensor1 = new Sensor();
  Sensor *current_sensor2 = new Sensor();
  Sensor *energy_sensorD = new Sensor();
  Sensor *energy_sensorT = new Sensor();

  MyCustomSensor() : PollingComponent(60000) { }

  void setup() override {
    ABBAurora::setup(Serial);
    inverter = new ABBAurora(INVERTER_ADDRESS);
  }

  void update() override {
    if (inverter->ReadDSPValue(GRID_POWER, GLOBAL_MESSUREMENT)) {
      power_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(GRID_VOLTAGE, GLOBAL_MESSUREMENT)) {
      voltage_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(GRID_CURRENT, GLOBAL_MESSUREMENT)) {
      current_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(FREQUENCY, GLOBAL_MESSUREMENT)) {
      frequency_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(ISOLATION_RESISTANCE, GLOBAL_MESSUREMENT)) {
      riso_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(I_LEAK_INVERTER, GLOBAL_MESSUREMENT)) {
      ileak_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(POWER_PEAK, GLOBAL_MESSUREMENT)) {
      powerpeak_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(POWER_PEAK_TODAY, GLOBAL_MESSUREMENT)) {
      powerpeaktoday_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(TEMPERATURE_INVERTER, GLOBAL_MESSUREMENT)) {
      tempinverter_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(TEMPERATURE_BOOSTER, GLOBAL_MESSUREMENT)) {
      tempbooster_sensor->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(POWER_IN_1, MODULE_MESSUREMENT)) {
      power_sensor1->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(POWER_IN_2, MODULE_MESSUREMENT)) {
      power_sensor2->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(V_IN_1, MODULE_MESSUREMENT)) {
      voltage_sensor1->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(V_IN_2, MODULE_MESSUREMENT)) {
      voltage_sensor2->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(I_IN_1, MODULE_MESSUREMENT)) {
      current_sensor1->publish_state(inverter->DSP.Value);
    }
    if (inverter->ReadDSPValue(I_IN_2, MODULE_MESSUREMENT)) {
      current_sensor2->publish_state(inverter->DSP.Value);
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
