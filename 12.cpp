#include <iostream>
#include <vector>
#include <cmath>
#define sieve_bound 4000000

using ll = long long;

int isPrime[sieve_bound];
std::vector<int> primes;
int bound = 50000;

std::vector<int> decomposition(ll n) {
    std::vector<int> decomp;
    ll search_bound = (ll) sqrt(n);

    ll i=0;

    for (; i<=search_bound && n>1; i++) {
        ll prime = primes[i];
        decomp.push_back(0);
        while (n % prime == 0) {
            decomp[decomp.size()-1]++; n /= prime;
        }
    }

    if (n>1) {
        while (primes[i] <= n) {
            decomp.push_back(0); i++;
        }
        decomp[decomp.size()-1]++;
    }

    return decomp;
}

std::vector<int> mix_decompositions(std::vector<int> &decomp_1, std::vector<int> &decomp_2) {
    std::vector<int> new_decomp;

    if (decomp_1.size() > decomp_2.size()) new_decomp = decomp_1;
    else new_decomp = decomp_2;
    
    for (int i=0; i<std::min(decomp_1.size(), decomp_2.size()); i++)
        new_decomp[i] = decomp_1[i] + decomp_2[i];

    return new_decomp;
}

int num_factors(std::vector<int> &decomp) {
    ll factors = 1;
    for (int i=0; i<decomp.size(); i++) factors *= (ll) (decomp[i]+1);
    return factors;
}

int main() {
    ll limit = 500;

    for (ll i=0; i<sieve_bound; i++) isPrime[i] = 1;

    primes.resize(0);
    for (ll i=2; i<std::min(bound, sieve_bound); i++)
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j=i*i; j<std::min(bound, sieve_bound); j+=i)
                isPrime[j] = 0;
    }

    for (ll i=1; i<bound; i++) {
        std::vector<int> decomp_i = decomposition(i);
        std::vector<int> decomp_ip = decomposition(i+1);

        std::vector<int> decomp_ii = mix_decompositions(decomp_i, decomp_ip);
        decomp_ii[0]--;

        if (num_factors(decomp_ii) > limit) {
            std::cout << (i*(i+1)) / 2 << std::endl; break;
        }
    }

    return 0;
}