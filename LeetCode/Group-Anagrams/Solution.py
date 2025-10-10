class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        v=[]
        n=len(strs)
        mp=defaultdict(list)

        for i in range(0,n):
            s=''.join(sorted(strs[i]))
            mp[s].append(strs[i])

        for key,val_list in mp.items():
            v.append(val_list)
        
        return v

        

        


        