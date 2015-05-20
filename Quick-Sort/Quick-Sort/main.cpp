//
//  main.cpp
//  Quick-Sort
//
//  Created by Anirudh Shekhawat on 18/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high) {
    int i = low, j = high + 1;
    while (true) {
        
    
        while (arr[++i] < arr[low]) {
            if (i == high) {
                break;
            }
        }
        while (arr[low] < arr[--j]) {
            if (j == low) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (high <= low) {
        return;
    }
    int j = partition(arr, low, high);
    quickSort(arr, low, j-1);
    quickSort(arr, j+1, high);
}

int main() {
    int* arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    clock_t start = clock();
    quickSort(arr, 0, n);
    clock_t end = clock();
    double cpu_time = double(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << "Time elapsed: " << cpu_time;
    
    
}
