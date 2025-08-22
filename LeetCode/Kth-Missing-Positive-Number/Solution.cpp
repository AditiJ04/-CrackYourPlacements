class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>m;
        int c=0;

        for(int i=1;i<arr[arr.size()-1];i++)
        {
            m.push_back(i);
        }

        int arri=0;

        for(int i=0;i<m.size();i++)
        {
            if(m[i]==arr[arri])
            {
                arri++;
            }
            else
            {
                c++;
            }
            if(c==k)
            {
                return m[i];
            }
        }

        if(c<k)
        {
            return arr[arr.size()-1]+(k-c);
        }

        else
        {
            return 0;
        }
    }
};