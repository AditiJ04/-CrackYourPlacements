class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp=defaultdict(int)

        for i in range(0,len(s)):
            mp[s[i]]+=1

        for i in range(0,len(t)):
            if t[i] in mp:
                mp[t[i]]-=1
                if mp[t[i]]==0:
                    del mp[t[i]]
            else:
                return False
        
        if len(mp)==0:
            return True
        return False
        