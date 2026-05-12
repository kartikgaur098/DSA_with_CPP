class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 1 ;
        int start = 0 ;
        int n = s.length();

        for(int i = 0 ; i< n ; i++){
            
            // for odd length palindrome
            int l = i ;
            int r = i ;

            while(l >= 0  && r < n && s[l] == s[r]){

                if(r-l+1 > maxlength){
                    start = l ;
                    maxlength = r-l+1 ;
                }
                l-- ;
                r++ ;
            }

              // for odd length palindrome
            l = i ;
            r = i + 1 ;

            while(l >= 0  && r < n && s[l] == s[r]){

                if(r-l+1 > maxlength){
                    start = l ;
                    maxlength = r-l+1 ;
                }
                l-- ;
                r++ ;
            }

        }
        return s.substr(start , maxlength);
    }
};