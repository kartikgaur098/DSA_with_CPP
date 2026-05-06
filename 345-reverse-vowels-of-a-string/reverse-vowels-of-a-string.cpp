class Solution {
public:

    bool isvowel(char ch){
        ch = tolower(ch) ;
        return ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ;
    }
    string reverseVowels(string s) {
        int l = 0 ;
        int r = s.length() ;

        while(l<r){
            if(isvowel(s[l]) && isvowel(s[r])){
                swap(s[l] , s[r]);
                    l++ ;
                    r-- ;
            }
            else if(isvowel(s[l]) == 0){
                    l++ ;
            }
            else{
                    r-- ;
            }

        }
        return s ;
    }
};