class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.split()[::-1]
        while ' ' in s:
            s.remove(' ')
        return " ".join(s)