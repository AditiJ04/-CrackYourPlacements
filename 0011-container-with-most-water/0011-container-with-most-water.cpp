class Solution {
public:
    int maxArea(vector<int>& height) {
        int h=height.size()-1;
        int l=0;

        int mx=0;
        while(l!=h)
        {
            int k=min(height[l],height[h]);
            mx=max(mx,k*(h-l));
            if(height[l]<=height[h])
            {
                l++;
            }
            else if(height[l]>height[h])
            {
                h--;
            }
        }

        return mx;
    }
};