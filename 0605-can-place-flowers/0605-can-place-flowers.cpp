class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        for(int i = 0; i<flowerbed.size(); i++ ){
            int l;
            int r;
            if(i==0){
                l=0;
            }
            else{
                l=flowerbed[i-1];
            }
            if(i==flowerbed.size()-1){
                r=0;
            }
            else{
                r=flowerbed[i+1];
            }
            if(flowerbed[i]==0 && l==0 && r==0){
                count ++;
                flowerbed[i]=1;
            }
        }
        return count >= n;
    }
};