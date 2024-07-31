/*
    Question Three : 
    All the alphabets(lower case) of english language a, b, c, ..., y, z
    are assigned values 1, 2, 3, ..., 25, 26. Given a sequence of n
    symbols from english alphabet (only lower case), write an 
    insertion-sort based algorithm to arrange the given n symbols, in an increasing order of their values. . You are expected
    to code the problem two different ways, say, c1 , c2 using two
    different approaches. Decide whether c1 is efficient or c2 is efficient
    based on the running time T(n) of the resepctive codes.
*/

#include <iostream>
using namespace std;

void insertionSort(char arr[], int n) {
    for (int j = 1; j < n; j++){
        char key = arr[j];
        int i = j - 1;
        while (i >= 0 and arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        } 
        arr[i + 1] = key;
    }
}

void printArray(char arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    char arr[] = {'c', 'a', 'r', 'w', 't'};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
