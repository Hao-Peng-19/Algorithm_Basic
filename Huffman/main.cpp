#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<>> Huffman;
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Huffman.push(a);
    }
    int cost = 0;
    while(Huffman.size()!=1){
        int P = Huffman.top();
        Huffman.pop();
        int Q = Huffman.top();
        Huffman.pop();
        cost += P + Q;
        Huffman.push(P+Q);
    }
    cout << cost;
    return 0;
}