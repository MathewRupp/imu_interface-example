/**
 * @file       bmi08.h
 * @date       2024-07-29
 * @version    v1.9.0
 *
 */

/**
 * \ingroup bmi08
 * \defgroup bmi08ag BMI08A / BMI08G
 */

#ifndef _BMI08_H
#define _BMI08_H

/*********************************************************************/
/* header files */
#include "bmi08_defs.h"

/*********************************************************************/
/*                     Macro Definitions                             */
/*********************************************************************/

/*********************** BMI08x Accelerometer function prototypes
 * ************************/

/**
 */

/*!
 * \ingroup bmi08aApiInit
 * \page bmi08a_api_bmi08a_init bmi08a_init
 * \code
 * int8_t bmi08a_init(struct bmi08_dev *dev);
 * \endcode
 * @details This API is the entry point for accel sensor.
 *  It performs the selection of I2C/SPI read mechanism according to the
 *  selected interface and reads the chip-id of accel sensor.
 *
 *  @param[in,out] dev  : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_init(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiConfig Accel Upload Config File
 * @brief Uploads config file onto the device
 */

/*!
 * \ingroup bmi08aApiConfig
 * \page bmi08a_api_bmi08a_load_config_file bmi08a_load_config_file
 * \code
 * int8_t bmi08a_load_config_file(struct bmi08_dev *dev);
 * \endcode
 * @details This API uploads the bmi08 config file onto the device.
 *
 *  @param[in,out] dev  : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_load_config_file(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiFConfig Upload Feature Config File
 * @brief Uploads config file onto the device
 */

/*
 * \ingroup bmi08aApiFConfig
 * \page bmi08a_api_bmi08a_write_feature_config bmi08a_write_feature_config
 * \code
 * int8_t bmi08a_write_feature_config(uint8_t reg_addr, const uint16_t
 * *reg_data, uint8_t len, const struct bmi08_dev *dev);
 *
 * \endcode
 * @details This API writes the feature configuration to the accel sensor.
 *
 *  @param[in] reg_addr : Address offset of the feature setting inside the
 * feature conf region.
 *  @param[in] reg_data : Feature settings.
 *  @param[in] len : Number of 16 bit words to be written.
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_write_feature_config(uint8_t reg_addr, const uint16_t *reg_data,
                                   uint8_t len, struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiRegs Accel Data
 * @brief Read / Write data from the given register address of accel sensor
 */

/*!
 * \ingroup bmi08aApiRegs
 * \page bmi08a_api_bmi08a_get_set_regs bmi08a_get_set_regs
 * \code
 * int8_t bmi08a_get_set_regs(uint8_t reg_addr, uint8_t *reg_data, uint16_t len,
 * const struct bmi08_dev *dev, uint8_t select); \endcode
 * @details This API reads the data from the given register address of accel
 * sensor.
 *
 *  @param[in] reg_addr  : Register address from where the data to be read
 *  @param[out] reg_data : Pointer to data buffer to store the read data.
 *  @param[in] len       : No. of bytes of data to be read.
 *  @param[in] dev       : Structure instance of bmi08_dev.
 *  @param[in] select    : Flag to select functionality between setting and
 * getting
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_set_regs(uint8_t reg_addr, uint8_t *reg_data, uint32_t len,
                           struct bmi08_dev *dev, uint8_t select);

/*!
 * \ingroup bmi08aApiRegs
 * \page bmi08a_api_bmi08a_get_set_i2c_wdt bmi08a_get_set_i2c_wdt
 * \code
 * int8_t bmi08a_get_set_i2c_wdt(uint8_t *i2c_wdt_sel, uint8_t *i2c_wdt_en,
 * struct bmi08_dev *dev, uint8_t select); \endcode
 * @details This API reads the watchdog related information
 *
 *  @param[out] i2c_wdt_sel  : Variable to hold i2c_wdt_sel
 *  @param[out] i2c_wdt_en   : Variable to hold i2c_wdt_en
 *  @param[in] dev           : Structure instance of bmi08_dev.
 *  @param[in] select    : Flag to select functionality between getting and
 * setting
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_set_i2c_wdt(uint8_t *i2c_wdt_sel, uint8_t *i2c_wdt_en,
                              struct bmi08_dev *dev, uint8_t select);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiErrorStatus Accel Error status
 * @brief Get error status from accel sensor
 */

