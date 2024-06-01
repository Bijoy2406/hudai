#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <stdexcept>
using namespace std;
const int INF = numeric_limits<int>::max();
struct Edge
{
    int u, v, w;
};
bool bellmanFord(int V, const vector<Edge> &edges, vector<int> &dist, int src)
{
    dist[src] = 0;
    for (int i = 1; i < V; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
    for (const auto &edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v])
        {
            return false;
        }
    }
    return true;
}
vector<int> dijkstra(int V, const vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);
    while (!pq.empty())
    {
        auto [currentDist, u] = pq.top();
        pq.pop();
        if (currentDist > dist[u])
            continue;
        for (const auto &[v, weight] : adj[u])
        {
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}
vector<vector<int>> johnson(int V, vector<Edge> &edges)
{
    vector<Edge> modifiedEdges(edges);
    vector<int> h(V + 1, INF);
    for (int i = 0; i < V; ++i)
    {
        modifiedEdges.push_back({V, i, 0});
    }
    if (!bellmanFord(V + 1, modifiedEdges, h, V))
    {
        throw runtime_error("The input graph contains a negative-weight cycle");
    }
    for (auto &edge : edges)
    {
        edge.w += h[edge.u] - h[edge.v];
    }
    vector<vector<pair<int, int>>> adj(V);
    for (const auto &edge : edges)
    {
        adj[edge.u].emplace_back(edge.v, edge.w);
    }
    vector<vector<int>> D(V, vector<int>(V, INF));
    for (int u = 0; u < V; ++u)
    {
        vector<int> dist = dijkstra(V, adj, u);
        for (int v = 0; v < V; ++v)
        {
            if (dist[v] != INF)
            {
                D[u][v] = dist[v] + h[v] - h[u];
            }
        }
    }
    return D;
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    try
    {
        vector<vector<int>> result = johnson(V, edges);
        cout << "The distance matrix is:\n";
        for (const auto &row : result)
        {
            for (const auto &dist : row)
            {
                if (dist == INF)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << dist << " ";
                }
            }
            cout << "\n";
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}