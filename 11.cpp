#include <iostream>

using ll = long long;

int main() {
    int N = 20;
    ll grid[N][N];

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            std::cin >> grid[i][j];

    ll max_prod = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (j < N-4) 
                max_prod = std::max(max_prod, grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]);
            if (i < N-4)
                max_prod = std::max(max_prod, grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
            if (i < N-4 && j < N-4)
                max_prod = std::max(max_prod, grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
            if (i < N-4 && j > 3)
                max_prod = std::max(max_prod, grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]);
        }
    }

    std::cout << max_prod << std::endl;

    return 0;
}