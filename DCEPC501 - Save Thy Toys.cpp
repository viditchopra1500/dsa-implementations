vll cost;
vvll dp;
ll n;
ll rec(ll pos,ll toys){
    if(pos>=n){
        return 0;
    }
    if(dp[pos][toys]!=-1) return dp[pos][toys];
    if(toys==1&&pos<n){
        return dp[pos][toys]=(
            max(rec(pos+2,1),max(rec(pos+2,2),rec(pos+2,3)))+cost[pos]
            );
    }
    else if(toys==2&&pos<n-1){
        return dp[pos][toys]=(
            max(rec(pos+4,1),max(rec(pos+4,2),rec(pos+4,3)))+cost[pos]+cost[pos+1]
            );
    }
    else if(toys==3&&pos<n-2){
        return dp[pos][toys]=(
            max(rec(pos+6,1),max(rec(pos+6,2),rec(pos+6,3)))+cost[pos]+cost[pos+1]+cost[pos+2]
            );
    }
    else {
        return 0;
    }

}

int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t;read(t);
while(t--){
    read(n);
    cost=vll(n);
    read(cost,n);
    dp=vvll(n,vll(4,-1));
    cout<<max(rec(0,1),max(rec(0,2),rec(0,3)))<<"\n";
}}
