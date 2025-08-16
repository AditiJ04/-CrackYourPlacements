If i > 0 and nums[i] == nums[i-1], skip to avoid duplicates.

Set two pointers:

left = i + 1, right = n - 1

While left < right:

Calculate the sum of the three elements.

If sum is 0 → store the triplet.

If sum < 0 → move left forward.

If sum > 0 → move right backward.