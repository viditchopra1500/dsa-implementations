// quite easy just need to follow basic steps for dp ie
//what are all the states it can reach from the current state. 

ll tot,n;
vll p,w;
vvll dp;
ll rec(ll pos,ll left){
    if(pos>=n)
    {
        if(left!=0) return MOD;
        else return 0;
    }
    if(dp[pos][left]!=-1) return dp[pos][left];
// deb(pos),deb(left);
ll a=MOD;
    for(ll i=0;0<=left-i*w[pos];i++){
        // deb(a);
        a=min(a,rec(pos+1,left-i*w[pos])+p[pos]*i);
        // deb(a);
        
    }
    return dp[pos][left]=a;
}

int main()
{fast;
    test{
        ll e,f;
        read(e,f,n);
        p=w=vll(n);
        dp=vvll(n,vll(f-e+1,-1));
        forn(i,n){
            read(p[i],w[i]);
        }
        ll ans=rec(0,f-e);
        if(ans==MOD) cout<<"This is impossible.";
        else
        cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".";
    cout<<"\n";
    }
}
