#include <bits/stdc++.h>
using namespace std;
const int N = 1100;

int degree[N];
int mark[N];
int p[N];
int n, m, a, b;

int findRoot(int x) {return x == p[x]? x : p[x] = findRoot(p[x]);}

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> n && n){
        cin >> m;
        memset(degree, 0, sizeof(degree));
        memset(mark, 0, sizeof(mark));
        for(int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            if (a == b)continue;
            degree[a]++;
            degree[b]++;

            int pa = findRoot(a);
            int pb = findRoot(b);
            if(pa != pb)
                p[pa] = pb;
        }

        int ans = 0;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if(degree[i] > 0){
            if (p[i] == i)ans++;
            if(degree[i] % 2 != 0)flag = 1;
            }
        }
        if(ans != 1 || flag == 1)printf("0\n");
        else printf("1\n");
    }
    return 0;
}
