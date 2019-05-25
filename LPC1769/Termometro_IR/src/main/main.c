/**
===============================================================================
 Name        : main.c
 Author      : Sebastian
 Version     : 1.0
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include "main.h"

int main(void) {

	//! Check mode, add tasks to schedule
	SYSTEM_Init();

    //! Start the scheduler
    SCH_Start();

    while(1)
    {
    	SCH_Dispatch_Tasks();
    }

    return (RETURN_FAULT);
}
