#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void preorder(int i, int j, const vector<vector<int>> &root, vector<int> &result)
{
    if (i > j)
        return;
    int r = root[i][j];
    result.push_back(r);
    preorder(i, r - 1, root, result);
    preorder(r + 1, j, root, result);
}

int main()
{
    int n;
    cin >> n;
    vector<double> prob(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; ++i)
    {
        cin >> prob[i];
    }

    vector<double> q(n + 1); // q:0->n
    vector<double> p(n + 1); // p:1->n
    q[0] = prob[0];
    for (int i = 1; i <= n; ++i)
    {
        p[i] = prob[2 * i - 1];
        q[i] = prob[2 * i];
    }

    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0.0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0.0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n + 1; ++i)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; ++l)
    {
        for (int i = 1; i <= n - l + 1; ++i)
        {
            int j = i + l - 1;
            e[i][j] = numeric_limits<double>::infinity();
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; ++r)
            {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    vector<int> result;
    preorder(1, n, root, result);

    for (size_t k = 0; k < result.size(); ++k)
    {
        cout << result[k];
        if (k != result.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}