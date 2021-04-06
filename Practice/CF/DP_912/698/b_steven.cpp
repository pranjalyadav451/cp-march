// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;

// =========== Book ============ //

// ============= Solution ============= //
//
// Observation 1: Because d itself is lucky, then if you can make k, you can make k + any multiple of d
// Formulate the problem as: for every 0 <= i < d, what is the minimum x where x % d == i such that x can be written as a sum of lucky nmubers?
//
// --> this question is independent of the 10^4 queries; it can be computed offline (preprocessing)
//
// Example 1: q = 3, d = 7.
// 7 is lucky. So if you can make x, you can make x + 7 (and x + 14, x + 21, etc)
//
// So we want to know, for each of i = 0, 1, ... 6,
// What is the minimum x (where x % 7 == i) such that you make x?
// To rephrase: Of all the makable numbers, what is the smallest one that is congruent to i mod x?
//
// Observation 2: Strategy for actually finding these key "x" values --> approach like a
//   knapsack problem
//
// Implementation strategy: vector<bool> (or bitset) of "makable" elements
//
int main()
{ // dobby is a free elf
    int T;
    cin >> T;

    const int maxn = 100;
    vector<vector<bool>> can(10, vector<bool>(maxn));
    for (int d = 1; d <= 9; ++d)
    {
        auto &makable = can[d];
        makable[0] = 1;
        for (int j = 0; j < 100; ++j)
        {
            int d0 = j % 10, d1 = j / 10;
            if (d0 == d || d1 == d)
            { // check if j is lucky
                for (int k = 0; k + j < maxn; ++k)
                {
                    // if k is makable, then k + j is makable
                    // "relax" this condition with the below assignment
                    makable[k + j] = makable[k + j] || makable[k];
                }
            }
        }
    }

    while (T--)
    {
        int q, d;
        cin >> q >> d;
        for (int i = 0; i < q; ++i)
        {
            int x;
            cin >> x;
            if (x >= 100)
            {
                int sub = (x - 99 + d - 1) / d;
                x -= sub * d;
            }
            if (can[d][x])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}