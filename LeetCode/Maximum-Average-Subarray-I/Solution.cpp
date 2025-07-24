    lst =  [ ] #list that stores all the maximums
    maxim = 0
    idx = -1
    for i in nums[0:len(nums)-k+1:]:
        idx += 1

        for j in nums[idx:idx+k:]:
            maxim += j
        lst.append(maxim/k)
        maxim = 0

    lst.sort()
    return lst[-1]