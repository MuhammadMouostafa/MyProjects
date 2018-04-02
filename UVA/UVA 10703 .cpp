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
	int n, m, h;
	cin >> n >> m >> h;
	while (n||m||h){
		vector< vector<int> >a(n + 5, vector<int>(m + 5, 0));
		while (h--){
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			a[x1][y1]++;
			a[x2 + 1][y1]--;
			a[x1][y2 + 1]--;
			a[x2 + 1][y2 + 1]++;
		}
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] += a[i - 1][j];

		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] += a[i][j-1];

		int sum = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		if (!a[i][j])
			sum++;
		if (sum == 0)
			cout << "There is no empty spots." << endl;
		else if (sum == 1)
			cout << "There is one empty spot." << endl;
		else cout <<"There are "<< sum <<" empty spots."<< endl;
		cin >> n >> m >> h;
	}
	//system("pause");
	return 0;
}