/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string S1, S2;
    cin >> S1 >> S2;

    int n = S1.length(), m = S2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] - 1;
    for (int j = 1; j <= m; ++j)
        dp[0][j] = dp[0][j - 1] - 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 2);
            }
            dp[i][j] = max({dp[i][j], dp[i - 1][j] - 1, dp[i][j - 1] - 1,0});
            //dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
 */

/* #include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MATCH_SCORE = 2;
const int MISMATCH_SCORE = -2;
const int GAP_PENALTY = -1;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0] + GAP_PENALTY;
    }

    for (int j = 1; j <= m; ++j)
    {
        dp[0][j] = dp[0][j - 1] + GAP_PENALTY;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int match_mismatch_val = (s1[i - 1] == s2[j - 1]) ? MATCH_SCORE : MISMATCH_SCORE;
            int score1 = dp[i - 1][j - 1] + match_mismatch_val;

            int score2 = dp[i - 1][j] + GAP_PENALTY;

            int score3 = dp[i][j - 1] + GAP_PENALTY;

            // dp[i][j] = max({score1, score2, score3});
            dp[i][j] = max({score1, score2, score3,0});
        }
    }

    cout << dp[n][m] << endl;

    return 0;
} */

/* #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    s1 = " " + s1;
    s2 = " " + s2;

    int n = s1.length() - 1;
    int m = s2.length() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] - 1;
    }

    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = dp[0][j - 1] - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int match = dp[i - 1][j - 1] + (s1[i] == s2[j] ? 2 : -2);

            int gap_s2 = dp[i - 1][j] - 1;

            int gap_s1 = dp[i][j - 1] - 1;

            dp[i][j] = max({match, gap_s1, gap_s2,0});
        }
    }

    cout << dp[n][m] << endl;

    return 0;
} */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

/*     for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0] - 1;
    }
    for (int j = 1; j <= m; ++j)
    {
        dp[0][j] = dp[0][j - 1] - 1;
    } */

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int match = (s1[i - 1] == s2[j - 1]) ? 2 : -2;
            match += dp[i - 1][j - 1];

            int gap1 = dp[i - 1][j] - 1;
            int gap2 = dp[i][j - 1] - 1;

            dp[i][j] = max({match, gap1, gap2, 0});
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}