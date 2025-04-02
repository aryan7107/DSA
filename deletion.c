#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int *arr, int size, int index){
    if(size <= index || index < 0){
        printf("Invalid index\n");
        return;
    }
    for(int i=index; i<size-1; i++){
        arr[i] = arr[i+1];
    }
}

void checkdeletion( int *arr, int size, int element, int index){
    if(arr[size]==0){
        printf("Element %d is deleted from index %d\n", element, index);
    } else {
        printf("Element %d is not deleted from index %d\n", element, index);
    }
}

int main(){
    int arr[100], size, index;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the index to be deleted: ");
    scanf("%d", &index);
    printf("Array before deletion: ");
    display(arr, size);
    deletion(arr, size, index);
    checkdeletion(arr, size, arr[index], index);
    size--;
    printf("Array after deletion: ");
    display(arr, size);
    
    return 0;
}