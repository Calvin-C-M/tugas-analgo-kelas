#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V, E;

    Edge* edge;
};

Graph* create(int V, int E) {
    Graph* graph=new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}

void inputGraph(Graph *graph, int E) {
    for(int i=0; i<E; i++) {        
        cout << "\nEdge " << i << endl;
        cout << "Source: "; cin >> graph->edge[i].src;
        cout << "Destination: "; cin >> graph->edge[i].dest;
        cout << "Weight: "; cin >> graph->edge[i].weight;
    }
}

void addEdge(Edge &edge, int src, int dest, int weight) {
    edge.src=src;
    edge.dest=dest;
    edge.weight=weight;
}

void printGraph(int dist[], int n) {
    cout << "Vertex\t\tDistance from Source" << endl;
    for(int i=0; i<n; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

void bellmanFord(Graph* graph, int src) {
    int V=graph->V;
    int E=graph->E;
    int dist[V];

    for(int i=0; i<V; i++)
        dist[i]=INT_MAX;
    dist[src]=0;

    for(int i=1; i<=V-1; i++) {
        for(int j=0; j<E; j++) {
            int u=graph->edge[j].src;
            int dest=graph->edge[j].dest;
            int weigth=graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u]+weigth < dist[dest]) 
                dist[dest]=dist[u]+weigth;

        }
    }

    for(int i=0; i<E; i++) {
        int u=graph->edge[i].src;
        int dest=graph->edge[i].dest;
        int weight=graph->edge[i].weight;
        if(dist[u] != INT_MAX && dist[u]+weight < dist[dest]) 
            cout << "Graph contains negative weight cycle";
    }

    printGraph(dist, V);
}

int main() {
    int V=0;
    int E=0;

    cout << "Masukkan jumlah vertices: "; cin >> V;
    cout << "Masukkan jumlah edge: "; cin >> E;
    Graph *graph=create(V,E);

    inputGraph(graph,E);

    int src=0;
    cout << "Masukkan sumber: "; cin >> src; 

    auto start=high_resolution_clock::now();

    bellmanFord(graph,src);

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Durasi algoritma = " << duration.count() << " microseconds";
}