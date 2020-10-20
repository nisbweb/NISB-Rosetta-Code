

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iomanip>
#define ll long long
#define mod 1000000007
using namespace std;
const int INF = 2e9 + 1;

//slow solution
ll get_ans(vector<ll>& hcost,ll i,ll j,ll val,ll m)
{
	//base case
	if(i==j)
	{
		return val;
	}

	if(val <= m)
	{
		return val;
	}

	ll sa1=get_ans(hcost,i+1,j,val-hcost[i],m);
	ll sa2=get_ans(hcost,i,j-1,val-hcost[j],m);

	return max(sa1,sa2);

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


ll n,m,ans=-1;
cin>>n>>m;

vector<ll> hcost(n,0);

for(ll i=0;i<n;i++)
{
	cin>>hcost[i];
}


//fast solution
ll fast,slow;

ll val=hcost[0];

fast=slow=0;

while( fast<n-1 || slow<n-1 )
{

	//one of the terminating cond
	if(val==m)
	{
		ans=val;
		break;
	}

	if(val<m && fast<n-1)
	{
		fast++;
		val+=hcost[fast];
		if(val < m)
		{
			ans=max(ans,val);
		}
	}
	else
	if(val>m && slow<fast)
	{
		val-=hcost[slow];
		slow++;
		if(val <= m)
		{
			ans=max(ans,val);
		}
	}
	else
	if(val>m && slow==fast)
	{
		fast++;
		val+=hcost[fast];
		if(val <= m)
		{
			ans=max(ans,val);
		}		
	}
	else
	if(val<m && fast==n-1)
	{
		break;
	}


}

cout<<ans<<endl;

	return 0;
}
