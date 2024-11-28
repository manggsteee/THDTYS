#ifndef MAX30102_H_
#define MAX30102_H_

#include <stdint.h>
#include "fsl_lpi2c.h"

// MAX30102 I2C Address
#define MAX30102_I2C_ADDRESS (0x57)

// MAX30102 Register Definitions
#define MAX30102_REG_INTR_STATUS_1  0x00
#define MAX30102_REG_INTR_STATUS_2  0x01
#define MAX30102_REG_INTR_ENABLE_1  0x02
#define MAX30102_REG_INTR_ENABLE_2  0x03
#define MAX30102_REG_FIFO_WR_PTR    0x04
#define MAX30102_REG_OVF_COUNTER    0x05
#define MAX30102_REG_FIFO_RD_PTR    0x06
#define MAX30102_REG_FIFO_DATA      0x07
#define MAX30102_REG_MODE_CONFIG    0x09
#define MAX30102_REG_SPO2_CONFIG    0x0A
#define MAX30102_REG_LED1_PA        0x0C
#define MAX30102_REG_LED2_PA        0x0D
#define MAX30102_REG_PART_ID        0xFF

// Function Prototypes
void MAX30102_Init(LPI2C_Type *base);
uint8_t MAX30102_ReadRegister(LPI2C_Type *base, uint8_t reg);
void MAX30102_WriteRegister(LPI2C_Type *base, uint8_t reg, uint8_t value);
void MAX30102_ReadFIFO(LPI2C_Type *base, uint32_t *redData, uint32_t *irData);

#endif /* MAX30102_H_ */

