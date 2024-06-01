#include <bits/stdc++.h>
using namespace std;
const int MAX_VERTICES = 100;
struct Edge
{
    int u, v, weight;
};
bool bellmanFord(vector<Edge> &edges, vector<int> &h, int s, int n)
{
    vector<int> dist(n, numeric_limits<int>::max());
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight <
                                                                  dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (const auto &edge : edges)
    {
        if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight <
                                                              dist[edge.v])
        {
            return false;
        }
    }
    for (int v = 0; v < n; ++v)
    {
        h[v] = dist[v];
    }
    return true;
}
void dijkstra(vector<Edge> &edges, vector<int> &h, vector<vector<string>> &D, int u, int n)
{
    vector<int> dist(n, numeric_limits<int>::max());
    dist[u] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight +
                                                                      h[edge.u] - h[edge.v] <
                                                                  dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight + h[edge.u] - h[edge.v];
            }
        }
    }
    for (int v = 0; v < n; ++v)
    {
        if (dist[v] == numeric_limits<int>::max())
        {
            D[u][v] = "I";
        }
        else
        {
            D[u][v] = to_string(dist[v] + h[v] - h[u]);
        }
    }
}
int main()
{
    int n = 5;
    int m = 7;
    int s = 0;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 1}};
    vector<int> h(n, 0);
    if (!bellmanFord(edges, h, s, n))
    {
        cout << "contains negative-weight cycle" << endl;
        return 0;
    }
    vector<vector<string>> D(n, vector<string>(n, "I"));
    for (int u = 0; u < n; ++u)
    {
        dijkstra(edges, h, D, u, n);
    }
    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            cout << D[u][v] << " ";
        }
        cout << endl;
    }
    return 0;
}