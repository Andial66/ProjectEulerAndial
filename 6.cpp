#include <iostream>

int square_of_sum(int N) {
    int acum = 0;
    for (int i=1; i<=N; i++) acum += i;
    return acum * acum;
}

int sum_of_squares(int N) {
    int acum = 0;
    for (int i=1; i<=N; i++) acum += i*i;
    return acum;
}

int main() {
    int N = 100;

    std::cout << square_of_sum(N) - sum_of_squares(N) << std::endl;

    return 0;
}