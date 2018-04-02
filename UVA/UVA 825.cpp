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
int n, m;
ll sum;
vector< vector<bool> > a;
bool valid(int i, int j){ return i >= 0 && i < n&&j >= 0 && j < m && a[i][j]; }
void dp(int i, int j){
	if (!valid(i, j))
		return;
	if (i == n - 1 && j == m - 1){
		sum++;
		return;
	}
	a[i][j] = 0;
	dp(i+1,j);
	dp(i, j+1);
	a[i][j] = 1;
}
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		sum = 0;
		cin >> n >> m;
		a =vector< vector<bool> >(n, vector<bool>(m,1));
		cin.ignore();
		lp(i, n){
			string s;
			getline(cin, s);
			stringstream ss;
			ss << s;
			vector<int> c;
			int x;
			while (ss >> x){
				x--;
				c.push_back(x);
			}
			for (int j = 1; j < c.size(); j++){
				a[c[0]][c[j]] = 0;
			}
		}
		dp(0, 0);
		cout << sum << endl;
		if (t)
			cout << endl;
	}
	stop();
	return 0;
}