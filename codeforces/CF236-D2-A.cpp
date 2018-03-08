#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
int a[26];
int main()
{
	
	string s;	

	cin>>s;

	for(int i=0; i<s.size(); i++)
			a[s[i]-'a']=1;




	int sum=0;
	for(int i=0; i<26; i++)
		sum+=a[i];


	if(sum%2==0)
		cout<< "CHAT WITH HER!";
	else
		cout<< "IGNORE HIM!";

	
//	system("pause");
	return 0;
}