#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int arr[], int n, int key){

    int s = 0, e = n-1;

    while(s <= e){
        int  m = s+(e-s)/2;
        if(arr[m] == key){
            return m;
        }
        else if(arr[m] < key){
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return -1;
}

int main(){

    int n;
    printf("Enter size of array : \n");
    scanf("%d", &n);

    int* arr = (int*) malloc(n*sizeof(int));
    printf("Enter elements in ascending order : \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the product id to search for : \n");
    scanf("%d", &key);
    
    int ind = binarySearch(arr,n,key);

    if(ind == -1){
        printf("Product is not present");
    }
    else{
        printf("Product is available At %d position ", ind+1);
    }

    return 0;
}