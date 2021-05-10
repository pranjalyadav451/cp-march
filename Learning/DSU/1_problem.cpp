#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
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
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for (int i = (a); i <= (b); (i)++)
#define rrep(i, a, b) for (int i = (a); i >= (b); (i)--)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/**
 * You have 'n' persons standing at 'n' positions.
 * - X : means the person has left.
 * ? X : find the nearest person to the right (including the position of 'X') who hasn't left.
 * If there is no one standing to the right, then return -1.
 * N <=10^6
 * Queries <= 10^6
*/
const int N = 1e6 + 10;
int parent[N];
int Get(vector<int> & parent , int x) {
	if (parent[x] == -1) return parent[x];
	return parent[x] = ((parent[x] == x) ? x : Get(parent, parent[x]));
}
void Union(vector<int> & parent, int left, int right) {
	int p_left = Get(parent, left), p_right = Get(parent, right);
	parent[p_left] = p_right;
}


int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> parent(N + 5);
	for (int i = 1; i <= parent.size(); i++) {
		parent[i] = i;
	}
	while (M--) {
		char ch;
		int pos;
		cin >> ch >> pos;
		if (ch == '-') {
			Union(parent, pos, pos + 1);
		}
		if (ch == '?') {
			int res = Get(parent, pos);
			if (res == N + 1) cout << -1 << endl;
			else cout << res << endl;
		}
	}

}
