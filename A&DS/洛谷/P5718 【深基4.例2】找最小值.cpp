#include<bits/stdc++.h>
using namespace std;
int main(){//min *min_element sort
	int n,a,ans=1000;//initialize
	cin>>n;
	while(n-- && cin>>a)ans=min(a,ans);
	cout<<ans;
	return 0;
}
