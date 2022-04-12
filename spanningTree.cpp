#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    private:
    int *parent;
    int *rank;

    public:
    DSU(int n) {
        this->parent=new int[n];
        this->rank=new int[n];

        for(int i=0; i<n; i++) {
            parent[i]=-1;
            rank[i]=1;
        }
    }

    int find(int s) {
        if(parent[s] == -1) 
            return s;
        return parent[s]=find(parent[s]);
    }

    void unite(int x, int y) {
        int s1=find(x);
        int s2=find(y);

        if(s1!=s2) {
            if(rank[s1]<rank[s2]) {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            } else {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};

class Graph {
    private:
    vector<vector<int>> edge;
    int V;

    public:
    Graph(int V) {
        this->V=V;
    }

    void addEdge(int x, int y, int w) {
        this->edge.push_back({w,x,y});
    }

    void genericMST() {
        sort(this->edge.begin(), this->edge.end());

        DSU s(V);
        int ans=0;

        for(auto e: this->edge) {
            int w=e[0];
            int x=e[1];
            int y=e[2];

            if(s.find(x)!=s.find(y)) {
                s.unite(x,y);
                ans+=w;

            }
        }

        cout << "Minimum cost spanning tree = " << ans;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0,1,10);
    graph.addEdge(1,3,15);
    graph.addEdge(2,3,4);
    graph.addEdge(2,0,6);
    graph.addEdge(0,3,5);

    graph.genericMST();
}