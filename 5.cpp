#include <iostream>
#define sieve_bound 25

using ll = long long;

int isPrime[sieve_bound];

int main() {
    ll target = 20;
    ll ans = 1;

    for (ll i=0; i<sieve_bound; i++) isPrime[i] = 1;

    for (ll i=2; i<sieve_bound; i++)
        if (isPrime[i])
            for (ll j=i*i; j<sieve_bound; j+=i)
                isPrime[j] = 0;

    for (ll i=2; i<=target; i++) {
        if (isPrime[i]) {
            ll p = i;
            while (p * i < target) p *= i;
            ans *= p;
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}