/*!
 * \ingroup bmi08aApiErrorStatus
 * \page bmi08a_api_bmi08a_get_error_status bmi08a_get_error_status
 * \code
 * int8_t bmi08a_get_error_status(struct bmi08_err_reg *err_reg, const struct
 *bmi08_dev *dev); \endcode
 * @details This API reads the error status from the accel sensor.
 *
 *  Below table mention the types of error which can occur in the sensor
 *
 *@verbatim
 *************************************************************************
 *        Error           |       Description
 *************************|***********************************************
 *                        |       Fatal Error, chip is not in operational
 *        fatal           |       state (Boot-, power-system).
 *                        |       This flag will be reset only by
 *                        |       power-on-reset or soft reset.
 *************************|***********************************************
 *                        |       Value        Name       Description
 *        error_code      |       000        no_error     no error
 *                        |       001        accel_err      error in
 *                        |                               ACCEL_CONF
 *************************************************************************
 *@endverbatim
 *
 *  @param[out] err_reg : Pointer to structure variable which stores the
 *  error status read from the sensor.
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_error_status(struct bmi08_err_reg *err_reg,
                               struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApistatus Accel status
 * @brief Read status of accel sensor
 */

/*!
 * \ingroup bmi08aApistatus
 * \page bmi08a_api_bmi08a_get_status bmi08a_get_status
 * \code
 * int8_t bmi08a_get_status(uint8_t *status, const struct bmi08_dev *dev);
 * \endcode
 * @details This API reads the status of the accel sensor.
 *
 *  Below table lists the sensor status flags
 *
 *@verbatim
 *************************************************************************
 *        Status                    |       Description
 ***********************************|*************************************
 *        drdy_accel                | Data ready for Accel.
 *************************************************************************
 *@endverbatim
 *
 *  @param[out] status : Variable used to store the sensor status flags
 *  which is read from the sensor.
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_status(uint8_t *status, struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiSoftreset Accel Soft reset
 * @brief Performs soft reset of accel sensor
 */

/*!
 * \ingroup bmi08aApiSoftreset
 * \page bmi08a_api_bmi08a_soft_reset bmi08a_soft_reset
 * \code
 * int8_t bmi08a_soft_reset(const struct bmi08_dev *dev);
 * \endcode
 * @details This API resets the accel sensor.
 *
 *  @param[in] dev  : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_soft_reset(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiConf Read accel configurations
 * @brief Read / Write configurations of accel sensor
 */

/*!
 * \ingroup bmi08aApiConf
 * \page bmi08a_api_bmi08a_get_meas_conf bmi08a_get_meas_conf
 * \code
 * int8_t bmi08a_get_meas_conf(struct bmi08_dev *dev);
 * \endcode
 * @details This API reads the accel config values ie odr, band width and range
 * from the sensor, store it in the bmi08_dev structure instance passed by the
 * user.
 *  @param[in,out]  dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_meas_conf(struct bmi08_dev *dev);

/*!
 * \ingroup bmi08aApiConf
 * \page bmi08a_api_bmi08a_set_meas_conf bmi08a_set_meas_conf
 * \code
 * int8_t bmi08a_set_meas_conf(const struct bmi08_dev *dev);
 * \endcode
 * @details This API sets the Output data rate and bandwidth
 *  of accel sensor.
 *  @param[in] dev  : Structure instance of bmi08_dev.
 *
 *  @note : The user must select one among the following macros to
 *  select range value for BMI085 accel
 *
 *@verbatim
 *      config                         |   value
 *      -------------------------------|---------------------------
 *      BMI085_ACCEL_RANGE_2G          |   0x00
 *      BMI085_ACCEL_RANGE_4G          |   0x01
 *      BMI085_ACCEL_RANGE_8G          |   0x02
 *      BMI085_ACCEL_RANGE_16G         |   0x03
 *@endverbatim
 *
 *  @note : The user must select one among the following macros to
 *  select range value for BMI088 accel
 *
 *@verbatim
 *      config                         |   value
 *      -------------------------------|---------------------------
 *      BMI088_ACCEL_RANGE_3G          |   0x00
 *      BMI088_ACCEL_RANGE_6G          |   0x01
 *      BMI088_ACCEL_RANGE_12G         |   0x02
 *      BMI088_ACCEL_RANGE_24G         |   0x03
 *@endverbatim
 *
 *  @note : Refer user guide for detailed info.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_set_meas_conf(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiPowermode Accel power mode
 * @brief Set / Get power mode of accel sensor
 */

