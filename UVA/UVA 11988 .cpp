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
	string s;
	while (getline(cin, s)){
		string a="",x="";
		int f=0;  ///asd[gfh[[dfh]hgh]fdfhd[dfg[d]g[d]dg    //dddfgdfhgfhasdhghfdfhdgdg
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '['){
				if (f){
					a = x + a;
				}
				x = "";
				f=1;
			}
			else if (s[i] == ']'){
				if (f){
					a = x + a;
				}
				x = "";
				f=0;
			}
			else { 
				if (!f)
					a += s[i];
				else
					x += s[i];
			}
		}
		if (f)
			a = x + a;
		cout << a << "\n";
	}
	return 0;
}