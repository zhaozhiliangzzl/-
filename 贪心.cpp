#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
struct Node{
	int start,end,id;      //��ʼʱ�䣬����ʱ�䣬id 
}time[100];
int cmp(Node a,Node b){
	return a.end<b.end;     //��ÿ����Ŀ�Ľ���ʱ������������� 
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
	int temp=time[0].end;      //��¼��ǰ��Ŀ�Ľ���ʱ�� 
	for(int i=0;i<n-1;++i){
		if(temp<=time[i+1].start){    //����ǰ��Ŀ����ʱ������һ����Ŀ�Ŀ�ʼʱ�����Ƚ� 
			temp=time[i+1].end;
			sum++;
		}
		
	}
	printf("%d",sum);
} 
