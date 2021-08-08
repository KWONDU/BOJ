#include <iostream>
#include <vector>

using namespace std;

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

long long int lcm (int n1, int n2) {
    int temp1 = n1, temp2 = n2;
    while (temp1 > 0 && temp2 > 0) {
        if (temp1 > temp2) temp1 %= temp2;
        else temp2 %= temp1;
    }
    int gcd;
    if (temp1 > 0) gcd = temp1;
    else gcd = temp2;
    
    return (long long int)n1 * (long long int)n2 / (long long int)gcd;
}

int A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B;
	
	if (A == B) {
	    cout << "1";
	    return 0;
	}
	
	vector<int> divisor;
	int B_A = abs(B - A);
	for (int i = 1; i * i <= B_A; i++) {
	    if (B_A % i == 0) {
	        divisor.push_back(i);
	        if (i * i != B_A) divisor.push_back(B_A / i);
	    }
	}
	
	long long int minLCM = 4 * 1e18 + 1;
	int N = 1e9 + 1;
	for (int d : divisor) {
	    int tempN = d - A % d;
	    long long int tempLCM = lcm(A + tempN, B + tempN);
	    if (minLCM > tempLCM) {
	        minLCM = tempLCM;
	        N = tempN;
	    } else if (minLCM == tempLCM) N = min(tempN, N);
	}
	
	cout << N;
	
	return 0;
}