#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int Maxn = 250001;

struct oper {
       char typ;
       int a, b, c;
};

int n, m, st, h[Maxn], hl, sec[Maxn][2], sl;
LL BIT[Maxn];
oper op[Maxn];

void Add(int where, LL what)
{
     for (int i = where; i > 0; i -= i & -i) BIT[i] += what;
}

LL Get(int st, int lim)
{
    int i;
    LL res = 0;
    for (i = st; i <= lim; i += i & -i) res += BIT[i];
    return res;
}

int main()
{
    int i, a, b;
    scanf("%d %d %d", &n, &m, &st);
    for (i = 0; i < m; i++) {
        scanf(" %c %d", &op[i].typ, &op[i].a);
        if (op[i].typ != 'Q') scanf("%d %d", &op[i].b, &op[i].c);
        else h[++hl] = op[i].a;
    }
    sort(h+1, h+hl+1);
    hl = unique(h+1, h+hl+1) - (h+1);
    memset(BIT, 0, sizeof(BIT));
    for (i = 0; i < m ; i++)
       if (op[i].typ == 'S') {
                      sl++;
                      sec[sl][0] = op[i].a;
                      sec[sl][1] = op[i].b;
                      a = lower_bound(h+1, h+hl+1, sec[sl][0]) - h;
                      b = upper_bound(h+1, h+hl+1, sec[sl][1]) - h - 1;
                      if (a <= b) { Add(b, +op[i].c); Add(a-1, -op[i].c); }
       } else {
              a = lower_bound(h+1, h+hl+1, op[i].a) - h;
              printf("%lld\n", st+Get(a, hl));
       }
    //system("pause");
    return 0;
}
