//https://www.codechef.com/LTIME72B/problems/GRIDTOUR

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

bool f(int n, int kn)
{
    if((n==1)||(kn==1))
        return true;
    else if(kn==0)
        return false;
    if(__gcd(n, kn)>1)
        return false;
    else
        return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        if(f(n, k%n)&&f(m, k%m))
            cout<<n*m<<endl;
        else
            cout<<"-1\n";
    }
    return 0;
}