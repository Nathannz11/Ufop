#include "vetor_util.h"
#include <stdio.h>
#include <stdlib.h>

int buscaSequencial (int *vetor , int n, int elemento){
    
    for(int i = 0; i < n; i++){
        if(vetor[i] == elemento)
            return i; 
    }
    return -1;   
}

int buscaBinaria (int *vetor , int n, int elemento){
    if(n <= 0 || elemento > vetor[n-1])
        return -1;
    int metade = n/2;
    do{
        if (elemento < vetor[metade]){
            n = metade;
            metade = metade / 2;
        }           
        else if(elemento > vetor[metade]){
            metade += (n - metade) / 2;
        }  
        else return metade;

            
        
    }while(metade >= 0 && metade <= n - 1);
    return -1;
}

 int* intercalaVetoresOrdenados (int* nums1 , int nums1Tam , int* nums2 , int nums2Tam){
    
    int n = nums1Tam + nums2Tam, aux = 0, temp;
    int *vetTemp = malloc(n * sizeof(int));
    for(int i = 0; i < nums1Tam; i++){       
    vetTemp[aux] = nums1[i];
    aux++;
    }
    for(int i = 0; i < nums2Tam; i++){       
    vetTemp[aux] = nums2[i];
    aux++;
    }
    for(int j = n ; n > 0; n--){
        for(int i = 0; i < n - 1; i++){      
            if(vetTemp[i] > vetTemp[i+1]){
                temp = vetTemp[i+1];
                vetTemp[i+1] = vetTemp[i];
                vetTemp[i] = temp;
            }
        }
   }
    return vetTemp;    
}

int comparaVetores (int* nums1 , int* nums2 , int nums1Tam , int nums2Tam){
    
    if(nums1Tam != nums2Tam || nums1Tam < 0)
        return 0;

    for(int i = 0; i < nums1Tam; i++){
        if(nums1[i] != nums2[i])
            return 0;
    }


    return 1;
}