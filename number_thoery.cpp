#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

//Basic Euclidean GCD. Time complexity: O(log(min(a,b))
long long GCD(long long a, long long b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

//Time complexity: O(log(min(a,b))
long long LCM(long long a, long long b){
    long long gcd = GCD(a,b);
    return (a*b)/gcd;
}

//Pre-calculating factorial with MOD 1e9+7
vector<long long> pre_factorial(int n){
    vector<long long> fact(n+1);

    fact[0] = 1;

    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    return fact;
}

// (a^n) MOD 1e9+7
long long power(long long a, int n){
    long long res = 1;

    while(n){
        if(n&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return res;
}

long long MODInverse(long long n){
    return power(n,MOD-2);
}

// nCr MOD 1e9+7
long long nCr(long long n, long long r){
    vector<long long> fact = pre_factorial(n);
    
    int ans = (fact[n]*MODInverse(r)%MOD)%MOD;

    ans = (ans*MODInverse(n-r)%MOD)%MOD;
//
    ans %= MOD;

    return ans;
    
}

//All prime numbers till n. Time Complexity: O(NlogNlogN)
vector<int> Sieve(int n){
    int prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=2*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }

    vector<int> alls;

    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            alls.push_back(i);
        }
    }

    return alls;
}

//all divisors of n. Time Complexity: O(sqrt(N))
vector<int> factors(int n){
    vector<int> alls;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(n/i==i) alls.push_back(i);
            else{
                alls.push_back(n/i);
                alls.push_back(i);
            }
        }
    }

    return alls;
}

//prime factorization. Time Complexity: O(sqrt(N))
vector<int> prime_factorisation(int n){
    vector<int> alls;
    bool ok = 0;
    while(n%2==0){
        if(ok==0) alls.push_back(2);
        ok = 1;
        n /= 2;
    }

    for(int i=3;i*i<=n;i+=2){
        ok = 0;

        while(n%i==0){
            if(ok==0) alls.push_back(i);
            ok = 1;
            n /= i;
        }
    }

    if(n>1) alls.push_back(n);

    return alls;
}

int main(){

    return 0;
}
