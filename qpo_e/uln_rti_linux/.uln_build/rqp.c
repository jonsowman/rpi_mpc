/**
 * Jon Sowman 2016
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 */

#include "qpOASES_e.h"

USING_NAMESPACE_QPOASES

/* Setup data of first QP. */
/*real_t H[2*2] = { 1.0, 0.0, 0.0, 0.5 };
real_t A[1*2] = { 1.0, 1.0 };
real_t g[2] = { 1.5, 1.0 };
real_t lb[2] = { 0.5, -2.0 };
real_t ub[2] = { 5.0, 2.0 };
real_t lbA[1] = { -1.0 };
real_t ubA[1] = { 2.0 };*/

/* Setting up QProblem object. */
static Options options;
static QProblem example;
returnValue retval;

int nWSR;

void rqp_start(void)
{
	QProblemCON( &example,5,20,HST_POSDEF );
	Options_setToDefault( &options );
	options.printLevel = PL_NONE;
	QProblem_setOptions( &example,options );
    return;
}

void rqp_run(double *H, double *g, double *A, double *lb, double *ub, double *lbA, double *ubA, double *xOpt)
{
    /* Solve first QP. */
	nWSR = 20;
	retval = QProblem_init( &example,H,g,A,lb,ub,lbA,ubA,&nWSR,0 );

	/* Get and print solution of first QP. */	
	QProblem_getPrimalSolution( &example, xOpt );
}