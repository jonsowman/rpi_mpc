/**
 * Jon Sowman 2016
 * js29
 * j.sowman@soton.ac.uk
 * jonathan.sowman@ricardo.com
 */

#ifndef __RQP_H__
#define __RQP_H__

void qpOASES_uln_start();
void qpOASES_uln_run(double *H, double *g, double *A, double *lb, double *ub, double *lbA, double *ubA, int nV, int nC, double *xOpt, double *yOpt, double *obj, int *status);
void qpOASES_uln_terminate(void);

#endif /* __RQP_H__ */