#include <bits/stdc++.h>
using namespace std;
int N;
const int MAXN = 500;
long double dist[MAXN][MAXN];
int pos[MAXN][2];
bool pris[MAXN];
vector<int> cur;
vector<int> voisin; int suiv[MAXN]; 

long double score(vector<int> rep)
{
    long double res = 0;
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

    int deb = clock();
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
        long double mini = 1000000000; int id = -1;
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
        suiv[cur[i-1]] = id;
    }
    suiv[cur[N-1]] = 0;

    long double actu = score(cur);
    while (clock() - deb < 1.95e6)
    {
        voisin.clear();
        long double mini = 1000000000;int aM = -1, bM = -1;
        for (int a = 0; a < N; a ++)
        {
            for (int b= a+1; b < N; b ++)
            {
                int s1 = cur[a], s2 = cur[b];
                long double vois = actu + dist[cur[a]][cur[b]] + dist[cur[(a+1)%N]][cur[(b+1)%N]] - dist[cur[a]][cur[(a+1)%N]] - dist[cur[b]][cur[(b+1)%N]];
                if (vois < mini)
                {
                    mini = vois;
                    aM = a;
                    bM = b;
                }
            }
        }
        if (mini >= actu)
        {
            //cout << actu << '\n';
            //for (int i = 0; i < N; i ++) cout << cur[i] << ' ';
            //cout << '\n';
            return 0;
        }
        int a = aM, b = bM;
        int id1 = (b+1)%N, id2 = b;
        do
        {
            voisin.push_back(cur[id2]);
            id2 = (id2+N-1)%N;
        }    
        while (id2 != (a)%N);
        do
        {
            voisin.push_back(cur[id1]);
            id1 = (id1+1)%N;
        }
        while(id1 != (a+1)%N);
        cur = voisin;
        actu = mini;
        /*
        for (int i = 0; i < cur.size(); i ++) cout << cur[i] << ' ';
        cout << " : ";
        for (int i = 0;i < voisin.size(); i ++) cout << voisin[i] << ' ';
        cout << score(cur) << ' ' <<score(voisin) << ' ' << a << ' ' << b <<'\n';
        */
        cout << actu << '\n';
    }

    //cur.clear();
    /*
    int i =0;
    do
    {
        cout << i << ' ';
        cur.push_back(i);
        i = suiv[i];
    }
    while (i != 0);
    */
    //for (int i = 0; i < N; i ++) cout << cur[i] << ' ';
    //cout << '\n' << score(cur) << '\n';
}