/*!
 * \ingroup bmi08aApiPowermode
 * \page bmi08a_api_bmi08a_get_power_mode bmi08a_get_power_mode
 * \code
 * int8_t bmi08a_get_power_mode(struct bmi08_dev *dev);
 * \endcode
 * @details This API reads the accel power mode from the sensor,
 * store it in the bmi08_dev structure instance
 * passed by the user.
 *  @param[in,out]  dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_power_mode(struct bmi08_dev *dev);

/*!
 * \ingroup bmi08aApiPowermode
 * \page bmi08a_api_bmi08a_set_power_mode bmi08a_set_power_mode
 * \code
 * int8_t bmi08a_set_power_mode(const struct bmi08_dev *dev);
 * \endcode
 * @details This API sets the power mode of the accel sensor.
 *
 *  @param[in] dev  : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_set_power_mode(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiData Accel Data
 * @brief Read data from accel sensor
 */

/*!
 * \ingroup bmi08aApiData
 * \page bmi08a_api_bmi08a_get_data bmi08a_get_data
 * \code
 * int8_t bmi08a_get_data(struct bmi08_sensor_data *accel, const struct
 * bmi08_dev *dev); \endcode
 * @details This API reads the accel data from the sensor,
 *  store it in the bmi08_sensor_data structure instance
 *  passed by the user.
 *
 *  @param[out] accel  : Structure pointer to store accel data
 *  @param[in]  dev    : Structure instance of bmi08_dev.
 *
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_data(struct bmi08_sensor_data *accel, struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiIntConf Accel Interrupt Config
 * @brief Configures interrupt of accel sensor
 */

/*!
 * \ingroup bmi08aApiIntConf
 * \page bmi08a_api_bmi08a_set_int_config bmi08a_set_int_config
 * \code
 * int8_t bmi08a_set_int_config(const struct bmi08_accel_int_channel_cfg
 * *int_config, const struct bmi08_dev *dev); \endcode
 * @details This API configures the necessary accel interrupt
 *  based on the user settings in the bmi08_accel_int_channel_cfg
 *  structure instance.
 *
 *  @param[in] int_config  : Structure instance of bmi08_accel_int_channel_cfg.
 *  @param[in] dev         : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t
bmi08a_set_int_config(const struct bmi08_accel_int_channel_cfg *int_config,
                      struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiAccelTemp Accel Temperature
 * @brief Read temperature from accel sensor
 */

/*!
 * \ingroup bmi08aApiAccelTemp
 * \page bmi08a_api_bmi08a_get_sensor_temperature bmi08a_get_sensor_temperature
 * \code
 * int8_t bmi08a_get_sensor_temperature(const struct bmi08_dev *dev, int32_t
 * *sensor_temp); \endcode
 * @details This API reads the temperature of the sensor in degree Celcius.
 *
 *  @param[in]  dev             : Structure instance of bmi08_dev.
 *  @param[out] sensor_temp     : Pointer to store sensor temperature in degree
 * Celcius
 *
 *  @note Temperature data output must be divided by a factor of 1000
 *
 *  Consider sensor_temp = 19520 , Then the actual temperature is 19.520 degree
 * Celsius
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_sensor_temperature(struct bmi08_dev *dev,
                                     int32_t *sensor_temp);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiaccelsensortime Accel sensor time
 * @brief Read sensor time of accel sensor
 */

/*!
 * \ingroup bmi08aApiaccelsensortime
 * \page bmi08a_api_bmi08a_get_sensor_time bmi08a_get_sensor_time
 * \code
 * int8_t bmi08a_get_sensor_time(const struct bmi08_dev *dev, uint32_t
 * *sensor_time); \endcode
 * @details This API reads the sensor time of the accel sensor.
 *
 *  @param[in]  dev             : Structure instance of bmi08_dev.
 *  @param[out] sensor_time     : Pointer to store sensor time
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_sensor_time(struct bmi08_dev *dev, uint32_t *sensor_time);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiSync Data Synchronization
 * @brief Enable / Disable data synchronization
 */

