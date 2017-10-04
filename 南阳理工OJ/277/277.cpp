#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        string s;
        set<string> dict;
        cin >> n;
        while(n--)
        {
            cin >> s;
            dict.insert(s);
        }

        set<string> ::iterator it = dict.begin();
        cout << *it << endl;
    }
    return 0;
}
