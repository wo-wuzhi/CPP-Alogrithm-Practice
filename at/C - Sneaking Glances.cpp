#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> L;
int max_passes = 0;

void dfs(int step, long long pos, int passes) {
    if (step == N) {
        max_passes = max(max_passes, passes);
        return;
    }
    long long dist = L[step];
    {
        int new_passes = passes;
        if (pos < 0 && dist > -pos) {
            new_passes++;
        }
        dfs(step + 1, pos + dist, new_passes);
    }
    {
        int new_passes = passes;
        if (pos > 0 && dist > pos) {
            new_passes++;
        }
        dfs(step + 1, pos - dist, new_passes);
    }
}

int main() {
    cin >> N;
    L.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
        L[i] *= 2;
    }
    dfs(0, 1, 0); 
    cout << max_passes << endl;
    return 0;
}