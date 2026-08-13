#include <iostream>
#include <vector>
#include <numeric>   // Required for accumulate in some contexts, though not strictly here
#include <algorithm> // Required for sort and reverse
#include <limits>    // Required for numeric_limits

using namespace std;

// Function to print the solution in the specified format
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

// --- Greedy Algorithm ---
void greedy_coin(int n, int Y, const vector<int> &v)
{
    vector<int> denominations = v;
    // Greedy algorithm requires considering the largest denominations first
    // The input guarantees v1 < v2 < ... < vn, so we iterate backwards
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

    // Although the problem guarantees v1=1, ensuring a solution,
    // a robust implementation might check if remaining_amount is 0 here.
    // if (remaining_amount == 0) {
    print_solution(Y, coins_used);
    // } else {
    //     cout << "Greedy algorithm could not find a solution." << endl;
    // }
}

// --- Dynamic Programming Algorithm ---
void dp_coin(int n, int Y, const vector<int> &v)
{
    // dp[i] stores the minimum number of coins to make amount i
    vector<int> dp(Y + 1, Y + 1); // Initialize with a value larger than max possible coins (Y*v1)
    // last_coin[i] stores the denomination of the last coin used to make amount i optimally
    vector<int> last_coin(Y + 1, 0);

    dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= Y; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int coin_value = v[j];
            if (coin_value <= i)
            {
                // If using coin_value leads to a better (fewer coins) solution for amount i
                if (dp[i - coin_value] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin_value] + 1;
                    last_coin[i] = coin_value; // Record the coin used
                }
            }
        }
    }

    // Reconstruct the solution by backtracking using last_coin array
    if (dp[Y] > Y)
    { // Check if a solution was found
        cout << "Dynamic programming could not find a solution for " << Y << endl;
    }
    else
    {
        vector<int> coins_used;
        int current_amount = Y;
        while (current_amount > 0)
        {
            int coin = last_coin[current_amount];
            if (coin == 0)
            { // Should not happen if dp[Y] <= Y, but as a safeguard
                cerr << "Error reconstructing DP solution." << endl;
                return;
            }
            coins_used.push_back(coin);
            current_amount -= coin;
        }
        // The coins are added in reverse order of calculation, but the order
        // doesn't typically matter for the sum. If specific order needed, reverse here.
        // reverse(coins_used.begin(), coins_used.end());
        print_solution(Y, coins_used);
    }
}

int main()
{
    int n; // Number of coin denominations
    int Y; // Total amount to make change for

    // Read input
    cin >> n >> Y;

    vector<int> v(n); // Vector to store coin denominations
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // --- Solve using Greedy Algorithm ---
    // cout << "Greedy Algorithm Solution:" << endl; // Optional header
    greedy_coin(n, Y, v);

    // --- Solve using Dynamic Programming ---
    // cout << "Dynamic Programming Solution:" << endl; // Optional header
    dp_coin(n, Y, v);

    return 0;
}