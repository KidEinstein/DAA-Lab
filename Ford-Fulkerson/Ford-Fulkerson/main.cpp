//
//  main.cpp
//  Ford-Fulkerson
//
//  Created by Anirudh Shekhawat on 04/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int** flow;
int** rev_flow;
int num_nodes;
bool* visited;
int* parent;

void readGraph() {
    cout << "Enter number of vertices: ";
    cin >> num_nodes;
    flow = new int*[num_nodes];
    rev_flow = new int*[num_nodes];
    visited = new bool[num_nodes];
    parent = new int[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        flow[i] = new int[num_nodes];
        rev_flow[i] = new int[num_nodes];
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            flow[i][j] = 0;
            rev_flow[i][j] = 0;
        }
    }
    
    int i, j, cap, n;
    cout << "Enter number of edges";
    cin >> n;
    cout << "Enter the edges of the graph and their respective capacities:\n";
    
    while (n--) {
        cin >> i >> j >> cap;
        flow[i][j] = cap;
    }
}

typedef struct {
    int u,v;
}node;

deque<int> des_path;

void bfs(int src, int des) {
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int v=0; v<num_nodes; v++)
        {
            if (visited[v]==false && flow[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    des_path.clear();
    if (visited[des] == true) {
        des_path.push_front(des);
        des = parent[des];
    }
    
}

void displayFlow(int** graph) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (graph[i][j]) {
                cout << i << " --> " << j << " Flow: " << graph[i][j] <<endl;
            }
            
        }
    }
}

void fordFulkerson() {
    int src, des;
    cout << "Enter source";
    cin >> src;
    cout << "Enter destination";
    cin >> des;
    
    vector<int> path;
    while (true) {
        bfs(src, des);
        if (des_path.empty()) {
            break;
        }
        //Any initial value for min_cap
        int min_cap = flow[des_path[0]][des_path[1]];
        for (int i = 0; i < des_path.size() - 1; i++) {
            if (flow[des_path[i]][des_path[i + 1]] < min_cap) {
                min_cap = flow[des_path[i]][des_path[i + 1]] ;
            }
        }
        for (int i = 0; i < des_path.size() - 1; i++) {
            flow[des_path[i]][des_path[i + 1]] -= min_cap;
            rev_flow[des_path[i]][des_path[i + 1]] += min_cap;
        }
        displayFlow(flow);
    }
    
}


int main() {
    readGraph();
    displayFlow(flow);
    fordFulkerson();
    displayFlow(rev_flow);
    
}
