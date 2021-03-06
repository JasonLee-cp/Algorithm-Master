vector<int>visited;
int cnt;
void dfs(vector<vector<int>>& rooms, int cur){
    if(visited[cur]) return;
    visited[cur] = true;
    cnt++;
    for(auto &lock: rooms[cur]){
        dfs(rooms,lock);
    }
}

bool solve(vector<vector<int>>& rooms) {
    cnt=0;
    int n = rooms.size();
    if(n==0) return true;
    visited.clear();
    visited.resize(n,false);
    dfs(rooms,0);
    return cnt==n;
}



// Solution 2
vector<int>visited;

void dfs(vector<vector<int>>& rooms, int cur){
    if(visited[cur]) return;
    visited[cur] = true;

    for(auto &neighbor: rooms[cur]){
        dfs(rooms,neighbor);
    }
}

bool solve(vector<vector<int>>& rooms) {
    int n = rooms.size();
    visited={}; 
    visited.resize(n,false);
    dfs(rooms,0);

    for(auto &i: visited){
        if(i==false) return false;
    }
    
    return true;
    
}