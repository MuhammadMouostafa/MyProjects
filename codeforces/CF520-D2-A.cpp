#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int s[58];
int main()
{
	int n;
	cin>>n;
	string a;
	cin>>a;

	for(int i=0; i<a.size(); i++)
		s[a[i]-'A']=1;
	

	int sum=0;
	for(int i=0,j=32; j<58; i++,j++)
		if(s[i]==1 || s[j]==1)
			sum++;
	

	if(sum==26)
		cout<<"YES";
	else cout<<"NO";


//	system("pause");
	return 0;
}