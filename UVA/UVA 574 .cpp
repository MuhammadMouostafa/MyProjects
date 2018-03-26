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
int n, m,a[20],s[20],f=0;
set< vector<int> >st;
void foo(int i,int sum){
	if (i == n){
		if (sum == m){
			f++;
			vector<int> g;
			lp(j, n)
			if (s[j]){
				g.push_back(a[j]);
			}
			if (st.count(g) == 0){
				st.insert(g);
			}
		}
		return;
	}
	s[i] = 0;
	foo(i + 1, sum);
	s[i] = 1;
	foo(i + 1, sum + a[i]);

}
void pr(){
	if (st.size() == 0)
		return;
	vector<int> g = *st.begin();
	st.erase(g);
	pr();
	lp(j, g.size())
	if (j)
		cout << '+' << g[j];
	else cout << g[j];
	cout << endl;
}
int main(){
	fast();
	cin >> m >> n;
	while (n){
		f = 0;
		st.clear();
		lp(i, n)
			cin >> a[i];
		cout << "Sums of " << m << ":" << endl;
		foo(0, 0);
		pr();
		if (f == 0)
			cout << "NONE" << endl;
		cin >> m >> n;
	}
	//system("pause");
	return 0;
}