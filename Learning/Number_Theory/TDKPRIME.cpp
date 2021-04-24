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

const int N = 1e8;
bool isPrime[N]; //isPrime[i] = 0 indicates i is prime.
vector<int> primes;
void sieve()
{
    isPrime[0] = isPrime[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        if (!isPrime[i])
        {
            primes.push_back(i);
            for (ll j = i; j * i < N; j++)
                isPrime[j * i] = 1;
        }
    }

}


int main()
{

    sieve();
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        cout << primes[k - 1] << endl;
    }
    return 0;
}