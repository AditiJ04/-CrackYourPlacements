class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int l=0;
        int h=n-1;

        int mx=INT_MIN;
        while(l!=h)
        {
            int k=min(height[l],height[h]);
            mx=max(mx,k*(h-l));

            if(height[l]<=height[h])
            {
                l++;
            }
            else if(height[l]>=height[h])
            {
                h--;
            }
        }

        return mx;

    }
};