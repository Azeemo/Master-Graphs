// dfs on gfg by striver
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
       void dfs(int node , int vis[],vector<int>&lst,vector<int> adj[]){
        vis[node]=1;
        lst.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,lst,adj);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
 
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int visited[V] = {0};
    int start = 0;
    vector<int> traverse ;
    dfs(start,visited,traverse,adj);
    return traverse;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
