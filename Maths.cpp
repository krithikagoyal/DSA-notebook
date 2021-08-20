#include <bits/stdc++.h>
using namespace std;

const int N, MOD;

class Combinations {
   public:
    vector<long long> fact, ifact, inv;

    Combinations(const int n) {
        fact.assign(n + 1, 0);
        ifact.assign(n + 1, 0);
        inv.assign(n + 1, 0);

        fact[1] = fact[0] = 1;
        ifact[0] = ifact[1] = 1;
        inv[0] = inv[1] = 1;

        for (int i = 1; i <= N; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;

        for (int i = 2; i <= N; ++i)
            inv[i] = (((-(MOD / i) * inv[MOD % i]) % MOD) + MOD) % MOD;

        for (int i = 2; i <= N; ++i)
            ifact[i] = (ifact[i - 1] * inv[i]) % MOD;
    }

    long long C(int n, int k) {
        if (k > n)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return (fact[n] * ((ifact[n - k] * ifact[k]) % MOD)) % MOD;
    }
};

class Power {
   public:
    int power(int x, unsigned int y) {
        int res = 1;
        while (y > 0) {
            if (y & 1) res = res * x;
            y = y >> 1;
            x = x * x;
        }
        return res;
    }

    int _power(int x, unsigned int y, int p) {
        int res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    int invmod(int a, int m) { return _power(a, m - 2, m); }
};

void sieve(int MAXN, vector<int>& spf) {
    spf.resize(MAXN + 1);
    for (int i = 1; i <= MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getFactorization(int x, vector<int>& spf) {
    vector<int> pfactors;
    while (x != 1) {
        pfactors.push_back(spf[x]);
        x = x / spf[x];
    }
    return pfactors;
}

int main() {
    int mask;
    // iterate over all the subsets of the mask
    for (int i = mask; i > 0; i = (i - 1) & mask) {
        // i is a subset of mask
        // handle the case of 0 differently
    }
    for (int i = 0; i < (1 << N); ++i) {
        F[i] = A[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (mask & (1 << i))
                F[mask] += F[mask ^ (1 << i)];  // here I cant change the order of loop because
                                                // array is 1d whereas loops are 2.
        }
    }

    for (int mask = 0; mask < (1 << N); ++mask) {
        dp[mask][-1] = A[mask];  //handle base case separately (leaf states)
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i))
                dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << i)][i - 1];
            else
                dp[mask][i] = dp[mask][i - 1];
        }
        F[mask] = dp[mask][N - 1];
    }
}