// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool visited[10001] ;

	bool cycle_helper(int node, vector<int> adj[], int parent)
	{
		visited[node] = true;

		for (int a : adj[node])
		{
			if (not visited[a])
			{
				return cycle_helper(a, adj, node);
			}
			else
			{
				if (a != parent)
					return true;
			}
		}
		return false;
	}

	bool isCycle(int V, vector<int>adj[])
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < V; i++)
		{
			if (not visited[i])
			{
				if (cycle_helper(i, adj, -1))
					return true;
			}
		}
		return false;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends