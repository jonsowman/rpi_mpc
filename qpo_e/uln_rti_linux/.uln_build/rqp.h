/**
 * Jon Sowman 2016
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 */

#ifndef __RQP_H__
#define __RQP_H__

void rqp_start(void);
void rqp_run(double *H, double *g, double *A, double *lb, double *ub, double *lbA, double *ubA, double *xOpt);
//void rqp_run(double *H, double *g, double *lb, double *ub, double *xOpt);

#endif /* __RQP_H__ */