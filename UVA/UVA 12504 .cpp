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
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
void foo(map<string, string> &mp, string a){
	string ky, vl;
	bool f = 1;
	for (int i = 1; i < a.size(); i++){
		if (f){
			if (a[i] != ':')
				ky.push_back(a[i]);
			else f = 0;
		}
		else{
			if (a[i] != ','&&a[i] != '}')
				vl.push_back(a[i]);
			else {
				f = 1;
				mp[ky] = vl;
				ky = "";
				vl = "";
			}
		}
	}
}
int main(){
	fast();
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string a, s;
		getline(cin,a);
		getline(cin,s);
		map<string, string> mp1, mp2;
		foo(mp1, a);
		foo(mp2, s);
		map<string, string> ::iterator it,it2;
		vector<string> plus, minus, chan;
		for (it = mp1.begin(); it != mp1.end(); it++){
			if (it->second!="0"&&(mp2[it->first] == "" || mp2[it->first] == "0"))
				minus.push_back(it->first);
			else if (it->second != mp2[it->first])
				chan.push_back(it->first);
		}
		for (it2=mp2.begin(); it2 != mp2.end(); it2++){
			if (it2->second != "0" && (mp1[it2->first] == "" || mp1[it2->first] == "0"))
				plus.push_back(it2->first);
		}
		int x = 1;
		if (plus.size()){
			x = 0;
			cout << '+';
			sort(plus.begin(),plus.end());
			rep(i, plus)
				cout << plus[i], i + 1 == plus.size() ? cout << endl : cout << ',';
		}
		if (minus.size()){
			cout << '-';
			x = 0;
			sort(minus.begin(), minus.end());
			rep(i, minus)
				cout << minus[i], i + 1 == minus.size() ? cout << endl : cout << ',';
		}
		if (chan.size()){
			x = 0;
			cout << '*';
			sort(chan.begin(), chan.end());
			rep(i, chan)
				cout << chan[i], i + 1 == chan.size() ? cout << endl : cout << ',';
		}
		if (x)
			cout << "No changes" << endl;
		cout << endl;
	}
	stop();
	return 0;
}