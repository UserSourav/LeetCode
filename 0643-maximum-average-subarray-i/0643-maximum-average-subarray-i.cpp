class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0; 
        int j = i+k-1; 
        double cu_total=0;
        double max_total=0;
        
        for(int a=0; a<k; a++){
            cu_total += nums[a];
        }
        
        max_total=cu_total;
        while(j<n-1){
            cu_total=cu_total-nums[i]+nums[j+1];
            max_total=max(max_total,cu_total);
            i++;
            j++;
        }
        return max_total/k; 
        }
};