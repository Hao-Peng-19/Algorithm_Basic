#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[100];
vector<bool> visit(1000,false);
vector<int> color(1000, 0);
queue<int> q;

void bfs(int x){
    q.push(x);
    visit[x] = true;
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(color[x] == 0)
            color[x] = 1;
        for(int i = 0; i < map[x].size(); i++){
            int b = map[x][i];
            if(visit[b]==false){
                visit[b] = true;
                q.push(b);
                color[b] = -color[x];
            }
        }
    }
    return ;
}

int main(){
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if(color[i] == 0)
            bfs(i);
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if(color[i] == color[map[i][j]])
                flag = false;
            break;
        }
    }

    if(flag == true)
        cout <<"YES";
    else
        cout << "NO";

    return 0;
}
