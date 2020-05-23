#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e3+5;
int f[maxn][maxn];          //f[i][j]表示前i个项目的最大收益j元 
int val[maxn][maxn];       //val[i][j]第i个项目收益j元 
int n,m;                  //n个项目m元 
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>val[j][i];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<=j;++k){
				if(f[i-1][j-k]+val[i][k]>f[i][j]){
					f[i][j]=f[i-1][j-k]+val[i][k];
				}
			}
		}
	}
	printf("最大收益为：%d",f[n][m]);
}
