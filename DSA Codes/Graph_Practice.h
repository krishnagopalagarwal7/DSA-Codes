#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


// Adds edge to the undirected graph
void Add_Edge(vector<int> adj1[], int u, int v)
{
    adj1[u].push_back(v);
    adj1[v].push_back(u);
}
// Adds edge to the directed graph
void add_edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}


// BFS for connected graph
void BFS(vector<int> adj1[], int V, int s)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < adj1[u].size(); i++)
        {
            int v = adj1[u][i];
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// BFS for disconnected graph
void BFS_second(vector<int> adj1[], int s, bool visited[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < adj1[u].size(); i++)
        {
            int v = adj1[u][i];
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSDin(vector<int> adj1[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            BFS_second(adj1, i, visited);
        }
    }
}


// Helper Recursive function for DFS
void DFSRec(vector<int> adj1[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < adj1[s].size(); i++)
    {
        int v = adj1[s][i];
        if (visited[v] == false)
        {
            visited[v] = true;
            DFSRec(adj1, v, visited);
        }
    }
}

// Normal DFS
void DFS(vector<int> adj1[], int V, int s)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    DFSRec(adj1, s, visited);
}
// DFS for disconnected graph
void DFS_second(vector<int> adj1[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSRec(adj1, i, visited);
        }
    }
}


// Minimum Distance of all vertices from a source vertex // in an unweighted graph
void min_distance_from_vertex(vector<int> adj1[], int s, int v, int dist[])
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj1[u].size(); i++)
        {
            int v = adj1[u][i];
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


// Helper for checking cycle in an undirected graph
bool cycle_in_undirected_graph_helper(vector<int> adj[], bool visited[], int s, int parent)
{
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        int p = adj[s][i];
        if (visited[p] == false)
        {
            if (cycle_in_undirected_graph_helper(adj, visited, p, s) == true)
            {
                return true;
            }
        }
        else if (p != parent)
        {
            return true;
        }
    }
    return false;
}
// Checking if there is cycle or not in undirected graph
bool cycle_in_undirected_graph(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (cycle_in_undirected_graph_helper(adj, visited, i, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}


// Helper for checking cycle in directed graph
bool cycle_in_directed_graph_helper(vector<int> adj[], bool visited[], int s, bool recstk[])
{
    visited[s] = true;
    recstk[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        int p = adj[s][i];
        if (visited[p] == false && cycle_in_directed_graph_helper(adj, visited, p, recstk) == true)
        {
            return true;
        }
        else if (recstk[p] == true)
        {
            return true;
        }
    }
    recstk[s] = false;
    return false;
}
// Checking if there is cycle or not in directed graph
bool cycle_in_directed__graph(vector<int> adj[], int v)
{
    bool visited[v], recstk[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recstk[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (cycle_in_directed_graph_helper(adj, visited, i, recstk) == true)
        {
            return true;
        }
    }
    return false;
}


// For topological sorting of directed graph // also called kahn's algorithm // works only when there is no cycle in the graph
void topological_sort(vector<int> adj[], int v)
{
    vector<int> in_degree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            in_degree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            in_degree[adj[u][i]]--;
            if (in_degree[adj[u][i]] == 0)
            {
                q.push(adj[u][i]);
            }
        }
    }
    cout << endl;
}

// checking if there is cycle or not in directed graph using kahn's algorithm
bool cycle_in_directed__graph_using_kahn(vector<int> adj[], int v)
{
    vector<int> in_degree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            in_degree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    cout << endl;
    int count = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            in_degree[adj[u][i]]--;
            if (in_degree[adj[u][i]] == 0)
            {
                q.push(adj[u][i]);
            }
        }
        count++;
    }
    if (count != v)
    {
        return true;
    }
    return false;
}


// DFS for topological sort of graph
void DFS_for_topologocal_sort(vector<int> adj[], int s, stack<int> &st, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        int p = adj[s][i];
        if (visited[p] == false)
        {
            DFS_for_topologocal_sort(adj, p, st, visited);
        }
    }
    st.push(s);
}

// For topological sorting of directed graph using DFS
void topological_sort_using_dfs(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFS_for_topologocal_sort(adj, i, st, visited);
        }
    }
    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
    cout << endl;
}


// prim's algorithm for finding minimum spanning tree
int primMST(vector<int> graph[], int V)
{
    int key[V];
    int res = 0;
    fill(key, key + V, INT_MAX);
    bool mSet[V];
    key[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mSet[v] == false)
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}


