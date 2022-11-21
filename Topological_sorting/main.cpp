#include <iostream>
#include <vector>
using namespace std;

int flag = 0;
void dfs(vector<int> prerequisites[],int src,vector<bool> visit){
    if(visit[src]){
        flag = 1;
        return ;
    }
    int size = prerequisites[src].size();
    visit[src] = true;
    for (int i = 0; i < size; i++) {
        dfs(prerequisites,prerequisites[src][i],visit);
    }
    visit[src] = false;

    return ;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> prerequisites[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin>>x;
        getchar();
        cin>>y;
        prerequisites[x].push_back(y);
    }
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++) {
        dfs(prerequisites, i, visit);
    }

    if(flag == true)
        cout << "false";
    else
        cout << "true";
}