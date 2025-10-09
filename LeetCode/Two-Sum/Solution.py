class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        res=[-1,-1]
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    res[0]=i
                    res[1]=j

        return res

        