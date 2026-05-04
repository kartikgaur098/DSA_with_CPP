class Solution {
public:
    bool checkPalindrome(string s  , int start , int end){
        while(start <= end){
            if(s[start] == s[end]){
                start++ ;
                end-- ;
            }
            else {
                return false ;
            }
        }
        return true ;
    }
    bool validPalindrome(string s) {
        int start = 0 ;
        int end = s.length()-1;

        while(start<=end){
            if(s[start] == s[end]){
                start++ ;
                end-- ;
            }
            else{
                bool ansone = checkPalindrome(s , start+1 , end);
                bool anstwo = checkPalindrome(s , start , end-1);
                bool finalans = ansone||anstwo ;
                return finalans ;
            }
        }
    return true ;
    }
};