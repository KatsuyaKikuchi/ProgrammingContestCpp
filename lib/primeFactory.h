//
// Created by katsuya kikuchi on 2022/05/14.
//

#ifndef PROGRAMMINGCONTESTCPP_PRIMEFACTORY_H
#define PROGRAMMINGCONTESTCPP_PRIMEFACTORY_H

struct PrimeFactory {
    PrimeFactory(int n) {
        primes.clear();
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i])
                continue;
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<pair<int, int>> factorization(long long int n) {
        vector<pair<int, int>> ret;
        for (auto p: primes) {
            int c = 0;
            while (n % p == 0) {
                c++;
                n /= p;
            }
            if (c > 0)
                ret.emplace_back(p, c);
        }
        if (n > 1) {
            ret.emplace_back(n, 1);
        }
        return ret;
    }

    vector<int> primes;
};


#endif //PROGRAMMINGCONTESTCPP_PRIMEFACTORY_H
