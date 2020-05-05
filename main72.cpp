//nice problem but its very similar to what we do with vis array in dfs here if i dp at pos and given sum
//if already visted then i dont need to go down ...

ll n,sm;
vll arr;
vvll dp;
ll mp[100001];
void rec(ll pos,ll sum){
    if(mp[sum]==0)
    {
        mp[sum]=1;
        sm+=sum;
    }
    // deb(sum);
    if(pos>=n) return ;
    if(dp[pos][sum]!=-1) return;
    rec(pos+1,sum);
    rec(pos+1,sum+arr[pos]);
    dp[pos][sum]=1;
    return;
}

int main()
{fast;
    test{
        read(n);
        arr=vll(n);
        ll ma=0;
        forn(i,n){
            read(arr[i]);
            ma+=arr[i];
        }
        ini(mp,0);
        sm=0;
        dp=vvll(n+1,vll(ma+1,-1));
        rec(0,0);
        cout<<sm<<"\n";
    }}
