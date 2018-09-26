//��Ϊ��ʼ�õ��˶�ά�����ɾ�������Ը��ӶȱȽϸ�
//����һ�£����ǿ�����һ����ά����洢�±꣬������һά����
//�洢��Ӧ�������β����һ��β���±�
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

#define N 220000

typedef long long ll;

char s[N];
vector<int> num[N], zeros, ones;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%s", s) != EOF) {
        int n = strlen(s), i, cnt = 0;
        zeros.clear(); ones.clear();
        for (i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (ones.size()) {
                    int t = ones.back(); ones.pop_back();
                    num[t].push_back(i + 1);
                    zeros.push_back(t);
                } else {
                    num[cnt] = vector<int>(1, i + 1);
                    zeros.push_back(cnt++);
                }
            } else {
                if (zeros.size()) {
                    int t = zeros.back(); zeros.pop_back();
                    num[t].push_back(i + 1);
                    ones.push_back(t);
                } else break;
            }
        }
        if (i < n || ones.size()) puts("-1");
        else {
            printf("%d\n", cnt);
            for (int i = 0; i < cnt; ++i) {
                printf("%d", num[i].size());
                for (int j = 0; j < num[i].size(); ++j) printf(" %d", num[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
