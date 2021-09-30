#ifndef PROGRAMMINGCONTESTCPP_COMBINATION_H
#define PROGRAMMINGCONTESTCPP_COMBINATION_H

template<std::uint_fast64_t Modulus>
struct Combination {
    using u64 = std::uint_fast64_t;

    explicit Combination(int n) {
        frac.resize(n + 1);
        invFrac.resize(n + 1);
        frac[0] = 1;
        for (int i = 0; i < n; ++i) {
            frac[i + 1] = frac[i] * (i + 1) % Modulus;
        }
        invFrac[n] = inv(frac[n]);
        for (int i = n; i > 0; --i) {
            invFrac[i - 1] = (invFrac[i] * i) % Modulus;
        }
    }

    u64 get(int n, int r) {
        if (n < r)
            return 0;
        return (frac[n] * invFrac[r] % Modulus) * invFrac[n - r] % Modulus;
    }

private:
    u64 inv(u64 n) {
        u64 ret = 1;
        u64 m = Modulus - 2;
        u64 p = n;
        while (m > 0) {
            if ((m & 1) == 1)
                ret = (ret * p) % Modulus;
            m /= 2;
            p = (p * p) % Modulus;
        }
        return ret;
    }

    vector<u64> frac;
    vector<u64> invFrac;
};

#endif //PROGRAMMINGCONTESTCPP_COMBINATION_H
