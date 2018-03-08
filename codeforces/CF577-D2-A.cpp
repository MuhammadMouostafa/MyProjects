#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int main()
{
	int n,m,sum=0;
	cin>>n>>m;

	for(int i=1; i<=n; i++)
		if(m%i==0 && m/i<=n)
			sum++;


	cout<<sum;


//	system("pause");
	return 0;
}