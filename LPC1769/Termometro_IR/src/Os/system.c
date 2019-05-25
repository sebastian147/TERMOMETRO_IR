/**
===============================================================================
 Name        : system.c
 Author      : Sebastian
 Version     : 1.0
 Copyright   : $(copyright)
 Description : system definition
 	 	 	 	 se encarga de inicializar las tareas,
 	 	 	 	 el sistema, ademas de manejar las posibles
 	 	 	 	 fallas del mismo.
===============================================================================
*/
// Project header
#include "../main/main.h"


//! Task headers
//! aqui deberia incluir los headers de las funciones


//! ------ Public variable ------------------------------------------
//! In many designs, System_mode_G will be used in other modules.
//! - we therefore make this variable public.
eSystem_mode System_mode_G;


//! ------ Private function -----------------------------------------
void SYSTEM_Identify_Required_Mode(void);
void SYSTEM_Configure_Required_Mode(void);

/**
 * @brief Inicializa el sistema.
 *
 * @param void.
 * @return void.
 */
void SYSTEM_Init(void)
{
    SYSTEM_Identify_Required_Mode();
    SYSTEM_Configure_Required_Mode();
}

/**
 * @brief trata de ver el motivo del reseteo, y setea el modo del sistema operativo deacuerdo a eso.
 *
 * @param void.
 * @return void.
 * @note a mejorar
 */
void SYSTEM_Identify_Required_Mode(void)
{
	// Set system mode (Normal)
	System_mode_G = NORMAL;
}

/**
 * @brief configura el sistema operativo deacuerdo al modo.
 *
 * @param void.
 * @return void.
 */
void SYSTEM_Configure_Required_Mode(void)
{
	Chip_SetupXtalClocking();

	/** Setup FLASH access to 4 clocks (100MHz clock) */
	Chip_SYSCTL_SetFLASHAccess(FLASHTIM_100MHZ_CPU);

	SystemCoreClockUpdate();

	/** Initialize GPIO */
	Chip_GPIO_Init(LPC_GPIO);
	Chip_IOCON_Init(LPC_IOCON);

	switch (System_mode_G)
	{
        default: //! Default to "FAIL_SILENT"
        case FAIL_SILENT:
        {
            //! Reset caused by WDT
            //! Trigger "fail silent" behavior
            SYSTEM_Perform_Safe_Shutdown();

            break;
        }

        case NORMAL:
        {
        	//! Set up scheduler for 1 ms ticks (tick interval in *ms*)
            SCH_Init(1);

            /** Initialize WWDT and event router */
        	Chip_WWDT_Init(LPC_WWDT);

 //aca se inizializan las tareas

        	// Add tasks to schedule.
            // Parameters are:
            // 1. Task name
            // 2. Initial delay / offset (in ticks)
            // 3. Task period (in ticks): Must be > 0
            // 4. Task WCET (in microseconds)
            // 5. Task BCET (in microseconds)

// Add GPIO_SWITCH task
   // SCH_Add_Task(GPIO_SWITCH_Update, 1, 10, 20, 0);



            break;
        }
	}
}

/**
 * @brief pone al sistema opertaivo en un estado seguro.
 *
 * @param void.
 * @return void.
 * @note si esta el watchdog activo, hace que se resete el procesador
 *  lo que hace que el fallo pase devuelta cuando se resete,
 *  por ende es conveniente que entre a este estado seguro(revisar)
 */

void SYSTEM_Perform_Safe_Shutdown(void)
{
    //! Used for simple fault reporting
    uint32_t Delay, j;

    //! Here we simply "fail silent" with rudimentary fault reporting
    //! OTHER BEHAVIOUR IS LIKELY TO BE REQUIRED IN YOUR DESIGN
    //! *************************************
    //! NOTE: This function should NOT return
    //! *************************************
    // HEARTBEAT_Init();

    while(1)
	{
        //! Flicker Heartbeat LED to indicate fault
        for (Delay = 0; Delay < 200000; Delay++) j *= 3;
        //HEARTBEAT_Update();
	}
}


void SYSTEM_Change_Mode_Fault(eSystem_mode mode)
{
	System_mode_G = mode;
}


eSystem_mode SYSTEM_Get_Mode(void)
{
	return System_mode_G;
}


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
