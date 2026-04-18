#include<bits/stdc++.h>
using namespace std;
//八皇后问题：对角线标号映射、深搜裁枝 
//mainDiagonal:1-n<=r-c（常数）<=n-1	1<=r-c+n<=2n-1
//antiDiagonal:2=r+c<=2n				1<=r+c-1<=2n-1
vector<int> res;
bool col[14],diag1[26],diag2[26];//2n-1
int n,tot=0;
void dfsEightQueen(int r){//找出第r行结果 
	if(r==n+1){
		if(tot<3){
			for(auto ans:res)cout<<ans<<" ";
			cout<<"\n";
		}tot++;
		return;
	}
	for(int c=1;c<=n;c++){
		int d1=r-c+n,d2=r+c-1;
		if(!col[c] && !diag1[d1] && !diag2[d2]){
			col[c]=diag1[d1]=diag2[d2]=true;
			res.push_back(c);
			dfsEightQueen(r+1);
			res.pop_back();
			col[c]=diag1[d1]=diag2[d2]=false;
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	dfsEightQueen(1);
	cout<<tot;
	return 0;
}
