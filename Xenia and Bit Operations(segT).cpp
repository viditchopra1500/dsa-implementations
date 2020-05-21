 //remember segment tree is a perfect binary tree
ll segt[4*MAXN],lazy[4*MAXN];
vll arr10;                               
 
void buildSegt(ll v, ll tl, ll tr,ll d) {
    if (tl == tr) {
        segt[v] = arr10[tl];
    } else {
        ll tm = (tl + tr) / 2;
        buildSegt(v*2, tl, tm,d+1);       
        buildSegt(v*2+1, tm+1, tr,d+1);
        if(d%2==1)   
        segt[v] = segt[v*2] | segt[v*2+1];
        else
        segt[v]=segt[v*2]^segt[v*2+1];  
    }
}
 
void point_update(ll v,ll tl,ll tr,ll pos,ll add,ll d){
    if(tl==tr){
        segt[v]=add;
        return;
    }
    ll tm=(tr-tl)/2+tl;
    if(pos<=tm){
        point_update(2*v,tl,tm,pos,add,d+1);
    }
    else
        point_update(2*v+1,tm+1,tr,pos,add,d+1);
    if(d%2==1)
    segt[v]=segt[2*v]|segt[2*v+1];
else
    segt[v]=segt[2*v]^segt[2*v+1];
}
 
 
 
 
int main()
{   
    ll n,m;
    read(n,m);
    n=pow(2,n);
    arr10=vll(n+1);
    for1(i,n){
        read(arr10[i]);
    }
    ll a=log2((int)n);
    a=a%2;
    ini(segt,0);
    buildSegt(1,1,n,a);
 
    while(m--){
        ll pos,val;
        read(pos,val);
        point_update(1,1,n,pos,val,a);
        cout<<segt[1]<<"\n";
    }
}
