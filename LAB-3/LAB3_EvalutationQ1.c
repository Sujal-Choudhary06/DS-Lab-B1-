#include<stdio.h>

int bin(int* arr,int size,int key){
    int l=0;
    int r=size-1;
    int m=(l+r)/2;

    if(arr[m]==key)
    return m;
    else if(arr[m]>key)
    l=m+1;
    else if(arr[m]<key){
        r=m-1;
    }
    return m;
}

int main(){
    int arr[6]={2,7,9,11,15,18,};
    bin(arr,7,2);
    printf("binary search of target element %d is %d\n",7,bin(arr,7,4));
}
