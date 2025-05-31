class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> roman{
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };

        string answer="";

        for(int i=0;i<roman.size();i++){
            int value=roman[i].first;
            string symbol=roman[i].second;

            while(num>=value){
                answer=answer + symbol;
                num=num-value;
            }
        }
        return answer;
    }
};