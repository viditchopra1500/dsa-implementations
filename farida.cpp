iterative dp---------------------------------------------------------------------------
int main()
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
