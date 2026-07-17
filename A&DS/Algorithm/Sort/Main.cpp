#include<iostream>
#include<vector>
#include<algorithm>
#include"SORT.h"
using namespace std;
vector<int> vec={5,2,1,0,3,1,3,21,-8,-11};
int main(){
	HoareSort* sort=new HoareSort;
	sort->quickSort(vec);
	Sort::traverse(vec);
	delete sort;
	return 0;
}
