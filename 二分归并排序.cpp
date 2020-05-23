#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int a[maxn],temp[maxn];
int n;
void mergearry(int a[],int l,int mid,int r){
	int i=l,j=mid+1;
    int k=l;
    while(i<=mid&&j<=r){
    	if(a[i]<=a[j]) temp[k++]=a[i++];
    	else temp[k++]=a[j++];
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=r){
		temp[k++]=a[j++];
	}
	for(int i=l;i<=r;++i){
		a[i]=temp[i];
	}
    
} 
void mergesort(int a[],int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		mergearry(a,l,mid,r);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;++i) printf("%d%c",a[i],i==n-1?"\n":" ");
}
