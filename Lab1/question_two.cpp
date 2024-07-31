/*
    Question Two :
    Given a sequence of n numbers (real or integers) and a number
    k (k is one among the n numbers ), write an algorithm and the
    corresponding code to compute the position of k if the given n
    numbers are arranged in an increasing order, using insertionsort. 
    If the 2, −1, 3, 0, 7 and 3 are the input , your program
    should output 4 since 3 will be in the fourth position (starting
    from 1), in the sorted (increasing ) order. You are expected
    to code the problem two different ways, say, c1 , c2 using
    two different approaches. Decide whether c1 is efficient or c2
    is efficient based on the running time T(n) of the resepctive
    codes
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
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findPositionInSortedArray(int arr[], int size, int target){
    
    insertionSort(arr, size);
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i + 1;
        }
    }
    return -1;
}

int findPositionInSortedArrayOptimized(int arr[], int size, int target){

    insertionSort(arr, size);
    
    int low = 0;
    int high = size - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if (arr[low] == target){
            return low + 1;
        }
        else if(arr[high] == target){
            return high + 1;
        }

        int key = arr[mid];
        
        if (key < target){
            low = mid;
        }
        else if (key > target){
            high = mid;
        }
        else {
            return mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, -1, 3, 0, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int pos = findPositionInSortedArray(arr, n, target);
    cout << target << " is at the position " << pos << "\n";

    int pos2 = findPositionInSortedArrayOptimized(arr, n, target);
    cout << target << " is at the position " << pos2;

    return 0;
}

/*

    Comparing the functions findPositionInSortedArray And findPositionInSortedArrayOptimized :
    
    1) findPositionInSortedArray uses a linear search to find the position of the target.
        Time Complexity : O(N) where N refers to the input size.
    
    2) findPositionInSortedArrayOptimized uses a binary search to find the position of the target.
        Time Complexity : O(log N) where N refers to the input size.

    Hence findPositionInSortedArrayOptimized is a more efficient function.

*/

