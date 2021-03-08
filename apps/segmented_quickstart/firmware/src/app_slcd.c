/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_slcd.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_slcd.h"
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "gfx/driver/controller/slcd/drv_gfx_slcd.h"

const uint32_t quickstart_map[] = {
	0xE03C, 0x601C, 0x8484, 0xC014, 0x4930, 0xC30C, 0x8480, 0xE318, 0xE330, 0x8480 /* quickstart */
};

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_SLCD_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_SLCD_DATA app_slcdData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SLCD_Initialize ( void )

  Remarks:
    See prototype in app_slcd.h.
 */

void APP_SLCD_Initialize ( void )
{
    
	slcd_set_contrast(0xf);

    /* turn on backlight */
    SLCD_BACLKLIGHT_Set();
       
	/* Character map*/
	slcd_character_map_set(SLCD_AUTOMATED_CHAR_START_FROM_BOTTOM_RIGHT, 1);
	for(uint32_t i = 0; i < 8; i++) {
		slcd_character_write_data(0, 8 + i*2, quickstart_map[0+i], 0xffff0003);
	}

    /* enable lcd */
    slcd_enable();

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */

    /* Place the App state machine in its initial state. */
    app_slcdData.state = APP_SLCD_STATE_INIT;


    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_SLCD_Tasks ( void )

  Remarks:
    See prototype in app_slcd.h.
 */

void APP_SLCD_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( app_slcdData.state )
    {
        /* Application's initial state. */
        case APP_SLCD_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                app_slcdData.state = APP_SLCD_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_SLCD_STATE_SERVICE_TASKS:
        {

            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
