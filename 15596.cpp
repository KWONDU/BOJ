#include <vector>

long long sum (std::vector<int> &a) {
    long long int ret = 0;
    for (int x : a) ret += x;
    return ret;
}