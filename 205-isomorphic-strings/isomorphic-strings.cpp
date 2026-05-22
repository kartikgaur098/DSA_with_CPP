class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp1 ;
        unordered_map<char , char> mp2 ;
        for(int i = 0 ; i< s.size() ; i++){
            char wordChar = s[i];
            char patternChar = t[i];
            if(mp1.count(wordChar)){
                if(mp1[wordChar] != patternChar){
                    return false ;
                }
            }else{
                mp1[wordChar] = patternChar ;
            }
            if(mp2.count(patternChar)){
                if(mp2[patternChar] != wordChar){
                    return false ;
                }
            }else{
                mp2[patternChar] = wordChar ;
            }
        }
        return true ;
    }
};