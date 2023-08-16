#include <iostream>
#define sieve_bound 4000000

using ll = long long;

int isPrime[sieve_bound];

int main() {
    int bound = 2000000 ;

    for (ll i=0; i<sieve_bound; i++) isPrime[i] = 1;

    ll cnt = 0;
    for (ll i=2; i<std::min(bound, sieve_bound); i++)
        if (isPrime[i]) {
            cnt += i;
            for (ll j=i*i; j<std::min(bound, sieve_bound); j+=i)
                isPrime[j] = 0;
    }

    std::cout << cnt << std::endl;

    return 0;
}