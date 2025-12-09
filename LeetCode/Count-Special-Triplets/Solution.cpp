   if (nums == null || nums.length == 0)
return 0;

     int MOD = (int)(1e9+7);
    long ansCount=0;

    HashMap<Integer, Integer> rightfreq = new HashMap<>();
    HashMap<Integer, Integer> leftfreq = new HashMap<>();


        for(int val : nums)
        {
            rightfreq.put(val,rightfreq.getOrDefault(val,0)+1);  //storing frequencey
        }

    for(int j=0;j<nums.length;j++) //traverse through array and find right side and left side freq available 
        {
             rightfreq.put(nums[j],rightfreq.get(nums[j])-1); // right map me frequency kam krdo 
            int targetValue= 2*nums[j]; //need on both side map, will muliply frequency

           // ansCount+= (1L*rightfreq.getOrDefault(targetValue,0)*leftfreq.getOrDefault(targetValue,0))% MOD;
    ansCount = (ansCount + (1L * rightfreq.getOrDefault(targetValue, 0) * leftfreq.getOrDefault(targetValue, 0)) % MOD) % MOD;


             leftfreq.put(nums[j],leftfreq.getOrDefault(nums[j],0)+1) ;//insert in leftfreq map
             
        }

    return (int)ansCount ;
    
    
   
}