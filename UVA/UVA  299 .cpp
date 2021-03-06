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
ll cun = 0;
void merge(int A[], int start, int mid, int end) {
	int p = start, q = mid + 1;
	int a[205];
	for (int i = start; i <= end; i++)
		a[i] = A[i];
	for (int i = start; i <= end; i++) {
		if (p > mid)
			A[i] = a[q++];
		else if (q > end)
			A[i] = a[p++];
		else {
			if (a[p] < a[q])
				A[i] = a[p++];
			else
				A[i] = a[q++], cun += q - i - 1;
		}
	}
}
void merge_sort(int A[], int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(A, start, mid);
		merge_sort(A, mid + 1, end);
		merge(A, start, mid, end);
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
		int A[205];
		lp(i, n)
			cin >> A[i];
		merge_sort(A, 0, n - 1);
		cout << "Optimal train swapping takes "<<cun<<" swaps.";
		//if (t)
			cout << endl;
	}
	//system("pause");
	return 0;
}