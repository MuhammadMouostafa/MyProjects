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
	string a,s;
	getline(cin,a);
	rep(i, a){
		if (i&&a[i] != ' ' && (a[i] > 'z' || a[i] < 'a') && a[i - 1] == ' ')
			swap(a[i], a[i - 1]),i-=2;
	}
	rep(i, a){
		if (i&&a[i] == ' '&&a[i - 1] == ' ');
		else s += a[i];
	}
	if (s[0] == ' ')
		s.erase(0,1);
	a = s;
	s = "";
	rep(i,a)
	if (a[i]!=' '&&(a[i] > 'z' || a[i] < 'a')&&i!=(int)(a.size()-1)){
		s += a[i];
		if (a[i + 1] != ' ')
			s += ' ';
	}
	else s+= a[i];
	if (s[s.size()-1] == ' ')
		s.erase(s.size()-1, 1);
	cout << s;
	//system("pause");
	return 0;
}