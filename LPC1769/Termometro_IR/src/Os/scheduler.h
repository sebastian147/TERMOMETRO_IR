/**
===============================================================================
 Name        : sheduler.h
 Author      : Sebastian
 Version     : 1.0
 Copyright   : $(copyright)
 Description : scheduler definition
 	 	 	 	Se encarga de administrar las tareas, dandole
 	 	 	 	el tiempo de ejecucion correspondiente a cada una,
 	 	 	 	ademas de que maneja las fallas.
===============================================================================
*/


#ifndef _SCHEDULER_H
#define _SCHEDULER_H 1


//! ------ Public constants -----------------------------------------
//! The maximum number of tasks required at any one time
//! during the execution of the program
//
//! MUST BE CHECKED FOR EACH PROJECT (*not* dynamic)
#define SCH_MAX_TASKS (20)

#define SCH_DEBUG_TASK_RUN_OK		(1<<0)
#define SCH_DEBUG_TASK_UNDERRUN		(1<<1)
#define SCH_DEBUG_TASK_OVERRUN		(1<<2)


//! ------ Public data type -----------------------------------------
//! User-define type to store required data for each task
typedef struct
{
    uint32_t WCET;
    uint32_t BCET;
    uint32_t LET;
    uint32_t RunTimes;
	uint32_t State;
} debugInfo;


typedef struct
{
    //! Pointer to the task (must be a 'void (void)' function)
    void (*pTask) (void);
    //! Delay (ticks) until the task will (next) be run
    //! - see SCH_Add_Task() for further details
    uint32_t Delay;
    //! Interval (ticks) between subsequent runs.
    //! - see SCH_Add_Task() for further details
    uint32_t Period;
    //! Worst-case execution time (microseconds)
    uint32_t WCET;
    //! Best-case execution time (microseconds)
    uint32_t BCET;
    //! Debug Info.
    debugInfo Debug;
} sTask;


// ------ Public function prototypes -------------------------------
void SCH_Init(const uint32_t TICKms);			// Tick interval (ms)
void SCH_Start(void);
void SCH_Dispatch_Tasks(void);

uint32_t SCH_Add_Task(void (* pTask)(),
                      const uint32_t DELAY,		// Offset (in ticks)
                      const uint32_t PERIOD,	// Ticks
                      const uint32_t WCET,		// Microseconds
                      const uint32_t BCET		// Microseconds
);

uint32_t SCH_Get_Current_Task(void);
sTask* SCH_Get_Current_Task_Pointer(void);


#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
