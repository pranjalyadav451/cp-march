#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
// #define data _data


#define int long long

const int N = 1e6 + 1;
vector<pair<bool, int>> isPrime(N, {true, 0});

void sieve()
{
	isPrime[0] = {0, 0};
	isPrime[1] = {0, 0};

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i].fi)
		{
			for (int j = i; j * i < N; j++)
			{
				isPrime[j * i].fi = 0;
			}
		}
	}
}
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

void solve()
{

	int cnt_prime = 0;
	int cnt_pp = 0;

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i].first)
		{
			cnt_prime++;

		}
		if (isPrime[cnt_prime].first)
			cnt_pp++;
		isPrime[i].se = cnt_pp;
	}

}

int32_t main()
{

	sieve();
	solve();
	int tt;
	cin >> tt;
	while (tt--)
	{
		ll l, r;
		cin >> l >> r;
		cout << isPrime[r].se - isPrime[l - 1].se << endl;
	}
}


/*
*
*	isPrime[r].se - isPrime[l].se + 1
* 	The above code fails when -:
		- the numbers at l and l-1 have equal prime_prime numbers
*/