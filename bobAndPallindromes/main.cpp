#include <iostream>
#include <vector>
#define mod 1000000007
typedef unsigned long long ll;

ll power(ll base, ll exponent) {

    ll result = 1;
    ll p = base % mod;

    while (exponent){ //1
        if (exponent&1) result = (result * p)%mod;
        p = (p*p)%mod;
        exponent >>= 1;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "rb", stdin);
    freopen("output", "w", stdout);
#endif

    int n;

    std::cin >> n;

    while (std::cin >> n){
        ll T = power(26, n);
        ll P;
        if (n % 2 == 0 ) P = power(26, n/2);
        else P = power(26, n/2 + 1);

        ll sum;
        ll dividend;

        sum = 26*(power(26, n/2) - 1 + mod)%mod;
        dividend = power(25, mod -2);

        sum = (sum * dividend)%mod;
        sum = (sum*2)%mod;

        if (n%2 == 0) sum = (sum + 1)%mod;
        else sum = (sum + 2)%mod;

        sum = (sum*P)%mod;
        sum = (sum * power(T, mod-2))%mod;
        sum = (sum - 1 + mod)%mod;

        std::cout << sum << std::endl;
    }

    return 0;
}
