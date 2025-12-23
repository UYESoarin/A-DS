#include<stdio.h>
int a[1000];
int main(){
	int m,n,k;scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++){
		for(int k=0;k<m;k++){
			a[k]=0;
		}
		int top=0,dn=0,x=1;
		for(int j=0;j<n;j++){
			int d;scanf("%d",&d);
			if(d==a[top]){
				dn++;
				top--;
			}else if(d>a[top]){
				while(x<d){
					a[top++]=x;
					x++;
				}dn++;
			}else break;
		}
		if(dn==n)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
