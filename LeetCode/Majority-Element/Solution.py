class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp=defaultdict(int)
        n=len(nums)

        for i in range(0,n):
            mp[nums[i]]+=1

        for num, cnt in mp.items():
            if cnt> n//2:
                return num
        return -1