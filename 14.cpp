#include <iostream>
#define mem_bound 5000000

using ll = long long;
int dp[mem_bound];

ll chain_length(ll i) {
    if (i==1) return 1;
    if (i<mem_bound && dp[i] != -1) return dp[i];

    if (i<mem_bound) return dp[i] = 1 + (i&1 ? chain_length(3*i+1) : chain_length(i/2));
    else return 1 + (i&1 ? chain_length(3*i+1) : chain_length(i/2));
    
}

int main() {
    int limit = 1000000;
    for (int i=0; i<mem_bound; i++) dp[i] = -1;
    
    ll max = 1; ll max_cnt = 1;
    for (ll i=2; i<limit; i++) {
        ll cur = i;
        ll cnt = chain_length(i);

        if (cnt > max_cnt) {
            max = i; max_cnt = cnt;
        }
    }

    std::cout << max << std::endl;

    return 0;
}