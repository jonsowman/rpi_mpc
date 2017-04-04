/**
 * Jon Sowman 2016-17
 *
 * This file is part of the Ultra-Low NOx project. 
 *
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 */

#ifndef __RQP_H__
#define __RQP_H__

void rqp_start(void);
void rqp_run(double *H, double *g, double *A, double *lb, double *ub, 
        double *lbA, double *ubA, int nV, int nC, double *xOpt, 
        double *yOpt, double *obj);

#endif /* __RQP_H__ */