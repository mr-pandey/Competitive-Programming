//https://www.codechef.com/LTIME72B/problems/DPS

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map<char, int> m;
        for(auto x:s)
            m[x]++;
        int c=0;
        for(auto x:m)
            if(x.second%2)
                c++;
        if(((int)s.size())&1)
        {
            if(c>3)
                cout<<"!DPS\n";
            else
                cout<<"DPS\n";
        }
        else
        {
            if(c==2)
                cout<<"DPS\n";
            else
                cout<<"!DPS\n";
        }
        
    }
    return 0;
}