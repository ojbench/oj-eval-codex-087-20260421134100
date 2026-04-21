#include <bits/stdc++.h>
using namespace std;

static long long landing_position(long long D, long long n) {
    long long idx = 1;
    // We need the leaf switch index (depth D), so take D-1 decisions
    for (int i = 0; i < D - 1; ++i) {
        if (n & 1LL) {
            idx = idx * 2;
            n = (n + 1) / 2;
        } else {
            idx = idx * 2 + 1;
            n = n / 2;
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, n;
    if (!(cin >> D >> n)) return 0;

    long long last = landing_position(D, n);

    vector<long long> counts(1, n);
    // Propagate D-1 levels to reach leaves at depth D
    for (int depth = 0; depth < D - 1; ++depth) {
        vector<long long> next(counts.size() * 2, 0);
        for (size_t i = 0; i < counts.size(); ++i) {
            long long c = counts[i];
            long long left = (c + 1) / 2; // odds
            long long right = c / 2;      // evens
            next[2 * i] += left;
            next[2 * i + 1] += right;
        }
        counts.swap(next);
    }

    cout << last << '\n';
    for (size_t i = 0; i < counts.size(); ++i) {
        if (i) cout << ' ';
        cout << (counts[i] & 1LL);
    }
    cout << '\n';
    return 0;
}
