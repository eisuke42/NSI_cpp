#include <bits/stdc++.h>
using namespace std;

int N;
double long dist[15][15];
int pos[15][2];
vector<int> best;
vector<int> cur;
double long totM = 1000000000;

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

    for (int i = 0; i < N; i ++) cur.push_back(i);

    do
    {
        double long tot = 0;
        for (int i = 0; i < N; i ++)
        {
            tot += dist[cur[i]][cur[(i+1)%N]];
        }
        if (tot < totM)
        {
            best = cur;
            totM = tot;
        }
    }
    while (next_permutation(cur.begin(), cur.end()));

    for (auto e : best) cout << e << ' ';
    cout << '\n' << score(best) << '\n';
}