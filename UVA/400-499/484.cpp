#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ma;

int main() {
    int x;
    vector<int> vec;
    while (scanf("%d", &x) != EOF) {
        ++ma[x];
        if (ma[x] == 1) vec.push_back(x);
    }
    int n = vec.size();
    for (int i = 0; i < n; ++i) printf("%d %d\n", vec[i], ma[vec[i]]);
    return 0;
}
