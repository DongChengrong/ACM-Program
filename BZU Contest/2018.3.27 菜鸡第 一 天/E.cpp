/*这个题是个求只交换两个数之后的最大的偶数问题
首先，因为长度高达10的五次方，所以我们首选字符串进行处理
其次，一个数的大小与位数和该数的大小有关
所以这个题优先考虑位数
另外，如果要交换的偶数比最后一位数大，交换之后数变小，这种情况下就不要交换了
但是，如果只有这一个偶数，那我们就不得不交换
时间复杂度O(N)
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
