#include <iostream>
#include <algorithm>

using namespace std;

struct task{
    int start;
    int end;
}t[1000];

bool comp(task x, task y){
    return x.end < y.end;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i].start >> t[i].end;
    }

    sort(t,t+n, comp);

    int choose = 0;
    int a = 1;
    for (int i = 1; i < n; i++) {
        if (t[i].start >= t[choose].end){
            a++ ;
            choose = i;
        }
    }
    cout << a << endl;
}

int main(){
    solve();

    return 0;
}
