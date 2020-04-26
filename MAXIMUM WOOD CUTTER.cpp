vector<vector<char>> graph;
ll dp[201][201][2];
ll m,n;
bool valid(ll i,ll j){
    return (i>=0&&i<m&&j>=0&&j<n);
}

ll rec(ll i,ll j,ll dir){
    if(dp[i][j][dir]!=-1) return dp[i][j][dir];
    if(graph[i][j]=='#') return dp[i][j][dir]=0;
    ll ma=0,t=0;
    if(graph[i][j]=='T') t=1,ma=1;
    if(dir==0){
        if(valid(i,j+1)){
            ma=max(ma,rec(i,j+1,0)+t);
        }
        if(valid(i+1,j)){
            ma=max(ma,rec(i+1,j,1)+t);
        } 
    }
    if(dir==1){
        if(valid(i,j-1)){
            ma=max(ma,rec(i,j-1,1)+t);
        }
        if(valid(i+1,j)){
            ma=max(ma,rec(i+1,j,0)+t);
        } 
    }
    return dp[i][j][dir]=ma;    
}

int main()
{fast;
test{
    read(m,n);
    graph=vector<vector<char>>(m+1,vector<char>(n+1));
    forn(i,m){
        forn(j,n){
            read(graph[i][j]);
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    cout<<rec(0,0,0)<<"\n";
}}
