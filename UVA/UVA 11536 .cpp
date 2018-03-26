#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
#define cini(n)         scanf("%d",&n)
#define cinl(n)         scanf("%lld",&n)
#define cind(n)         scanf("%Lf",&n)
#define cinf(n)         scanf("%f",&n)   
#define cinc(n)         scanf("%c",&n)
#define cins(n)         scanf("%s",&n)
#define cinsl(n)        cin.ignore(), scanf("%[^\n]%*c",n)
#define couti(n)         printf("%d",n)
#define coutl(n)         printf("%lld",n)
#define coutd(n)         printf("%Lf",n)
#define coutdd(n)         printf("%.9l f",n)
#define coutf(n)         printf("%f",n)   
#define coutc(n)         printf("%c",n)
#define coutarc(n)         printf("%s",n)
#define couts(n)         printf("%s",n.c_str())
#define coutln()         printf("\n")   
#define coutsp(n)         printf(" ")


typedef  long long ll;
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main(){
	fast();
	int t;
	cin >> t;
	for (int h = 1; h <= t; h++){
		int n, m, s;
		cin >> n >> m >> s;
		vector<int> a(n);
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		for (int i = 3; i < n; i++)
			a[i] = (a[i-1]+a[i-2]+a[i-3]) % m+1;
		int sum = 0, mn = n+1, i = 0, j = 0;
		int f[1005] = { 0 };
		while (j < n){
			if (f[a[j]] == 0&&a[j]<=s)
				sum++;
			f[a[j]]++;
			while (sum >= s){
				mn = min(mn, j - i + 1);
				f[a[i]]--;
				if (f[a[i]] == 0 && a[i] <= s)
					sum--;
				i++;
			}

			j++;
		}
		if (mn==n+1)
			cout << "Case " << h << ": " << "sequence nai" << endl;
		else 
			cout <<"Case "<<h<<": "<< mn<<endl;
	}
	//system("pause");
	return 0;
}