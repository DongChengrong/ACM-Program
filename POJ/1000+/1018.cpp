#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;

struct Dev
{
    double b,p;
    bool operator < (const Dev& a) const
    {
        return this->b < a.b;
    }
}D[maxn][maxn];

double B[maxn * maxn];
int m[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,id = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&m[i]);
            for(int j = 0; j < m[i]; j++)
            {
                scanf("%lf%lf",&D[i][j].b,&D[i][j].p);
                B[id++] = D[i][j].b;
            }
        }

        sort(B,B+id);
        double Max = 0;
        for(int i = 0; i < id; i++)
        {
            double sum = 0;
            int flag = 0;
            for(int j = 0; j < n; j++)
            {
                double Min = 100000;
                for(int k = 0; k < m[j]; k++)
                {
                    if(B[i] <= D[j][k].b)
                    {
                        Min = min(Min,D[j][k].p);
                        flag = 1;
                    }
                }
                sum += Min;
            }
            if(!flag) break;
            double Tmp = B[i] / sum;
            if(Tmp > Max) Max = Tmp;
        }
        printf("%.3lf\n",Max);
    }
    return 0;
}
