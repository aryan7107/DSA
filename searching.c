//binary search
#include <stdio.h>
#include <stdlib.h>

void search(int *arr, int size, int element) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == element) {
            printf("Element %d found at index %d\n", element, mid);
            return;
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element %d not found in the array\n", element);
}

int main() {
    int arr[100], size, element;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array in sorted order: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &element);
    search(arr, size, element);
    
    return 0;
}