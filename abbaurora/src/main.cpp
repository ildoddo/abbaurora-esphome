// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
sensor::Sensor *sensor_sensor;
sensor::Sensor *sensor_sensor_2;
sensor::Sensor *sensor_sensor_3;
#include "my_custom_sensor.h"
#include "ABBAurora.h"
#include "ABBAuroraEnums.h"
#include "ABBAuroraStrings.h"
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: abbaurora
  //   platform: ESP8266
  //   board: nodemcuv2
  //   includes:
  //   - my_custom_sensor.h
  //   - ABBAurora.h
  //   - ABBAuroraEnums.h
  //   - ABBAuroraStrings.h
  //   libraries:
  //   - Wire
  //   arduino_version: platformio/espressif8266@2.6.2
  //   build_path: abbaurora
  //   platformio_options: {}
  //   esp8266_restore_from_flash: false
  //   board_flash_mode: dout
  //   name_add_mac_suffix: false
  App.pre_setup("abbaurora", __DATE__ ", " __TIME__, false);
  // logger:
  //   level: DEBUG
  //   hardware_uart: UART1
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART1);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  web_server_base_webserverbase->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  captive_portal_captiveportal->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Abbaurora Fallback Hotspot
  //     password: loDS8LCal7D1
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   enable_mdns: true
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: wifiot
  //     password: 00aa11bb22cc33dd44ee55
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: abbaurora.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("abbaurora.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("wifiot");
  wifi_wifiap_2.set_password("00aa11bb22cc33dd44ee55");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Abbaurora Fallback Hotspot");
  wifi_wifiap.set_password("loDS8LCal7D1");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // ota:
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   password: ''
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  // sensor.custom:
  //   platform: custom
  //   lambda: !lambda |-
  //     auto my_sensor = new MyCustomSensor();
  //     App.register_component(my_sensor);
  //     return {my_sensor->power_sensor, my_sensor->energy_sensorD, my_sensor->energy_sensorT};
  //   sensors:
  //   - name: fv_power
  //     unit_of_measurement: W
  //     accuracy_decimals: 2
  //     state_class: measurement
  //     device_class: power
  //     disabled_by_default: false
  //     id: sensor_sensor
  //     force_update: false
  //   - name: fv_energy_day
  //     unit_of_measurement: kWh
  //     accuracy_decimals: 2
  //     state_class: measurement
  //     device_class: energy
  //     disabled_by_default: false
  //     id: sensor_sensor_2
  //     force_update: false
  //   - name: fv_energy_total
  //     unit_of_measurement: kWh
  //     accuracy_decimals: 2
  //     state_class: total_increasing
  //     device_class: energy
  //     disabled_by_default: false
  //     id: sensor_sensor_3
  //     force_update: false
  //   id: custom_customsensorconstructor
  custom::CustomSensorConstructor custom_customsensorconstructor = custom::CustomSensorConstructor([=]() -> std::vector<sensor::Sensor *> {
      #line 42 "/config/esphome/abbaurora.yaml"
      auto my_sensor = new MyCustomSensor();
      App.register_component(my_sensor);
      return {my_sensor->power_sensor, my_sensor->energy_sensorD, my_sensor->energy_sensorT};
  });
  sensor_sensor = custom_customsensorconstructor.get_sensor(0);
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("fv_power");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("power");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("W");
  sensor_sensor->set_accuracy_decimals(2);
  sensor_sensor->set_force_update(false);
  sensor_sensor_2 = custom_customsensorconstructor.get_sensor(1);
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("fv_energy_day");
  sensor_sensor_2->set_disabled_by_default(false);
  sensor_sensor_2->set_device_class("energy");
  sensor_sensor_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_2->set_unit_of_measurement("kWh");
  sensor_sensor_2->set_accuracy_decimals(2);
  sensor_sensor_2->set_force_update(false);
  sensor_sensor_3 = custom_customsensorconstructor.get_sensor(2);
  App.register_sensor(sensor_sensor_3);
  sensor_sensor_3->set_name("fv_energy_total");
  sensor_sensor_3->set_disabled_by_default(false);
  sensor_sensor_3->set_device_class("energy");
  sensor_sensor_3->set_state_class(sensor::STATE_CLASS_TOTAL_INCREASING);
  sensor_sensor_3->set_unit_of_measurement("kWh");
  sensor_sensor_3->set_accuracy_decimals(2);
  sensor_sensor_3->set_force_update(false);
  // socket:
  //   implementation: lwip_tcp
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
