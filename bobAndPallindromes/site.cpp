#include <iostream>
#define mod 1000000007 
using namespace std;
typedef long long ll;

ll power(ll base, ll exponent) {
    ll result =1;
    ll p = base%mod;
    
    while(exponent) {
        if (exponent&1) result = (result * p)%mod;
        p = (p*p)%mod;
        exponent >>= 1;
    }
    
    return result;
}

int main() {
    int n;
	std::cin >> n;
	
	while(std::cin >> n){
	    ll T = power(26, n);
	    ll P;
	    if(n%2==0) P = power(26, n/2);
	    else P = power(26, n/2 + 1);
	    
	    ll sum;
	    if(n%2 == 0){
	        sum = (26*(power(26, n/2)- 1)%mod /25)%mod;
	    }
	    else {
	        sum = (26*(power(26, (n-1)/2) -1)%mod /25)%mod;
	    }
	    
	    sum = (sum*2)%mod;
	    
	    if(n%2 == 0) sum = (sum + 1)%mod;
	    else sum = (sum + 2)%mod;
	    
	    std::cout << (((sum*P)%mod)*power(T, n-2) - 1 + mod)%mod << std::endl;
	}
	
	return 0;
}
