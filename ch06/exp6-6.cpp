#include <cstdio>
#include <cstring>

const int maxn = 20;
int s[1 << maxn];

int main()
{
    int D, I;
    /* 方案一：模拟整个流程
    while (scanf("%d%d", &D, &I) == 2 && D)
    {
        memset(s, 0, sizeof(s));
        int k, n = (1 << D) - 1;
        for (int i = 0; i < I; i++)
        {
            k = 1;
            for (;;)
            {
                s[k] = !s[k];
                k = s[k] ? k * 2 : k * 2 + 1;
                if (k > n)
                    break;
            }
        }
        printf("%d\n", k / 2);
    }
    */
    // 方案二：直接从原理出发推导
    while (scanf("%d%d", &D, &I) == 2 && D)
    {
        int k = 1;
        for (int i = 0; i < D - 1; i++)
        {
            if (I % 2)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I = I / 2;
            }
            printf("%d\n", k);
        }
    }
    return 0;
}