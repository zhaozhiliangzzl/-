#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e3+5;
int f[maxn][maxn];          //f[i][j]��ʾǰi����Ŀ���������jԪ 
int val[maxn][maxn];       //val[i][j]��i����Ŀ����jԪ 
int n,m;                  //n����ĿmԪ 
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
	printf("�������Ϊ��%d",f[n][m]);
}
