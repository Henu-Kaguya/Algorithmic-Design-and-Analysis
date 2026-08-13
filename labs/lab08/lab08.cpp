#include <iostream>
using namespace std;

// x和y是输入的两个数组(字符串)
template <typename T>
void Lcs_length(T x, T y, int **Clength, char **bPos)
{
    int m = x.length();
    int n = y.length();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            { // 注意这里修改为i-1和j-1
                Clength[i][j] = Clength[i - 1][j - 1] + 1;
                bPos[i][j] = 'Q';
            }
            else if (Clength[i - 1][j] >= Clength[i][j - 1])
            {
                Clength[i][j] = Clength[i - 1][j];
                bPos[i][j] = 'W';
            }
            else
            {
                Clength[i][j] = Clength[i][j - 1];
                bPos[i][j] = 'A';
            }
        }
    }
}

template <typename T>
void Print_LCS(char **bPos, T x, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (bPos[i][j] == 'Q')
    {
        Print_LCS(bPos, x, i - 1, j - 1);
        cout << x[i - 1]; // 同样修改为i-1
    }
    else if (bPos[i][j] == 'W')
        Print_LCS(bPos, x, i - 1, j);
    else
        Print_LCS(bPos, x, i, j - 1);
}

int main()
{
    string x;
    string y;
    cin >> x >> y;

    int xlen = x.length();
    int ylen = y.length();

    // 修改数组大小为xlen+1和ylen+1
    int **Clen = new int *[xlen + 1];
    for (int i = 0; i <= xlen; i++)
    {
        Clen[i] = new int[ylen + 1];
    }

    char **bPos = new char *[xlen + 1];
    for (int i = 0; i <= xlen; i++)
    {
        bPos[i] = new char[ylen + 1];
    }

    // 完整初始化
    for (int i = 0; i <= xlen; i++)
    {
        Clen[i][0] = 0;
    }
    for (int j = 0; j <= ylen; j++)
    {
        Clen[0][j] = 0;
    }

    Lcs_length(x, y, Clen, bPos);

    cout << Clen[xlen][ylen]; // 修改为xlen和ylen

    // cout << endl;
    // Print_LCS(bPos, x, xlen, ylen);

    for (int i = 0; i <= xlen; i++)
    {
        delete[] bPos[i];
    }
    delete[] bPos;

    for (int i = 0; i <= xlen; i++)
    {
        delete[] Clen[i];
    }
    delete[] Clen;
}