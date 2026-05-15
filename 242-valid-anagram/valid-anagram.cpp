class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false ;
        unordered_map<char , int > map ;
        for(char c : s){
            map[c]++ ;
        }
        for(char c : t){
            map[c]--;
        }

        for(int i = 0 ; i<= s.size() ; i++){
            if(map[s[i]] > 0)
            return false ;
        }   
        return true ;
 }
};