#include<set>
#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {

    set<char> vars;
    int maxn = 0;
    int cnt = 0;
    int d = s.size();

    int left = 0,right = 0;
    while(right < d)
    {
        if(vars.count(s[right]) == 0)
        {
            cnt++;
            vars.insert(s[right++]);
        }
        else
        {
            maxn = max(cnt,maxn);
            vars.erase(s[left++]);
            cnt--;
        }
    }

    maxn = max(cnt,maxn);

    return maxn;
}

int main()
{
    string s;
    while(cin >> s)
    {
        cout << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
