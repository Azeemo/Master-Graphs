
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // HERE THE QUESTION HAS TAKEN DIRECTED UNWEIGTED GRAPH
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      // zero indexing graph as it is staring form zero
      int vis[V] = {0};
      // initilized a visited array with all 0 values of size = VERTICES; 
      vis[0] = 1;
      
      queue<int> q;
      q.push(0); // AS STARTING NODE IS 0 SO PUSHING THIS FIRST
      
      vector<int> bfs;
      // FOR STORING THE TRAVERSAL
      
      while(!q.empty()){
          int node = q.front();
          // taking the front node
          q.pop();
          
          bfs.push_back(node); 
          // pushing the node in vector as traversal
         
         // now visiting all the neigboura of that node and including in the list
         // if they are not  visited
         
          for(auto it : adj[node])
          {  
              // here it will give the actual neigbour 
              if(!vis[it])
              // that particular node if not visted then go
              // otherwise  move to other nodes related to adj[node]
              {
                  vis[it]=1;
                  // marking it as 1 for being the visited
                  q.push(it);
              }
          }
      }
      return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;