/*!
 * \ingroup bmi08aApiSync
 * \page bmi08a_api_bmi08a_configure_data_synchronization
 * bmi08a_configure_data_synchronization \code int8_t
 * bmi08a_configure_data_synchronization(struct bmi08_data_sync_cfg sync_cfg,
 * struct bmi08_dev *dev); \endcode
 * @details This API is used to enable/disable the data synchronization
 *  feature.
 *
 *  @param[in] sync_cfg : Configure sync feature
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t
bmi08a_configure_data_synchronization(struct bmi08_data_sync_cfg sync_cfg,
                                      struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiSyncData Sync Data
 * @brief Synchronizes accel and gyro data from the sensor
 */

/*!
 * \ingroup bmi08aApiSyncData
 * \page bmi08a_api_bmi08a_get_synchronized_data bmi08a_get_synchronized_data
 * \code
 * int8_t bmi08a_get_synchronized_data(struct bmi08_sensor_data *accel,
 *                                   struct bmi08_sensor_data *gyro,
 *                                   const struct bmi08_dev *dev);
 *
 * \endcode
 * @details This API reads the synchronized accel & gyro data from the sensor,
 *  store it in the bmi08_sensor_data structure instance
 *  passed by the user.
 *
 *  @param[out] accel  : Structure pointer to store accel data
 *  @param[out] gyro   : Structure pointer to store gyro  data
 *  @param[in]  dev    : Structure instance of bmi08_dev.
 *
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_synchronized_data(struct bmi08_sensor_data *accel,
                                    struct bmi08_sensor_data *gyro,
                                    struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiInt interrupt
 * @brief Configuring Interrupts
 */

/*!
 * \ingroup bmi08aApiInt
 * \page bmi08a_api_bmi08a_set_data_sync_int_config
 * bmi08a_set_data_sync_int_config \code int8_t
 * bmi08a_set_data_sync_int_config(const struct bmi08_int_cfg *int_config, const
 * struct bmi08_dev *dev); \endcode
 * @details This API configures the synchronization interrupt
 *  based on the user settings in the bmi08_int_cfg
 *  structure instance.
 *
 *  @param[in] int_config : Structure instance of accel bmi08_int_cfg.
 *  @param[in] dev         : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_set_data_sync_int_config(const struct bmi08_int_cfg *int_config,
                                       struct bmi08_dev *dev);

/*!
 * \ingroup bmi08aApiInt
 * \page bmi08a_api_bmi08a_get_data_int_status bmi08a_get_data_int_status
 * \code
 * int8_t bmi08a_get_data_int_status(uint8_t *int_status, struct bmi08_dev
 **dev); \endcode
 * @details This API is to get accel feature interrupt status
 *
 * @param[out] int_status      : Variable to store interrupt status
 * @param[in]  dev             : Structure instance of bmi08_dev
 *
 *@verbatim
 *-----------------------------------------
 *   int_status    |     Interrupt
 *-----------------------------------------
 *      0x01       |    Fifo full
 *      0x02       |    Fifo watermark
 *      0x08       |    Accel data ready
 *------------------------------------------
 *@endverbatim
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 */
int8_t bmi08a_get_data_int_status(uint8_t *int_status, struct bmi08_dev *dev);

/*********************** BMI088 Gyroscope function prototypes
 * ****************************/

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiInit Gyro Initialization
 * @brief Initialize the sensor and device structure
 */

/*!
 * \ingroup bmi08gApiInit
 * \page bmi08g_api_bmi08g_init bmi08g_init
 * \code
 * int8_t bmi08g_init(struct bmi08_dev *dev);
 * \endcode
 * @details This API is the entry point for gyro sensor.
 *  It performs the selection of I2C/SPI read mechanism according to the
 *  selected interface and reads the chip-id of gyro sensor.
 *
 *  @param[in,out] dev : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_init(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiRegs Gyro Data
 * @brief Read / Write data from the given register address of gyro sensor
 */

/*!
 * \ingroup bmi08gApiRegs
 * \page bmi08g_api_bmi08g_get_regs bmi08g_get_regs
 * \code
 * int8_t bmi08g_get_regs(uint8_t reg_addr, uint8_t *reg_data, uint16_t len,
 * const struct bmi08_dev *dev); \endcode
 * @details This API reads the data from the given register address of gyro
 * sensor.
 *
 *  @param[in] reg_addr  : Register address from where the data to be read
 *  @param[out] reg_data : Pointer to data buffer to store the read data.
 *  @param[in] len       : No. of bytes of data to be read.
 *  @param[in] dev       : Structure instance of bmi08_dev.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_get_regs(uint8_t reg_addr, uint8_t *reg_data, uint32_t len,
                       struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiRegs
 * \page bmi08g_api_bmi08g_set_regs bmi08g_set_regs
 * \code
 * int8_t bmi08g_set_regs(uint8_t reg_addr, uint8_t *reg_data, uint16_t len,
 * const struct bmi08_dev *dev); \endcode
 * @details This API writes the given data to the register address
 *  of gyro sensor.
 *
 *  @param[in] reg_addr  : Register address to where the data to be written.
 *  @param[in] reg_data  : Pointer to data buffer which is to be written
 *  in the sensor.
 *  @param[in] len       : No. of bytes of data to write.
 *  @param[in] dev       : Structure instance of bmi08_dev.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_set_regs(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len,
                       struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiSoftreset gyro Soft reset
 * @brief Performs soft reset of gyro sensor
 */

