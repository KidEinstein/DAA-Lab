//
//  main.cpp
//  Merge-Sort-with-Inversions
//
//  Created by Anirudh Shekhawat on 19/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

int inversions;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void merge(int arr[], int aux[], int low, int high, int mid) {
    int i = low, j = mid + 1;

    for (int k = low; k <= high; k++) {
        if (i > mid) {
            arr[k] = aux[j++];
        }
        else if (j > high) {
            arr[k] = aux[i++];
        }
        else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
            inversions += mid - i + 1;
        }
        else {
            arr[k] = aux[i++];
        }
    }
}

void sort(int arr[], int aux[], int low, int high) {
    if (high <= low) {
        return;
    }
    int mid  = (high + low) / 2;
    sort(aux, arr, low, mid);
    sort(aux, arr, mid+1, high);
    merge(arr, aux, low, high, mid);
}
int main() {
    inversions = 0;
    int* arr;
    int* aux;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    arr = new int[n];
    aux = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%1000;
        aux[i] = arr[i];
    }
    printArray(arr, n);
    sort(arr, aux, 0, n-1);
    printArray(arr, n);
    cout << "Inversions: " << inversions;
    
}
