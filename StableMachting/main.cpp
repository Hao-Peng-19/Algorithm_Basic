#include <iostream>
#include <vector>

using namespace std;

bool wPrefersM1OverM(vector<vector<int>> prefer, int w, int m,int m1, int n){
    //判断函数
    for (int i = 0; i < n; i++)
    {   // 谁在前面更爱谁
        if (prefer[w+n][i] == m1)
            return true;
        if (prefer[w+n][i] == m)
            return false;
    }
    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> prefer(2*n, vector<int>(n)); //存储
    vector<bool> men (n, false); //表示男人有无约会对象
    vector<int> womenPartner(n, -1); //表示女人有无约会对象

    int freeCount = n;

    //存男性女性的优先表
    for(int i = 0 ; i < 2 * n ; i ++)
        for(int j = 0; j < n; j++)
            cin >> prefer[i][j];

    while(freeCount > 0){
        int m;
        //挑出未有对象的男性
        for (int i = 0; i < n; i++) {
            if (men[i] == false){
                m = i;
                break;
            }
        }
        //选对象
        for (int i = 0; i < n; i++) {
            int w = prefer[m][i];
            //女性没有对象时
            if (womenPartner[w]==-1){
                    womenPartner[w] = m;
                    men[m] = true;
                    freeCount--;
                    break;
            }

            //有对象时进入判断
            else{
                int m1 = womenPartner[w];
                if (wPrefersM1OverM(prefer, w, m, m1, n) == false){
                    womenPartner[w] = m;
                    men[m] = true;
                    men[m1] = false;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(womenPartner[i] == k){
            cout << i ;
            break;
        }
    }
}


int main(){
    solve();
}
