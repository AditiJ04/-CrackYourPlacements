import math
from itertools import permutations
class Solution:
    def sumZero(self, n: int) -> List[int]:
        mid = math.ceil(n/2)
        numbers = [n for n in range(-mid, mid+1)] # array of n/2 in positive and negative directions
        allPermutations = []
        allPermutations = permutations(numbers, n) # all permutation of n elements
        for permutation in allPermutations:
            permutation = list(permutation)
            if len(permutation) == n and sum(permutation) == 0:
                return permutation