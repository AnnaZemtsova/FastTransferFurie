#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "workWithBinaryCode17.c"
#include "complexOperations.c"

	

/*------------------------------------------------------------------------*/

	    int *findArrayForSecond(int M){
		  int *arr = (int*)calloc(M,sizeof(int));
		  int i=0;
		  int tmp = M;
		  while(tmp!=0){
		    arr[i]=i+1;
		    i=i+1;
		    tmp--;
		  }
	       return arr;
	    }


/*------------------------------------------------------------------------*/


	  double *findFirstW(double *arr){
		arr[0] = findCos(1,4);
		arr[1] = findSin(1,4); 
	  
	  }


/*------------------------------------------------------------------------*/

		int *findArrayOfN(int N,int M){
		  int *result = (int*)calloc(M,sizeof(int));
		  int i;
		  result[M-1]=N;
	 	  for(i=M-2;i>-1;i--){
		    N=N/2;
	 	    result[i]=N;        
		  }
		 return result;
		}



/*------------------------------------------------------------------------*/

	    double ***giveMemoryFor3(int a,int M,int *allN){//need a/2
		double*** arrResult = NULL;
		int sizeSecond=0;
		int i;
		int j;
		int k=0;
		 for(i=0;i<M;i++) sizeSecond+=allN[i];
		 arrResult = (double***)calloc(M,sizeof(double**));
		 for(i=0;i<M;i++){
		    arrResult[i]=(double**)calloc(allN[i],sizeof(double*));
		    for(j=0;j<allN[i];j++){
			    arrResult[i][j] = (double*)calloc(2,sizeof(double));		
		    }	
		   k++;
		 }
	      return arrResult;
	   }

/*------------------------------------------------------------------------*/
   
   

	   void findW(double *arr,int k,int N){;
		arr[0] = findCos(k,N);
		arr[1] = findSin(k,N);
	   }

/*------------------------------------------------------------------------*/

	  void fullAllM(double ***W,double **arr,int N,int index){
	    int i;
	    int power = N;
	    power = pow(2,power);
	    power = power*2;
	    findW(arr[0],1,power);
	     for(i=1;i<N;i++){
	 	  arr[i]=W[index-1][i-1];
	     }
	  }

/*------------------------------------------------------------------------*/	

	    void fullWArray(double ***W,int M,int *arrN){
		findFirstW(W[0][0]);
		int i;
		 for(i=1;i<M;i++){
		    fullAllM(W,W[i],arrN[i],i);
		 }
	    }


/*------------------------------------------------------------------------*/	

	  double ***getWArray3(int a){
		  int M = findTwoDegree(a/4)+1;
		  int *arr = findArrayForSecond(M);
		  double ***W = giveMemoryFor3(a/2,M,arr);
		  fullWArray(W,M,arr);
		return W;
	  }

/*------------------------------------------------------------------------*/
