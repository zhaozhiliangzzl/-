#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1e+5;
const int inf = 0x3f3f3f;
int f[maxn][maxn],m[maxn][maxn];    
int n;
int P[maxn];
int main() {
    cin>>n;
    for (int i = 0; i <= n; ++i) {
    	cin>>P[i];
	}
    for (int i = 1; i <= n; ++i){
    	f[i][i] = 0;
	}
    for (int len = 2; len <= n; ++len) {            
        for (int l = 1; l + len - 1 <= n; ++l) {       
            int r = l + len - 1;
            f[l][r] = inf;
            m[l][r] = 0;
            for (int i = l; i < r; ++i) {           
                if (f[l][i] + f[i + 1][r] + P[l - 1] * P[i] * P[r] < f[l][r]) {
                    f[l][r] = f[l][i] + f[i + 1][r] + P[l - 1] * P[i] * P[r];
                    s[l][r] = i;
                }
            }
        }
    }
    printf("%d\n", f[1][n]);
}
