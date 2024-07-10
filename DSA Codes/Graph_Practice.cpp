#include "Graph_Practice.h"

signed main()
{
    cout << "Graph 1" << endl;
    vector<int> adj1[7]; // Array of vectors
    Add_Edge(adj1, 0, 1);
    Add_Edge(adj1, 1, 2);
    Add_Edge(adj1, 2, 3);
    Add_Edge(adj1, 3, 4);
    Add_Edge(adj1, 0, 2);
    Add_Edge(adj1, 1, 3);
    Add_Edge(adj1, 2, 4);
    Add_Edge(adj1, 1, 6);
    Add_Edge(adj1, 2, 5);
    Add_Edge(adj1, 4, 5);
    cout << "Checkpoint 1" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Vertices connected with vertex " << i << " are: ";
        for (int j = 0; j < adj1[i].size(); j++)
        {
            cout << adj1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Checkpoint 2" << endl;
    BFS(adj1, 7, 0);
    cout << endl;
    cout << "Checkpoint 3" << endl;
    DFS(adj1, 7, 0);
    cout << endl;
    cout << "Checkpoint 4" << endl;
    int dis[7];
    for (int i = 0; i < 7; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    min_distance_from_vertex(adj1, 0, 7, dis);
    for (int i = 0; i < 7; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    cout << "Checkpoint 5" << endl;
    if (cycle_in_undirected_graph(adj1, 7) == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }
    cout << endl;

    cout << "Graph 2" << endl;
    vector<int> adj2[11];
    Add_Edge(adj2, 0, 1);
    Add_Edge(adj2, 1, 2);
    Add_Edge(adj2, 2, 3);
    Add_Edge(adj2, 3, 4);
    Add_Edge(adj2, 0, 5);
    Add_Edge(adj2, 5, 6);
    Add_Edge(adj2, 6, 7);
    Add_Edge(adj2, 6, 8);
    Add_Edge(adj2, 9, 10);
    cout << "Checkpoint 1" << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << "Vertices connected with vertex " << i << " are: ";
        for (int j = 0; j < adj2[i].size(); j++)
        {
            cout << adj2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Checkpoint 2" << endl;
    BFS(adj2, 10, 0);
    cout << endl;
    BFS(adj2, 10, 9);
    cout << endl;
    BFSDin(adj2, 11);
    cout << endl;
    cout << "Checkpoint 3" << endl;
    DFS(adj2, 11, 0);
    cout << endl;
    DFS(adj2, 11, 9);
    cout << endl;
    DFS_second(adj2, 11);
    cout << endl;
    cout << "Checkpoint 4" << endl;
    int dist[11];
    for (int i = 0; i < 11; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    min_distance_from_vertex(adj2, 0, 11, dist);
    for (int i = 0; i < 11; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    cout << "Checkpoint 5" << endl;
    if (cycle_in_undirected_graph(adj2, 11) == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }
    cout << endl;

    cout << "Graph 3" << endl;
    vector<int> adj3[6];
    add_edge(adj3, 0, 1);
    add_edge(adj3, 2, 1);
    add_edge(adj3, 2, 3);
    add_edge(adj3, 3, 4);
    add_edge(adj3, 4, 5);
    add_edge(adj3, 5, 3);
    cout << "Checkpoint 1" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Vertices connected with vertex " << i << " are: ";
        for (int j = 0; j < adj3[i].size(); j++)
        {
            cout << adj3[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Checkpoint 2" << endl;
    if (cycle_in_directed__graph(adj3, 6) == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }
    cout << "Checkpoint 3" << endl;
    topological_sort(adj3, 6); // graph is cyclic so we are not getting full topological sort of this graph.
    if (cycle_in_directed__graph_using_kahn(adj3, 6) == true)
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not present" << endl;
    }

    cout << "Graph 4" << endl;
    vector<int> adj4[5];
    add_edge(adj4, 0, 1);
    add_edge(adj4, 1, 3);
    add_edge(adj4, 2, 3);
    add_edge(adj4, 2, 4);
    add_edge(adj4, 3, 4);
    cout << "Checkpoint 1" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Vertices connected with vertex " << i << " are: ";
        for (int j = 0; j < adj4[i].size(); j++)
        {
            cout << adj4[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Checkpoint 2" << endl;
    topological_sort_using_dfs(adj4, 5);
    cout << endl;
    
    // cout << "Graph 5" << endl;
    // vector<vector<int>> graph1 = {
    //     {0, 50, 100, 0},
    //     {50, 0, 30, 200},
    //     {100, 30, 0, 20},
    //     {0, 200, 20, 0},
    // };
    // for (int i = 0; i < dijkstra(graph1, 0, 4).size(); i++)
    // {
    //     cout << dijkstra(graph1, 0, 4)[i] << " ";
    // }
    // cout << endl << endl;

    cout << "Graph 6" << endl;
    vector<vector<int>> graph2 = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    BellmanFord(graph2, 5, 8, 0);

    cout << "Graph 7" << endl;
    int V = 5;
    vector<vector<int>> adj(V);
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    cout << "Following are strongly connected components in the given graph\n";
    printSCCs(V, adj);

    int Vertex = 5;
    vector<int> adj5[Vertex];
    Add_Edge(adj5, 1, 0);
    Add_Edge(adj5, 0, 2);
    Add_Edge(adj5, 2, 1);
    Add_Edge(adj5, 0, 3);
    Add_Edge(adj5, 3, 4);
    cout << "Articulation points in first graph \n";
    AP(adj5, Vertex);
    cout << endl;
    cout << "Bridges in first graph \n";
    bridge(adj5, 5);
    SCC(5, adj5);

    Vertex = 4;
    vector<int> adj6[Vertex];
    Add_Edge(adj6, 0, 1);
    Add_Edge(adj6, 1, 2);
    Add_Edge(adj6, 2, 3);
    cout << "\nArticulation points in second graph \n";
    AP(adj6, Vertex);
    cout << endl;
    cout << "Bridges in first graph \n";
    bridge(adj6, 4);

    Vertex = 7;
    vector<int> adj7[Vertex];
    Add_Edge(adj7, 0, 1);
    Add_Edge(adj7, 1, 2);
    Add_Edge(adj7, 2, 0);
    Add_Edge(adj7, 1, 3);
    Add_Edge(adj7, 1, 4);
    Add_Edge(adj7, 1, 6);
    Add_Edge(adj7, 3, 5);
    Add_Edge(adj7, 4, 5);
    cout << "\nArticulation points in third graph \n";
    AP(adj7, Vertex);
    cout << endl;
    cout << "Bridges in first graph \n";
    bridge(adj7, 7);
    return 0;
}