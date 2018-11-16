#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n) {
             n = n - 1;
             printf("%d\n", n);
	 }
    }
    return 0;
}
