class Solution {
public:
        void merge(vector<int>& nums1 ,int m , vector<int>& nums2 , int n) {
            int last = m+n-1;
            while (m>0 && n>0){
                if(nums1[m-1]>nums2[n-1]){
                    nums1[last]=nums1[m-1];
                    m-=1;
                }else{
                    nums1[last]=nums2[n-1];
                     n-=1;
                }
                last-=1;
            }
            while (n>0){
                nums1[last]=nums2[n-1];
                last-=1;
                n-=1;
            }   
        }
};
    


// sbse pehle to LAST name k variable m pehli array ka last wala index dal do 
// uske bad jbhtk m or n dono m se koi bhi 0 se bda hoga tbtk loop chlta rhega 
// fr if condition lga k dono m wale index or n wale index m se usko last m lga do 
// fr jis bhi index ki value ati hai use ek km krdo fr last ki bhi krnni he pdegi 
// jb last m ek case ayega jisme n ki value ho skta h m se jada ho to unko bhi last m dal kr n or last dono km krdo