#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
struct File{
	int name,size;
	bool operator<(const File& f)const{
		return size!=f.size?size>f.size:name<f.name;
	}
};
int main(){
	vector<map<int,int>> fd(6);
	vector<set<File>> fsize(6);
	vector<set<int>> fname(6);
	int Q;cin>>Q;
	while(Q--){
		int op,f;cin>>op>>f;
		if(op==1){
			int name,size;cin>>name>>size;
			if(fd[f].count(name)){
				int oldsize=fd[f][name];
				fsize[f].erase({name,oldsize});
				fname[f].erase(name);
			}
			fd[f][name]=size;
			fsize[f].insert({name,size});
			fname[f].insert(name);
		}if(op==2){
			int name;cin>>name;
			int size=fd[f][name];
			fd[f].erase(name);
			fsize[f].erase({name,size});
			fname[f].erase(name);
		}if(op==3){
			int k,cnt=0;cin>>k;
			for(auto& file:fsize[f]){
				if(cnt>=k)break;
				if(cnt)cout<<" ";
				cout<<file.name;
				cnt++;
			}cout<<endl;
		}if(op==4){
			int k,cnt=0;cin>>k;
			for(int name:fname[f]){
				if(cnt>=k)break;
				if(cnt)cout<<" ";
				cout<<name;
				cnt++;
			}cout<<endl;
		}
	}
	return 0;
}
