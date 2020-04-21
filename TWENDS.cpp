vll v;
ll n;
vvll dp;

ll rec(ll l,ll r){
        if(l==r) return v[l];

    if(l>r){
        return 0;
    }

    if(dp[l][r]!=-1) return dp[l][r];
    ll v1,v2;
    if(v[r]>v[l+1]){
        v1=rec(l+1,r-1)+v[l];
    }
    else{
        v1=rec(l+2,r)+v[l];
    }
    if(v[l]>=v[r-1]){
        v2=rec(l+1,r-1)+v[r];
    }
    else{
        v2=rec(l,r-2)+v[r];
    }
    return dp[l][r]=max(v1,v2);
}

int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll m=1;
while(1){
read(n);
ll sum=0;
if(n==0) break;
v=vll(n);
forn(i,n){
    read(v[i]);
    sum+=v[i];
}
dp=vvll(n,vll(n,-1));
cout<<"In game "<<m++<<", the greedy strategy might lose by as many as ";
cout<<2*rec(0,n-1)-sum<<" points.\n";
}}
