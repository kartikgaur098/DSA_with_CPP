class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> roman{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int n= s.length();
        int total=0;
        for(int i=0;i<n;i++){
            if(i+1<=n && roman[s[i]]<roman[s[i+1]]){
            total=total-roman[s[i]];
            }
            else{
            total=total+roman[s[i]];
            }
        }
        return total;
    }
};