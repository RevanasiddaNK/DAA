#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[10],int n){
    for(int i=0; i<n ;i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] >= key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){

    int n;
    printf("Enter size of array : \n");
    scanf("%d", &n);

    int* phoneNumber = (int*) malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        phoneNumber[i] = rand() % 1000000000 + 100000000;
    }

    insertionSort(phoneNumber,n);
    printf("sorted phone numbers : \n");

    for(int i=0; i<n; i++){
        printf("%d \n", phoneNumber[i]);
    }
    return 0;
}