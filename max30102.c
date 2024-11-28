#include "max30102.h"

// Helper function to write data to a register
void MAX30102_WriteRegister(LPI2C_Type *base, uint8_t reg, uint8_t value) {
    lpi2c_master_transfer_t transfer;
    uint8_t data[2] = {reg, value};

    transfer.slaveAddress = MAX30102_I2C_ADDRESS;
    transfer.direction = kLPI2C_Write;
    transfer.subaddress = 0;
    transfer.subaddressSize = 0;
    transfer.data = data;
    transfer.dataSize = 2;
    transfer.flags = kLPI2C_TransferDefaultFlag;

    LPI2C_MasterTransferBlocking(base, &transfer);
}

// Helper function to read data from a register
uint8_t MAX30102_ReadRegister(LPI2C_Type *base, uint8_t reg) {
    lpi2c_master_transfer_t transfer;
    uint8_t value;

    // Write the register address
    transfer.slaveAddress = MAX30102_I2C_ADDRESS;
    transfer.direction = kLPI2C_Write;
    transfer.subaddress = reg;
    transfer.subaddressSize = 1;
    transfer.data = NULL;
    transfer.dataSize = 0;
    transfer.flags = kLPI2C_TransferDefaultFlag;

    LPI2C_MasterTransferBlocking(base, &transfer);

    // Read the register value
    transfer.direction = kLPI2C_Read;
    transfer.data = &value;
    transfer.dataSize = 1;

    LPI2C_MasterTransferBlocking(base, &transfer);

    return value;
}

// Initialize MAX30102
void MAX30102_Init(LPI2C_Type *base) {
    // Reset the sensor
    MAX30102_WriteRegister(base, MAX30102_REG_MODE_CONFIG, 0x40);

    // Configure SpO2 settings: 16-bit resolution, 100 Hz sampling rate
    MAX30102_WriteRegister(base, MAX30102_REG_SPO2_CONFIG, 0x27);

    // Set LED pulse amplitudes
    MAX30102_WriteRegister(base, MAX30102_REG_LED1_PA, 0x24); // Red LED
    MAX30102_WriteRegister(base, MAX30102_REG_LED2_PA, 0x24); // IR LED
}

// Read FIFO data (SpO2 and Heart Rate)
void MAX30102_ReadFIFO(LPI2C_Type *base, uint32_t *redData, uint32_t *irData) {
    uint8_t fifoData[6]; // 3 bytes each for Red and IR
    lpi2c_master_transfer_t transfer;

    transfer.slaveAddress = MAX30102_I2C_ADDRESS;
    transfer.direction = kLPI2C_Read;
    transfer.subaddress = MAX30102_REG_FIFO_DATA;
    transfer.subaddressSize = 1;
    transfer.data = fifoData;
    transfer.dataSize = 6;
    transfer.flags = kLPI2C_TransferDefaultFlag;

    LPI2C_MasterTransferBlocking(base, &transfer);

    // Parse data
    *redData = ((uint32_t)fifoData[0] << 16) | ((uint32_t)fifoData[1] << 8) | fifoData[2];
    *irData = ((uint32_t)fifoData[3] << 16) | ((uint32_t)fifoData[4] << 8) | fifoData[5];
}

