// nice problem teaches us how to reduce the time complexity 

ll n,y,a;
vll bond,ret;
vvll dp;
ll rec(ll pos,ll n){
    if(pos>=a||n==0){
        return 0;
    }
    if(dp[pos][n]!=-1) return dp[pos][n];
    ll ma=0;
    for(ll i=0;n-i*bond[pos]>=0;i++){
        ma=max(ma,rec(pos+1,n-i*bond[pos])+ret[pos]*i);
    }
    return dp[pos][n]=ma;
}

int main()
{fast;
    test{
        read(n,y,a);
        ll rem=n%1000;
        n/=1000;
        ret=bond=vll(a);
        forn(i,a){
            read(bond[i],ret[i]);
            bond[i]/=1000;
        }
        dp=vvll(10,vll(100000,-1));
        forn(i,y){
            ll ans=rec(0,n);
            n+=(rem+ans)/1000;
            rem=(ans+rem)%1000;
        }
        cout<<(n*1000+rem)<<"\n";
    }
}
