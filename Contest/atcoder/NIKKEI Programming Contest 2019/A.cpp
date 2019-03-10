#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int main() {
    int n, a, b;
    while (scanf("%d%d%d", &n, &a, &b) != EOF)  {
        printf("%d %d\n", min(a, b), a + b - n > 0 ? a + b - n : 0 );
    }
    return 0;
}
