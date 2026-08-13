#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    vector<int> w(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    vector<vector<int>> F(n + 1, vector<int>(b + 1, 0));

    for (int curItem = 0; curItem <= n; ++curItem)
    {
        F[curItem][0] = 0;
    }
    for (int curB = 0; curB <= b; ++curB)
    {
        F[0][curB] = 0;
    }

    for (int curItem = 1; curItem <= n; ++curItem)
    {
        for (int curB = 1; curB <= b; ++curB)
        {
            if (curB < w[curItem - 1])
            {
                F[curItem][curB] = F[curItem - 1][curB];
            }
            else
            {
                int valNo = F[curItem - 1][curB];
                int valYes = F[curItem - 1][curB - w[curItem - 1]] + v[curItem - 1];
                F[curItem][curB] = max(valNo, valYes);
            }
        }
    }

    vector<int> x;
    int remainB = b;
    for (int curItem = n; curItem >= 1; --curItem)
    {
        if (F[curItem][remainB] > F[curItem - 1][remainB])
        {
            x.push_back(curItem);
            remainB -= w[curItem - 1];
        }
    }

    cout << F[n][b] << endl;

    sort(x.begin(), x.end());
    for (size_t i = 0; i < x.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << "x" << x[i];
    }
    cout << endl;

    return 0;
}