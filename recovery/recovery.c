#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "/home/anna/Documents/transferFurie/workWithTree/transferFurie.c"
#include "/home/anna/Documents/transferFurie/workWithSignal/modelOfSignal.c"


/*------------------------------------------------------------------------*/

	double recoveryAmplitude(double *complex,int a){
		double result = 2*(sqrt(pow(complex[0],2)+pow(complex[1],2)))/a;
		return result;
	}

/*------------------------------------------------------------------------*/


	double *recoveryAmplitudes(double **allComplex,int a){
		double limit = 0.1*0.1*(double)a*(double)a;
 		double *result = (double*)calloc(a,sizeof(double));
		int i;
		for(i=0;i<a/2;i++){
			double lim2 = allComplex[i][0]*allComplex[i][0]+allComplex[i][1]*allComplex[i][1];
			if((lim2-limit)>0.1)
			result[i]=recoveryAmplitude(allComplex[i],a);
			else result[i] = 0.0;
		}
		return result;
	}


/*------------------------------------------------------------------------*/

	double recoveryPhase(double *complex){
		double result = atan(complex[1]/complex[0]);
		return result;
	}


/*------------------------------------------------------------------------*/


	double *recoveryPhases(double **allComplex,int a){
 		double *result = (double*)calloc(a,sizeof(double));
		int i;
		for(i=0;i<a;i++){
			result[i]=recoveryPhase(allComplex[i]);
		}
		return result;
	}


/*------------------------------------------------------------------------*/

	double *recoveryFrequency(double **allComplex,int T,int a){
 		double *result = (double*)calloc(a,sizeof(double));
		int i;
		for(i=1;i<a;i++){
			result[i]=(double)i/T;
		}
		return result;
	}


/*------------------------------------------------------------------------*/

/*	int main(){//ONLY FOR TEST
   //double meth(){
		int i;
		double T=6*p;
		int a=512;
		double *inputValues = getInputValues(a,T);
		double *firstInput = (double*)calloc(a/2,sizeof(double));
		double *secondInput = (double*)calloc(a/2,sizeof(double));
		for(i=0;i<a/2;i++) firstInput[i]=inputValues[i];
		for(i=a/2;i<a;i++) secondInput[i-a/2]=inputValues[i];


		double **complex1 = (double**)calloc(a,sizeof(double));
		for(i=0;i<a/2;i++)
		   complex1[i] = (double*)calloc(2,sizeof(double));

		double **complex2 = (double**)calloc(a,sizeof(double));
		for(i=0;i<a/2;i++)
		   complex2[i] = (double*)calloc(2,sizeof(double));

		complex1 = fastTransferFurie(a/2,firstInput);
		complex2 = fastTransferFurie(a/2,secondInput);


		/*for(i=0;i<a;i++){
			printf("Inp %lf\n",inputValues[i]);  
		}

		for(i=0;i<a;i++){
			printf(" %lf ||| %lf\n",complex[i][0],complex[i][1]);  
		}*/
 /*
		double *allAmplitude1 = recoveryAmplitudes(complex1,a/2);
		double *allPhase1= recoveryPhases(complex1,a/2);
		double *allFrequency1 = recoveryFrequency(complex1,T/2,a/2);


		double *allAmplitude2 = recoveryAmplitudes(complex2,a/2);
		double *allPhase2= recoveryPhases(complex2,a/2);
		double *allFrequency2 = recoveryFrequency(complex2,T/1,a/2);

		for(i=1;i<a/4;i++){
			if((allAmplitude1[i]-0.1)>0)
			printf("%d. A: %lf ||ph: %lf ||F %lf\n",i,allAmplitude1[i],allPhase1[i],allFrequency1[i]);  
		}

printf("--------------------------------------\n");
		for(i=1;i<a/4;i++){
			if((allAmplitude2[i]-0.1)>0)
			printf("%d. A: %lf ||ph: %lf ||F %lf\n",i,allAmplitude2[i],allPhase2[i],allFrequency2[i]);  
		}	

printf("--------------------------------------\n");

	for(i=1;i<a/4;i++){
		if(fabs(allPhase2[i]-allPhase1[i])>0.001&&((allAmplitude1[i]-0.1)>0)){ 
			printf("%d.A: %lf ||ph: %lf ||F %lf\n",i,allAmplitude1[i],allPhase2[i]-allPhase1[i],allFrequency1[i]);  
                }
	}
/*
		for(i=0;i<a/2;i++){
		   printf(" %lf |||  %lf",result[i][0],result[i][1]);  
		   printf("\n");
		}
         return allAmplitude;*/	   
	//}


/*------------------------------------------------------------------------*/
