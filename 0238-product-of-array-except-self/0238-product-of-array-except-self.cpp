class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        int a = 1;

        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {

            res[i] = a;

            a = a * nums[i];
        }

        int b = 1;

        for (int i = n - 1; i >= 0; i--) {

            res[i] *= b;

            b = b * nums[i];
        }

        return res;
    }
};