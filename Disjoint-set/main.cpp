#include <iostream>
using namespace std;
int fa[1000];

int find(int x){
    while(x != fa[x])
        x = fa[x];
    return x;
}

void Union(int x,int y){
    fa[y] = x;
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int z1 = find(x);
        int z2 = find(y);
        if(z1!=z2)
            Union(z1,z2);
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int z1 = find(x);
        int z2 = find(y);
        if(z1 == z2)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}