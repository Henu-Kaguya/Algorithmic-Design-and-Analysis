
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define myMin(a, b) (((a) < (b)) ? (a) : (b))

int dp[1001][1001];

// 打印编辑距离DP表格的函数
void printDPTable(char *pSource, char *pTarget, int srcLen, int trgtLen)
{
    int i, j;

    // 打印表头
    printf("    |   ");
    printf("  "); // 为空字符预留位置
    for (j = 0; j < trgtLen; j++)
    {
        printf("%c  ", pTarget[j]);
    }
    printf("\n----+");

    // 打印分隔线
    for (j = 0; j <= trgtLen; j++)
    {
        printf("---");
    }
    printf("\n");

    // 打印每一行
    for (i = 0; i <= srcLen; i++)
    {
        if (i == 0)
            printf("   ");
        else
            printf("%c  ", pSource[i - 1]);

        printf("| ");

        for (j = 0; j <= trgtLen; j++)
        {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int editDistance(char *pSource, char *pTarget)
{
    int srcLen = strlen(pSource);
    int trgtLen = strlen(pTarget);
    int i, j;
    for (i = 0; i <= srcLen; ++i)
        dp[i][0] = i;
    for (j = 1; j <= trgtLen; ++j)
        dp[0][j] = j;
    for (i = 1; i <= srcLen; ++i)
        for (j = 1; j <= trgtLen; ++j)
        {
            if (pSource[i - 1] == pTarget[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = myMin(myMin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    printDPTable(pSource, pTarget, srcLen, trgtLen);

    return dp[srcLen][trgtLen];
}

int main(void)
{
    char pSource[] = "algorithm";
    char pTarget[] = "altruistic";
    int res;

    printf("计算将 \"%s\" 转换为 \"%s\" 的编辑距离\n\n", pSource, pTarget);
    res = editDistance(pSource, pTarget);
    printf("编辑距离: %d\n", res);

    return 0;
}

