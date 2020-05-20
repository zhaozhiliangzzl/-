# -
算法作业
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1e5+10;
int fa[maxn];
int n,m;

struct edge  
{
    int u, v, w; //点、权值
}edges[maxn];

//按权值进行升序排列 
bool cmp(edge a,edge b){
	return a.w<b.w;
}

//并查集用于处理集合中的边 
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void baba(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}

void kruskal(){
	for(int i=0;i<m;++i){
		int fx=find(edges[i].u);
		int fy=find(edges[i].v);
		if(fx==fy){
			continue;
			
		}
		baba(edges[i].u,edges[i].v);
		printf("V%d->V%d\n",edges[i].u,edges[i].v);
		
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<maxn;++i){
		fa[i]=i;
	}
	for(int i=0;i<m;++i){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	sort(edges,edges+m,cmp);
	kruskal();
}
