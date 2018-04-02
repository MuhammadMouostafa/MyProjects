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
vector<int> a;
bool dp(int i, int sum){
	if (i == 5){
		return sum == 23;
	}
	return dp(i + 1, sum + a[i]) || dp(i + 1, sum * a[i]) || dp(i + 1, sum - a[i]);
}
int main(){
	fast();
	int x = 0;
	a = vector<int>(5);
	lp(i, 5)
		cin >> a[i], x |= a[i];
	while (x){
		bool s = dp(1, a[0]);
		sort(a.begin(), a.end());
		do{
			s = s || dp(1, a[0]);
		} while (next_permutation(a.begin(), a.end()));
		if (s)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
		x = 0;
		lp(i, 5)
			cin >> a[i], x |= a[i];
	}
	//	system("pause");
	return 0;
}