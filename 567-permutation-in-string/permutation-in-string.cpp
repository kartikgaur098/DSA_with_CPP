class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1>n2) return false ;

        vector<int> freq1(26 , 0);
        vector<int> freq2(26 , 0);

        for(char ch : s1){
            freq1[ch - 'a']++;
        }

        for(int i = 0 ; i<n1 ; i++){
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2){
            return true ;
        }

        for(int i = n1 ; i <n2 ; i++){

            char newchar = s2[i] ;
            int newIndex = newchar - 'a';
            freq2[newIndex]++ ;


            char oldchar = s2[i-n1];
            int oldIndex = oldchar  - 'a';
            freq2[oldIndex]-- ;

            if(freq1 == freq2 ) return true ;

        }
        return false ;
    }
};