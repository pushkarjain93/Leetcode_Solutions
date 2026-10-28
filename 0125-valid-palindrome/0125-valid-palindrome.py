class Solution(object):
    def isPalindrome(self, s):
        i=0 
        j=len(s)-1
        while i<j:
            while i<j and s[i].isalnum()==False:
                i=i+1
            while i<j and s[j].isalnum()==False:
                j=j-1
            if s[i].lower()!=s[j].lower():
                return False
            i=i+1
            j=j-1
        return True

        