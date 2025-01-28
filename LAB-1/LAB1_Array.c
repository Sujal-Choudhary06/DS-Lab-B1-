#include <stdio.h>
int main(){
    int n;
    printf("Enter Size of Array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the  %d index Element :\n ",i+1);
        scanf("%d",&arr[i]);
}
    printf("The elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
