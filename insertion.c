#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int *arr, int size, int element, int index){
    if(size < index || index < 0){
        printf("Invalid index\n");
        return;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}

void checkinsertion(int *arr, int size, int element, int index){
    if(arr[index] == element){
        printf("Element %d is inserted at index %d\n", element, index);
    } else {
        printf("Element %d is not inserted at index %d\n", element, index);
    }
}

int main(){
    int arr[100], size, element, index;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the index at which to insert the element: ");
    scanf("%d", &index);
    printf("Array before insertion: ");
    display(arr, size);
    insertion(arr, size, element, index);
    size++;
    printf("Array after insertion: ");
    display(arr, size);
    printf("Element %d inserted at index %d\n", element, index);
    checkinsertion(arr, size, element, index); 
    
    return 0;
}

