//important to check sometimes the state is not less than 0 found great trick to esc that shitzz

ll n;
vll  ox,ni,wt;
ll dp[1001][22][80];
ll rec(ll pos,ll ot,ll nt){
    if(dp[pos][ot][nt]!=-1) return dp[pos][ot][nt];
    if(ot==0&&nt==0){
        return dp[pos][ot][nt]=0;
    }
    if(pos>=n){
        return dp[pos][ot][nt]=INF;
    }
    ll a=rec(pos+1,max(0ll,ot-ox[pos]),max(0ll,nt-ni[pos]))+wt[pos];
    ll b=rec(pos+1,ot,nt);
    return dp[pos][ot][nt]=min(a,b);
}

int main()
{fast;
    test{
        ll t,a;
        ini(dp,-1);
        read(t,a,n);
        ox=ni=wt=vll(n);
        forn(i,n){
            read(ox[i],ni[i],wt[i]);
        }
        cout<<rec(0,t,a)<<"\n";
    }}
