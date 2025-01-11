#include "accelerometer_interface.h"
#include "config.h"
#include <stdio.h>

#if defined(SENSOR_BOSCH)
#include "bosch_sensor.h"
const AccelerometerInterface *selected_sensor = &bosch_accelerometer;
#elif defined(SENSOR_STM)
#include "stm_sensor.h"
const AccelerometerInterface *selected_sensor = &stm_accelerometer;
#else
#error "No sensor selected! Define SENSOR_BOSCH or SENSOR_STM in config.h"
#endif

void test_accelerometer(const AccelerometerInterface *accel) {
  accel->init();
  accel->configure(42);
  int x, y, z;
  accel->read_data(&x, &y, &z);
  accel->print_hello_world();
}

int main() {
  printf("Testing Selected Accelerometer:\n");
  test_accelerometer(selected_sensor);
  return 0;
}
