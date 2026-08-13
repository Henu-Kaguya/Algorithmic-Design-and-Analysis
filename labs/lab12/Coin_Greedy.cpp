#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

using namespace std;

void print_solution(int total_amount, const vector<int> &coins_used)
{
    cout << total_amount << "=";
    for (size_t i = 0; i < coins_used.size(); ++i)
    {
        cout << coins_used[i];
        if (i < coins_used.size() - 1)
        {
            cout << "+";
        }
    }
    cout << endl;
}

void greedy_coin(int n, int Y, const vector<int> &v)
{
    vector<int> denominations = v;

    vector<int> coins_used;
    int remaining_amount = Y;

    for (int i = n - 1; i >= 0; --i)
    {
        while (remaining_amount >= denominations[i])
        {
            remaining_amount -= denominations[i];
            coins_used.push_back(denominations[i]);
        }
    }

    print_solution(Y, coins_used);

}

void dp_coin(int n, int Y, const vector<int> &v)
{
    vector<int> dp(Y + 1, Y + 1);

    vector<int> last_coin(Y + 1, 0);

    dp[0] = 0;

    for (int i = 1; i <= Y; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int coin_value = v[j];
            if (coin_value <= i)
            {
                if (dp[i - coin_value] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin_value] + 1;
                    last_coin[i] = coin_value;
                }
            }
        }
    }

    if (dp[Y] > Y)
    {
        cout << "dp算法不行,没找到" << Y << endl;
    }
    else
    {
        vector<int> coins_used;
        int current_amount = Y;
        while (current_amount > 0)
        {
            int coin = last_coin[current_amount];
            if (coin == 0)
            {
                cout << "错误" << endl;
                return;
            }
            coins_used.push_back(coin);
            current_amount -= coin;
        }

        print_solution(Y, coins_used);
    }
}

int main()
{
    int n;
    int Y;

    cin >> n >> Y;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    greedy_coin(n, Y, v);

    dp_coin(n, Y, v);

    return 0;
}