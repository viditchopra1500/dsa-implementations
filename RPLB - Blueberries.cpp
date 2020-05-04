ll n,k;
vll blue;
vvll dp;

ll rec(ll pos,ll straw){
    if(pos>=n||straw<=0){
        return 0;
    }
    if(dp[pos][straw]!=-1) return dp[pos][straw];
    ll a=0,b=0;

        b=max(b,rec(pos+1,straw));

        if(straw-blue[pos]>=0)
        a=max(a,rec(pos+2,straw-blue[pos])+blue[pos]);

    return dp[pos][straw]=max(a,b);

}

int main()
{fast;
    ll c=1;
    test{
        read(n,k);
        blue=vll(n);
        forn(i,n){
            read(blue[i]);
        }
        dp=vvll(n,vll(k+1,-1));
        cout<<"Scenario #"<<c<<": "<<rec(0,k)<<"\n";
        c++;
    }}
