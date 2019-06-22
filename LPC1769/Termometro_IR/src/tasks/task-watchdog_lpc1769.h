/*------------------------------------------------------------------*-

    task-watchdog_lpc1769.h (Released 2015-04)

  ------------------------------------------------------------------

  - See task-watchdog_lpc1769.c for details.

-*------------------------------------------------------------------*/


#ifndef _WDT_H
#define _WDT_H 1


// ------ Public constants -----------------------------------------
// From NXP

/** Define divider index for microsecond ( us ) */
#define WDT_US_INDEX ((uint32_t)(1000000))

/** WDT Time out minimum value */
#define WDT_TIMEOUT_MIN ((uint32_t)(0xFF))

/** WDT Time out maximum value */
#define WDT_TIMEOUT_MAX ((uint32_t)(0xFFFFFFFF))

// Jumper connections
// WDT will only be enabled if jumper is inserted
// (connecting the jumper pin to ground)
// - see Port Header for jumper pin details.
#define WDT_JUMPER_INSERTED (0)
#define WDT_PCLK (4000000)


// ------ Public data type declarations ----------------------------


// ------ Public function prototypes -------------------------------
void WATCHDOG_Init(const uint32_t);
void WATCHDOG_Update(void);


#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
