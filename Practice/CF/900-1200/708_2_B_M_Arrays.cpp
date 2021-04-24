#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define read(x) cin >> x
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

int solve(vec<ll> &arr, int n, int m)
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        vec<ll> arr(n);
        rep(i, 0, n)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n, m) << endl;
    }
}