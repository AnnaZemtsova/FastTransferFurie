#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

//#include </home/anna/Documents/transferFurie/workWithTree/tree.h>

/*------------------------------------------------------------------------*/

	  void printTwoDegreeArray(double** arr,int size1,int size2){
	  int i;
	  int j;
		for(i=0;i<size1;i++){
			for(j=0;j<size2;j++){
				printf("%lf ",arr[i][j]);
			}	
		printf("\n");
		}
	  }

/*------------------------------------------------------------------------*/

	  void printThirdDegreeArray(double*** arr,int M,int *arrN){
	  int i;
	  int j;
	  int k;
	     for(i=0;i<M;i++){
		for(j=0;j<arrN[i];j++){
		  for(k=0;k<2;k++){
		    printf("%lf ",arr[i][j][k]);
		  }
		  printf("\n");
		}
	       printf("\n");
	     }
	  }

/*------------------------------------------------------------------------*/

	void print(int* ar,int M){
		int i;
		 for(i=0;i<M;i++){
		   printf("%d ",ar[i]);
		 }
		printf("\n");
        }

/*------------------------------------------------------------------------*/
	void printD(double* ar,int M){
		int i;
		 for(i=0;i<M;i++){
		   printf("%lf\n",ar[i]);
		 }
		//printf("\n");
        }

/*------------------------------------------------------------------------*/


	void fullArrForTest(double *arr,int a){
			int i;
			srand(time(NULL));
			for(i=0;i<a;i++){
				double f=120+(rand()%1000-600)*0.87;
				arr[i]=f;
				//printf("%lf\n",f);
			}
		}


/*------------------------------------------------------------------------*/


	void printTree(struct tree* root,int size){
	      if(size < 1) return;
	         printTree((*root).left,size/2); 
	         printTree((*root).right,size/2);
	      int i;
	      for(i=0;i<size;i++){
	        printf("%lf |||  %lf",(*root).complex[i][0],(*root).complex[i][1]);
	        printf("\n");
	      }
	       printf("---------------STOP-------------------;\n");
 	}


/*------------------------------------------------------------------------*/


	void fullArray(double *arr,int size){
		int i;
		  for(i=0;i<size;i++){
		   scanf("%lf",&arr[i]);
		 }
	}

/*------------------------------------------------------------------------*/



