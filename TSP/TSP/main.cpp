//
//  main.cpp
//  TSP
//
//  Created by Anirudh Shekhawat on 20/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <unordered_set>

#define INFINIT 999

using namespace std;

typedef unordered_set<int> IntUSet;

int** adj_matrix;
int num_nodes;
IntUSet node_set;

void readGraph() {
    cout<<"Enter number of vertices: ";
    cin>>num_nodes;
    adj_matrix = new int*[num_nodes];
    
    for (int i = 0; i < num_nodes; i++) {
        adj_matrix[i] = new int[num_nodes];
        if (i == 0) {
            continue;
        }
        node_set.insert(i);
    }
    
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = INFINIT;
            if (i == j){
                adj_matrix[i][j] = 0;
            }
        }
    }
    
    int i, j, l, n;
    cout<<"Enter number of edges";
    cin>>n;
    cout<<"Enter the edges of the graph: \n";
    
    while (n--) {
        cin>>i>>j>>l;
        adj_matrix[i][j] = l;
    }
}

void displayGraph() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            cout<<adj_matrix[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
}

//Starting from node i and reaching 0 going through all nodes in set

int tsp(int i, IntUSet set) {
    if (set.empty()) {
        return adj_matrix[i][0];
    }
    int min = 999;
    for (auto it = set.begin(); it!= set.end(); ++it) {
        IntUSet temp = set;
        temp.erase(*it);
        int res = adj_matrix[i][*it] + tsp(*it, temp);
        if (res < min) {
            min = res;
        }
    }
    return min;
}

int main() {
    readGraph();
    displayGraph();
    cout << "Min cost: " << tsp(0, node_set);
    
}
