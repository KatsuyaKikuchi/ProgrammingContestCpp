//
// Created by katsuya kikuchi on 2022/06/05.
//

#ifndef PROGRAMMINGCONTESTCPP_GCD_H
#define PROGRAMMINGCONTESTCPP_GCD_H

long long int gcd(long long int a, long long int b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#endif //PROGRAMMINGCONTESTCPP_GCD_H
