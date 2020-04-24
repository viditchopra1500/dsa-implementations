const int fx[] = {0, +1, 0, -1};
const int fy[] = {-1, 0, +1, 0};
void bfs(ll r1,ll c1)
{
    deque<pll> q;
    q.push_back({r1,c1});
    d[r1][c1]=0;
    while(!q.empty())
    {
        pll v = q.front();
        q.pop_front();
        ll x=v.first,y=v.second;
        forn(i,4)
        {
            ll x1=x+fx[i],y1=y+fy[i];
            if(x1>=0&&y1>=0&&x1<r&&y1<c){
            if(mp[x1][y1]==mp[x][y]){
                if(d[x1][y1]>d[x][y]){
                q.push_front({x1,y1});
                d[x1][y1]=d[x][y];
            }}
            else{
                if(d[x1][y1]>d[x][y]+1){
                q.push_back({x1,y1});
                d[x1][y1]=d[x][y]+1;
            }
            }
        }
        }
    }
}
int main()
{fast;ll t;
while(t--){
    read(r,c);
    mp=vector<vector<char>>(r,vector<char>(c));
    forn(i,r){
        forn(j,c){
            read(mp[i][j]);
        }
    }
    d=vvll(r,vll(c,INF));
    bfs(0,0);
    cout<<d[r-1][c-1]<<"\n";
}}
