#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Person{
	int _id,_t;
	Person(int id,int t):_id(id),_t(t){}
};
bool cmp(const Person& p1,const Person& p2){
	if(p1._t==p2._t)return p1._id<p2._id;
	return p1._t<p2._t;
}//pair<int,int> {t,id}
int main(){
	int n;cin>>n;
	vector<Person> vec;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		vec.push_back(Person(i,t));
	}
	sort(vec.begin(),vec.end(),cmp);
	ll sum=0;
	for(int i=1;i<n;i++){
		vec[i]._t+=vec[i-1]._t;
		sum+=vec[i-1]._t;
	}
	for(int i=0;i<n;i++)cout<<vec[i]._id<<" ";
	cout<<"\n";
	printf("%.2f",sum*1.0/n);
	return 0;
}

