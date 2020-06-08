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


*----------------------------------------------------------------------------------------iterative dp
int main()
{fast;ll c=1;
    while(1){
        ll n;
        read(n);
        if(n==0)
            break;
        else{
            ll arr[n][3],dp[n][3];
            forn(i,n){
                forn(j,3){
                    read(arr[i][j]);
                }
            }
            dp[0][0]=MOD,dp[0][1]=arr[0][1],dp[0][2]=arr[0][2]+arr[0][1];
            for1(i,n-1){
                forn(j,3){
                    ll a=dp[i-1][0],b=dp[i-1][1],c=dp[i-1][2];
                    if(j==0){
                        dp[i][0]=arr[i][j]+min(a,b);
                    }
                    if(j==1){
                        dp[i][1]=arr[i][j]+min(a,min(b,min(dp[i][0],c)));
                    }
                    if(j==2){
                        dp[i][2]=arr[i][j]+min(b,min(c,dp[i][1]));
                    }
                }
            }
            cout<<c<<". "<<dp[n-1][1]<<"\n";
c++;
        }
    }
}
