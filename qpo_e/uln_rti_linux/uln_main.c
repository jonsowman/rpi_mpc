/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'uln_rti_linux'.
 *
 * Model version                  : 1.202
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Tue Nov 15 14:01:26 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "uln_rti_linux.h"             /* Model's header file */
#include "rtwtypes.h"
#include <omp.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

#define CONTROL_TIMESTEP 0.25 /* In seconds */

extern ExtU_uln_rti_linux_T uln_rti_linux_U;
extern ExtY_uln_rti_linux_T uln_rti_linux_Y;

double tstart, tend;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = 0;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(uln_rti_linux_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  uln_rti_linux_step();
 

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
    /* Unused arguments */
    (void)(argc);
    (void)(argv);

    /* UDP stuff */
    int udpSocket, nBytes;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
    int i;
    float *fp;
    float uOpt[1];

    /*Create UDP socket*/
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*Bind socket with address struct*/
    bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*Initialize size variable to be used later on*/
    addr_size = sizeof serverStorage;

    /* Initialize model */
    uln_rti_linux_initialize();

    /* Attach rt_OneStep to a timer or interrupt service routine with
     * period 0.1 seconds (the model's base sample time) here.  The
     * call syntax for rt_OneStep is
     *
     *  rt_OneStep();
     */
    printf("Warning: The simulation will run forever. "
            "Generated ERT main won't simulate model step behavior. "
            "To change this behavior select the 'MAT-file logging' option.\n");
    fflush((NULL));
    while (rtmGetErrorStatus(uln_rti_linux_M) == (NULL)) {
        /* Model states */
        nBytes = recvfrom(udpSocket,buffer,1024,0,
                (struct sockaddr *)&serverStorage, &addr_size);
        fp = (float *)buffer;
        uln_rti_linux_U.x0[0] = (real_T)fp[0];
        uln_rti_linux_U.x0[1] = (real_T)fp[1];
        uln_rti_linux_U.x0[2] = (real_T)fp[2];
        uln_rti_linux_U.x0[3] = (real_T)fp[3];
        printf("Got x0 = [%f %f %f %f %f]\n", 
                uln_rti_linux_U.x0[0],
                uln_rti_linux_U.x0[1],
                uln_rti_linux_U.x0[2],
                uln_rti_linux_U.x0[3]);

        /*  Perform other application tasks here */
        tstart = omp_get_wtime();
        rt_OneStep();
        tend = omp_get_wtime();

        printf("Time taken %.2f milliseconds (%.1f%%)\n", 
                (tend-tstart)*1e3,
                (tend-tstart)/CONTROL_TIMESTEP*100);
        printf("uOpt = [%.4f]\n", 
                uln_rti_linux_Y.uOpt[0]);

        /* Return uOpt to host */
        uOpt[0] = uln_rti_linux_Y.uOpt[0];
        sendto(udpSocket, uOpt, 1*sizeof(float), 0, 
                (struct sockaddr*) &serverStorage, addr_size);

        /* Wait until next */
        sleep(CONTROL_TIMESTEP);
    }

    /* Disable rt_OneStep() here */

    /* Terminate model */
    uln_rti_linux_terminate();
    return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
