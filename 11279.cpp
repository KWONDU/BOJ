#include <iostream>

using namespace std;

int heap[131072 + 1];
int heapSize;

void heapInsert (int x) {
    heap[++heapSize] = x;
    
    int pos = heapSize;
    while (pos > 1) {
        int comp = pos / 2;
        if (heap[comp] < heap[pos]) {
            int temp = heap[pos];
            heap[pos] = heap[comp];
            heap[comp] = temp;
            pos = comp;
        } else break;
    }
}

int heapDelete () {
    if (heapSize == 0) return 0;
    
    int x = heap[1];
    heap[1] = heap[heapSize--];
    
    int pos = 1;
    while (pos <= heapSize / 2) {
        int comp = pos * 2;
        if (comp + 1 <= heapSize && heap[comp + 1] > heap[comp]) comp++;
        if (heap[pos] < heap[comp]) {
            int temp = heap[pos];
            heap[pos] = heap[comp];
            heap[comp] = temp;
            pos = comp;
        } else break;
    }
    
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    heapSize = 0;
    
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) cout << heapDelete() << "\n";
        else heapInsert(x);
    }
    
    return 0;
}