vll hotg,tom;
vvll dp;
ll rec(ll a,ll b){
    if(a==hotg.size()||b==tom.size()){
        return 0;
    }
    if(dp[a][b]!=-1) return dp[a][b];
    ll ma=0;
    if(hotg[a]==tom[b]){
        ma=max(ma,rec(a+1,b+1)+1);
    }
    else{
        ma=max(ma,max(rec(a,b+1),rec(a+1,b)));
    }
    return dp[a][b]=ma;
}

int main()
{fast;
    test{
        vll a1,b1,ne;
        while(1){
            ll a;
            read(a);
            if(a==0) break;
            a1.pb(a);
        }
        ll ma=0;
        hotg=a1;
        while(1){
            ll a;
            read(a);
            if(a==0){
                if(b1.size()==0)
                {
                    break;
                }
                tom=b1;
                b1=ne;
                dp=vvll(hotg.size(),vll(tom.size(),-1));
                ma=max(ma,rec(0,0));
            }
            else{
                b1.pb(a);
            }
        }
        cout<<ma<<"\n";
    }
}
