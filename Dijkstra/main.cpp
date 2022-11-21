#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    int a,b;
    cin >> n >> m;
    cin >> a >> b;
    vector<vector<int> > point(n*n, vector<int>(-1)); //用于存放图
    vector<int> dis(n,-1);
    vector<bool> vis(n, false);
    dis[a] = 0;
    /* 把图存入一个二维数组 */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if( i == j){
                point[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x, y;
            double l;
            cin >> x >> y >> l;
            point[x][y] = l;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int node = -1;
        for (int j = 0; j < n; j++) {
            if(!vis[j] && (node = -1 || dis[j] < dis[node]))
                node = j;
            }
        for(int j = 0; j < n; j++){
            dis[j] = min(dis[j], dis[node] + point[node][j]);
        }
        vis[i] = true;
    }
}