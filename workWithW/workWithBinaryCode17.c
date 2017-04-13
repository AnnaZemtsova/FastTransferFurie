#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include "/home/anna/Documents/transferFurie/printAll/printAll.c"

int *arr;
int *replaceArr;



/*------------------------------------------------------------------------*/

	int defineI(int a){
	int i;
          if(a<2)
            i=16; else
          if(a<4)
            i=15; else 
          if(a<8)
            i=14; else
	  if(a<16)
	    i=13; else
	  if(a<32)
	    i=12; else
	  if(a<64)
	    i=11; else
	  if(a<128)
	    i=10; else
	  if(a<256)
	    i=9; else
	  if(a<512)
	    i=8; else
	  if(a<1024)
	    i=7; else
	  if(a<2048)
	    i=6; else
	  if(a<4096)
	    i=5; else
	  if(a<8192)
	    i=4; else
	  if(a<16384)
	    i=3; else
	  if(a<32768)
	    i=2; else
	  if(a<65536)
	    i=1; else 
	    i=0;
	 return i;
	}

/*------------------------------------------------------------------------*/

	int* arrayReplace(int size,int* arr,int a){//DON`T USED
	 replaceArr = (int*)calloc(size,sizeof(int));
	 int i = defineI(a);
	 int j=15;
	 int tmp;
	 int l = i+2;
	 if(i==10||i==9)l = l+1;
	 if(i==8||i==7) l = l+2;
	 if(i==6||i==5) l = l+3;
	 if(i==4||i==3) l = l+4;
	 if(i==2||i==1) l = l+5;
	 if(i==0) 	l = l+6;
	   for(;i<l;i++){
	     tmp = arr[i];
	     arr[i]=arr[j];
	     arr[j]=tmp;
	     j--;
	   }
	replaceArr = arr;
	return replaceArr;
	}

/*------------------------------------------------------------------------*/

	int *intToBits(int a){
	  int i = defineI(a);
	  int j;
	  for(j=16;j>=i;j--){
	    arr[j]=a%2;
	    a=a/2;
	 }
	return arr;
	} 

/*------------------------------------------------------------------------*/

        int bitsToInt(int* arr){
           int result=0;
  	   int i;
           int j=16;
           for(i=0;i<17;i++){
 		result=result+arr[i]*pow(2,j);
                j--;
	   }
         return result;
	}

/*------------------------------------------------------------------------*/

    int findTwoDegree(int a){
	    arr = (int*)calloc(17,sizeof(int));
 	    arr= intToBits(a);
            int i;
	    int j=0;
   	    for(i=16;i>0;i--){
	       if(arr[i]==1) return j;	
		  j++;
		}
          return j; 
	}

/*------------------------------------------------------------------------*/
