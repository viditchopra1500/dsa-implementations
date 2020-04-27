vll arr;
ll dp[3001][3001];
string a,b;
ll n,m;
ll rec(ll pos1,ll pos2){
    if(pos1==n){
        return abs(pos2-m);
    }
    if(pos2==m)
        return abs(pos1-n);
    if(dp[pos1][pos2]!=-1) return dp[pos1][pos2];
    ll mi=MOD;
        if(a[pos1]==b[pos2]){
            mi=min(mi,rec(pos1+1,pos2+1));
        }
        else{
            mi=min(mi,rec(pos1+1,pos2)+1);
            mi=min(mi,rec(pos1,pos2+1)+1);
            mi=min(mi,rec(pos1+1,pos2+1)+1);
        }
        return dp[pos1][pos2]=mi;
}

int main()
{fast;
    test{
        ini(dp,-1);
        read(a,b);
        n=a.length();
        m=b.length();
        cout<<(rec(0,0));
    }}
