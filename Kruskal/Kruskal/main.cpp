//
//  main.cpp
//  Kruskal
//
//  Created by Anirudh Shekhawat on 01/05/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

//Uses weighted quick union

#include <iostream>
#define INFINIT 9999
using namespace std;

struct Edge {
    int u, v;
    int weight;
    bool selected;
};

Edge *e;
int num_nodes;
int num_edges;

class QuickUnionUF {
    int *id;
    int *size;
public:
    QuickUnionUF(int sz) {
        id = new int[sz];
        size = new int[sz];
        for (int i = 0; i < sz; i++) {
            id[i] = i;
            size[i] = 1;
        }
        
    }
    
    int root(int i) {
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }
    
    bool connected(int p, int q) {
        return root(p) == root(q);
    }
    
    void doUnion(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (size[i] > size[j]) {
            id[j] = i;
            size[i] += size[j];
        }
        else {
            id[i] = j;
            size[j] += size[i];
        }
    }
};


void readGraph() {
    cout<<"Enter number of vertices: ";
    cin>>num_nodes;
    int u, v, w;
    cout<<"Enter number of edges";
    cin>>num_edges;
    cout<<"Enter the edges of the graph: \n";
    e = new Edge[num_edges];
    for (int i = 0; i < num_edges; i++) {
        cin>>u>>v>>w;
        e[i].u = u;
        e[i].v = v;
        e[i].weight = w;
    }
}

void sort(Edge e[]) {
    int min_index;
    for (int i = 0; i < num_edges; i++) {
        min_index = i;
        for (int j = i + 1; j < num_edges; j++) {
            if (e[j].weight < e[min_index].weight) {
                min_index = j;
            }
            Edge temp = e[i];
            e[i] = e[min_index];
            e[min_index] = temp;
        }
    }
}
void kruskal() {
    sort(e);
    QuickUnionUF uf(num_nodes);
    for (int i = 0; i < num_edges; i++) {
        cout<<e[i].u<<"\t"<<e[i].v<<"\t"<<e[i].weight<<"\n";
        e[i].selected = false;
    }
    int n = 0, i = 0;
    e[i].selected = true;
    uf.doUnion(e[i].u, e[i].v);
    i++;
    n++;
    while (n != num_nodes - 1) {
        if (!uf.connected(e[i].u, e[i].v)) {
            uf.doUnion(e[i].u, e[i].v);
            e[i].selected = true;
            n++;
        }
        i++;
    }
    
    for (int i = 0; i < num_edges; i ++) {
        if (e[i].selected) {
            cout<<e[i].u<<"\t"<<e[i].v<<"\n";
        }
    }
    
}

int main() {
    readGraph();
    kruskal();
}



