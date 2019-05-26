//https://codeforces.com/contest/797/problem/B

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
    int n, ans=0, minodd=M, maxodd=-M;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>0)
        {
            ans+=arr[i];
            if(arr[i]&1)
                minodd=min(minodd, arr[i]);
        }
        else
        {
            if(abs(arr[i])&1)
                maxodd=max(arr[i], maxodd);
        }
    }
    if(ans&1)
        cout<<ans;
    else
        cout<<ans-min(minodd, -1*maxodd);
    return 0;
}