#include <iostream>
using namespace std;

int* filterPositiveElements(const int* arr, int size, int& newSize) {
    // First, count how many positive elements there are
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            ++newSize;
        }
    }

    // Allocate memory for the new array
    int* positiveElements = new int[newSize];

    // Populate the new array with positive elements
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveElements[index++] = arr[i];
        }
    }

    return positiveElements;
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-10, 15, -20, 25, 0, -5, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    int newSize;
    int* positives = filterPositiveElements(arr, size, newSize);

    cout << "Positive elements: ";
    printArray(positives, newSize);

    // Clean up allocated memory
    delete[] positives;

    return 0;
}
