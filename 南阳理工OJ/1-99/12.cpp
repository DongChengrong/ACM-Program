#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 10;

int w,h,n;

struct Dev
{
    int p,r;   //p�������꣬r����뾶
    double start, end;
    Dev(){}
    Dev(int p,int r)
    {
        this->p = p;
        this->r = r;
        if(2 * r < h)   //������ˮװ������
        {
            this->start = this->end = -1;
            return;
        }
        double x = sqrt(pow(r,2) - pow((double)h / 2,2));
        this->start = (double)p - x < 0 ? 0 : (double)p - x;
        this->end = (double)p + x > w ? w : (double)p + x;
    }

    bool operator < (const Dev &a) const
    {
        return this->start < a.start;
    }

}D[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&w,&h);
        for(int i = 0; i < n; i++)
        {
            int p,r;
            scanf("%d%d",&p,&r);
            D[i] = Dev(p,r);
        }

        //����ˮװ�ð������λ�ô�С��������
        sort(D, D + n);

        int count = 0;
        bool ok = true;
        double start = 0,end = 0;
        for(int i = 0; i < n; i++)
        {
            if(D[i].start == -1) continue;  //ѡ�����ˮװ������
            if(end < D[i].start) break;
            if(end == w) break;

            if(D[i].start <= start)
                end = max(end,D[i].end);
            else
            {
                start = end;
                if(D[i].start <= start)
                {
                    end = max(end,D[i].end);
                    count++;
                }
                else
                    break;
            }
        }

        count++;
        if(end != w) ok = false;

        if(ok) printf("%d\n",count);
        else printf("0\n");

    }
    return 0;
}
