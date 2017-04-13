#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
//#include "/home/anna/Documents/transferFurie/printAll/printAll.c"


/*------------------------------------------------------------------------*/

	double defineStep(double maxAmplitude,int size){
		return maxAmplitude/size;		
	}

/*------------------------------------------------------------------------*/


	double *arrForDistributionFunction(double step,int size){
		double *result = (double*)calloc(size,sizeof(double));
		int i;
		double x=step;
		for(i=0;i<size;i++){
			result[i]=x;
			x+=step;
		}
		return result;
	}

/*------------------------------------------------------------------------*/


	double findMaxAmplitude(double *amplitude, int size){
		int i;
		double max = amplitude[1];
		int index=1;
		for(i=1;i<size;i++){
			if(amplitude[i]>max) {
				max= amplitude[i];
				index=i;
			}
		}
		return index;
	}


/*------------------------------------------------------------------------*/

	void sortArray(double *allAmplitudes,int size){
		int i;
		int j;
		for(i=0;i<size;i++){
		double min = allAmplitudes[i];
			for(j=i+1;j<size;j++){
				if(allAmplitudes[j]<min){
					allAmplitudes[i] = allAmplitudes[j];
					allAmplitudes[j] = min;
	         			min = allAmplitudes[i];
				}
			}
		}
	}
	
/*------------------------------------------------------------------------*/


	double findAmountOfGarmonik(double *allAmplitudes, double amplitude,int size){//find amount of garmonics that less then input amplitude
		int i;
		double result=0;
		for(i=0;i<size;i++){
			if((allAmplitudes[i]-amplitude)<0.0001){
				result+=1;
			}
		}
		return result;
	}

/*------------------------------------------------------------------------*/

	double **findDistributionFunction(double *amplitude, double *realAmplitude,int size){
		int i;
		double **result = (double**)calloc(2*size,sizeof(double));
		for(i=0;i<size;i++){
			result[i] = (double*)calloc(size,sizeof(double));
		}
		for(i=0;i<size;i++){
		        result[i][0] = amplitude[i];
			result[i][1] = findAmountOfGarmonik(realAmplitude,amplitude[i],size);
		}
		return result;
	}


/*------------------------------------------------------------------------*/


	double **findDensityDistribution(double *amplitude, double *realAmplitude, int size){
		int i;
		double **result = (double**)calloc(2*size,sizeof(double));
		for(i=0;i<size;i++){
			result[i] = (double*)calloc(size,sizeof(double));
		}
		double **distributionFunction = findDistributionFunction(amplitude,realAmplitude,size);

printf("-----------------------------------\n");
printTwoDegreeArray(distributionFunction ,size,2);
		for(i=1;i<size;i++){
		        result[i][0] = amplitude[i];
			result[i][1] = distributionFunction[i][1]-distributionFunction[i-1][1];
		}
		return result;
	}


/*------------------------------------------------------------------------*/


	double **getDensityDistribution(double *amplitude,int size){//MAIN METHOD!
		sortArray(amplitude,size);
		double max =  findMaxAmplitude(amplitude,size);
		double step = defineStep(max,size);
		double *distArr = arrForDistributionFunction(step,size);
		double **result = findDensityDistribution(distArr,amplitude,size);
		return result;
	}
/*------------------------------------------------------------------------*/


	/*int main(){
		int a=8;
		double *arr = (double*)calloc(a,sizeof(double));
		fullArray(arr,a);
/*printD(arr,a);
printf("-----------------------------------\n");
		sortArray(arr,a);
		double max =  findMaxAmplitude(arr,a);
		double step = defineStep(max,a);
printf("st %lf\n",step);
		double *distArr = arrForDistributionFunction(step,a);
		printD(distArr,a);
		double **funcDenc = findDensityDistribution(distArr,arr,a);
printf("-----------------------------------\n");
		printTwoDegreeArray(funcDenc,a,2);
           double **result =getDensityDistribution(arr,a);

printf("-----------------------------------\n");
printTwoDegreeArray(result,a,2);
	}*/

/*------------------------------------------------------------------------*/