/*!
 * \ingroup bmi08gApiSoftreset
 * \page bmi08g_api_bmi08g_soft_reset bmi08g_soft_reset
 * \code
 * int8_t bmi08g_soft_reset(const struct bmi08_dev *dev);
 * \endcode
 * @details This API resets the gyro sensor.
 *
 * @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08g_soft_reset(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiConf Read gyro configurations
 * @brief Read / Write configurations of gyro sensor
 */

/*!
 * \ingroup bmi08gApiConf
 * \page bmi08g_api_bmi08g_get_meas_conf bmi08g_get_meas_conf
 * \code
 * int8_t bmi08g_get_meas_conf(struct bmi08_dev *dev);
 * \endcode
 * @details This API reads the gyro odr and range from the sensor,
 *  store it in the bmi08_dev structure instance
 *  passed by the user.
 *
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 *  @note : band width also updated, which is same as odr
 *          Refer user guide for detailed info.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_get_meas_conf(struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiConf
 * \page bmi08g_api_bmi08g_set_meas_conf bmi08g_get_meas_conf
 * \code
 * int8_t bmi08g_set_meas_conf(struct bmi08_dev *dev);
 * \endcode
 * @details This API sets the output data rate, range and bandwidth
 *  of gyro sensor.
 *
 *  @param[in] dev : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 *  @note : No need to give the band width parameter,
 *          odr will update the band width.
 *          Refer user guide for detailed info.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_set_meas_conf(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiPowermode Gyro power mode
 * @brief Set / Get power mode of gyro sensor
 */

/*!
 * \ingroup bmi08gApiPowermode
 * \page bmi08g_api_bmi08g_get_power_mode bmi08g_get_power_mode
 * \code
 * int8_t bmi08g_get_power_mode(struct bmi08_dev *dev);
 * \endcode
 * @details This API gets the power mode of the gyro sensor and store it
 *  inside the instance of bmi08_dev passed by the user.
 *
 *  @param[in] dev : Structure instance of bmi08_dev.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t bmi08g_get_power_mode(struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiPowermode
 * \page bmi08g_api_bmi08g_set_power_mode bmi08g_set_power_mode
 * \code
 * int8_t bmi08g_set_power_mode(const struct bmi08_dev *dev);
 * \endcode
 * @details This API sets the power mode of the gyro sensor.
 *
 * @param[in] dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08g_set_power_mode(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiData Gyro data
 * @brief Read Gyro data
 */

/*!
 * \ingroup bmi08gApiData
 * \page bmi08g_api_bmi08g_get_data bmi08g_get_data
 * \code
 * int8_t bmi08g_get_data(struct bmi08_sensor_data *gyro, const struct bmi08_dev
 * *dev); \endcode
 * @details This API reads the gyro data from the sensor,
 *  store it in the bmi08_sensor_data structure instance
 *  passed by the user.
 *
 * @param[out] gyro   : Structure pointer to store gyro data
 * @param[in] dev     : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08g_get_data(struct bmi08_sensor_data *gyro, struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiIntconfig Gyro interrupt config
 * @brief Set interrupt configurations of gyro sensor
 */

/*!
 * \ingroup bmi08gApiIntconfig
 * \page bmi08g_api_bmi08g_set_int_config bmi08g_set_int_config
 * \code
 * int8_t bmi08g_set_int_config(const struct bmi08_gyro_int_channel_cfg
 * *int_config, const struct bmi08_dev *dev); \endcode
 * @details This API configures the necessary gyro interrupt
 *  based on the user settings in the bmi08_gyro_int_channel_cfg
 *  structure instance.
 *
 *  @param[in] int_config  : Structure instance of bmi08_gyro_int_channel_cfg.
 *  @param[in] dev         : Structure instance of bmi08_dev.
 *  @note : Refer user guide for detailed info.
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 *
 */
