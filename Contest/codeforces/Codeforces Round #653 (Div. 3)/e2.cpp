#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec1, vec2, vec3, vec4;

int main() {
    int n, m, K;
    while (scanf("%d%d%d", &n, &m, &K) != EOF) {
        int a, b, t;
        vec1.clear(); vec2.clear(); vec3.clear(); vec4.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &t, &a, &b);
            if (!a && !b) vec4.push_back(t);
            if (a && b) vec1.push_back(t);
            else if (a) vec2.push_back(t);
            else if (b) vec3.push_back(t);
        }
        int sz1 = vec1.size();
        int sz2 = vec2.size();
        int sz3 = vec3.size();
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        sort(vec3.begin(), vec3.end());
        sort(vec4.begin(), vec4.end());
        int i = 0, j = 0, k = 0, num = 0;
        a = b = t = 0;
        while (i < sz1 && (j < sz2 && k < sz3)) {
            if (vec1[i] < vec2[j] + vec3[k]) {
                ++a; ++b; t += vec1[i]; ++i; num++;
            } else {
                ++a; ++b; t += vec2[j] + vec3[k]; ++j; ++k; num += 2;
            }
            if (a == K) break;
        }
        while (i < sz1 && (a < K)) {
            ++a; ++num;
            t += vec1[i++];
        }
        while ((j < sz2 && k < sz3) && (a < K)) {
            ++a; num += 2;
            t += vec2[j] + vec3[k]; ++j; ++k;
        }
        while (num < m) {
            if ()
        }
        if (a < K) puts("-1");
        else printf("%d\n",t);
    }
    return 0;
}
