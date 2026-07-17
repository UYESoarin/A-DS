#include"SORT.h"
using namespace std;

void Sort::traverse(vector<int>& vec){
	for(int num:vec)cout<<num<<" ";
	cout<<endl;
}

void Sort::bubbleSort(vector<int>& vec){ 
	int len=vec.size();
	for(int i=0;i<len-1;i++){
		bool flag=false;
		for(int j=0;j<len-1-i;j++)
			if(vec[j]>vec[j+1]){
				swap(vec[j],vec[j+1]);
				flag=true;
			}
		if(!flag)break;
	}//O(n^2) 
}

void Sort::selectionSort(vector<int>& vec){
	int len=vec.size();
	for(int i=0;i<len-1;i++){
		int minIdx=i;
		for(int j=i+1;j<len;j++)
			if(vec[j]<vec[minIdx])minIdx=j;
		swap(vec[i],vec[minIdx]);
	}//O(n^2)
}

void Sort::insertionSort(vector<int>& vec){
	int len=vec.size();
	for(int i=1;i<len;i++){
		int key=vec[i];
		int j=i-1;
		while(j>=0 && vec[j]>key){
			vec[j+1]=vec[j];
			j--;
		}
		vec[j+1]=key;
	}//O(n^2)
}

void Sort::shellSort(vector<int>& vec){
	int len=vec.size();
	for(int gap=len/2;gap>0;gap/=2){
		for(int i=gap;i<len;i++){
			int key=vec[i],j=i-gap;
			while(j>=0 && vec[j]>key){
				vec[j+gap]=vec[j];
				j-=gap;
			}
			vec[j+gap]=key;
		}
	}//O(n^1.3)
}

void Sort::mergeSort(vector<int>& vec){
	mergeSort(vec,0,vec.size()-1);
}
void Sort::merge(vector<int>& vec,int l,int m,int r){
	int len=r-l+1;
	int i=l,j=m+1,k=0;
	vector<int> temp(len);
	while(i<=m && j<=r)temp[k++]=vec[i]<=vec[j]?vec[i++]:vec[j++];
	while(i<=m)temp[k++]=vec[i++];
	while(j<=r)temp[k++]=vec[j++];
	for(k=0;k<len;k++)vec[l+k]=temp[k];
}
void Sort::mergeSort(vector<int>& vec,int l,int r){
	if(l>=r)return;
	int m=l+(r-l)/2;
	mergeSort(vec,l,m);
	mergeSort(vec,m+1,r);
	merge(vec,l,m,r);
	//O(nlogn)
}

void LomutoSort::quickSort(vector<int>& vec){
	quickSort(vec,0,vec.size()-1);
}
void LomutoSort::quickSort(vector<int>& vec,int low,int high){
	if(low>=high)return;
	int pi=partition(vec,low,high);
	//pi作为中位 
	quickSort(vec,low,pi-1);
	quickSort(vec,pi+1,high);
	//O(nlogn)
}
int LomutoSort::partition(vector<int>& vec,int low,int high){
	int pivot=vec[high],i=low-1;
	for(int j=low;j<high;j++)if(vec[j]<=pivot)swap(vec[++i],vec[j]);
	swap(vec[i+1],vec[high]);
	return i+1;
}

void HoareSort::quickSort(vector<int>& vec){
	quickSort(vec,0,vec.size()-1);
}
void HoareSort::quickSort(vector<int>& vec,int low,int high){
	if(low>=high)return;
	int pi=partition(vec,low,high);
	//pi作为分界
	quickSort(vec,low,pi);
	quickSort(vec,pi+1,high);
}
int HoareSort::partition(vector<int>& vec,int low,int high){
	int pi=medianOfThree(vec,low,high);
	int pivot=vec[pi];
	int i=low-1,j=high+1;
	while(true){
		do i++;while(vec[i]<pivot);
		do j--;while(vec[j]>pivot);
		if(i>=j)return j;//[...j][i...] 
		swap(vec[i],vec[j]);
	}
}
int HoareSort::medianOfThree(vector<int>& vec,int low,int high){
	int mid=low+(high-low)/2;
	if(vec[low]>vec[mid])swap(vec[low],vec[mid]);
	if(vec[low]>vec[high])swap(vec[low],vec[high]);
	if(vec[mid]>vec[high])swap(vec[mid],vec[high]);
	return mid;
}
void Sort::heapify(vector<int>& vec,int n,int i){
	int top=i,l=2*i+1,r=2*i+2;//0~n-1: parentIdx = (childIdx-1)/2
	if(l<n && vec[l]>vec[top])top=l;
	if(r<n && vec[r]>vec[top])top=r;
	if(top!=i){
		swap(vec[top],vec[i]);
		heapify(vec,n,top);
	}
}
void Sort::heapSort(vector<int>& vec){
	int n=vec.size();
	for(int i=n/2-1;i>=0;--i)heapify(vec,n,i);//0~n-1: lastNotLeafIdx = n/2-1
	for(int i=n-1;i>0;--i){
		swap(vec[0],vec[i]);
		heapify(vec,i,0);
	}//O(nlogn)
}
void Sort::countingSort(vector<int>& vec){
	int n=vec.size();
//	int maxVal=*max_element(vec.begin(),vec.end());//#include<algorithm>
//	int minVal=*min_element(vec.begin(),vec.end());
	int maxVal=0,minVal=0;
	for(auto x:vec){
		maxVal=max(maxVal,x);
		minVal=min(minVal,x);
	}
	int range=maxVal-minVal+1;
	vector<int> cnt(range,0);//min~max
	for(int i=0;i<n;++i)cnt[vec[i]-minVal]++;
	for(int i=1;i<range;++i)cnt[i]+=cnt[i-1];//partialSumToIdx
	vector<int> res(n);
	for(int i=n-1;i>=0;--i){
		res[cnt[vec[i]-minVal]-1]=vec[i];
		cnt[vec[i]-minVal]--;
	}for(int i=0;i<n;++i)vec[i]=res[i];//vec=res
}

