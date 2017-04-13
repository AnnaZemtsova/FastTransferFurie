#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>


/*------------------------------------------------------------------------*/

	double findAverageValue(double *inputValue,int size){
		int i;
		double sum=0;
		for(i=0;i<size;i++){
			sum+=inputValue[i];
		}
		double result = sum/size;
		return result;
	}

/*------------------------------------------------------------------------*/


	double findStandardDeviation(double *inputValue,int size){
		int i;
		double sum=0;
		double average = findAverageValue(inputValue,size);
		for(i=0;i<size;i++){
			sum+=pow(inputValue[i]-average,2);
		}
		double result = sqrt(sum/(size-1));
		return result;	
	}

	
/*------------------------------------------------------------------------*/
