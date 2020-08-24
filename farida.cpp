iterative dp---------------------------------------------------------------------------
1)int main()
{fast;
    ll c=1;
    test{
        vll coins,dp;
        ll n;
        read(n);
        dp=vll(n,0);
        coins=vll(n);
        read(coins,n);
        if(n>=1)
            dp[0]=coins[0];                          //here we usually think whats the answer if 1 coins 
        if(n>=2)
            dp[1]=max(coins[1],coins[0]);            //here whats the answer if 2 coins
        for(ll i=2;i<n;i++){                         //these are my base cases.
            dp[i]=max(dp[i-1],dp[i-2]+coins[i]);
        }
        if(n==0){
        cout<<"Case "<<c<<": "<<0<<"\n";}
        else
        cout<<"Case "<<c<<": "<<dp[n-1]<<"\n";
        c++;
    }}
    

2)void solve(){
    ll n;
    read(n);
    ll arr[n];
    read(arr,n);
    ll dp[n]={0};
    //dp[i] is the max gold coins if we dont take from adjacent monsters.
    dp[0]=arr[0];
    if(n>1)
    dp[1]=max(dp[0],arr[1]);
    forn(i,n-1){
        dp[i+1]=max(dp[i+1],dp[i]);
        if(i<n-2)
            dp[i+2]=max(dp[i+2],dp[i]+arr[i+2]);
    }
    if(n==0) cout<<0;
    else
    cout<<dp[n-1];en;
}

    recursive sol--------------------------------------------------------------------------
    
    ll rec(ll i){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)
        return dp[i];
    ll ma=max(coins[i]+rec(i+2),rec(i+1));
    return dp[i]=ma;
}

int main()
{fast;
    test{
        // ll n;
        vll coins;
        vll dp;
        ll n;
        read(n);
        dp=vll(n,-1);
        coins=vll(n);
        read(coins,n);
        cout<<rec(0)<<"\n";
    }
}
