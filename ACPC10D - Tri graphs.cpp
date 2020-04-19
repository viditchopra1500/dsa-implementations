vvll cost;
vvll dp;
ll n;
ll rec(ll r,ll c){
    if(r>=n){
        return MOD;
    }
    if(r==n-1&&c==1) return cost[r][c];
    if(dp[r][c]!=-1) return dp[r][c];
    if(c==1){
        return dp[r][c]=min(rec(r+1,0),min(rec(r+1,1),min(rec(r+1,2),rec(r,2))))+cost[r][c];
    }
    else if(c==2){
        return dp[r][c]=min(rec(r+1,2),rec(r+1,1))+cost[r][c];
    }
    else{
        return dp[r][c]=min(rec(r+1,0),min(rec(r+1,1),rec(r,1)))+cost[r][c];
    }
}

int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll c=1;
while(true){
    cin>>n;
    if(n==0) break;
    cost=vvll(n,vll(3));
    forn(i,n){
        forn(j,3){
            read(cost[i][j]);
        }
    }
    dp=vvll(n,vll(3,-1));
    cout<<c<<". "<<rec(0,1)<<"\n";
    c++;
}}
