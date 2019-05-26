//https://www.codechef.com/LTIME72B/problems/CV

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
    set<char> st={'a', 'e', 'i', 'o', 'u'};
    while(t--)
    {
        int n, c=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0; i<n-1; i++)
            if((st.find(s[i])==st.end())&&(st.find(s[i+1])!=st.end()))
                c++;
        cout<<c<<endl;
    }
    return 0;
}