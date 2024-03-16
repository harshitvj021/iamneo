#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    int P[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    P[N] = -1;

    int day[N + 1];
    int pre[N + 1];
    int nex[N + 1];
    bool done[N + 1] = {false};
    queue<int> q;

    for (int i = N - 1; i >= 1; i--) {
        pre[i] = i - 1;
        nex[i] = i + 1;
        if (P[i] > P[i - 1]) {
            day[i] = 1;
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (done[cur]) {
            continue;
        }

        done[cur] = true;
        ans = day[cur];
        nex[pre[cur]] = nex[cur];
        pre[nex[cur]] = pre[cur];

        if (P[nex[cur]] > P[pre[cur]]) {
            day[nex[cur]] = day[cur] + 1;
            q.push(nex[cur]);
        }
    }

    cout << ans;

    return 0;
}
