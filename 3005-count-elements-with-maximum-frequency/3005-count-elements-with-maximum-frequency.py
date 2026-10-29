class Solution(object):
    def maxFrequencyElements(self, a):
        mp = {}
        mx=0
        ans=0
        for i in range(0,len(a)):
            mp[a[i]]=mp.get(a[i],0)+1
            mx=max(mx,mp[a[i]])
        for key,value in mp.items():
            if(value == mx):
                ans=ans+value
        return ans