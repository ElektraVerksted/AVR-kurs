#include "mcp9808.h"
#include "mcc_generated_files/system/system.h"
#include <stdint.h>
#include <stdio.h>


uint16_t MCP9808_temp(){
    uint8_t data[2];
    uint8_t tempRegister = 0x05;

    // Les to bytes fra temperaturregisteret 
    I2C_Host_WriteRead(0x1C, &tempRegister, 1, data, 2);

    while(I2C_Host_IsBusy()){}


    return (data[0] & 0x1F) * 16 + data[1] / 16;
}
