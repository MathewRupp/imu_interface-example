#ifndef ACCELEROMETER_INTERFACE_H
#define ACCELEROMETER_INTERFACE_H

typedef struct {
  int (*init)(void);
  int (*configure)(int settings);
  int (*read_data)(int *x, int *y, int *z);
  void (*print_hello_world)();
} AccelerometerInterface;

#endif // ACCELEROMETER_INTERFACE_H
