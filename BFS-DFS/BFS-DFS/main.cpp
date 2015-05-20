//
//  main.cpp
//  BFS-DFS
//
//  Created by Anirudh Shekhawat on 20/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int num_nodes;

vector<int>* adj_list;

void readGraph() {
    cout << "Enter number of nodes: ";
    cin >> num_nodes;
    adj_list = new vector<int>[num_nodes];
    int num_edges;
    cout << "Enter number of edges: ";
    cin >> num_edges;
    for (int i = 0; i < num_edges; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }
}

void bfs(int v) {
    queue<int> node_queue;
    vector<bool> visited(num_nodes);
    visited[v] = true;
    node_queue.push(v);
    while (!node_queue.empty()) {
        int x = node_queue.front();
        node_queue.pop();
        cout << x << " ";
        for (auto it = adj_list[x].begin(); it != adj_list[x].end(); it++) {
            if (!visited[*it]) {
                node_queue.push(*it);
                visited[*it] = true;
            }
        }
        
    }
}

void dfs(int v) {
    stack<int> node_stack;
    vector<bool> visited(num_nodes);
    node_stack.push(v);
    visited[v] = true;
    while (!node_stack.empty()) {
        int x = node_stack.top();
        cout << x << " ";
        node_stack.pop();
        for (auto it = adj_list[x].begin(); it!= adj_list[x].end(); it++) {
            if (!visited[*it]) {
                node_stack.push(*it);
                visited[*it] = true;
            }
            
        }
    }
}
int main() {
    readGraph();
    cout << "BFS: ";
    bfs(0);
    cout << "DFS: ";
    dfs(0);
}
