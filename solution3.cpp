#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
int Key(std::vector<int> &v, int l, int n, int key) {
    while (n-l > 1) 
    {
    	int m = l + (n-l)/2;
    	if (v[m] >= key)
        n = m;
    	else
        l = m;
    }
    return n;
}
 
int LIS(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
    vector<int> end(v.size(), 0);
    int l = 1; 
    end[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < end[0])
            end[0] = v[i];
        else if (v[i] > end[l-1])
            end[l++] = v[i];
        else
            end[Key(end, -1, l-1, v[i])] = v[i];
    }
    return l;
}
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[n+i]=a[i];
		}
		int b=0;
		for(int i=0;i<n;i++)
		{
			vector <int> v(a+i,a+i+n);
			b=max(b,LIS(v));
		}
		cout<<b<<endl;
	}
	return 0;
}