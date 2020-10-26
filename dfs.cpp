#include<bits/stdc++.h>
using namespace std;
/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void DFS(vector<int>adj[],int n, int s, int *vis, vector<int> &ans)
{
    vis[s]=1;
    ans.push_back(s);
    
    for(int u: adj[s])
    {
        if(vis[u]==0)
        {
            DFS(adj,n,u,vis,ans);
        }
    }
}
vector <int> dfs(vector<int> g[], int n)
{
    vector<int>ans;
    int vis[n];
    for(int i=0;i<n;i++)
        vis[i]=0;
    DFS(g,n,0,vis,ans);
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}
