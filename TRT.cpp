vll v;
ll n;
vvll dp;

ll rec(ll l,ll r){
    if(l>r){
        return 0;
    }
    ll z=n-(r-l+1)+1;
    if(dp[l][r]!=-1) return dp[l][r];
    return (
        dp[l][r]=max(rec(l+1,r)+v[l]*z,rec(l,r-1)+v[r]*z)
        );
}

int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
read(n);
v=vll(n);
read(v,n);
dp=vvll(n,vll(n,-1));
cout<<rec(0,n-1);
}
