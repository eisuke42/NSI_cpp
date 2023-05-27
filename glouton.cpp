#include <bits/stdc++.h>
using namespace std;

int N;
const int MAXN = 500;
double long dist[MAXN][MAXN];
int pos[MAXN][2];
bool pris[MAXN];
vector<int> cur;

double long score(vector<int> rep)
{
    double long res = 0;
    for (int i = 0; i < (int)rep.size(); i ++)
    {
        res += dist[rep[i]][rep[(i+1)%rep.size()]];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> pos[i][0] >> pos[i][1];
    }
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j ++)
        {
            dist[i][j] = pow(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2), 0.5);
        }
    }
    cur.push_back(0);
    pris[0]=true;
    for (int i = 1; i < N; i ++)
    {
        double long mini = 1000000000; int id = -1;
        for (int pro = 0; pro < N; pro++)
        {
            if (pris[pro]) continue;
            if (dist[cur[i-1]][pro] < mini)
            {
                mini = dist[cur[i-1]][pro];
                id = pro;
            }
        }
        cur.push_back(id);
        pris[id] = true;
    }
    for (int i = 0; i < N; i ++) cout << cur[i] << ' ';
    cout << '\n' << score(cur)<<'\n';
}