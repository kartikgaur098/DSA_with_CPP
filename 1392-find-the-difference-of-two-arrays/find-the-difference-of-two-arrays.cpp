class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a ;
        vector<int> b ;
        unordered_map<int , int> map1 ;
        unordered_map<int , int> map2 ;
        vector<vector<int>> ans ;

        for(int x : nums1) map1[x]=1 ;
        for(int x : nums2) map2[x]=1 ; 

        for(int x : nums1){
            if(!map2.count(x)){
                a.push_back(x);
                map2[x] = 1;
            }
        }

        for(int x : nums2){
            if(!map1.count(x)){
                b.push_back(x);
                map1[x] = 1;
            }
        }

        ans.push_back(a);
        ans.push_back(b);

        return ans ;
    }
};