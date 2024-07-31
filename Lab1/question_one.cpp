/*
    Question One : 
    Translate the Insertion-sort algorithm discussed in the class into a program 
    which takes n numbers (real or integers). Inputs for the program is n and the n numbers. 
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int j = 1; j < n; j++){
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 and arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        } 
        arr[i + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
