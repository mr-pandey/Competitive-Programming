//https://codeforces.com/contest/538/problem/B

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
    vector<int> v;
    while(n>0)
    {
        v.pb(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
    vector<int> ans;
    for(int i=0; i<9; i++)
    {
        int tmp=0;
        for(int j=0; j<v.size(); j++)
        {
            if(v[j]>0)
            {
                v[j]--;
                tmp=(tmp*10)+1;
            }
            else
                tmp*=10;
        }
        if(tmp>0)
            ans.pb(tmp);
    }
    cout<<(int)ans.size()<<endl;
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}