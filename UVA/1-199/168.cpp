#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define N 300

int vis[30];
char s[N];
vector<int> G[30];

int main() {

    while (gets(s) && s[0] != '#') {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 30; ++i) G[i].clear();
        int cur = s[0] - 'A';
        int pos = 2;
        while (s[pos] != '.') {
            if (s[pos] == ';') {
                cur = s[pos + 1] - 'A'; pos += 3;
            }
            else {
                G[cur].push_back(s[pos++] - 'A');
            }
        }
        pos += 2;
        int u = s[pos] - 'A'; pos += 2;
        int v = s[pos] - 'A'; pos += 2;
        int k = atoi(s + pos);
        int count = 0;
        while (1) {
            int next = -1;
            for (int i : G[u]) {
                if (!vis[i] && v != i) {
                    next = i; break;
                }
            }

            if (next == -1) {
                printf("/%c\n", u + 'A'); break;
            }
            ++count;
            v = u; u = next;
            if (count % k == 0) {
                vis[v] = 1;
                printf("%c ", v + 'A');
            }
        }
    }
    return 0;
}
