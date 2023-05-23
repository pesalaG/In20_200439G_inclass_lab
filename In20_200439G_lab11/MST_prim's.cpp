#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int infinity = INT_MAX; //  infinity

// To find minimum key
int findMinKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min_Key = infinity;
    int minIn = -1;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min_Key) {
            min_Key = key[v];
            minIn = v;
        }
    }

    return minIn;
}

// Function to output the MST
void print_MST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Connections in order to have the minimum cost"<<endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " -- " << i << "    cost of the line: " << graph[i][parent[i]] << endl;
    }
}

// to get MST by prim's algo
void prims_MST(vector<vector<int>>& graph, int V) {
    vector<int> MST(V); //to store MST
    vector<int> key(V, infinity); // Keys to get min weight edge
    vector<bool> mst_set(V, false); // check vertices entered to MST

    // Start with the "0" vertex
    key[0] = 0;
    MST[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mst_set, V);

        mst_set[u] = true;

        // changing the key and the parent 
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v]) {
                MST[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // output the MST
    print_MST(MST, graph, V);
}

int main() {
    int V = 6;
  
    
    vector<vector<int>> graph(V, vector<int>(V));

  //entering the possible telecom lines as a weighted graph
    graph = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};

    prims_MST(graph, V);

    return 0;
}
