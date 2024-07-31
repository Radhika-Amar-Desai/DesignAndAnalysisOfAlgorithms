/*
    Question Four : 
    Given a sequence of n numbers (real or integers), write an
    algorithm and the corresponding code to arrange the given
    n numbers are arranged in such a way that all the negative
    numbers (if any) are arranged in a descending order and all
    the positive numbers are arranged in an increasing order with
    zero (if it is in the input) appearing between the smallest negative number 
    and the smallest positive number. If 7, 3, 2, 4 the
    output should be 2, 3, 4, 7. If −7, −3, 2, 4 the output should be
    −3, −7, 2, 4 should be the output. If 7, 3, −1, 0, 2, 4 the output
    should be −1, 0, 3, 4, 7
*/

#include <iostream>
using namespace std;

void insertionSortIncreasingOrder(int arr[], int n) {
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

void insertionSortDecreasingOrder(int arr[], int n) {
    for (int j = 1; j < n; j++){
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 and arr[i] < key){
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

int* getPositiveElements(int arr[], int size, int newSize){
    int* positiveElements = new int[newSize];
    int index = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] > 0){
            positiveElements[index] = arr[i];
            index += 1;
        }
    }

    return positiveElements;
}

int* getNegativeElements(int arr[], int size, int newSize){
    int* negativeElements = new int[newSize];
    int index = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            negativeElements[index] = arr[i];
            index += 1;
        }
    }

    return negativeElements;
}

int getNumOfPositives(int arr[], int size){

    int numOfPositives = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > 0){
            numOfPositives += 1;
        }
    }
    return numOfPositives;
}

int getNumOfNegatives(int arr[], int size){

    int numOfNegatives = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            numOfNegatives += 1;
        }
    }
    return numOfNegatives;
}

int getNumOfZeros(int arr[], int size){

    int numOfZeros = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            numOfZeros += 1;
        }
    }
    return numOfZeros;
}

int main() {
    int arr[] = {-7, -3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting : ";
    printArray(arr, n);

    int numOfPositiveElements = getNumOfPositives(arr, n);
    int numOfNegativeElements = getNumOfNegatives(arr, n);
    int numOfZeroElements = getNumOfZeros(arr, n);

    int* positiveElements = getPositiveElements(arr, n, numOfPositiveElements);
    int* negativeElements = getNegativeElements(arr, n, numOfNegativeElements);

    insertionSortDecreasingOrder(negativeElements, numOfNegativeElements);
    insertionSortIncreasingOrder(positiveElements, numOfPositiveElements);    

    int index = 0;

    for(int i = 0; i < numOfNegativeElements; i++){
        arr[index] = negativeElements[i];
        index += 1;
    }

    for(int i = 0; i < numOfZeroElements; i++){
        arr[index] = 0;
        index += 1;
    }

    for(int i = 0; i < numOfPositiveElements; i++){
        arr[index] = positiveElements[i];
        index += 1;
    }
    
    cout << "After Sorting : ";
    printArray(arr, n);

    return 0;
}
