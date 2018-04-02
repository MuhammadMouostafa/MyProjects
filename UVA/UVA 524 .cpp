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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
vector<int> a,v;
int n,s[100];
void foo(int i){
	if (i == n){
		if (s[a[0] + a[n - 1]] == 1){
			cout << endl;
			lp(j, n-1)
				cout << a[j] << " ";
			cout <<a[n-1];
		}
		return;
	}
	for (int j = 2; j <= n; j++){
		if (v[j] == 0&&s[j+a[i-1]]==1){
			v[j] = 1;
			a[i] = j;
			foo(i + 1);
			v[j] = 0;
		}
	}

}
int pmr(int m){
	for (int i = 2; i < m; i++)
	if (m%i == 0)
		return 0;
	return 1;
}
int main(){
	fast();
	for (int i = 1; i < 90; i++)
		s[i] = pmr(i);
	int l = 0;
		while(cin >> n){
		a = vector<int>(n+5);
		v = vector<int>(n + 5,0);
		if (l)
			cout << endl;
		cout << "Case " << ++l <<":";
		v[1] = 1;
		a[0] = 1;
		foo(1);
		cout << endl;
	}
	stop();
	return 0;
}