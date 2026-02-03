class Solution:
    def countMonobit(self, n: int) -> int:
        result = []

        #n = 11

        if n ==1 :
           return 2
            
        while (n !=0) : 
           temp = n % 2 
           result.append(temp)
           n = n//2

        result.reverse()
        
        if sum(result) == len(result):
           return len(result) + 1
        else :
           return len(result) 
        