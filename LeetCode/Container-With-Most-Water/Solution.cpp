class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int l=0,h=n-1;
        int mx_ar=0;

        while(l!=h)
        {
            int k=min(height[l],height[h])*(h-l);
            mx_ar=max(k,mx_ar);

            if(height[l]<height[h])
            {
                l++;
            }
            else
            {
                h--;
            }
        }

        return mx_ar;
    }
};