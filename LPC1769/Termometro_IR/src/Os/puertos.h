/**
===============================================================================
 Name        : puertos.h
 Author      : Sebastian
 Version     : 1.0
 Copyright   : $(copyright)
 Description : puertos definition
 	 	 	 	 tiene las definiciones de los puertos, pines
 	 	 	 	 y las variables que necesito para manejar
 	 	 	 	 los perifericos del microcontrolador
===============================================================================
*/

#ifndef _PORT_H
#define _PORT_H 1


// ------ Public constants -----------------------------------------
#define TIM_PRESCALE_USVAL	(100)
// Allows Active Low or Active High led to be used (or other wiring variations)
#define LED_ON	(true)
#define LED_OFF (false)


// Heartbeat LED
// Connected to "LED2" on LPC1769 board
// Port 0, Pin 22
#define HEARTBEAT_LED_PORT (0)
#define HEARTBEAT_LED_PIN (22)
#define HEARTBEAT_LED_PIN_MODE (IOCON_MODE_INACT)
#define HEARTBEAT_LED_PIN_FUNC (IOCON_FUNC0)


// RGB LED
// Connected to "RED" on LPC1769 board
// Port 2, Pin 0


// RGB LED
// Connected to "GREEN" on LPC1769 board
// Port 2, Pin 1
#define GPIO_LED_PORT (2)
#define GPIO_LED_PIN (1)
#define GPIO_LED_PIN_MODE (IOCON_MODE_INACT)
#define GPIO_LED_PIN_FUNC (IOCON_FUNC0)


// RGB LED
// Connected to "BLUE" on LPC1769 board
// Port 0, Pin 26


// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED (false)
#define SW_NOT_PRESSED (true)


// SW2-PRESS SWITCH
// Connected to "SW2 PRESS" on LPCXpresso baseboard
// Port 0, Pin 17


// SW2-UP SWITCH
// Connected to "SW2 UP" on LPCXpresso baseboard
// Port 2, Pin 3


// SW2-DOWN SWITCH
// Connected to "SW2 DOWN" on LPCXpresso baseboard
// Port 0, Pin 15


// SW2-LEFT SWITCH
// Connected to "SW2 LEFT" on LPCXpresso baseboard
// Port 2, Pin 4


// SW2-RIGHT SWITCH
// Connected to "SW2 RIGHT" on LPCXpresso baseboard
// Port 0, Pin 16


// SW3 SWITCH
// Connected to "SW3" on LPCXpresso baseboard
// Port 2, Pin 10
#define GPIO_SWITCH_PORT (2)
#define GPIO_SWITCH_PIN (10)
#define GPIO_SWITCH_PIN_MODE (IOCON_MODE_PULLUP)
#define GPIO_SWITCH_PIN_FUNC (IOCON_FUNC0)


// SW4 SWITCH
// Connected to "SW4" on LPCXpresso baseboard
// Port 1, Pin 31

// Add jumper wire on baseboard to control WDT
// WDT is enabled *only* if jumper is in place.
// (Jumper is read at init phase only)
// Port 2, Pin 3 => Connected to "SW2 UP" on LPCXpresso baseboard
#define WDT_JUMPER_PORT (2)
#define WDT_JUMPER_PIN (3)
#define WDT_JUMPER_PIN_MODE (IOCON_MODE_PULLUP)
#define WDT_JUMPER_PIN_FUNC (IOCON_FUNC0)

// ------ Public data type -----------------------------------------


// ------ Public function prototypes -------------------------------


#endif


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
