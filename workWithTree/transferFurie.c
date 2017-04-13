#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "createTree.c"
#include "/home/anna/Documents/transferFurie/workWithW/workWithAllW.c"
double ***W;

/*------------------------------------------------------------------------*/

	    struct tree *fullTree(int N,double *arr){
		struct tree *evenOddTree;
		evenOddTree = createTree(arr,N);
		return evenOddTree;
	    }

/*------------------------------------------------------------------------*/

 	   double ***getWInMemory(int N){
		double ***W = getMemoryWArray(N);
		return W;
	   }

/*------------------------------------------------------------------------*/

	   void findTmpTransfer(struct tree* root,int size){
	      int i;	
	      int j=0;
	      int s = size/2;
	      for(i=0;i<s;i++){
		  j=i;
		  double *w = getW(i,size,W);
                  double *odd = multiply(w,(*(*root).right).complex[i]);
		  (*root).complex[j] = sum((*(*root).left).complex[i],odd); 
		  (*root).complex[j+s] = minus((*(*root).left).complex[i],odd) ;
		  j+=s;
              }
	   }

/*------------------------------------------------------------------------*/

           void transferFurie(struct tree* root,int size){
		if(size <2) {
			(*root).complex[0][0]=(*root).arr[0];
			(*root).complex[0][1]=(*root).arr[1];
			return;
		}
	   	transferFurie((*root).left,size/2); 
	   	transferFurie((*root).right,size/2);
	        findTmpTransfer(root,size);	        
	   }    

/*------------------------------------------------------------------------*/

	     double **fastTransferFurie(int a, double *arr){//MAIN METHOD!!!!!! 
		int i;
		struct tree *evenOddTree = fullTree(a,arr);
		W = getWInMemory(a);
		transferFurie(evenOddTree,a);
		//printTree(evenOddTree,a);
		double **result = (double**)calloc(a*2,sizeof(double));
		for(i=0;i<a;i++)
		   result[i] = (double*)calloc(2,sizeof(double));
		result = (*evenOddTree).complex;
		return result;
	     }



/*------------------------------------------------------------------------*/
