#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    srand(clock());
    
    int N = 100;
    cout << N << '\n';
    for (int i = 0; i < N; i ++)
    {
        cout << rand()%10000 << ' ' << rand()%10000 << '\n';
    }
}