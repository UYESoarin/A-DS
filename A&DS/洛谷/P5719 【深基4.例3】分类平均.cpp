#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	double ansA,ansB;
	int cntA,cntB;
	ansA=ansB=cntA=cntB=0;
	for(int i=1;i<=n;i++){
		if(i%k)ansA+=i,cntA++;
		else ansB+=i,cntB++;
	}
	ansA/=cntA,ansB/=cntB;
	cout<<fixed<<setprecision(1)<<ansB<<" "<<ansA;
	return 0;
}
