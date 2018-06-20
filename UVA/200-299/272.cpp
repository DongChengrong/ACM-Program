#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string buffer;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int flag = 0;
    while (getline(cin, buffer)) {
        for (int i = 0; i < buffer.size(); ++i) {
            if (buffer[i] == '"') {
                if (!flag) printf("``");
                else printf("''");
                flag = !flag;
            } else printf("%c", buffer[i]);
        }
        puts("");
    }
    return 0;
}
