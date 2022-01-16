//
// Created by katsuya kikuchi on 2022/01/08.
//

#include <functional>
#include <vector>

#ifndef PROGRAMMINGCONTESTCPP_SEGMENTTREE_H
#define PROGRAMMINGCONTESTCPP_SEGMENTTREE_H

//
// 後で修正する
//
template<typename T>
struct SegmentTree {
    using F = std::function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(int n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const std::vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        if (left > right)
            return identity;
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    std::vector<T> node;
    int offset;
};

#endif //PROGRAMMINGCONTESTCPP_SEGMENTTREE_H
