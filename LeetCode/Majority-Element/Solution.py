class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp=defaultdict(int)
        n=len(nums)

        for i in range(0,n):
            mp[nums[i]]+=1

        for number, count in mp.items():
            if count> n//2:
                return number
        return -1