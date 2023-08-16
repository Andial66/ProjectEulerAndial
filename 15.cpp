#include <iostream>

using ll = long long;

ll dp[200][200];

ll solve(int n, int m) {
    if (n==0 && m==0) return 1;
    if (dp[n][m] != -1) return dp[n][m];
    if (n==0) return dp[n][m] = solve(n, m-1);
    if (m==0) return dp[n][m] = solve(n-1, m);
    return dp[n][m] = solve(n-1, m) + solve(n, m-1);
}

int main() {
    int N = 20; int M = 20;

    for (int i=0; i<=N; i++)
        for (int j=0; j<=M; j++)
            dp[i][j] = -1;

    std::cout << solve(N, M) << std::endl; 

    return 0;
}