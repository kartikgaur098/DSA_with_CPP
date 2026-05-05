class Solution {
public:

    int expandaroundcenter(string s ,int i ,int j){
        int count = 0 ;

        while(i>=0 && j<= s.length() &&s[i] == s[j] ){
            count++ ;
            i--;
            j++;
        }
        return count ;
    }
    int countSubstrings(string s) {
        int totalCount = 0 ;
        for(int center = 0 ; center < s.length() ; center++ ){
            
            // odd palindromic substrings
            int i = center;
            int j = center;
             
            int leftsubstringkacount = expandaroundcenter(s , i , j);

            // even palindromic substrings 
             i = center ;
             j = center + 1;

            int rightsubstringkacount = expandaroundcenter(s, i , j);

            totalCount = totalCount + leftsubstringkacount + rightsubstringkacount ;
        }

        return totalCount ;
   }
};