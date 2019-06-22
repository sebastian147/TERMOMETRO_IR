/*------------------------------------------------------------------*-

    monittor_lpc1769.h (Released 2019-04)

  ------------------------------------------------------------------

    See monittor_lpc1769.c for details.

-*------------------------------------------------------------------*/

#ifndef _MONITTOR_H
#define _MONITTOR_H 1


// ------ Public constants -----------------------------------------


// ------ Public data type declarations ----------------------------


// ------ Public function prototypes -------------------------------
void MONITTOR_I_Init(void);

void MONITTOR_I_Start(const uint32_t TASK_ID,
	    			  // Task Identier
					  const uint32_t TASK_WCET_us,
					  // Worst-case execution time (microseconds)
					  const uint32_t TASK_BCET_us,
					  // Best-case execution time (microseconds)
					  const uint32_t ALLOWED_TIMING_VARIATION_us);

uint32_t MONITTOR_I_Stop(void);

void MONITTOR_I_Disable(void);


#endif
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
