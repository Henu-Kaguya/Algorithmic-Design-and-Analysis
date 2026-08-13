#include <iostream>
using namespace std;

int n;
int queen[20];
int count = 0;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queen[i] == col)
        {
            return false;
        }
        if (abs(queen[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void solve(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << queen[i] + 1;
            if (i < n - 1)
                cout << " ";
        }
        cout << endl;
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            queen[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    cin >> n;
    solve(0);
    cout << count << endl;
    return 0;
}