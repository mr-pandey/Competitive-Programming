//https://codeforces.com/contest/987/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define M 998244353963
#define minn(x, y, z) min(x, min(y, z))

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans=M;
    cin>>n;
    int s[n], c[n];
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<n; i++)
        cin>>c[i];
    for(int j=1; j<n-1; j++)
    {
        int sum=c[j], tmp=M;
        for(int i=0; i<j; i++)
            if(s[i]<s[j])
                tmp=min(tmp, c[i]);
        sum+=tmp;
        tmp=M;
        for(int k=j+1; k<n; k++)
            if(s[j]<s[k])
                tmp=min(tmp, c[k]);
        sum+=tmp;
        ans=min(ans, sum);
    }
    if(ans>=M)
        ans=-1;
    cout<<ans;
    return 0;
}