#include<map>
#include<iostream>
using namespace std;

#define int long long
#define M 1000000007

map<int, int> F;

int f(int n)
{
	if (F.count(n))
        return F[n];
	int k=n/2;
	if(n%2==0)
		return F[n]=(f(k)*f(k)+f(k-1)*f(k-1))%M;
	else
		return F[n]=(f(k)*f(k+1)+f(k-1)*f(k))%M;
}

int main()
{
	int n;
	F[0]=F[1]=1;
	while (cin >> n)
	cout << (n==0 ? 0 : f(n-1)) << endl;
    return 0;
}