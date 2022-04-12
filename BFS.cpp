#include <iostream>
#include <list>

using namespace std;

class Graph {
    private:
    int V;
    list<int> *adj;

    public:
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        bool *visited=new bool[this->V];
        for(int i=0; i<this->V; i++) 
            visited[i]=false;

        list<int> queue;
        visited[s]=true;
        queue.push_back(s);

        list<int>::iterator i;

        while(!queue.empty()) {
            s=queue.front();
            cout << s << " ";
            queue.pop_front();

            for(i=adj[s].begin(); i!=adj[s].end(); i++) {
                if(!visited[*i]) {
                    visited[*i]=true;
                    queue.push_back(*i);
                }
            }
        }
    }
};


int main() {
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(2,3);
    graph.addEdge(3,3);

    cout << "Breadth First Traversal" << endl;
    graph.BFS(2);
}