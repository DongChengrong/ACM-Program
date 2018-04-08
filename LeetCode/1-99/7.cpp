class Solution {
public:
    int reverse(int x) {
        int dir = 1;
        long long result = 0;
        if(x < 0)
        {
            dir = -1;
            x = -1 * x;
        }
        while(x)
        {
            result = result * 10 + (x % 10);
            x = x / 10;
        }
        result = result * dir;
        return (result < INT_MIN || result > INT_MAX) ? 0 : result;
    }
};
