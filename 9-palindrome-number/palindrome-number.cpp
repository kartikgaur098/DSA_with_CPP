class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false ;
        string num = to_string(x);
        int left = 0 ;
        int right = num.length()-1;

        while(left < right){
            if(num[left] == num[right]){
                left++ ;
                right--;
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};