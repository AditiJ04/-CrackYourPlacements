class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans=[]
        n=len(nums1)
        m=len(nums2)

        mp=defaultdict(int)

        for i in range(0,n):
            mp[nums1[i]]+=1

        for i in range(0,m):
            if mp[nums2[i]]>0:
                ans.append(nums2[i])
                mp[nums2[i]]-=1

                if mp[nums2[i]]==0:
                    del mp[nums2[i]]
        
        return ans

        