#include<bits/stdc++.h>
#define ll long long
typedef std::string string;

ll mod = 1e9 + 7;

class Vec {
    ll data[3];
public:

    Vec(){
        data[0] = 1;
        data[1] = 1;
        data[2] = 0;
    }

    Vec(std::vector<ll> val){
        for (int i = 0; i < 3; i++) {
            data[i] = val[i];
        }
    }

    ll& operator[](size_t i){
        return data[i];
    }

};

class Matrix {
    ll data[9];
public:
    Matrix(){
        for (int i = 0; i<9; i++) {
            data[i] = 0;
        }
    }
    Matrix(std::vector<ll> val){
        for (int i = 0; i < 9; i ++) {
            data[i] = val[i];
        }
    }

    void transform(){
        data[0] = 1;
        data[1] = 1;
        data[2] = 1;

        data[3] = 0;
        data[4] = 1;
        data[5] = 1;

        data[6] = 0;
        data[7] = 1;
        data[8] = 0;

        // | 1 1 1 |   |  Sn  |   | Sn + Fn+1 = Sn+1 |
        // | 0 1 1 | * |  Fn  | = | Fn + Fn-1 = Fn+1 |
        // | 0 1 0 |   | Fn-1 |   |           =  Fn  |
    }
    void id(){
        data[0] = 1;
        data[1] = 0;
        data[2] = 0;

        data[3] = 0;
        data[4] = 1;
        data[5] = 0;

        data[6] = 0;
        data[7] = 0;
        data[8] = 1;

        // 1 0 0
        // 0 1 0
        // 0 0 1
    }

    ll& operator[](size_t i){
        return data[i];
    }

    Matrix operator*(Matrix A){
        return
        Matrix({ ((data[0]*A[0])%mod + (data[1]*A[3])%mod + (data[2]*A[6])%mod)%mod, ((data[0]*A[1])%mod + (data[1]*A[4])%mod + (data[2]*A[7])%mod)%mod, ((data[0]*A[2])%mod + (data[1]*A[5])%mod + (data[2]*A[8])%mod)%mod,
                 ((data[3]*A[0])%mod + (data[4]*A[3])%mod + (data[5]*A[6])%mod)%mod, ((data[3]*A[1])%mod + (data[4]*A[4])%mod + (data[5]*A[7])%mod)%mod, ((data[3]*A[2])%mod + (data[4]*A[5])%mod + (data[5]*A[8])%mod)%mod,
                 ((data[6]*A[0])%mod + (data[7]*A[3])%mod + (data[8]*A[6])%mod)%mod, ((data[6]*A[1])%mod + (data[7]*A[4])%mod + (data[8]*A[7])%mod)%mod, ((data[6]*A[2])%mod + (data[7]*A[5])%mod + (data[8]*A[8])%mod)%mod});
    }

    Vec operator*(Vec A){
        return
        Vec({ ((data[0]*A[0])%mod + (data[1]*A[1])%mod + (data[2]*A[2])%mod)%mod,
              ((data[3]*A[0])%mod + (data[4]*A[1])%mod + (data[5]*A[2])%mod)%mod,
              ((data[6]*A[0])%mod + (data[7]*A[1])%mod + (data[8]*A[2])%mod)%mod });
    }

    Matrix operator^(ll expo){
        Matrix result; result.id();
        Matrix self = (*this);

        while (expo) {
            if(expo&1) result = result*self;
            self = self*self;
            expo >>= 1;
        }

        return result;
    }
};

ll fib_sum(ll N){
    if(N <= 0) return 0;
    Matrix T; T.transform();
    Vec Fibo;

    T = T^(N-1);
    Fibo = T*Fibo;
    return Fibo[0];
}

auto main() -> int {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int N, M;
        std::cin >> N >> M;

        auto BEGIN = fib_sum(N-1);
        auto END   = fib_sum(M);
        std::cout << (END-BEGIN + mod)%mod << std::endl;
    }
    //print(Fibo);

    return 0;
}
