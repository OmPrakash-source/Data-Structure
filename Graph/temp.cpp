#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<list>
#include<vector>
#include <stack>
using namespace std;

class Graph{
    // int V;
    // list<int>*l;
    unordered_map<int, list<int>>l;
public:
    // Graph(int V){
    //     this->V = V;
    //     l = new list<int>[V]; // V size ki list jaha sare neighbours sore hoge
    // }
    int addedge(int u, int v){
        l[u].push_back(v);  // u --> v
        l[v].push_back(u);  // v --> u
    }

    int print(){
        // for(int u=0; u<V; u++){
    //         // vector<int> neighbours = l[u]; // can't importent to make a list
    //         cout<<u << ": ";
    //         for(int v : l[u]){
    //             cout<<v<<" ";
    //         }
    //         cout<<endl;
    //     }

        for(auto v : l){
            cout<<v.first<<": ";
            for(auto u : v.second){
                cout<< u <<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int st){
        vector<bool>vec(l.size(), false);
        queue<int>q;
        q.push(st);
        vec[st] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout<< u << " ";
            for(int v : l[u]){
                if(!vec[v]){
                    vec[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void DFS(int u, unordered_map<int,bool> &visited){
        visited[u] = true;
        cout<<u<<" ";
        for(auto v : l[u]){
            if(!visited[v]){
                DFS(v, visited);
            }
        }
    }

    //connected Island (Hard)
    void BFSForIsland(vector<vector<int>>&adj,vector<vector<bool>>&vis, int row, int col){
        int n = adj.size();
        int m = adj[0].size();
        vis[row][col] = true;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            auto result = q.front();q.pop();
            int rowno = result.first;
            int colno = result.second;
            // for all 8 direction check 
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delrow <= 1; delcol++){
                    int newrow = rowno + delrow;
                    int newcol = colno + delcol;
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && adj[newrow][newcol] && !vis[newrow][newcol]){
                        vis[newrow][newcol] = true;
                        q.push({newrow,newcol});
                    }
                }
            }
        } 
    }
    int Island(vector<vector<int>>adj){
            int n = adj.size();
            int m = adj[0].size();
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int count = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && adj[i][j] == '1'){
                        count++;
                        BFSForIsland(adj,vis,i,j);
                    }
                }
            }
            return count;
        }
// 994
        int orangesRotting_994(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m, 0));
        // ({r,c},t)
        queue<pair<pair<int,int>, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0, 1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if( ncol >= 0 && nrow >= 0 && 
                    ncol < m && nrow < n && 
                    vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] == 1){

                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, t+1});
                 }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return tm;
    }
