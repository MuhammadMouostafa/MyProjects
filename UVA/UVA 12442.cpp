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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main(){
	fast();
	int t;
	cin >> t;
	for (int l = 1; l <= t; l++){
		int n;
		cin >> n;
		vector< vector<int> >a(n, vector < int>());
		lp(i, n){
			int s, x;
			cin >> s >> x;
			s--;
			x--;
			a[s].push_back(x);
		}
		vector<bool> v(n, 0);
		int mx = 0,f=0;
		lp(i,n)
		if (!v[i]){
			vector<bool> v2(n, 0);
			queue<int> q;
			q.push(i);
			int sum = 0;
			while(q.size()){
				sum++;
				int s = q.front();
				q.pop();
				v[s] = 1;
				v2[s] = 1;
				rep(j, a[s]){
					if (!v2[a[s][j]])
						q.push(a[s][j]);
				}
			}
			if (sum > mx){
				mx = sum;
				f = i;
			}
		}
		cout << "Case "<<l<<": "<<f+1 << endl;
	}
	stop();
	return 0;
}
