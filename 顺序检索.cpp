#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int main(){
	int m[maxn];
	int n,a,b=0;
	cin>>n>>a;     //n数组元素，a目标元素 
	for(int i=1;i<=n;++i){
		cin>>m[i];
		if(a==m[i]) b=i;
	}
	printf("下标 = %d",b);
} 
