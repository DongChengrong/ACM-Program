#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 30;
vector<int> blocks[maxn];
int n;

void find_block(int x,int &p,int &h)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < blocks[i].size(); j++)
        {
            if(blocks[i][j] == x)
            {
                p = i;
                h = j;
                return;
            }
        }
}

void clear_above(int p,int h)
{
    for(int i = h+1; i < blocks[p].size();i++)
    {
        int b = blocks[p][i];
        blocks[b].push_back(b);
    }
    blocks[p].resize(h+1);
}

void pile(int p,int h,int p2)
{
    for(int i = h; i < blocks[p].size(); i++)
        blocks[p2].push_back(blocks[p][i]);
    blocks[p].resize(h);
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        printf("%d:",i);
        for(int j = 0; j < blocks[i].size(); j++)
            printf(" %d",blocks[i][j]);
        printf("\n");
    }
}

int main()
{
    int a,b;
    string s1,s2;
    cin >> n;
    for(int i = 0; i < n; i++) blocks[i].push_back(i);
    while(cin >> s1)
    {
        if(s1 == "quit") break;
        cin >> a >> s2 >> b;
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa == pb) continue;
        if(s1 == "move") clear_above(pa,ha);
        if(s2 == "onto") clear_above(pb,hb);
        pile(pa,ha,pb);
    }
    print();
    return 0;
}
