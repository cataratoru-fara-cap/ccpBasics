#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>
// http://www.cplusplus.com/reference/queue/queue/

using namespace std;

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            // allocation de la matrice d'adjacence
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];

			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    A[i][j] = 0;

            // allocation de l'info des noeuds
            nodeInfo = new TnodeInfo[N];

            // allocation de la matrice avec l'info des aretes
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = A[j][i] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = A[j][i] = 0; }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = edgeInfo[j][i] = info; }

        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j]; }

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete nodeInfo;
        }
};

/// changer le constructeur pour obtenir le graphe du ppt
Graph<char*, int> g(7);
char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}

void biparti(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop();
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}

int main() {
   // Graph<char*, int> g(8); // Use the constructor that takes the number of nodes as an argument
    int i;
    ///ajouter les autres aretes
    g.addEdge(0, 1);    
    g.addEdge(0, 2);    
    g.addEdge(0, 3);    
    g.addEdge(3, 2);    
    g.addEdge(1, 2);    
    g.addEdge(5, 6);    
    


    visited = new char[g.N];

    for (i = 0; i < g.N; i++)
        visited[i] = 0;
    
    /* dfs(0);
    
    bool connexe = true;
    for (i = 0; i < g.N; i++){
        if(visited[i] == 1){
            cout << "node " << i << " visited" << endl;
        } else {
            cout << "node " << i << "Not Visited" << endl;
            connexe = false;
        }
        cout << connexe << endl;
    } */
    
    //implementation to checkn if graph is Hamiltonian

    //implementation Ex 5 verifie le nombre de composants
    
    int conteur = 0;
    for (i = 0; i < g.N; i++){
        if(visited[i] == 0){
            cout << "node " << i << " not visited" << endl;
            dfs(i);
            conteur++;
        }
    }
    cout << "nous avons " << conteur << " components" << endl;

    
}