// Don't work for negative weight edges
void dijkshtra(vector<vector<pair <int, int>>> adj,  int source, int n, vector <int> &dist)
{
    // If we want to find the path of the shortest distance from
    // source to destination, then parent array is used
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap
    pq.push({0, source});
    while (pq.empty() == false)
    {
        int u = pq.top().second;
        int v = pq.top().first;
        pq.pop();
        if (dist[u]==v)
        {
            for (int i = 0; i < adj[u].size(); i++)
            {
                if (dist[u] + adj[u][i].second < dist[adj[u][i].first])
                {
                    dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                    pq.push({dist[adj[u][i].first], adj[u][i].first});
                }
            }
        }
    }
}


// Works for negative weight edges and identifies if there is negative cycle or not in the graph
void BellmanFord(vector<vector<int>> &graph, int V, int E, int src)
{
    int dis[V];
    for (int i = 0; i < V; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }
    // check for negative-weight cycles. The above step guarantees shortest distances if graph doesn't contain negative weight cycle.  If we get a shorter path, then there is a cycle.
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
        {
            cout << "Graph contains negative  weight cycle" << endl;
            break;
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dis[i] << endl;
    }
}


// Next five functions is for Kosaraju's Algorithm
void fillOrder(int v, bool visited[], stack<int> &s, vector<vector<int>> &adj)
{
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int p = adj[v][i];
        if (visited[p] == false)
        {
            fillOrder(p, visited, s, adj);
        }
    }
    s.push(v);
}

void DFSUtil(int v, bool visited[], vector<vector<int>> &adj)
{
    visited[v] = true;
    cout << v << " ";
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            DFSUtil(i, visited, adj);
        }
    }
}

vector<vector<int>> getTranspose(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<vector<int>> g(V);
    for (int v = 0; v < V; v++)
    {
        for (int i = 0; i < adj[v].size(); i++)
        {
            int p = adj[v][i];
            g[p].push_back(v);
        }
    }
    return g;
}

void printSCCs(int V, vector<vector<int>> &adj)
{
    stack<int> s;
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            fillOrder(i, visited, s, adj);
        }
    }
    vector<vector<int>> gr = getTranspose(adj);
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (visited[v] == false)
        {
            DFSUtil(v, visited, gr);
            cout << endl;
        }
    }
}

void addEdge(vector<vector<int>> &adj, int v, int w)
{
    adj[v].push_back(w);
}


// For Articulation Points in a graph
void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int &time, int parent, bool isAP[])
{
    int children = 0;
    visited[u] = true;
    time++;
    disc[u] = low[u] = time;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (visited[v] == false)
        {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, isAP);
            // Check if the subtree rooted with v has a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u])
            {
                isAP[u] = true;
            }
        }
        // Update low value of u for parent function calls.
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
    {
        isAP[u] = true;
    }
}

void AP(vector<int> adj[], int V)
{
    int disc[V] = {0};
    int low[V];
    bool visited[V] = {false};
    bool isAP[V] = {false};
    int time = 0, par = -1;
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            APUtil(adj, u, visited, disc, low, time, par, isAP);
        }
    }
    for (int u = 0; u < V; u++)
    {
        if (isAP[u] == true)
        {
            cout << u << " ";
        }
    }
}


// For bridges in a graph
void bridgeUtil(vector<int> adj[], int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int &time)
{
    visited[u] = true;
    time++;
    disc[u] = low[u] = time;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == parent)
        {
            continue;
        }

        if (visited[v])
        {
            low[u] = min(low[u], disc[v]);
        }
        else
        {
            bridgeUtil(adj, v, visited, disc, low, u, time);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                cout << u << " " << v << endl;
            }
        }
    }
}

void bridge(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    int time = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bridgeUtil(adj, i, visited, disc, low, -1, time);
        }
    }
}


// Tarjan's Algorithm
void SCCUtil(int u, int disc[], int low[], stack<int> &st, bool visited[], vector<int> adj[], int V, int &time)
{
    time++;
    disc[u] = low[u] = time;
    st.push(u);
    visited[u] = true;
    for (int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if (disc[v] == -1)
        {
            SCCUtil(v, disc, low, st, visited, adj, V, time);
            low[u] = min(low[u], low[v]);
        }
        else if (visited[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    int w = 0;
    if (low[u] == disc[u])
    {
        while (st.top() != u)
        {
            w = st.top();
            cout << w << " ";
            visited[w] = false;
            st.pop();
        }
        w = st.top();
        cout << w << "\n";
        visited[w] = false;
        st.pop();
    }
}

void SCC(int V, vector<int> adj[])
{
    int disc[V];
    int low[V];
    bool visited[V];
    stack<int> st;
    int time = 0;
    for (int i = 0; i < V; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            SCCUtil(i, disc, low, st, visited, adj, V, time);
        }
    }
}