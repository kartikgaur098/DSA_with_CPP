class Solution {
public:
    void solve(vector<vector<int>> &ans , vector<int> &curr , int k ,int start , int n ){
        if(k==0){
            ans.push_back(curr);
            return ;
        }
        for (int i= start ; i<=n; i++){
            curr.push_back(i);
            solve(ans , curr ,k-1, i+1 ,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> ans;
     vector<int> curr;
     solve(ans ,curr , k , 1, n);
     return ans;   
    }
};

// isme bhi recursion approach use kri hai 
// sbse pehle ans chahiye vector m to ek ans name ka vector of vector initialize krenge fr ek or vector initialize krenge jisme current wala combination store krenge 
// fr ek function pass krenge jisme ans jayega curr jayega k jayega  fr start ki jagah pr 1 jayega or n jayega
// isme pehel to check krenge ki k ahr zero hoga to ese he retunr kr denge 
//  fr ek loop chlayenge jo i = start se shuru hoga kuki hme duplicacy avoid krni hai to ek age se chlayenge fr curr m push krnege i ko usk bad solve ko call krenge age ka krne k liye lekin isme ek value k ki km ho jayegi or i ki bdh jayegi fr pop kr lenge  