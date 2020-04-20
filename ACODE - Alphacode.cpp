vvll dp;
string s;
ll rec(ll pos,ll pair){
    ll n=s.length();
    if(pos>=n-1&&pair==1) return 0;
    if(pos>=n){
        return 1;
    }
    string s1="";
    if(s[pos]=='0') return 0;
    s1+=s[pos];
    s1+=s[pos+1];
    if(dp[pos][pair]!=-1) return dp[pos][pair];
    if(pair==1&&(stoi(s1)>26)) {
        return dp[pos][pair]=0;
    }
    if(pair==0){
        return dp[pos][pair]=rec(pos+1,0)+rec(pos+1,1);
    }
    else{
        return dp[pos][pair]=rec(pos+2,0)+rec(pos+2,1);
    }
}

int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
while(1)
{
read(s);
if(s=="0") break;
dp=vvll(s.length(),vll(2,-1));
cout<<rec(0,0)+rec(0,1)<<"\n";
}}
