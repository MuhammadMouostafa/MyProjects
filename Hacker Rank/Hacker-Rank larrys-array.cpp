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
vector<int> A;
int cun = 0;
void merge(int start, int mid, int end) {
	int p = start, q = mid + 1;
	int k = 0;
	vector<int> a(A.size());
	for (int i = start; i <= end; i++) {
		if (p > mid)
			a[k++] = A[q++];

		else if (q > end)
			a[k++] = A[p++];

		else {
				if (A[p] < A[q])
					a[k++] = A[p++];

				else
					a[k++] = A[q++],cun+=q-i-1;
			}
	}
	for (int p = 0; p< k; p++) {
		A[start++] = a[p];
	}
}
void merge_sort(int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		int n;
		cun = 0;
		cin >> n;
		A = vector<int>(n);
		lp(i, n)
			cin >> A[i];
		merge_sort(0, n - 1);
		if (cun % 2 == 0)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}