#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/rope>

#define op() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

int n, m, x, y, z;

const int INF = 1e9 + 7;

vector<pii> adj[100001];

vector<int> dijkstra_y(int st)
{
    vector<int> dist(n+1, INF);

    priority_queue<pii, vector<pii>, greater<pii>> p;

    dist[st] = 0;

    p.push({dist[st], st});

    while(!p.empty())
    {
        auto [co, cu] = p.top(); p.pop();

        if(dist[cu] < co) continue;

        for(auto& [nc, n] : adj[cu])
        {
            if(dist[n] > nc + co)
            {
                dist[n] = nc + co;
                p.push({dist[n], n});
            }
        }
    }

    return dist;
}

vector<int> dijkstra(int st)
{
    vector<int> dist(n+1, INF);

    priority_queue<pii, vector<pii>, greater<pii>> p;

    dist[st] = 0;

    p.push({dist[st], st});

    while(!p.empty())
    {
        auto [co, cu] = p.top(); p.pop();

        if(dist[cu] < co) continue;

        for(auto& [nc, n] : adj[cu])
        {
            if(n == y) continue;
            
            if(dist[n] > nc + co)
            {
                dist[n] = nc + co;
                p.push({dist[n], n});
            }
        }
    }

    return dist;
}

int32_t main()
{
    op()

    cin >> n >> m;

    while(m--)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    cin >> x >> y >> z;

    vector<int> d1 = dijkstra_y(x), d2 = dijkstra_y(y);
    vector<int> dist = dijkstra(x);

	int rd1 = d1[y], rd2 = d2[z];

    if(rd1 == INF || rd2 == INF)
        cout << -1 << " ";
    else cout << rd1 + rd2 << " ";

    cout << (dist[z] == INF ? -1 : dist[z]) << "\n";
    
	return 0;
}