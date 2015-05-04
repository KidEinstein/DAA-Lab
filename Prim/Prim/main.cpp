//
//  main.cpp
//  Prim
//
//  Created by Anirudh Shekhawat on 01/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#define INFINIT 9999
using namespace std;

int** adj_matrix;
int size;
int num_edges;

void readGraph() {
    cout<<"Enter number of vertices: ";
    cin>>size;
    adj_matrix = new int*[size];
    
    for (int i = 0; i < size; i++)
        adj_matrix[i] = new int[size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj_matrix[i][j] = INFINIT;
        }
    }
    
    int i, j, l, n;
    cout<<"Enter number of edges";
    cin>>n;
    num_edges = n;
    cout<<"Enter the edges of the graph: \n";
    
    while (n--) {
        cin>>i>>j>>l;
        adj_matrix[i][j] = l;
    }
}

void displayGraph() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<adj_matrix[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
}

void prim() {
    bool** selected = new bool*[size];
    for (int i = 0; i < size; i++) {
        selected[i] = new bool[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            selected[i][j] = false;
        }
    }
    bool* selected_v = new bool[size];
    
    for (int i = 0; i < size; i++) {
        selected_v[i] = false;
    }
    
    selected_v[0] = true;
    
    int num_selected = 0;
    while (num_selected < size - 1) {
        int min_i = -1;
        int min_j = -1;
        for (int i = 0; i < size; i++) {
            if (!selected_v)
                continue;
            for (int j = 0; j < size; j++) {
                if (selected_v[j] || selected[i][j])
                    continue;
                if (min_i == -1)
                    min_i = i;
                if (min_j == -1)
                    min_j = j;
                if (adj_matrix[i][j] < adj_matrix[min_i][min_j]) {
                    min_i = i;
                    min_j = j;
                }
            }
        }
        selected[min_i][min_j] = true;
        selected_v[min_i] = true;
        selected[min_j][min_i] = true;
        selected_v[min_j] = true;
        num_selected++; 
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (selected[i][j]) {
                cout<<i<<"\t"<<j<<"\t"<<adj_matrix[i][j]<<"\n";
            }
        }
    }
}
int main() {
    readGraph();
    displayGraph();
    prim();
    
}
