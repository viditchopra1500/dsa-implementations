//just like elis but with extra features
ll n;
string s;
vvll dp;
ll solve(ll i,ll num){
    if(i>=n){
        if(num==4)
            return 0;
        else return -MOD;
    }
    if(dp[i][num]!=-1) return dp[i][num];
    ll ma=0;
    if(num==0){
        if(s[i]=='1')
            ma=solve(i+1,1)+1;
        else ma=solve(i+1,0);
    }
    else{
        if(num==1){
            if(s[i]=='1')
                ma=solve(i+1,1)+1;
            else if(s[i]=='8')
                ma=max(solve(i+1,1),solve(i+1,2)+1);
            else
                ma=solve(i+1,1);
        }
        else if(num==2){
           if(s[i]=='8')
                ma=solve(i+1,2)+1;
            else if(s[i]=='0')
                ma=max(solve(i+1,2),solve(i+1,3)+1);
            else
                ma=solve(i+1,2); 
        }
        else if(num==3){
            if(s[i]=='0')
                ma=solve(i+1,3)+1;
            else if(s[i]=='7')
                ma=max(solve(i+1,3),solve(i+1,4)+1);
            else
                ma=solve(i+1,3);    
        }
        else{
            if(s[i]=='7')
                ma=solve(i+1,4)+1;
            else ma=solve(i+1,4);
        }
    }
    return dp[i][num]=ma;
}



int main(){
        read(s);
        n=s.length();
        dp=vvll(n,vll(5,-1));
        ll ans=max(solve(0,0),0ll);
       cout<< ans;
    }
