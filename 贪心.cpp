#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
struct Node{
	int start,end,id;      //开始时间，结束时间，id 
}time[100];
int cmp(Node a,Node b){
	return a.end<b.end;     //将每个项目的结束时间进行升序排列 
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>time[i].start>>time[i].end;
		time[i].id=i;
	}
	sort(time,time+n,cmp);
	int sum=1;
	int temp=time[0].end;      //记录当前项目的结束时间 
	for(int i=0;i<n-1;++i){
		if(temp<=time[i+1].start){    //将当前项目结束时间与下一个项目的开始时间作比较 
			temp=time[i+1].end;
			sum++;
		}
		
	}
	printf("%d",sum);
} 
