#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define p  3.14159265359
#define a0  0.3635819
#define a1  0.4891775
#define a2  0.1365995
#define a3  0.0106411

/*------------------------------------------------------------------------*/

	   double findCos(int k,int N){
		 double res;
		 long double arg = (long double)(2*k)/N;
		 arg = arg*p;
		 res = cos(arg);
		 return res;
	   }

/*------------------------------------------------------------------------*/

	   double findSin(int k,int N){
		 double res;
		 long double arg =(long double) (2*k)/N;
		 arg = arg*p;
		 res = -sin(arg);
		 return res;
	   }

/*------------------------------------------------------------------------*/
   
	  double *multiply(double* W1,double *W2){
	    double *result = (double*)calloc(2,sizeof(double));
	    result[0]=W1[0]*W2[0]-W1[1]*W2[1];
	    result[1]=W1[0]*W2[1]+W2[0]*W1[1];
	   return result;
	  }
  
/*------------------------------------------------------------------------*/

	 double *sum(double *W1,double *W2){
	    double *result = (double*)calloc(2,sizeof(double));
	    result[0]=(W1[0]+W2[0]);
	    result[1]=(W1[1]+W2[1]);
	   return result;
	  }

/*------------------------------------------------------------------------*/


	 double *minus(double *W1,double *W2){
	    double *result = (double*)calloc(2,sizeof(double));
	    result[0]=(W1[0]-W2[0]);
	    result[1]=(W1[1]-W2[1]);
	   return result;
	  }


/*------------------------------------------------------------------------*/
  double *multiplyT(double W1,double *W2){//ONLY FOR TEST-PROGRAM/Don`t use in real
	    double *result = (double*)calloc(2,sizeof(double));
	    result[0]=W1*W2[0];
	    result[1]=-W1*W2[1];
	   return result;
	  }