//733
     void dfs(vector<vector<int>>& image,vector<vector<int>>& ans, int row, int col,int delrow[],int delcol[], int color, int el){
        
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(ncol < m && nrow < n && nrow >= 0 && ncol >= 0 &&image[nrow][ncol] == el && ans[nrow][ncol] != color){
                dfs(image,ans,nrow,ncol,delrow,delcol,color,el);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>>ans = image;
        int el = image[sr][sc];
        if (el == color) return image;
        
        dfs(image,ans,sr,sc,delrow,delcol,color, el);
        return ans;
    }

// detect a cycle in graph using bfs
    bool detect_cycle(vector<int>adj, vector<bool>vis, int st){
        // node, parent
        queue<pair<int,int>>q;
        vis[st] = true;
        q.push({st,-1});
        while(!q.empty()){
            int parent = q.front().second;
            int node = q.front().first;
            q.pop();
            for(auto adjnode : adj){
                if(!vis[adjnode]){
                    vis[adjnode] = true;
                    q.push({adjnode,node}); // push node as parent
                }else if(adjnode != parent){ // if node is visited but it is not parent mean other is visit it 
                    return true; 
                }
            }
        }
        return false;
    }
    bool cycle_detection_bfs(vector<int>adj,int st){
        vector<bool>vis(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                if(detect_cycle(adj,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
//541 And 1765 both diff is there find close 0 and second one follow close 1
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }else vis[i][j] = false;
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[r][c] = step;
            for(int i=0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow < n && ncol < m && ncol >= 0 && nrow >= 0 && vis[nrow][ncol]==false){
                    q.push({{nrow,ncol},step + 1});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return ans;
    }

    // 130 convert 'O' to 'X' if 'O' is not in boundry 
    void dfs(vector<vector<char>>& b,vector<vector<bool>>&vis, int r, int c){
        vis[r][c] = true;
        int n = b.size();
        int m = b[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if(nr < n && nc < m && nr >= 0 && nc >= 0 && !vis[nr][nc] && b[nr][nc] == 'O'){
                dfs(b,vis,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0; i<m; i++){
            //first row
            if(!vis[0][i] && b[0][i] == 'O'){
                dfs(b,vis,0,i);
            }
            //last row
            if(!vis[n-1][i] && b[n-1][i] == 'O'){
                dfs(b,vis,n-1, i);
            }
        }
        for(int i=0; i<n; i++){
            //first col
            if(!vis[i][0]  && b[i][0] == 'O'){
                dfs(b,vis,i,0);
            }
            //last col
            if(!vis[i][m-1] && b[i][m-1] == 'O'){
                dfs(b,vis,i,m-1);
            }
        }
        // remainting 
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && b[i][j] == 'O'){ 
                    b[i][j] = 'X'; // convert
                }
            }
        }
    }
//127
    int ladderLength(string bw, string ew, vector<string>& w) {
        unordered_set<string>st(w.begin(),w.end());
        queue<pair<string,int>>q;
        q.push({bw,1});
        st.erase(bw);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == ew) return step;
            for(int i=0; i<word.size(); i++){
                int og = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, step+1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }

    //785
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int s = 0; s < n; s++) {
            if (color[s] != -1) continue;

            queue<int> q;
            q.push(s);
            color[s] = 0; //first node color is 0

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = !color[u]; //store reverse color for parent
                        q.push(v);
                    } else if (color[v] == color[u]) { //if parent and child have same color mean not bipartite
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // topological sorting kahn's algo
    vector<int> DAC(vector<vector<int>> adj){
        int n = adj.size();
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++){
            for(auto v : adj[i]){
                indeg[v]++; //for each indegree increase value  
            }
        }
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);    //for any value which size is 0 mean less priority so include
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);   //yaha wo hi nade hogi jiski priority low hai mean inclue in ans
            for(auto v : adj[node]){
                indeg[v]--; //if se same node aai to indeg me uski value decrease 
                if(indeg[v] == 0) q.push(v);
            }
        }
        return topo;
    }

    //topo sort in directed acyclic graph
    bool DAC_directed_cycleDetection(vector<vector<int>> adj){
        int n = adj.size();
        vector<int> indeg(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            for(auto v : adj[i]){
                indeg[v]++; //for each indegree increase value  
            }
        }
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);    //for any value which size is 0 mean less priority so include
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;   //yaha wo hi nade hogi jiski priority low hai mean inclue in ans
            for(auto v : adj[node]){
                indeg[v]--; //if se same node aai to indeg me uski value decrease 
                if(indeg[v] == 0) q.push(v);
            }
        }
        return count == n?false:true;
    } 

    //802
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<int>indegree(graph.size(),0);
        queue<int>q;
        vector<vector<int>>adj(graph.size());

        for(int i=0; i<graph.size();i++){
            for(int it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0; i<graph.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }   
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);
            for(int v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
    sort(ans.begin(), ans.end());
    return ans;
    }


    // shortest path
    void dfs(int node, stack<int> &st, vector<bool> &vis, vector<vector<pair<int,int>>> &adj) {
        vis[node] = true;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, st, vis, adj);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological sort using DFS
        stack<int> st;
        vector<bool> vis(N, false);
        for (int i = 0; i < N; i++) {
            if (!vis[i]) dfs(i, st, vis, adj);
        }

        // Step 3: Initialize distance array
        vector<int> dist(N, INT16_MAX);
        dist[0] = 0; // Assuming source node = 0

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT16_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    int N = 6; // Number of nodes
    int M = 7; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 5, 4},
        {5, 3, 1}
    };
    Graph g;
    vector<int> ans = g.shortestPath(N, M, edges);

    cout << "Shortest distance from source (0):\n";
    for (int i = 0; i < N; i++) {
        if (ans[i] == INT16_MAX) cout << "INF ";
        else cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
