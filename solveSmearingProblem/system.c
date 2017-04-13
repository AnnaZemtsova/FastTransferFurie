#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "/home/anna/Documents/transferFurie/recovery/recovery.c"
#include "/home/anna/Documents/transferFurie/solveSmearingProblem/findDensityDistribution.c"


/*------------------------------------------------------------------------*/


	double findA(double m,int k,int N){
		double x = 2*p*(m-k);
		double y = 2*p*(m-k)/N;
		double result = (cos(x-y)-cos(x)-cos(y)+1)/(2*(1-cos(y)));
		return result;
	}

/*------------------------------------------------------------------------*/

	double findB(double m,int k,int N){
		double x = 2*p*(m-k);
		double y = 2*p*(m-k)/N;
		double result = (sin(y-x)-sin(y)+sin(x))/(2*(1-cos(y)));
		return result;
	}

/*------------------------------------------------------------------------*/


	double findC(double m,int k,int N){
		double x = 2*p*(m+k);
		double y = 2*p*(m+k)/N;
		double result = (cos(x-y)-cos(x)-cos(y)+1)/(2*(1-cos(y)));
		return result;
	}

/*------------------------------------------------------------------------*/

	double findD(double m,int k,int N){
		double x = 2*p*(m+k);
		double y = 2*p*(m+k)/N;
		double result = (sin(y-x)-sin(y)+sin(x))/(2*(1-cos(y)));
		return result;
	}


/*------------------------------------------------------------------------*/

	int compareForM(double *Xk,double *Xk1,double *Zk,double *Zk1,double e){
		int i=0;
		double a = sqrt(pow(Zk[0]*Xk1[0]+Zk[1]*Xk1[1],2)+pow(Xk1[1]*Zk[0]+Zk[1]*Xk1[0],2));
		double b = sqrt(pow(Xk[0]*Zk1[0]+Xk[1]*Zk1[1],2)+pow(Zk1[1]*Xk[0]+Xk[1]*Zk1[0],2));
		if (fabs(a-b)<e) i=1;
		return i;
	}



/*------------------------------------------------------------------------*/

	int compareForFi(double *Xk,double *Xk1,double *Zk,double *Zk1,double e){
		int i=0;
		double argZ = atan(Zk[1]/Zk[0]);
		double argX = atan(Xk[1]/Xk[0]);
		if(fabs(argZ-argX)<e) i=1;
		return i;
	}

/*------------------------------------------------------------------------*/

	double *defineZ(double m,double fi,int k,int N){
		double *Z = (double*)calloc(2,sizeof(double));
		double a=  findA(m,k,N);
		double b = findB(m,k,N);
		double c= findC(m,k,N);
		double d = findD(m,k,N);
		double cosFi = cos(fi);
		double sinFi = sin(fi);
		Z[0]= cosFi*(a+c)+sinFi*(b+d);
		Z[1]= cosFi*(d-b)+sinFi*(a-c);
		return Z;
	}

/*------------------------------------------------------------------------*/

	double defineM(double fi,int k,int N,double *Xk,double *Xk1,double e){

		int i=0;
		double step=0.00001;
		double m=k;
		while(i!=1){
			m+=step;
			double *Zk = defineZ(m,fi,k,N);
			double *Zk1 = defineZ(m,fi,k+1,N);
			i = compareForM(Xk,Xk1,Zk,Zk1,e);
		}
		printf("ResM %lf\n",m);
		return m;		
	}

/*------------------------------------------------------------------------*/

	double defineFi(double m,int k,int N,double *Xk,double *Xk1,double e){
		int i;
		double step=p/100;
		double fi=0;
		while(i!=1){
			fi+=step;
			double *Zk = defineZ(m,fi,k,N);
			double *Zk1 = defineZ(m,fi,k+1,N);
			i = compareForFi(Xk,Xk1,Zk,Zk1,e);
		}
		printf("ResFi = %lf\n",fi);
		return fi;		
	}
/*------------------------------------------------------------------------*/

	double *defineMAndPhase(int k,int N,double *Xk,double *Xk1){
		double  *mfi = (double*)calloc(2,sizeof(double));
		double e=0.01;
		mfi[0]=k+0.01;
		int i;
			mfi[1] = defineFi(mfi[0],k,N,Xk,Xk1,e);
 		        mfi[0] = defineM(mfi[1],k,N,Xk,Xk1,e);
                return mfi; 
	}

/*------------------------------------------------------------------------*/

	int main(){
		int i;
		double T=p;
		int a=64;
		double *inputValues = getInputValues(a,T);
		double **complex = (double**)calloc(a*2,sizeof(double));
		for(i=0;i<a;i++)
		   complex[i] = (double*)calloc(2,sizeof(double));
		complex = fastTransferFurie(a,inputValues);
		
		double *allAmplitude = recoveryAmplitudes(complex,a);
		double *allPhase= recoveryPhases(complex,a);
		double *allFrequency = recoveryFrequency(complex,T,a);
		
		int max = findMaxAmplitude(allAmplitude,a);
		printf("MAX %d\n",max);

		for(i=1;i<a/2;i++){
			if((allAmplitude[i]-0.1)>0)
			printf("%d. A: %lf ||ph: %lf ||F %lf\n",i,allAmplitude[i],allPhase[i],allFrequency[i]);  
		}

		double *mfi = defineMAndPhase(max,a,complex[max],complex[max+1]);
		double *Z = defineZ(mfi[0],mfi[1],max,a);
		double *Xk = complex[max];
		Xk[0]= 2*Xk[0];
		Xk[1]=2*Xk[1];
		//double re = 
		double foundAmplitude = (sqrt(pow(Xk[0],2)+pow(Xk[1],2)))/(sqrt(pow(Z[0],2)+pow(Z[1],2)));
		printf("foundAmplitude = %lf\n",foundAmplitude);
           
	}
	
/*------------------------------------------------------------------------*/

