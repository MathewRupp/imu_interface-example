#include "bosch_sensor.h"
#include <stdio.h>

static int bosch_init(void) {
  printf("Bosch accelerometer initialized.\n");
  return 0;
}

static int bosch_configure(int settings) {
  printf("Bosch accelerometer configured with settings: %d\n", settings);
  return 0;
}

static int bosch_read_data(int *x, int *y, int *z) {
  *x = 10;
  *y = 20;
  *z = 30;
  printf("Bosch accelerometer data: X=%d, Y=%d, Z=%d\n", *x, *y, *z);
  return 0;
}

static void bosch_print_hello_world() { printf("Hello World\n"); }
const AccelerometerInterface bosch_accelerometer = {
    .init = bosch_init,
    .configure = bosch_configure,
    .read_data = bosch_read_data,
    .print_hello_world = bosch_print_hello_world};
