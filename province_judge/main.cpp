#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main()
{
    int n;
    int a[100][100];
    queue<int> q;
    int b[100];
    memset(b,0,sizeof(b));
    cin>>n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
                scanf("%d",&a[i][j]);
            else scanf(",%d",&a[i][j]);
        }

    int sum = 0;
    for(int k = 0; k < n; k++)
    {
        if(b[k]==0)
        {
            q.push(k);
            b[k] = 1;
            sum++;
        }
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(int i = 0; i < n; i++)
            {
                if(!b[i] && a[t][i])
                {
                    b[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    cout<<sum<<"\n";

    return 0;
}