/*������Ǹ���ֻ����������֮�������ż������
���ȣ���Ϊ���ȸߴ�10����η�������������ѡ�ַ������д���
��Σ�һ�����Ĵ�С��λ���͸����Ĵ�С�й�
������������ȿ���λ��
���⣬���Ҫ������ż�������һλ���󣬽���֮������С����������¾Ͳ�Ҫ������
���ǣ����ֻ����һ��ż���������ǾͲ��ò�����
ʱ�临�Ӷ�O(N)
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 100010

char s[N];

int main()
{
    while(scanf("%s",s) == 1)
    {
        int i = 0,MIN = -1;
        int len = strlen(s);
        while(i < len){
            if( (s[i] - '0') % 2 == 0 ){
                MIN = i;
                if(s[i] < s[len - 1]) break;
            }
            i++;
        }

        if(MIN == -1) printf("-1\n");
        else{
            swap(s[MIN],s[len - 1]);
            printf("%s\n",s);
        }
    }
    return 0;
}
