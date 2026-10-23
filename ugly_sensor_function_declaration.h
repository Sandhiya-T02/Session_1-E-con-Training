#ifndef UGLY_SENSOR_FUNCTION_DECLARATION_H
#define UGLY_SENSOR_FUNCTION_DECLARATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Definition
typedef struct
{
        int address;
        int value;
} Register_t;

//Function declaration 
int ReadRegister(int number);
int InitSensor(char *input_name);


#endif
