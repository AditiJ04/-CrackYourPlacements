class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();

        int val=0;

        for(int i=0;i<n;i++)
        {
            if(operations[i][1]=='+') val+=1;
            else val-=1;
        }

        return val;
    }
};