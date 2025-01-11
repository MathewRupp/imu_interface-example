# Designing an IMU Interface

## Init Functions

`int imu_init(void);`
`int imu_reset(void);`

## Config Functions

`int imu_configure(int settings);`
`int imu_set_power_mode(int mode);`
`int imu_set_scale(int accel_scale, int gyro_scale);`
`int imu_enable_interrupt(int interrupt_type, void (*callback)(void));`

## Data Acquisition

`int imu_read_accel(int *x, int *y, int *z);`
`int imu_read_gyro(int *x, int *y, int *z);`
`int imu_read_temp(int *temperature);`
`int imu_read_all(int *ax, int *ay, int *az, int *gx, int *gy, int *gz, int *temp);`

## Register Level Access

`int imu_write_register(uint8_t reg, uint8_t value);`
`int imu_read_register(uint8_t reg, uint8_t *value);`
`int imu_read_registers(uint8_t reg, uint8_t *buffer, size_t length);`

## Self Test

`int imu_self_test(void);`
`int imu_calibrate(void);`

## Error Handling

`int imu_get_status(void);`
`const char \*imu_get_error_string(int error_code);`

## Low-Level Communication Utility Functions

`int imu_select(void);`
`int imu_deselect(void);`
`int imu_transfer(uint8_t *tx_buffer, uint8_t *rx_buffer, size_t length)`
