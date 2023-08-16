#include <iostream>
#define sqrt_bound 1000000

using ll = long long;

int isPrime[sqrt_bound];

int main() {
    ll x = 600851475143;

    for (ll i=0; i<sqrt_bound; i++) isPrime[i] = 1;
    
    for (ll i=2; i<sqrt_bound; i++)
        if (isPrime[i])
            for (ll j=i*i; j<sqrt_bound; j+=i)
                isPrime[j] = 0;


    ll ans = -1;
    for (ll i=sqrt_bound-1; i>=2 && ans==-1; i--)
        if (x % i == 0 && isPrime[i])
            ans = i;

    std::cout << ans << std::endl;

    return 0;
}
