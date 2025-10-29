class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;

        int cnt1 = 0, cnt2 = 0;
        int el1 = 0, el2 = 0;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1) {
            cnt1++;
        }
        else if (nums[i] == el2) {
            cnt2++;
        }

        else {
            cnt1--;
            cnt2--;
        }
    }

    int c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == el1)
            c1++;
        else if (nums[i] == el2)
            c2++;
    }

    if (c1 > (n / 3))
        v.push_back(el1);
    if (c2 > (n / 3))
        v.push_back(el2);

    return v;
}
}
;