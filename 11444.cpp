#include <iostream>

using namespace std;

struct Matrix {
    long long int lu, ru, ld, rd;
    Matrix (long long int _lu, long long int _ru, long long int _ld, long long int _rd) {
        lu = _lu;
        ru = _ru;
        ld = _ld;
        rd = _rd;
    }
};

const int mod = 1e9 + 7;

long long int n;

Matrix multiply (Matrix m1, Matrix m2) {
    Matrix temp = Matrix(0, 0, 0, 0);
    temp.lu = ((m1.lu * m2.lu) % mod + (m1.ru * m2.ld) % mod) % mod;
    temp.ru = ((m1.lu * m2.ru) % mod + (m1.ru * m2.rd) % mod) % mod;
    temp.ld = ((m1.ld * m2.lu) % mod + (m1.rd * m2.ld) % mod) % mod;
    temp.rd = ((m1.ld * m2.ru) % mod + (m1.rd * m2.rd) % mod) % mod;

    return temp;
}

Matrix power (Matrix base, long long int exp) {
    if (exp == 1) return base;

    Matrix temp = power(base, exp / 2);
    if (exp % 2 == 0) return multiply(temp, temp);
    else return multiply(multiply(temp, temp), base);
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    Matrix m = Matrix(1, 1, 1, 0);
    Matrix ans = power(m, n);
    cout << ans.ld;

    return 0;
}