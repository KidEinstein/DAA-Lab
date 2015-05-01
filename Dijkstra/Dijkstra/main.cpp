#include <iostream>
#include <math.h>

using namespace std;

#define INFINIT 9999

int** adj_matrix;
int size;

void readGraph() {
    cout<<"Enter number of vertices: ";
    cin>>size;
    adj_matrix = new int*[size];
    
    for (int i = 0; i < size; i++)
        adj_matrix[i] = new int[size];
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
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
    
    while (n--){
        cin>>i>>j>>l;
        adj_matrix[i][j] = l;
    }
}

void displayGraph() {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout<<adj_matrix[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
}

void dijkstra() {
    
    string* shortest_path = new string[size];
    int* arr = new int[size];
    bool* done = new bool[size];
    int mini;
    int src;
    
    cout<<"Enter source vertex: ";
    cin>>src;
    
    for (int i = 0; i < size; i++){
        arr[i] = INFINIT;
        done[i] = false;
        shortest_path[i] = to_string(src);
    }
    
    arr[src] = 0;
    
    for (int i = 0; i < size - 1 ; i++){
        mini = -1;
        
        for (int j = 0; j < size; j++){
            if (done[j])
                continue;
            
            if (mini == -1){
                mini = j;
            }
            
            if (arr[mini] > arr[j] && !done[j]){
                mini = j;
            }
        }
        
        done[mini] = true;
        
        for (int j = 0; j < size; j++){
            if (arr[mini] + adj_matrix[mini][j] < arr[j]) {
                arr[j] = arr[mini] + adj_matrix[mini][j];
                shortest_path[j] = shortest_path[mini] + " --> " + to_string(j);
            }
        }
    }
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<"\t"<<shortest_path[i]<<"\n";
        
    }
    
}
int main() {
    readGraph();
    displayGraph();
    dijkstra();
    return 0;
}