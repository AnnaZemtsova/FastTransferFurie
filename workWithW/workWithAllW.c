#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "workWithWInMemory.c"

/*------------------------------------------------------------------------*/


  int* findArrayOfWDegree(int a,int size,int findI){//WAS CHANGED FROM 15 TO 16, FROM 16 TO 17
	    arr = (int*)calloc(17,sizeof(int));
 	    arr= intToBits(a);
 	    int i;
  	    int j=0;
 	    int *result =( int*) calloc(size,sizeof(int));
	    for(i=0;i<size;i++){
		   result[i]=0;
		}
		 
	    for(i=16;i>=findI;i--){
		   if(arr[i]==1) {
			result[j]=abs(i-16);
			j++;
		   }
	    }

	    if(result[1]==0){
 		 result[0]=result[0]-1;
		 result[1]=result[0];
	    }

	   for(i=0;i<size;i++){
            if(i==0||result[i]!=0)
	     result[i]=pow(2,result[i]);
	   }
	 return result;
	}

/*------------------------------------------------------------------------*/

	  int definePlaceIn3Array(int N){
	     int nDegree = findTwoDegree(N);
	     nDegree = nDegree-2;
	    return nDegree; 
	  }

/*------------------------------------------------------------------------*/


	double *getW(int k,int N,double ***WArray){
	  double *result = (double*)calloc(2,sizeof(double));
	   if(k==0){
                 result[0]=1.0;
		 result[1]=0.0;
          
          }else{
	    if(N==2) {
		result[0] = -1.0;
		result[1] = 0.0;
	   }else{
	  int index = definePlaceIn3Array(N);
          if(k==1) result = WArray[index][0];
          else if(k==2){
		  if(N==4){
		     result[0]=-1.0;
		     result[1]=0.0;
		 } else result = WArray[index][1];
		}
          else{
	  	  int foundI=defineI(k);
		  int size = 17-foundI;//WAS CHANGED FROM 16 TO 17!!
		  int *wDegree = findArrayOfWDegree(k,size,foundI);
		  int power = findTwoDegree(wDegree[0]);
	  	  result=WArray[index][power];
		  int i;
		   for(i=1;i<size;i++){
			 if(wDegree[i]!=0){
		           power = findTwoDegree(wDegree[i]);
		           result = multiply(result,WArray[index][power]);
		       	 }
		   }
	        }
	   }
	}
 	  return result;
	}


/*------------------------------------------------------------------------*/
        double ***getMemoryWArray(int a){
		double ***result = getWArray3(a);
	 	return result;
	}

/*------------------------------------------------------------------------*/
