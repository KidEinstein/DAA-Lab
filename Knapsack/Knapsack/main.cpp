//
//  main.cpp
//  Knapsack
//
//  Created by Anirudh Shekhawat on 03/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

struct Item* item;
int capacity;
int** m;
int n;
vector<int> chosen_items;
void knapsack() {
    for (int w = 0; w < capacity; w++) {
        m[0][w] = 0;
    }
    for (int i = 1; i <= n ; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (item[i].weight > w) {
                m[i][w] = m[i - 1][w];
            }
            else {
                m[i][w] = max(m[i - 1][w], item[i].value + m[i - 1][w - item[i].weight]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << m[i][w] << " ";
        }
        cout << endl;
        
    }
}

void findSolution() {
    int i = n;
    int k = capacity;
    while (i > 0 && k > 0) {
        if (m[i][k] != m[i - 1][k]) {
            chosen_items.push_back(i);
            i = i - 1;
            k = k - item[i].weight;
        }
        else {
            i = i - 1;
        }
    }
    for (int i = 0; i < chosen_items.size(); i++) {
        cout << "Item: "<< chosen_items[i] << endl;
    }
}
int main() {
    cout << "Enter number of items: ";
    cin >> n;
    item = new Item[n + 1];
    cout << "Enter weight and values of the item: \n";
    item[0].weight = item[0].value = 0;
    for (int i = 1; i <= n; i++) {
        cin >> item[i].weight >> item[i].value;
    }
    
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    
    m = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        m[i] = new int[capacity + 1];
    }
    knapsack();
    findSolution();
    
}
