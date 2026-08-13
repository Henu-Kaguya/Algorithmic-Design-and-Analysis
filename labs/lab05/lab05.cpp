#include <iostream>
using namespace std;

int MOD = 10000;

// 矩阵2x2
struct Matrix
{
    int mat[2][2];
    // 计算 2x2 矩阵相乘，并对 10000 取模
    Matrix operator*(Matrix &b){
        Matrix res;
        res.mat[0][0] = (mat[0][0] * b.mat[0][0] + mat[0][1] * b.mat[1][0]) % MOD;
        res.mat[0][1] = (mat[0][0] * b.mat[0][1] + mat[0][1] * b.mat[1][1]) % MOD;
        res.mat[1][0] = (mat[1][0] * b.mat[0][0] + mat[1][1] * b.mat[1][0]) % MOD;
        res.mat[1][1] = (mat[1][0] * b.mat[0][1] + mat[1][1] * b.mat[1][1]) % MOD;
        return res;
    }
};

Matrix matrix_pow(Matrix base, int exp)
{
    Matrix res = {{{1, 0}, {0, 1}}};//初始化为单位矩阵,遇到奇数在进行改变,改变之后不会立马乘上去,而是会慢慢累积
    while (exp){
        if (exp % 2)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int fibonacci_mod(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix result = matrix_pow(base, n - 1);
    return result.mat[0][0]; // F(n) = M^(n-1) 的 (0,0) 元素
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci_mod(n) << endl;
    return 0;
}
