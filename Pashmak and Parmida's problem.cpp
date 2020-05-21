
ll fen[MAXN];
void updateFent(ll i, ll add) {
    while (i > 0 && i < MAXN)
    {
        fen[i] += add;
        i += (i & (-i));
    }
}
 
ll queryFent(ll i) {
    ll s = 0;
    while (i > 0)
    {
        s += fen[i];
        i = i - (i & (-i));
    }
    return s;
}

ll rangeSumQueryFent(ll l,ll r){
    return(queryFent(r)-queryFent(l-1));
}

int main()
{
    fast;
    ll n;
    read(n);
    ll arr[n];
    read(arr,n);
    map<ll,ll> mp,mp1;
    ll pre[n]={0},suf[n]={0};
    forn(i,n){
        mp[arr[i]]++;
        pre[i]=mp[arr[i]];
    }
    forr(i,n){
        mp1[arr[i]]++;
        suf[i]=mp1[arr[i]];
    }
    ll ans=0;
    ini(fen,0);                          //why i need fen tree to solve->as whole prefix array changes 
                                         //when an element is inserted
    forr(i,n){
        ans+=queryFent(pre[i]-1);        //I am making prefix sum of suff array(containing freq_of_ai from suffix)
        updateFent(suf[i],1);            //and querying at i how many elements are less than or equal to pre[i]-1 
    }
    cout<<ans;
}
