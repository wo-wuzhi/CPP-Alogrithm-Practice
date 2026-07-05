#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXP = 200000; 
vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAXP + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXP; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((ll)i * i <= MAXP) {
                for (int j = i * i; j <= MAXP; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> p(n + 1);
        p[1] = 1;
        for (int i = 2; i <= n; ++i) {
            p[i] = primes[i - 2]; 
        }
        vector<ll> a(n);
        a[0] = p[1];
        for (int i = 1; i < n; ++i) {
            a[i] = p[i] * p[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}