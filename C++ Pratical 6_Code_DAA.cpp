#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printParenthesis(vector<vector<int>>& split, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";

    int k = split[i][j];

    printParenthesis(split, i, k);

    cout << " x ";

    printParenthesis(split, k + 1, j);

    cout << ")";
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter " << n + 1 << " dimensions: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // DP table
    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(n + 1, 0)
    );

    // Split table
    vector<vector<int>> split(
        n + 1,
        vector<int>(n + 1, 0)
    );

    // Matrix Chain Multiplication
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++)
            {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    (long long)p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications = "
         << dp[1][n] << endl;

    cout << "Optimal Parenthesization = ";

    printParenthesis(split, 1, n);

    cout << endl;

    return 0;
}