#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
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
	cin >> s;
	int v[26],f[26][26];
	char a[26][26];
	lp(i, 26)
		cin >> v[i];
	lp(i,26)
		lp(j, 26){
			f[i][j] = 1e9;
			lp(l, 26){
				int sum = abs(v[l]-v[j]) + abs(v[l]-v[i]);
				if (sum < f[i][j]){
					f[i][j] = sum;
					a[i][j] = 'a' + l;
				}
			}
		}
	int s1 = -1, s2=s.size();
	rep(i, s)
	if (s[i] != '?'){
		if (s1 == -1)
			s1 = i;
		s2 = i;
	}
	if (s1 == -1){
		rep(i, s)
			s[i] = 'a';
	}
	else{
		lp(i, s1)
			s[i] = a[s[s1] - 'a'][s[s1] - 'a'];
		for (int i = s2 + 1; i < s.size(); i++)
			s[i] = a[s[s2] - 'a'][s[s2] - 'a'];

	}
	for (int i = 1; i < (int)s.size() - 1; i++)if(s[i]=='?'){
		int j = i;
		while (s[j] == '?')
			j++;
		int t = i; 
		while (t<j)
			s[t] = a[s[i-1] - 'a'][s[j] - 'a'],t++;
		i = j;
	}
	ll sum = 0;
	lp(i, s.size()-1)
		sum += f[s[i + 1] - 'a'][s[i] - 'a'];
	cout << sum << endl << s;
//	system("pause");
	return 0;
}