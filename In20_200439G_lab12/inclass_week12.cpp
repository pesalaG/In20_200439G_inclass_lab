#include <iostream>
#include <limits.h>

using namespace std;

#define V 6 // defining the vertices

void printans(int time[]) {
    cout<<"starting from "<< 5 << " node"<<endl;
    for (int i = 0; i < V; i++) {
        cout<<"time taken to node[" << i << "]"<<" : " << time[i] << "\n";
    }
}

void dijkstra(int graph[V][V], int source) {
    int time[V];
    bool visited[V];

    //initialise visited and time arrays
    for (int i = 0; i < V; i++) {
        time[i] = INT_MAX;
        visited[i] = false;
    }

    time[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, min_ind;
    
        for (int v = 0; v < V; v++) {
            if (!visited[v] && time[v] <= min) {
                min = time[v];
                min_ind = v;
            }
        }

        visited[min_ind] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[min_ind][v] && time[min_ind] != INT_MAX && time[min_ind] + graph[min_ind][v] < time[v]) {
                time[v] = time[min_ind] + graph[min_ind][v];
            }
        }
    }

    printans(time);
}

int main() {
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0, 0 } };

    dijkstra(graph, 5);

    return 0;
}
