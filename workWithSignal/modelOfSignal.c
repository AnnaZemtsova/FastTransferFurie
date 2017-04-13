 #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

  #define p  3.14159265359
/*------------------------------------------------------------------------*/

	double getY(double x){
		double y = 2*sin(1*x+p/16)+13*sin(2*x)+23*sin(x)+16*sin(1.08*x);//sin(5*x) + 4*cos(x) + 2*sin(x) - sin(3*x +2);//+16*sin(x)-sin(x)-cos(x);//-2*cos(2*x)+4*cos(4*x+3)-16*sin(6*x)+0.4*cos(2*x+5)-10*sin(3*x);
		return y;
	}

/*------------------------------------------------------------------------*/

	double defineStepOfSampling(double T,double N){
		double result = T/N;
		return result;
	}

/*------------------------------------------------------------------------*/

	double *getInputValues(int N,double T){
		double *inputValue = (double*)calloc(N,sizeof(double));
		double step = defineStepOfSampling((double)T,N);
		double x=0;
		int i;
		for(i=0;i<N;i++){	
			inputValue[i]=getY(x);
			x+=step;
		}
		return inputValue;
	}


/*------------------------------------------------------------------------*/


	/*  int main(){//ONLY FOR TEST
		int T=10;
		int N=64;
		double *inputValues = getInputValues(N,T);
		int i;
		for(i=0;i<N;i++){
			printf("%lf\n",inputValues[i]);
		}
	  }*/

/*------------------------------------------------------------------------*/
