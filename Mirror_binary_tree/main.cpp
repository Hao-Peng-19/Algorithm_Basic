#include <iostream>
#include <vector>

using namespace std;
vector<int> tree(10000);

int main(){
    int ele = 0;
    while(cin >> tree[++ele]);
    int len = 1;
    int l = 1;
    while(true){
        int r = l + len - 1;
        while(l<=r){
            if(tree[l]!=tree[r]){
                cout << "NO";
                return 0;
            }
            l++;
            r--;
        }
        len <<= 1 ;
        l = len;
        if(l > ele)
            break;
    }
    cout << "YES";
}