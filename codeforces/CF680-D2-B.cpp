#define _CRT_SECURE_NO_WARNINGS
//#define __builtin_popcount__popcnt
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
//#define __builtin_popcount__popcnt

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
	int n,m;
	cin >> n >> m;
	vector<int> a,s;
	lp(i, m-1){
		int f;
		cin >> f;
		a.push_back(f);
	}
	int sum ;
	cin >> sum;
	for (int i = m; i < n; i++){
		int f;
		cin >> f;
		s.push_back(f);
	}
	reverse(a.begin(),a.end());
	lp(i, min(s.size(),a.size()))
	if (a[i] == s[i])
		sum += 2 * a[i];
	int j = min(s.size(), a.size());
	while (j < s.size()){
		sum += s[j++]; 
	}
	while (j < a.size()){
		sum += a[j++];
	}
	cout << sum;
	//system("pause");
	return 0;
}