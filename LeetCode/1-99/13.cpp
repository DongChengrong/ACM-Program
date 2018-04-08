class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'I') result = result + 1;
            else if(s[i] == 'X') result = result + 10;
            else if(s[i] == 'C') result = result + 100;
            else if(s[i] == 'M') result = result + 1000;
            else if(s[i] == 'V') result = result + 5;
            else if(s[i] == 'L') result = result + 50;
            else if(s[i] == 'D') result = result + 500;
        }
        return result;
    }
};
