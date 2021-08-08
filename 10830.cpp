#include <iostream>

using namespace std;

int N;
long long int B;
int A[25];

const int mod = 1000;

int* mulN (int* a1, int* a2) {
    int* ret = new int[N * N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            ret[i * N + j] = 0;
            for (int k = 0; k < N; k++) {
                ret[i * N + j] += ( a1[i * N + k] * a2[k * N + j] ) % mod;
                ret[i * N + j] %= mod;
            }
        }
    
    return ret;
}

int* cal (long long int b) {
    if (b == 1) return A;
    
    int* temp1Arr = cal(b / 2);
    int* temp2Arr = mulN(temp1Arr, temp1Arr);
    if (b % 2 == 0) return temp2Arr;
    else return mulN(A, temp2Arr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> A[i * N + j];
            A[i * N + j] %= mod;
        }
    
    int* ans = cal(B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << ans[i * N + j] << " ";
        cout << endl;
    }
    
    return 0;
}