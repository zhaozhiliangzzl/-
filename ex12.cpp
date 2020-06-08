#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;

int n, m, match;       //图的顶点数，可用的颜色数量，边的数量
int c[maxn][maxn];  //图的链接矩阵
int color[maxn];          //当前的解
int sum = 0;            //方案数

bool Same(int cur) {
    for (int i = 1; i <= n; ++i) {
        if (c[cur][i] == 1 && color[i] == color[cur])
            return false;
    }
    return true;
}

void BackTrack(int cur) {
    if (cur > n) {
        sum++;
        for (int i = 1; i <= n; ++i)
            printf("%d ", color[i]);
        printf("\n");
    }
    else {
        for (int i = 1; i <= m; ++i) {
            color[cur] = i;
            if (Same(cur))BackTrack(cur + 1);
            color[cur] = 0;
        }
    }
}

int main() {
    scanf("%d", &m);
    scanf("%d %d", &n, &match);
    for (int i = 1; i <= match; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        c[x][y] = c[y][x] = 1;
    }
    BackTrack(1);
    if (sum == 0)printf("NO\n");
else printf("%d\n", sum);
}
