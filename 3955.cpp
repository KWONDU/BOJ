#include <iostream>

using namespace std;

int t, K, C;

int gcd (int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) n1 %= n2;
        else n2 %= n1;
    }
    if (n1 > 0) return n1;
    else return n2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while (t--) {
	    cin >> K >> C;
	    
	    // C = 1, K = 1 인 경우 2 를 출력해야 되기 때문에 C를 K보다 먼저 확인한다
	    if (C == 1) {
	        if (K + 1 > 1e9) cout << "IMPOSSIBLE\n";
	        else cout << (K + 1) << "\n";
	        continue;
	    } else if (K == 1) {
	        cout << "1\n";
	        continue;
	    }
	    
	    if(gcd(K, C) != 1) {
	        cout << "IMPOSSIBLE\n";
	        continue;
	    }
	    
	    //Extended Euclidean Algorithm
	    long long int rPrev = C, rCur = K, sPrev = 1, sCur = 0, tPrev = 0, tCur = 1, rNxt, sNxt, tNxt, q;
	    while (rCur != 0) {
	        q = rPrev / rCur;
	        rNxt = rPrev % rCur;
	        rPrev = rCur, rCur = rNxt;
	        sNxt = sPrev - q * sCur;
	        sPrev = sCur, sCur = sNxt;
	        tNxt = tPrev - q * tCur;
	        tPrev = tCur, tCur = tNxt;
	    }
	    
	    while (sPrev <= 0) sPrev += K;
	    
	    if (sPrev > 1e9) cout << "IMPOSSIBLE\n";
	    else cout << sPrev << "\n";
	}
	
	return 0;
}