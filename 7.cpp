#include <iostream>
#define sieve_bound 10000000

using ll = long long;

int isPrime[sieve_bound];

int main() {
    int N = 10001;

    for (ll i=0; i<sieve_bound; i++) isPrime[i] = 1;

    int cnt = 0;
    for (ll i=2; i<sieve_bound; i++)
        if (isPrime[i]) {
            cnt += 1;
            if (cnt == N) {
                std::cout << i << std::endl;
                break;
            }
            for (ll j=i*i; j<sieve_bound; j+=i)
                isPrime[j] = 0;
    }

    return 0;
}