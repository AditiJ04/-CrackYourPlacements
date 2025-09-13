class Solution {
    public long minimumPossibleSum(int n, int target) {
        if(n==1) return 1;
        return min(1,target,n,0,0,new HashSet<>());
    }
    public long min(int index,int target,int n,int size,long sum,Set<Integer> set){
        if(size==n){
            if(sum==target) return Long.MAX_VALUE;
            return sum;
        }
        long take = Long.MAX_VALUE;
        if(!set.contains(target-index)){
            set.add(index);
            take = min(index+1,target,n,size+1,sum+index,set);
            set.remove(index);
            if(take != Long.MAX_VALUE) return take;
        }
        long nottake = min(index+1,target,n,size,sum,set);
        return Math.min(take,nottake);
    }
}