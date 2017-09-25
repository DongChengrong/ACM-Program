class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        y = x
        z = 0
        if x < 0:
            return False
        while y > 0:
            z = z * 10 + y % 10
            y = y / 10
        if x == z:
            return True
        else:
            return False
