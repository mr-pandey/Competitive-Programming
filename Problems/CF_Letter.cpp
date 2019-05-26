//https://codeforces.com/contest/180/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define M 998244353963

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    vector<int> prefix(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        if(isupper(s[i-1]))
            prefix[i]=prefix[i-1]+1;
        else
            prefix[i]=prefix[i-1];
    }
    int ans=LLONG_MAX;
    for(int i=0; i<=n; i++)
    {
        int up=i-prefix[i];
        int down=prefix[n]-prefix[i];
        ans=min(ans, up+down);
    }
    cout<<ans<<endl;
    return 0;
}