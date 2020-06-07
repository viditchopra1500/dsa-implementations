int main()
{fast;
        ll n,k;
        read(n,k);
        ll a[n],b[n];
        read(a,n);
        read(b,n);
        ll dp[n][2],c=0;
        dp[0][0]=a[0];                                 //whats the ans if n=0 and u start from 1 train
        dp[0][1]=b[0];                                 //whats the ans if n=0 and u start from 2 train  
        for1(i,n-1){
            forn(j,2){
                if(j==0)
                dp[i][j]=min(dp[i-1][j]+a[i],dp[i-1][1-j]+a[i]+b[i]);
            else
                dp[i][j]=min(dp[i-1][j]+b[i],dp[i-1][1-j]+a[i]+b[i]);
            }
            ll mi=min(dp[i][0],dp[i][1]);
            if(mi>k){
                c=i;break;
            }
        }
        if(c)
            cout<<c<<" "<<min(dp[c-1][0],dp[c-1][1]);
        else
        cout<<n<<" "<<min(dp[n-1][0],dp[n-1][1]);
    }
