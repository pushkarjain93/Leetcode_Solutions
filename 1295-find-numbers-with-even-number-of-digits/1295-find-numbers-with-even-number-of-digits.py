class Solution(object):
    def findNumbers(self, a):
        ans=0
        for i in range(len(a)):
            b=len(str(a[i]))
            if (b%2) == 0:
                ans=ans+1
        return ans

        