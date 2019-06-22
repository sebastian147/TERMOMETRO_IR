/**
===============================================================================
 Name        : system.h
 Author      : Sebastian
 Version     : 1.0
 Copyright   : $(copyright)
 Description : system definition
 	 	 	 	 se encarga de inicializar las tareas,
 	 	 	 	 el sistema, ademas de manejar las posibles
 	 	 	 	 fallas del mismo.
===============================================================================
*/
#ifndef _SYSTEM_H
#define _SYSTEM_H 1


//! ------ Public constants -----------------------------------------
//! Required system operating frequency (in Hz)
//! Will be checked in the scheduler initialization file
#define Required_SystemCoreClock (100000000)	// 100MHz

#define SysTick_RateHz	(1000)				// 1000 ticks per Second

#define SysTick_RatemS	(1000 / SysTick_RateHz)		// 1mS
#define SysTick_RateuS	(1000 * SysTick_RatemS)		// 1000uS

#define WatchDog_RateuS ((11 * SysTick_RateuS)/10)	// 1100uS


//------------------------------------------------------------------
// System fault codes
//------------------------------------------------------------------

//! Scheduler fault codes
#define FAULT_SCH_TOO_MANY_TASKS (1)
#define FAULT_SCH_ONE_SHOT_TASK (2)

//! Other fault codes may be added here, if required

//------------------------------------------------------------------
// Project constants
//------------------------------------------------------------------

#define RETURN_NORMAL 0
#define RETURN_FAULT 1


// Three possible system modes
typedef enum {FAIL_SILENT, NORMAL, FAULT_TASK_TIMING} eSystem_mode;



//! ------ Public data type -----------------------------------------


//! ------ Public function prototypes -------------------------------
void SYSTEM_Init(void);
void SYSTEM_Perform_Safe_Shutdown(void);
void SYSTEM_Change_Mode_Fault(eSystem_mode mode);
eSystem_mode SYSTEM_Get_Mode(void);


#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
