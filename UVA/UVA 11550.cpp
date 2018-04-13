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
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
			vector< vector<int> >a(n, vector<int>(m));
			lp(i, n)
				lp(j, m)
				cin >> a[i][j];
			int mx=0;
			lp(i, n){
				int s = 0;
				lp(j, m)
					s += a[i][j];
				mx = max(mx, s);
			}
			int f = 1;
			lp(j, m){
				int s = 0;
				lp(i, n)
					s += a[i][j];
				if (s != 2)
					f = 0;
			}
			vector< vector<int> >r(m, vector<int>(n));
			lp(i, n)
				lp(j, m)
				r[j][i] = a[i][j];
			lp(i,m)
			for (int j = i + 1; j < m; j++){
				if (r[i] == r[j])
					f = 0;
			}
			//cout << mx << " " << f << endl;
			if (f&&n-1 >= mx)
				cout << "Yes" << endl;
			else cout << "No" << endl;
	}
	stop();
	return 0;
}