/**
 * Jon Sowman 2016-17
 *
 * This file is part of the Ultra-Low NOx project. 
 *
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 */

#include "qpOASES_e.h"

USING_NAMESPACE_QPOASES

#define __SUPPRESSANYOUTPUT __

/* Setting up QProblem object. */
static Options options;
static QProblem example;
returnValue retval;

int nWSR;

void rqp_start(void)
{
	Options_setToMPC( &options );
    QProblem_setOptions( &example,options );
}

void rqp_run(double *H, double *g, double *A, double *lb, double *ub, 
        double *lbA, double *ubA, int nV, int nC, double *xOpt, 
        double *yOpt, double *obj)
{
    /* Set up QP */
    QProblem_setPrintLevel( &example, PL_NONE );
    QProblemCON( &example, nV, nC, HST_POSDEF ); 
    
    /* Solve  QP. */
	nWSR = 200;
	retval = QProblem_init( &example,H,g,A,lb,ub,lbA,ubA,&nWSR,0 );

	/* Get primal solution of QP. */	
	QProblem_getPrimalSolution( &example, xOpt );
    
    /* Get dual solution */
    QProblem_getDualSolution( &example, yOpt );
    
    /* Get objective value */
    *obj = QProblem_getObjVal( &example );  
}
