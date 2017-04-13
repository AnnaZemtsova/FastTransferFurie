#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "tree.h"


/*------------------------------------------------------------------------*/

	 double* findEven(double* arr,int size){
	    int i;
	    double *resultArr = (double*)calloc(size,sizeof(double));
	    int j=0;
	     for(i=0;i<size;i++){
		if(i%2==0){
		  resultArr[j]=arr[i];
	 	  j++;
		}
	     }
	    return resultArr;
	  }

/*------------------------------------------------------------------------*/

	double* findOdd(double* arr,int size){
	    int i;
	    double *resultArr = (double*)calloc(size,sizeof(double));
	    int j=0;
	     for(i=0;i<size;i++){
		if(i%2==1){
		  resultArr[j]=arr[i];
	 	  j++;
		}
	     }
	    return resultArr;
	  }

/*------------------------------------------------------------------------*/

	struct tree *createTree(double *arr, int size){
		if(size<1) return NULL;
		struct tree *root = (struct tree*)calloc(1, sizeof(struct tree));
		(*root).arr = arr;
		int i;
		(*root).complex = (double**)calloc(size*2,sizeof(double));
		for(i=0;i<size;i++)
		   (*root).complex[i] = (double*)calloc(2,sizeof(double));
		(*root).left = createTree(findEven(arr, size), size/2);
		(*root).right = createTree(findOdd(arr, size), size/2);
		return root;
	}

/*------------------------------------------------------------------------*/

