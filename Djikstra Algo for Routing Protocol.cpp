#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent edges
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Structure to represent nodes
struct Node {
    int id;
    vector<Edge> edges;
    Node() {}
    Node(int i) : id(i) {}
};

// Implementation of Dijkstra's Algorithm
vector<int> dijkstra(vector<Node>& graph, int source) {
    vector<int> dist(graph.size(), numeric_limits<int>::max());
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if the popped distance is greater than the current shortest distance to u
        if (d > dist[u]) continue;

        for (const Edge& e : graph[u].edges) {
            int v = e.to;
            int w = e.weight;

            // If a shorter path to v through u is found, update the distance to v
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v}); // Update priority queue with the new distance
            }
        }
    }

    return dist;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<Node> graph(numNodes);

    cout << "Enter the edges (from to weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].edges.emplace_back(to, weight);
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> shortestDistances = dijkstra(graph, source);

    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}

// 0 2 2
// 0 1 3
// 0 3 5
// 1 3 1
// 1 4 4
// 2 3 2
// 2 5 1
// 3 4 3
// 4 5 2
