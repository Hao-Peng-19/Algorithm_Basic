#include <iostream>
using namespace std;
#define INF 99999
int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    double map[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        double s;
        cin >> x >> y >> s;
        map[x][y] = s;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    printf("%.2f\n",map[a][b]);
}
