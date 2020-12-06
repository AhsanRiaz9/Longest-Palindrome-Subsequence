#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int findLongestPalindrome(string st)
{
	
	int n=st.length();
	char * s = new char [n+2];
	for(int i=1;i<=n;i++)
	{
		s[i]= st[i-1];
	}
	s[n+1]='\0';
	int ** arr = new int * [n+1];
	for(int i=0;i<=n;i++)
	{
		arr[i]=new int[n+1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)	
		{
			if(i==0 || j==0)
			{
				arr[i][j]=0;
			}
			if(i==j)
			{
				arr[i][j]=1;
			}
			else
			{
				arr[i][j]=0;
			}
		}
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			if(s[i]!=s[j])
			{
				if(arr[i+1][j]>arr[i][j-1])
				{
					arr[i][j]=arr[i+1][j];
				}
				else
				{
					arr[i][j]=arr[i][j-1];
				}
			}
			else
			{
				arr[i][j] = 2 + arr[i+1][j-1];	
			}
		}	
	}
	s[0]=' ';
	for(int i=0;i<=n;i++)
	{
		cout<<s[i]<<'\t';
	}
	for(int i=1;i<=n;i++)
	{
		cout<<'\n'<<s[i]<<"\t";
		for(int j=1;j<=n;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
	}
	cout<<'\n';
	return arr[1][n];
}

int main()
{
	
	string s;
	cout<<"Enter string: \t";
	cin>>s;
	int max = findLongestPalindrome(s);
	cout<<"\nLongest Palindrome Subsequence :\t"<<max;
	return 0;
}
