#include <iostream>
#include <time.h>  
// Swap to integers
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray (int arr[], int n){
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void randomize (int arr[], int n){
    srand (time(NULL));

    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main(){
    int arr[]   = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n       = sizeof(arr) / sizeof(arr[0]);
    randomize(arr, n);
    printArray(arr, n);
    return 0;
}