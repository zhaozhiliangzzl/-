#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int m[maxn];
int n,a;
//该题默认是有序数组 
int Binary_Search(int x){
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		if(x<m[mid]) r=mid-1;
		else if(x>m[mid]) l=mid+1;
		else{
			return mid;
		}
	}
	return 0;
} 
int main(){
	cin>>n>>a;     //n数组元素，a目标元素 
	for(int i=1;i<=n;++i){
		cin>>m[i];
	}
	printf("下标 = %d",Binary_Search(a));
} 
