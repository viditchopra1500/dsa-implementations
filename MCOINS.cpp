
ll dp[1000001];
ll k,l,m;
ll rec(ll n){
    if(dp[n]!=-1) return dp[n];
    ll ch=0;
    if(n-1>=0){
        ll a;
        a=rec(n-1);
        ch|=!a;
    }
    if(n-l>=0){
        ch|=!rec(n-l);
    }
    if(n-k>=0){
        ch|=!rec(n-k);
    }
    return dp[n]=ch;
}



int main()
{fast;
    read(k,l,m);
    forn(i,1000001) dp[i]=-1;
    dp[0]=0;
    dp[1]=1;
    ll arr[m],ma=0;
    forn(i,m){
        ll a;
        read(a);
        ma=max(ma,a);
        arr[i]=a;
    }
    rec(ma);
    forn(i,m){
        if(dp[arr[i]]) cout<<'A';
        else cout<<'B';
    }
}
