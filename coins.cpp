
map<ll,ll> dp;

ll rec(ll n){
    if(dp[n]!=0) return dp[n];
    if(n/2+n/3+n/4<=n){
        return dp[n]=n;
    }
    ll a=rec(n/2)+rec(n/4)+rec(n/3);
    return dp[n]=a;
}

int main()
{
    ll a;
    while(cin>>a){
        if(dp[a]!=0) cout<<dp[a];
        else{
            rec(a);
            cout<<dp[a];
        }
        cout<<"\n";
    }
}
