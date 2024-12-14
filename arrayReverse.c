/*
Array reversal with different methods
*/

/*
1. without creating a new array
    directly altering existing array
*/

#if(0)
#include <stdio.h>


void revArray (int* arr, int n){
    int current = 0;
    int left = 0;
    int right = n-1;
    while(left<right){
        current = arr[left];
        arr[left++] = arr[right];
        arr[right--] = current;
    }
}

int main(){
    int array[5] = {1,2,4,5};
    revArray(array, 4);
    for(int i=0; i<4; i++){
         printf("%d ",array[i]);
    }    
    return 0;
}

/*------------------------------------------------------------------------*/

/*
by using a seperate array and returning it.
We cannot used a static variable to retain value across function calls. This is because variable length array cannot be static.
Hence, we use dynamic memory allocation
*/

#else

#include <stdlib.h>
#include <stdio.h>

int* revArray (int* array, int n){
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        arr[n-1-i] = array[i];
    }
    return arr;
}

int main(){
    int array[4] = {1,2,4,10};    
    int* ar = revArray(array, 4);
    for(int i=0; i<4; i++){
         printf("%d ",ar[i]);
    }   
    free(ar); 
    return 0;
}

#endif