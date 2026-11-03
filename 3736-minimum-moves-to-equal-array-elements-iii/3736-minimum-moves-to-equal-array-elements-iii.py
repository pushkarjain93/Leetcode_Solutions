class Solution(object):
    def minMoves(self, a):
       ans = 0
       x=a[0]
       for i in range(0,len(a)):
        x=max(x,a[i])
       for i in range(0,len(a)):
        ans=ans+(x-a[i])
       return ans