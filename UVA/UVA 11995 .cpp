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
	int n;
	while (cin>>n){
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		int t = 0;
		int a1 = 1, a2 = 1, a3 = 1;
		while (n--){
			int x, y;
			cin >> x >> y;
			if (x == 1){
				s.push(y);
				q.push(y);
				p.push(y);
				t++;
			}
			else {
				if (t){
					int s1, s2, s3;
					s1 = s.top();
					s2 = q.front();
					s3 = p.top();
					s.pop();
					q.pop();
					p.pop();
					if (s1 != y)
						a1 = 0;
					if (s2 != y)
						a2 = 0;
					if (s3 != y)
						a3 = 0;
					t--;
				}
				else{
					a1 = a2 = a3 = 0;
				}
			}
		}
		if (a1 + a2 + a3 == 0)
			cout << "impossible" << endl;
		else if (a1 + a2 + a3 >1)
			cout << "not sure" << endl;
		else if (a1)
			cout << "stack" << endl;
		else if (a2)
			cout << "queue" << endl;
		else cout << "priority queue" << endl;
	}
	//system("pause");
	return 0;
}
