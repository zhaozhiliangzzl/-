#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 100;
const int inf = 0x3f3f3f3f;
double minn = inf,x[N], r[N];              //分别为最小圆排列长度，每个圆心横坐标，每个圆半径
int n;
double bestr[N];                //最小圆排列的半径顺序

double cter(int n) {         
    double temp = 0;
    for (int j = 1; j < n; ++j) {
        double now = x[j] + 2.0 * sqrt(r[n] * r[j]);  //判断与之前的圆是否相切 
        if (now > temp)        //取所求圆心的最小值
            temp = now;
    }
    return temp;
}

void compute()
{
	double low=0,high=0;
	for(int i=1;i<n;++i)
	{
		if(x[i]-r[i]<low)
			low=x[i]-r[i];
		if(x[i]+r[i]>high)
			high=x[i]+r[i];
	}
	if(high-low<minn)
	{
		minn=high-low;
		for(int i=1;i<N;++i)
			bestr[i]=r[i];
	}

}
void dfs(int t) {
    if (t == n + 1) {
        compute();
    }
    else {
        for (int j = t; j <= n; ++j) {
            swap(r[t], r[j]);
            double now = cter(t);
            if (now + r[t] + r[1] < minn) {
                x[t] = now;
                dfs(t + 1);
            }
            swap(r[t], r[j]);     //还原
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i){
    	scanf("%lf", &r[i]);
	}
    dfs(1);
    printf("最小圆排列长度为：%.2f\n", minn);
    printf("最小圆排列的顺序对应的半径分别为：\n");
    for (int i = 1; i <= n; ++i) {
        if (i != 1)printf(" ");
        printf("%.2f", bestr[i]);
    }
    return 0;
}
