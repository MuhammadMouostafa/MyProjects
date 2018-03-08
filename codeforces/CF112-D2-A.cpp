#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<iomanip>

int main()
{
	//cout<<fixed<<setprecision(4);
	
	
	string a,s;
	cin>>a;
	cin>>s;

	for(int i=0; i<a.size(); i++)
		{
			if(a[i]<=90)
				a[i]+=32;
	
			if(s[i]<=90)
				s[i]+=32;
		}


		if(a<s)
			cout<<-1;
		else if(s<a)
			cout<<1;
		else cout<<0;

	//system("pause");
	return 0;
}