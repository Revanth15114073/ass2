#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;



class avoid
{
	public:
	long long No_ways(int w, int h,vector < pair<int,int> > v[2]);
};

int valid(int a,int b,int c,int d,vector < pair<int,int> > v[2])
{
	int n=v[0].size();
	for(int i=0;i<n;i++)
	{
		if(v[0][i].first==a&&v[0][i].second==b&&v[1][i].first==c&&v[1][i].second==d)
		return 1;
		if(v[0][i].first==c&&v[0][i].second==d&&v[1][i].first==a&&v[1][i].second==b)
		return 1;
	}
	return 0;
}

long long avoid::No_ways(int w, int h,vector < pair<int,int> > v[2])
{
	long long  dp[h+1][w+1];
	for(int i=h;i>=0;i--)
	{
		for(int j=w;j>=0;j--)
		{
			long long  ans=0;
			if(j<w)
			{
				if(valid(i,j,i,j+1,v)==0)
				ans+=dp[i][j+1];
			}
			if(i<h)
			{
				if(valid(i,j,i+1,j,v)==0)
				ans+=dp[i+1][j];
			}
			if(j==w&&i==h)
			ans=1;
			dp[i][j]=ans;
		}
	}
	return dp[0][0];
}

int main() {
	int w,h;
	cin>>w>>h;
	int k;
	int n=0;
	vector < pair<int,int> > v[2];
	while(cin>>k)
	{
		if(k<0)
		break;
		int p,q,r;
		cin>>p>>q>>r;
		v[0].push_back(make_pair(k,p));
		v[1].push_back(make_pair(q,r));
		n++;
	}
	avoid xyz;
	cout<<xyz.No_ways(w,h,v);
	return 0;
}
