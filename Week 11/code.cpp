/////EXERCISE 11.1:
//#include <iostream>
//#include <queue>
//using namespace std;
//
//class Graph {
//    int n;
//    int** adjMatrix;
//
//public:
//    Graph(int size) {
//        n = size;
//        adjMatrix = new int* [n];
//        for (int i = 0; i < n; ++i) {
//            adjMatrix[i] = new int[n];
//            for (int j = 0; j < n; ++j)
//                adjMatrix[i][j] = -1;
//        }
//    }
//
//    void addEdge(int u, int v, int weight = 1, bool undirected = true) {
//        adjMatrix[u][v] = weight;
//        if (undirected) adjMatrix[v][u] = weight;
//    }
//    void print() {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (adjMatrix[i][j] == -1) {
//                    cout << "0" << " ";
//                }
//                else if (adjMatrix[j][i] == -1) {
//                    cout << "0" << " ";
//                }
//                else {
//                    cout << adjMatrix[i][j] << " ";
//                }
//            }
//            cout << endl;
//        }
//    }
//
//    void BFS(int start) {
//        bool* visited = new bool[n]();
//        queue<int> q;
//
//        visited[start] = true;
//        q.push(start);
//
//        cout << "BFS starting from node " << start << ": ";
//        while (!q.empty()) {
//            int v = q.front();
//            cout << v << " ";
//            q.pop();
//
//            for (int i = 0; i < n; ++i) {
//                if (adjMatrix[v][i] && !visited[i]) {
//                    q.push(i);
//                    visited[i] = true;
//                }
//            }
//        }
//        cout << endl;
//        delete[] visited;
//    }
//
//    void DFSUtil(int v, bool visited[]) {
//        visited[v] = true;
//        cout << v << " ";
//
//        for (int i = 0; i < n; ++i) {
//            if (adjMatrix[v][i] && !visited[i])
//                DFSUtil(i, visited);
//        }
//    }
//
//    void DFS(int start) {
//        bool* visited = new bool[n]();
//        cout << "DFS starting from node " << start << ": ";
//        DFSUtil(start, visited);
//        cout << endl;
//        delete[] visited;
//    }
//
//    ~Graph() {
//        for (int i = 0; i < n; ++i)
//            delete[] adjMatrix[i];
//        delete[] adjMatrix;
//    }
//};
//
//int main() {
//    int size = 5;
//    Graph g(size);
//
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 2, 4);
//    g.addEdge(1, 2, 1);
//    g.addEdge(1, 3, 7);
//    g.addEdge(2, 4, 3);
//    g.addEdge(3, 4, 1);
//    g.print();
//
//    g.BFS(0);
//    g.DFS(0);
//
//    return 0;
//}

//Exercise 11.2:
//#include <iostream>
//#include <limits.h>
//using namespace std;
//
//class Graph {
//    int n;
//    int** adjMatrix;
//
//public:
//    Graph(int size) {
//        n = size;
//        adjMatrix = new int* [n];
//        for (int i = 0; i < n; ++i) {
//            adjMatrix[i] = new int[n];
//            for (int j = 0; j < n; ++j)
//                adjMatrix[i][j] = 0;
//        }
//    }
//
//    void addEdge(int u, int v, int weight = 1, bool undirected = true) {
//        adjMatrix[u][v] = weight;
//        if (undirected) adjMatrix[v][u] = weight;
//    }
//
//    int minDistance(int dist[], bool sptSet[]) {
//        int min = INT_MAX, min_index = -1;
//        for (int v = 0; v < n; v++) {
//            if (!sptSet[v] && dist[v] <= min) {
//                min = dist[v];
//                min_index = v;
//            }
//        }
//        return min_index;
//    }
//
//    void dijkstra(int src) {
//        int* dist = new int[n];
//        bool* sptSet = new bool[n];
//
//        for (int i = 0; i < n; i++) {
//            dist[i] = INT_MAX;
//            sptSet[i] = false;
//        }
//
//        dist[src] = 0;
//
//        for (int count = 0; count < n - 1; count++) {
//            int u = minDistance(dist, sptSet);
//            if (u == -1) break;  // No reachable vertex left
//            sptSet[u] = true;
//
//            for (int v = 0; v < n; v++) {
//                if (!sptSet[v] && adjMatrix[u][v] &&
//                    dist[u] != INT_MAX &&
//                    dist[u] + adjMatrix[u][v] < dist[v]) {
//                    dist[v] = dist[u] + adjMatrix[u][v];
//                }
//            }
//        }
//
//        cout << "Dijkstra's shortest paths from node " << src << ":\n";
//        for (int i = 0; i < n; i++)
//            cout << "To " << i << " -> Distance: " << dist[i] << endl;
//
//        delete[] dist;
//        delete[] sptSet;
//    }
//
//    ~Graph() {
//        for (int i = 0; i < n; ++i)
//            delete[] adjMatrix[i];
//        delete[] adjMatrix;
//    }
//};
//
//int main() {
//    int size = 5;
//    Graph g(size);
//
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 2, 4);
//    g.addEdge(1, 2, 1);
//    g.addEdge(1, 3, 7);
//    g.addEdge(2, 4, 3);
//    g.addEdge(3, 4, 1);
//
//    g.dijkstra(0);
//
//    return 0;
//}