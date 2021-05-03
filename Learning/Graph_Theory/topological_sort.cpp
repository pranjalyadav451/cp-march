// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool visited[10000 + 5];
    vector<int>ans;

    void dfs(stack<int>&toPrev, vector<int>adj[], int i)
    {
        visited[i] = true;
        for (int a : adj[i])
        {
            if (!visited[a])
                dfs(toPrev, adj, a);
        }
        toPrev.push(i);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        memset(visited, 0, sizeof(visited));
        ans.clear();
        stack<int>toPrev;
        for (int i = 0; i < V; i++)
        {
            if (not visited[i])
            {
                dfs(toPrev, adj, i);
            }
        }
        while (toPrev.empty() == false)
        {
            ans.push_back(toPrev.top());
            toPrev.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}  // } Driver Code Ends