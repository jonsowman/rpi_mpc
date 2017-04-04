/**
 * Jon Sowman 2016
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 *
 * $Id: qpOASES_uln.c 173 2016-11-15 13:39:30Z js29 $
 */

#include "qpOASES_uln.h"
#include "qpOASES_wrapper.h"

/* Setting up QProblem object. */
static qpOASES_Options options;
static int first_run;
static int nWSR;

/**
 * Configure the SQProblem and solver options
 */
void qpOASES_uln_start()
{
    /* Configure options */
    qpOASES_Options_init( &options,0 );
    
    /* Quiet unless errors */
    options.printLevel = PL_LOW;
    
    /* First run */
    first_run = 1;
    
    /*
	Options_setToDefault( &options );
	options.printLevel = PL_NONE;
	QProblem_setOptions( &example,options );
    */
    return;
}

/**
 * Run at each model timestep. Configure any relevant options
 * and then solve the QP
 */
void qpOASES_uln_run(double *H, double *g, double *A, double *lb, double *ub, double *lbA, double *ubA, int nV, int nC, double *xOpt, double *yOpt, double *obj, int *status)
{
    /* Solve QP, hotstarting if required */
    nWSR = 200;
    if( first_run )
    {
        SQProblem_setup( nV, nC, HST_UNKNOWN );
        SQProblem_init( H,g,A,lb,ub,lbA,ubA,&nWSR,0,&options,xOpt,yOpt,obj,status );
        first_run = 0;
    }
    else
    {
        SQProblem_hotstart( H,g,A,lb,ub,lbA,ubA,&nWSR,0,xOpt,yOpt,obj,status );
    }
}

/**
 * Call the qpOASES cleanup methods.
 */
void qpOASES_uln_terminate(void)
{
    SQProblem_cleanup();
}
