#include "stm_sensor.h"
#include <stdio.h>

static int stm_init(void) {
  printf("STM accelerometer initialized. fuckface\n");
  return 0;
}

static int stm_configure(int settings) {
  printf("STM accelerometer configured with settings: %d\n", settings);
  return 0;
}

static int stm_read_data(int *x, int *y, int *z) {
  *x = 100;
  *y = 200;
  *z = 300;
  printf("STM accelerometer data: X=%d, Y=%d, Z=%d\n", *x, *y, *z);
  return 0;
}

static void stm_print_hello_world() { printf("Hello Worlds\n"); }

const AccelerometerInterface stm_accelerometer = {.init = stm_init,
                                                  .configure = stm_configure,
                                                  .read_data = stm_read_data,
                                                  .print_hello_world =
                                                      stm_print_hello_world};
