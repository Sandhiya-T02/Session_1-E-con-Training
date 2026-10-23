/*DESCRIPTION OF PROGRAM: This program checks for the
 * address of register,updates the count based on register.
 * It returns a value based on count*/

#include "ugly_sensor_function_declaration.h"

//MACRO DECALARATION
#define REGISTER_1_ADDRESS	0x300 // Address for first register
#define REGISTER_COUNT		4     // Number of registers
				      
#define SQR(x) x*x


//Initialization of Global variables
int g_count;
Register_t *g_Register;


int main()
{
        int result;
        int is_error = 0;
        result = InitSensor("CameraSensor0");


        if(result > 1 || result == 1)//checks if InitSensor Function has properly worked
        {
                printf("InitSensor function failed\n ");
                is_error = 1;
        }
        else
        {
                printf("InitSensor function succeeded\n");
        }
        return is_error;
}


/*Function: Doubles the given number
 *ReturnType: returns the doubled number (int)
 *Argument: An Integer number from user. */
int ReadRegister(int number) 
{ 
	return number * 2; 
}   


/* Function: Returns an integer value based on the address of the Register
 * ReturnType: returns an integer 
 * Argument: An character array from user */
int InitSensor(char *input_name)
{	
	//Initialization and declaration of variables
	size_t input_name_size = 0;
  	int index = 0;
	int return_value = 0;
	int limit = 10;  
	int number_t = -1;
	unsigned char is_error = 0;

	input_name_size = strlen(input_name) + 1;
	char device_name[input_name_size];


  	strcpy(device_name,input_name);
  	g_Register = (void *)malloc(REGISTER_COUNT * sizeof(Register_t));//size allocation for g_Register

	if(g_Register == NULL)//checks if malloc has assigned memory correctly
	{
		printf("Memory allocation failed\n");
		is_error = 1;
	}
	else
	{
		printf("Memory allocation for g_Register is successfull!!\n");
	}

	if(!is_error)
	{
		//Allocates address and value for each register based on first register's address
		for(index = 0;index<REGISTER_COUNT;index++)
        	{
                	g_Register[index].address = REGISTER_1_ADDRESS + index;
                	g_Register[index].value = ReadRegister(g_Register[index].address);
        	}

        	if (g_Register[0].value == (REGISTER_1_ADDRESS*2))//checks if for loop has ran properly
        	{
                	printf("sensor ok\n");
                	printf("init done\n");
        	}
        	else
        	{
                	printf("init can't be performed\n");
			is_error = 1;
        	}
	}

	if(!is_error)//assigns count value based on other register's value
	{
		switch (g_Register[1].value) 
		{
  			case ((REGISTER_1_ADDRESS +1)*2): 
				g_count = 1; 
				break;
  			case ((REGISTER_1_ADDRESS +2)*2): 
				g_count = 2;
				break;
			default:
				g_count = -1;
  		}
	}

  	if (!is_error && (g_count > 1))//updates return_value based on count value 
	{	
		return_value = 0;
        }		
  	else if (!is_error && (g_count == 1)) 
	{
		return_value = -1;
	}
	else
	{
	    return_value = 1;
	}

  
  	if (number_t < limit)
	{	
		printf("t is small\n");
	}

  	return SQR((return_value + 1));//squares the given value
}

