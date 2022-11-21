#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> color(10000, 0);
vector<bool> visit(10000, false);
vector<int> map[10000];
queue<int> q;


void bfs(int a){
    q.push(a);
    visit[a] = true;
    while(!q.empty()){
        a = q.front();
        q.pop();
        if(color[a] == 0)
            color[a] = 1;
        for (int i = 0; i < map[a].size(); i++) {
            int b = map[a][i];
            if(visit[b] == false){
                visit[b] = true;
                q.push(b);
                color[b] = -color[a];
            }
        }
    }
    return ;
}

/*void solve(vector<int> map[], int n){
    bool flag = 0;
    for (int i = 0; i <= n ; i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if(color[i] == color[map[i][j]]){
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return;
}*/

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if(color[i] == 0){
            bfs(i);
        }
    }

    //solve(map, n);
    bool ok = true;
    for(int i = 1; i <= n; i++)
    {
        for(int k = 0; k < (int)map[i].size(); k++)
        {
            if(color[i] == color[map[i][k]]){
                ok = false;
                break;
            }
        }
    }

    if(ok)
        cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";

    return 0;
}

