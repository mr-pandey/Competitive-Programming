//https://codeforces.com/contest/698/problem/A

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define M 998244353
#define minn(x, y, z) min(x, min(y, z))

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)
        cin>>x;
    int dp[n][3];
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            dp[i][j]=LLONG_MAX;
    dp[0][0]=1;
    if((arr[0]==1)||(arr[0]==3))
        dp[0][1]=0;
    if((arr[0]==2)||(arr[0]==3))
        dp[0][2]=0;
    for(int i=1; i<n; i++)
    {
        dp[i][0]=1+minn(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        if((arr[i]==1)||(arr[i]==3))
            dp[i][1]=min(dp[i-1][0], dp[i-1][2]);
        if((arr[i]==2)||(arr[i]==3))
            dp[i][2]=min(dp[i-1][0], dp[i-1][1]);
    }
    cout<<minn(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
    return 0;
}