int8_t
bmi08g_set_int_config(const struct bmi08_gyro_int_channel_cfg *int_config,
                      struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiIntconfig
 * \page bmi08g_api_bmi08g_get_data_int_status bmi08g_get_data_int_status
 * \code
 * int8_t bmi08g_get_data_int_status(uint8_t *int_status, struct bmi08_dev
 **dev); \endcode
 * @details This API is to get accel feature interrupt status
 *
 * @param[out] int_status      : Variable to store interrupt status
 * @param[in]  dev             : Structure instance of bmi08_dev
 *
 *@verbatim
 *----------------------------------------------
 *   int_status    |     Interrupt
 *----------------------------------------------
 *      0x08       |    Gyro data ready
 *      0x10       | Fifo full, Fifo watermark
 *----------------------------------------------
 *@endverbatim
 *
 *  @return Result of API execution status
 *  @retval 0 -> Success
 *  @retval < 0 -> Fail
 */
int8_t bmi08g_get_data_int_status(uint8_t *int_status, struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiSelftest Gyro self test
 * @brief Set / Get power mode of gyro sensor
 */

/*!
 * \ingroup bmi08gApiSelftest
 * \page bmi08g_api_bmi08g_perform_selftest bmi08g_perform_selftest
 * \code
 * int8_t bmi08g_perform_selftest(const struct bmi08_dev *dev);
 * \endcode
 * @details This API checks whether the self test functionality of the
 *  gyro sensor is working or not
 *
 *  @param[in]  dev : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08g_perform_selftest(struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08gApiFIFO FIFO
 * @brief Access and extract FIFO gyro data
 */

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_get_fifo_config bmi08g_get_fifo_config
 * \code
 * int8_t bmi08g_get_fifo_config(struct bmi08_gyr_fifo_config *fifo_conf, ,
 * struct bmi08_dev *dev); \endcode
 * @details This API is used to get the fifo configurations like fifo mode, fifo
 * data select, etc
 *
 * @param[in] fifo_conf  : Structure pointer to fifo configurations
 * @param[in] dev        : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_get_fifo_config(struct bmi08_gyr_fifo_config *fifo_conf,
                              struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_get_fifo_ext_int_sync bmi08g_get_fifo_ext_int_sync
 * \code
 * int8_t bmi08g_get_fifo_ext_int_sync(struct bmi08_gyro_fifo_ext_int
 * *fifo_config, struct bmi08_dev *dev); \endcode
 * @details This API is used to get external FIFO synchronization mode
 *
 * @param[in] fifo_conf  : Structure instance to external FIFO synchronization
 * mode
 * @param[in] dev        : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_get_fifo_ext_int_sync(struct bmi08_gyro_fifo_ext_int *fifo_config,
                                    struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_set_fifo_ext_int_sync bmi08g_set_fifo_ext_int_sync
 * \code
 * int8_t bmi08g_set_fifo_ext_int_sync(const struct bmi08_gyro_fifo_ext_int
 * *fifo_config, struct bmi08_dev *dev); \endcode
 * @details This API is used to set and enable external FIFO synchronization
 * mode
 *
 * @param[in] fifo_config  : Structure pointer to external FIFO synchronization
 * mode
 * @param[in] dev          : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t
bmi08g_set_fifo_ext_int_sync(const struct bmi08_gyro_fifo_ext_int *fifo_config,
                             struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_set_fifo_config bmi08g_set_fifo_config
 * \code
 * int8_t bmi08g_set_fifo_config(const struct bmi08_gyr_fifo_config *fifo_conf,
 * , struct bmi08_dev *dev); \endcode
 * @details This API is used to set the fifo configurations like fifo mode, fifo
 * data select, etc
 *
 * @param[in] fifo_conf  : Structure pointer to fifo configurations
 * @param[in] dev        : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_set_fifo_config(const struct bmi08_gyr_fifo_config *fifo_conf,
                              struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_get_fifo_length bmi08g_get_fifo_length
 * \code
 * int8_t bmi08g_get_fifo_length(const struct bmi08_gyr_fifo_config
 * *fifo_config, struct bmi08_fifo_frame *fifo); \endcode
 * @details This API is used to get fifo length
 *
 * @param[in] fifo_config  : Structure instance of bmi08_gyr_fifo_config
 * @param[in] fifo         : Structure instance of bmi08_fifo_frame.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_get_fifo_length(const struct bmi08_gyr_fifo_config *fifo_config,
                              struct bmi08_fifo_frame *fifo);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_read_fifo_data bmi08g_read_fifo_data
 * \code
 * int8_t bmi08g_read_fifo_data(const struct bmi08_gyr_fifo_config *fifo, struct
 * bmi08_dev *dev); \endcode
 * @details This API reads FIFO data.
 *
 * @param[in, out] fifo       : Structure instance of bmi08_fifo_frame
 * @param[in]      dev        : Structure instance of bmi08_dev.
 *
 * @note APS has to be disabled before calling this function.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_read_fifo_data(const struct bmi08_fifo_frame *fifo,
                             struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_extract_gyro bmi08g_extract_gyro
 * \code
 * void bmi08g_extract_gyro(struct bmi08_sensor_data *gyro_data,
 *                        const uint16_t *gyro_length,
 *                        const struct bmi08_gyr_fifo_config *fifo_conf,
 *                        const struct bmi08_fifo_frame *fifo);
 * \endcode
 * @details This API parses and extracts the gyroscope frames from FIFO data
 * read by the "bmi08g_read_fifo_data" API and stores it in the "gyro_data"
 * structure instance.
 *
 * @param[out]    gyro_data    : Structure instance of bmi08_sensor_data
 *                               where the parsed data bytes are stored.
 * @param[in,out] gyro_length  : Number of gyroscope frames.
 * @param[in,out] fifo_conf    : Structure instance of bmi08_gyr_fifo_config
 * @param[in,out] fifo         : Structure instance of bmi08_fifo_frame
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
void bmi08g_extract_gyro(struct bmi08_sensor_data *gyro_data,
                         const uint16_t *gyro_length,
                         const struct bmi08_gyr_fifo_config *fifo_conf,
                         const struct bmi08_fifo_frame *fifo);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_get_fifo_overrun bmi08g_get_fifo_overrun
 * \code
 * int8_t bmi08g_get_fifo_overrun(uint8_t *fifo_overrun, struct bmi08_dev *dev);
 * \endcode
 * @details This API is used to get the fifo over run
 *  in the register 0x0E bit 7
 *
 * @param[in,out] fifo_overrun  : The value of fifo over run
 * @param[in]     dev           : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_get_fifo_overrun(uint8_t *fifo_overrun, struct bmi08_dev *dev);

/*!
 * \ingroup bmi08gApiFIFO
 * \page bmi08g_api_bmi08g_enable_watermark bmi08g_enable_watermark
 * \code
 * int8_t bmi08g_enable_watermark(uint8_t enable, struct bmi08_dev *dev);
 * \endcode
 * @details This API is used to set fifo watermark enable/disable
 *  in the register 0x1E bit 7
 *
 * @param[in,out] enable        : The value of fifo watermark enable/disable
 * @param[in]     dev           : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval >0 -> Warning
 * @retval <0 -> Fail
 */
int8_t bmi08g_enable_watermark(uint8_t enable, struct bmi08_dev *dev);

/*********************************************************************************/
/*                              Accel APIs */
/*********************************************************************************/

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiFifo FIFO operations
 * @brief FIFO operations of the sensor
 */

/*!
 * \ingroup bmi08aApiFifo
 * \page bmi08a_api_bmi08a_get_set_fifo_config bmi08a_get_set_fifo_config
 * \code
 * int8_t bmi08a_get_set_fifo_config(struct bmi08_accel_fifo_config *config,
 * const struct bmi08_dev *dev, uint8_t select); \endcode
 * @details This API gets or sets the FIFO configuration of the sensor..
 *
 * @param[out] config   : Structure instance to get FIFO configuration value.
 * @param[in]  dev      : Structure instance of bmi08_dev.
 * @param[in] select    : Flag to select functionality between getting and
 * setting
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_set_fifo_config(struct bmi08_accel_fifo_config *config,
                                  struct bmi08_dev *dev, uint8_t select);

/*!
 * \ingroup bmi08aApiFifo
 * \page bmi08a_api_bmi08a_read_fifo_data bmi08a_read_fifo_data
 * \code
 * int8_t bmi08a_read_fifo_data(struct bmi08_fifo_frame *fifo, const struct
 * bmi08_dev *dev); \endcode
 * @details This API reads FIFO data.
 *
 * @param[in, out] fifo     : Structure instance of bmi08_fifo_frame.
 * @param[in]      dev      : Structure instance of bmi08_dev.
 *
 * @note APS has to be disabled before calling this function.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_read_fifo_data(struct bmi08_fifo_frame *fifo,
                             struct bmi08_dev *dev);

/*!
 * \ingroup bmi08aApiFifo
 * \page bmi08a_api_bmi08a_get_fifo_length bmi08a_get_fifo_length
 * \code
 * int8_t bmi08a_get_fifo_length(uint16_t *fifo_length, const struct bmi08_dev
 * *dev); \endcode
 * @details This API gets the length of FIFO data available in the sensor in
 * bytes.
 *
 * @param[out] fifo_length  : Pointer variable to store the value of FIFO byte
 *                            counter.
 * @param[in]  dev          : Structure instance of bmi08_dev.
 *
 * @note The byte counter is updated each time a complete frame is read or
 * written.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_fifo_length(uint16_t *fifo_length, struct bmi08_dev *dev);

/*!
 * \ingroup bmi08aApiFifo
 * \page bmi08a_api_bmi08a_get_set_fifo_wm bmi08a_get_set_fifo_wm
 * \code
 * int8_t bmi08a_get_fifo_wm(uint16_t *wm, const struct bmi08_dev *dev);
 * \endcode
 * @details This API gets the FIFO water mark level which is set in the sensor.
 *
 * @param[out] wm        : Pointer variable to store FIFO water-mark level.
 * @param[in]  dev       : Structure instance of bmi08_dev.
 * @param[in] select     : Flag to select functionality between getting and
 * setting
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */
int8_t bmi08a_get_set_fifo_wm(uint16_t *wm, struct bmi08_dev *dev,
                              uint8_t select);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiExtractAccel Extract accel frames from FIFO
 * @brief Parse and extract accelerometer frames from FIFO data read
 */

/*!
 * \ingroup bmi08aApiExtractAccel
 * \page bmi08a_api_bmi08a_extract_accel bmi08a_extract_accel
 * \code
 * int8_t bmi08a_extract_accel(struct bmi08_sensor_data *accel_data,
 *                          uint16_t *accel_length,
 *                           struct bmi08_fifo_frame *fifo,
 *                          const struct bmi08_dev *dev);
 * \endcode
 * @details This API parses and extracts the accelerometer frames from FIFO data
 * read by the "bmi08_read_fifo_data" API and stores it in the "accel_data"
 * structure instance.
 *
 * @param[out]    accel_data   : Structure instance of bmi08_sensor_data
 *                               where the parsed data bytes are stored.
 * @param[in,out] accel_length : Number of accelerometer frames.
 * @param[in,out] fifo         : Structure instance of bmi08_fifo_frame.
 * @param[in]     dev          : Structure instance of bmi08_dev.
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 * @retval > 0 -> Warning
 *
 */
int8_t bmi08a_extract_accel(struct bmi08_sensor_data *accel_data,
                            uint16_t *accel_length,
                            struct bmi08_fifo_frame *fifo,
                            const struct bmi08_dev *dev);

/**
 * \ingroup bmi08ag
 * \defgroup bmi08aApiFIFODown Accel FIFO down sampling
 * @brief Set / Get accel FIFO down sampling rate
 */

/*!
 * \ingroup bmi08aApiFIFODown
 * \page bmi08a_api_bmi08a_get_set_fifo_down_sample
 * bmi08a_get_set_fifo_down_sample \code int8_t
 * bmi08a_get_fifo_down_sample(uint8_t *fifo_downs, const struct bmi08_dev *dev,
 * uint8_t select); \endcode
 * @details This API gets the down sampling rate, configured for FIFO
 * accelerometer.
 *
 * @param[out] fifo_downs : Pointer variable to store the down sampling rate
 * @param[in]  dev        : Structure instance of bmi08_dev.
 * @param[in] select      : Flag to select functionality between setting and
 * getting
 *
 * @return Result of API execution status
 * @retval 0 -> Success
 * @retval < 0 -> Fail
 *
 */

int8_t bmi08a_get_set_fifo_down_sample(uint8_t *fifo_downs,
                                       struct bmi08_dev *dev, uint8_t select);

#ifdef __cplusplus
}
#endif

#endif /* _BMI08_H */
