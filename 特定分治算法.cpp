#include <stdio.h>
#include <stdlib.h>
const int maxn=1e3+5;
//二分归并排序
void mergearry(int a[],int l,int mid,int r){
	int i=l,j=mid+1;
    int k=l;
    int temp[maxn];
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
//核心算法 
int select(int a[],int left,int right,int k) 
{
	int n=right-left;
	if (n<5){
		mergesort(a,left,right-1);
		return a[left+k-1];
	}
	int i;
	int t=n/5;
	int *m = new int[t];
	for (i=0;i<t;i++) {
		mergesort(a,left+i*5,left+i*5+5-1);
		m[i] = a[left+i*5+2];
	}
	mergesort(m,0,i-1);
	int mid=m[i/2];
	int *a1=new int[n];
	int *a2=new int[n];
	int *a3=new int[n];
	int s1=0,s2=0,s3=0;
	for(int i=left;i<right;i++)
	{
		if(a[i]<mid)
		{
			a1[s1++]=a[i];
		}
		else if(a[i]==mid)
		{
			a2[s2++]=a[i];
		}
		else
			a3[s3++]=a[i];
	}
	if(s1>=k)
	{
		return select(a1,0,s1,k);
	}
	if (s1+s2>=k)
	{
		return mid;
	}
	else
		return select(a3,0,s3,k-s1-s2);
}
int main()
{
    int n,k;
    int a[maxn];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
	printf("第%d小元素为%d",k, select(a,0,n,k));
    return 0;
}
