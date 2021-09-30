#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int MAX_C = 7500;
const int MAX_P = 23;
vector <int> bad[MAX_C + 1], b[MAX_P + 1];
vector <int> primes, lp(MAX_C + 1, -1);
int a[(1 << MAX_P) + 1], c[(1 << MAX_P) + 1];
signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i <= MAX_C; i++)
    {
        if(lp[i] == -1)
        {
        int j = i ;
        while(j <= MAX_C)
        {
            lp[j] = lp[j] != -1 ? lp[j] : sz(primes);
            j += i;
        }
            primes.push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n, C;
        cin >> n >> C;
        int m = 1, k = 1;
        while(primes[m] * primes[m + 1] <= C)
        {
            m++;
        }
        while(k < sz(primes) && primes[k] <= C)
        {
            k++;
        }
        for(int i = 0; i < k; i++)
        {
            bad[i].clear();
        }
        for(int mask = 0; mask < (1 << m); mask++)
        {
            a[mask] = 0;
        }
        for(int i = 0; i <= m; i++)
        {
            b[i] = vector <int> (1 << i);
        }
        for(int i = 0; i < n; i++)
        {
            int x, mask = (1 << m) - 1;
            cin >> x;
            for(;x > 1 && lp[x] < m; x = x / primes[lp[x]])
            {
                mask = mask & (~(1 << lp[x]));
            }
            if(x == 1)
            {
                a[mask] = MAX_C;
            }
            else
            {
                bad[lp[x]].push_back(mask);
            }
        }
        for(int l = m; l < k; l += m)
        {
            int sz = 0;
            while(sz < m && primes[l] * primes[sz] <= C)
            {
                sz++;
            }
            for(int mask = 0; mask < (1 << sz); mask++)
            {
                c[mask] = 0;
            }
            for(int i = l; i < min(l + m, k); i++)
            {
                for(auto &x : bad[i])
                {
                    c[((1 << sz) - 1) & x] |= (1 << (i - l));
                }
            }
            for(int mask = (1 << sz) - 1; mask > 0; mask--)
            {
                for(int i = 0; i < sz; i++)
                {
                    if((mask >> i) & 1)
                    {
                        c[mask ^ (1 << i)] |= c[mask];
                    }
                }
            }
            for(int mask = 0; mask < (1 << sz); mask++)
            {
                b[sz][mask] += __builtin_popcount(c[mask]);
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int mask = 0; mask < (1 << i); mask++)
            {
                a[mask + (1 << m) - (1 << i)] += b[i][mask];
            }
            for(int mask = 0; mask < (1 << m); mask++)
            {
                if((1 << i) & mask)
                {
                    continue;
                }
                a[mask] += a[mask ^ (1 << i)];
            }
        }
        for(int mask = 0; mask < (1 << m); mask++)
        {
            a[mask] += b[m][mask];
        }
        pair <int, int> ans = {MAX_C, 0};
        for(int mask = 0; mask < (1 << m); mask++)
        {
            int t = __builtin_popcount(mask);
            if(a[mask] + t <  ans.X)
            {
                ans = {a[mask] + t, mask};
            }
        }
        cout << ans.X << "\n";
        for(int j = 0; j < m; j++)
        {
            if((1 << j) & ans.Y)
            {
                cout << primes[j] << " ";
            }
        }
        for(int j = m; j < k; j++)
        {
            for(auto p : bad[j])
            {
                if((p & ans.Y) == ans.Y)
                {
                    cout << primes[j] << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
