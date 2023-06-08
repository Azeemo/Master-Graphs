// on gfg / leetcode by striver
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node , vector<int> adjLs[],int vis[]){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
         vector<int> adjls[V];
       // now to conert adj matrix to list
      
       for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
               if(adj[i][j]==1 && i!=j){
                   // i!=j is for self nodes
               adjls[i].push_back(j);
               }
           }
       }
       int count = 0;
      int visited[V]={0};
      for(int i=0;i<V;i++){
          if(!visited[i]){
              count++;
              dfs(i,adjls,visited);
          }
      }
       return count ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
