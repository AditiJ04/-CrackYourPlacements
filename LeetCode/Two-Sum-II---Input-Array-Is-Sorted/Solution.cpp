class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0;
        int h=n-1;
        vector<int>v;

        while(l<n && h<n)
        {
            if(numbers[l]+numbers[h]==target)
            {
                v.push_back(l+1);
                v.push_back(h+1);
                break;
            }
            if(numbers[l]+numbers[h]>target)
            {
                h--;
            }
            if(numbers[l]+numbers[h]<target)
            {
                l++;
            }
        }
        return v;
    }
};