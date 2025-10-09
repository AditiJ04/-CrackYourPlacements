class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        res=[-1,-1]
        mp={}
        for i in range(0,len(nums)):
            val=target-nums[i]
            if val in mp:
                res[0]=mp[val]
                res[1]=i
                break
            else:
                mp[nums[i]]=i
        return res
        