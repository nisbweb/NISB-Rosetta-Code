#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w;
		cin>>w;
		string s;
		cin>>s;
		int a[7];
		for(int i=0;i<7;i++)
		{
			a[i]=4;
		}
		if(s=="mon")
		{
			if(w==30)
			{
				a[0]++;
				a[1]++;
			}
			if(w==31)
			{
				a[0]++;
				a[1]++;
				a[2]++;
			}	
		}
		else if(s=="tues")
		{
			if(w==30)
			{
				a[1]++;
				a[2]++;
			}
			if(w==31)
			{
				a[1]++;
				a[2]++;
				a[3]++;
			}
		}
		else if(s=="wed")
		{
			if(w==30)
			{
				a[2]++;
				a[3]++;
			}
			if(w==31)
			{
				a[2]++;
				a[3]++;
				a[4]++;
			}
		}
		else if(s=="thurs")
		{
			if(w==30)
			{
				a[3]++;
				a[4]++;
			}
			if(w==31)
			{
				a[3]++;
				a[4]++;
				a[5]++;
			}
		}
		else if(s=="fri")
		{
			if(w==30)
			{
				a[4]++;
				a[5]++;
			}
			if(w==31)
			{
				a[4]++;
				a[5]++;
				a[6]++;
			}
		}
		else if(s=="sat")
		{
			if(w==30)
			{
				a[5]++;
				a[6]++;
			}
			if(w==31)
			{
				a[5]++;
				a[6]++;
				a[7]++;
			}
		}
		else if(s=="sun")
		{
			if(w==30)
			{
				a[6]++;
				a[0]++;
			}
			if(w==31)
			{
				a[6]++;
				a[0]++;
				a[1]++;
			}
		}
		for(int i=0;i<7;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}