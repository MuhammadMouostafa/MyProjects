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
	int n, m;
	cin >> m >> n;
	while (n||m){
		vector< vector<int> > a(n, vector<int>(2));
		lp(i, n){
			int s, r;
			cin >> s >> r;
			a[i][0] =max(0,s - r);
			a[i][1] = -1*(s + r);
		}
		sort(a.begin(),a.end());
		lp(i, n)
			a[i][1] *= -1;
		int f = 1;
		if (a[0][0] > 0)
			f = 0;
		int mx = a[0][1];
		for (int i = 1; i < n; i++){
			if (a[i][0]>mx){
				f = 0;
				break;
			}
			mx = max(mx, a[i][1]);
		}
			if (f == 0||mx<m)
				cout << -1 << endl;
			else{
				int sum=0;
				lp(i, n){
					if (a[i][1] >= m){
						sum += n - i - 1;
						n= i + 1;
						break;
					}
				}
				lp(i, n-1){
					int s=0,x,j=i+1;
					while (j < n&&a[j][0] <= a[i][1]){
						s = max(s, a[j][1]);
						j++;
					}
					j--;
					sum += j - i-1;
					a[j][1] = s;
					i = j - 1;
				}
				cout << sum<<endl;
				//lp(i, n){
					//cout << a[i][0] << " " << a[i][1] << "    ";
			//}
		
		}
			cin >> m >> n;
	}
//	cout << endl;
//	system("pause");
	return 0;
}