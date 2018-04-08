#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
string filenames[maxn];

void print(string s, int len, char extra)
{
    cout << s;
    for(int i = 0; i < len - s.length(); i++)
        cout << extra;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int M = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> filenames[i];
            M = max(M, (int)filenames[i].length());
        }

        print("",60,'-');
        cout << "\n";
        int cols = (60 - M) / (M + 2) +1;
        int rows = (n - 1) / cols + 1;
        sort(filenames,filenames + n);
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int id = c * rows + r;
                if(id < n) print(filenames[id],c == n - 1 ? M : M + 2, ' ');
            }
            cout << "\n";
        }
    }
    return 0;
}
