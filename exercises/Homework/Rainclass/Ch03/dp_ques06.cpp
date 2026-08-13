#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void printTable(int table[4][11], const string &tableName)
{
    cout << "\n"
         << tableName << "表：" << endl;
    cout << "    |";
    for (int j = 0; j <= 10; j++)
    {
        cout << setw(4) << j;
    }
    cout << endl;
    cout << "----|";
    for (int j = 0; j <= 10; j++)
    {
        cout << "----";
    }
    cout << endl;

    for (int i = 0; i <= 3; i++)
    {
        cout << " " << i << " |";
        for (int j = 0; j <= 10; j++)
        {
            cout << setw(4) << table[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int g[4][4] = {0, 0, 0, 0, 2, 4, 7, 11, 5, 10, 16, 20, 8, 12, 17, 22}; // 第一个下标来区分不同的投资函数，分别有g1,g2和g3，g0闲置。第二个下标用来表示投资的个数，数目从0~3。
    int F[4][11] = {0};                                                    // 优化函数F[k][y]，下标k表示选择前k个个x（其实一共也才3个x2333），k表示x_1^2+...+x_k^2 <= y
    int Re[4][11] = {0};                                                   // 备忘录函数，表示在选择前k个x，平方和的限制为y的情况下，选择x_k的个数（可以形象的理解为理解为选择了几个x_k）。

    for (int k = 1; k <= 3; k++) // 遍历k，表示选择前几个x
    {
        for (int y = 0; y <= 10; y++) // 遍历y，表示平方和的范围
        {
            int max = 0;
            for (int x = 0; x <= sqrt(y); x++) // 遍历选择的第k个x的取值范围，从0~3
            {
                if ((F[k - 1][y - x * x] + g[k][x]) > max)
                {
                    max = F[k - 1][y - x * x] + g[k][x];
                    Re[k][y] = x;
                }
            }
            F[k][y] = max; // 得到在选择前k个x，平方和限制为y下的最大收益
        }
    }

    // 打印F表和Re表
    printTable(F, "F");
    printTable(Re, "GPS");

    // 输出最大收益和最优决策
    cout << "\n最大收益: " << F[3][10] << endl;

    int i = 3;
    int y = 10;
    int solution[4] = {0}; // 存储x1, x2, x3的值

    cout << "\n最优解的路径：" << endl;
    while (i)
    {
        solution[i] = Re[i][y];
        cout << "x_" << i << " = " << Re[i][y] << ", 剩余平方和: " << y << " -> " << (y - Re[i][y] * Re[i][y]) << endl;
        y -= Re[i][y] * Re[i][y];
        i--;
    }

    cout << "\n最终解：" << endl;
    cout << "x_1 = " << solution[1] << ", x_2 = " << solution[2] << ", x_3 = " << solution[3] << endl;
    cout << "平方和检验：" << solution[1] * solution[1] + solution[2] * solution[2] + solution[3] * solution[3] << " <= 10" << endl;

    return 0;
}