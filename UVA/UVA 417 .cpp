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
	vector<string> s1,s2,s3,s4,s;
	int y = 0;
	lp(i, 26){
		string x;
		x.push_back('a' + i);
		s.push_back(x);
		for (int j = i+1; j < 26; j++){
			string x1=x;
			x1.push_back('a' + j);
			s1.push_back(x1);
			for (int l = j+1; l < 26; l++){
				string x2=x1;
				x2.push_back('a' + l);
				s2.push_back(x2);
				for (int h = l+1; h < 26; h++){
					string x3=x2;
					x3.push_back('a' + h);
					s3.push_back(x3);
					for (int t = h+1; t < 26; t++){
						string x4=x3;
						x4.push_back('a' + t);
						s4.push_back(x4);
					}
				}
			}
		}
	}
	sort(s.begin(),s.end());
	map<string, int> mp;
	rep(i, s)
		mp[s[i]] = i + 1;
	rep(i, s1)
		mp[s1[i]] = i + 1 + s.size();
	rep(i, s2)
		mp[s2[i]] = i + 1 + s.size() + s1.size();
	rep(i, s3)
		mp[s3[i]] = i + 1 + s.size() + s1.size() + s2.size();
	rep(i, s4)
		mp[s4[i]] = i + 1 + s.size() + s1.size() + s2.size() + s3.size();
	string a;
	while (cin >> a){
		cout << mp[a] << endl;
	}
	stop();
	return 0;
}
