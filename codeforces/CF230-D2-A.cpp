#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <deque>
#include <fstream>


#define  all(v)         ((v).begine()),((v).end())
#define  sz(v)	        ((int)(v).size())
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  lpi(i,j,n)     for(int i=j; i<n; i++)
#define  lpd(i,j,n)     for(int i=j; i>=n; i--)
const double E = 1e-12;

typedef  long long ll;
typedef  long double ld;
/*typedef  vector<int> vi;
typedef  vector<char> vc;
typedef  vector<string> vs;
typedef  vector<bool> vb();
*/
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	//freopen("001test.txt", "w", stdout);
	fast();
	int n, m;
	cin >> m >> n;
	vector< vector<int> > a(n, vector<int>(2));
	lp(i, n)
	{
		cin >> a[i][0];
		cin >> a[i][1];
		a[i][1] *= -1;
	}
	sort(a.begin(),a.end());
	lp(i, n)
		a[i][1] *= -1;
	int s = 1;
	lp(i, n)if (m > a[i][0])
		m += a[i][1];
	else s = 0;
	///cout << m << endl;
	if (s)
		cout << "YES";
	else cout << "NO";
//	system("pause");
	return 0;
}