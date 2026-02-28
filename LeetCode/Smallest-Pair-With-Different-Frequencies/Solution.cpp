class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        result = []

        fre = {}

        for i in range (len(nums)):
            if nums[i] in fre:
                fre[nums[i]] +=1
            else: 
                fre[nums[i]] = 1

        #return fre

        #return (sorted(fre.keys()))

        arr = sorted(fre.keys())

        if len((sorted(fre.keys()))) == 1:
            return [-1,-1]

        
        for key in arr:
                first_key = arr[0]
                first_key_fre = fre[arr[0]]
                if fre[key] !=first_key_fre:
                    second_key = key
                    return [first_key,second_key ] 
        else:
                    return [-1,-1 ]
            
        #result.append(fre[key])

        
            
        """
        else: 

            for key in (sorted(fre.keys())):
                if fre[key] != fre[key + 1] :
                    return [key,key+1 ]
                else:
                    return [-1,-1 ]
        """
        
        