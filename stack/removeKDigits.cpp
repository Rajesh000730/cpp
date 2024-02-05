class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char>st;
        
        st.push_back(num[0]);
        int n = num.size();
        if(k == 1 && n==1){
            return "0";
        }
        for(int i = 1; i < n ;i++){
            while( k > 0 && !st.empty() && num[i] <  st.back()){
                st.pop_back();
                k--;
            }
            while(st.size() > 1 && st.front() == '0'){
                    st.pop_front();
            }
            st.push_back(num[i]);
        }
        while(st.size() > 1 && st.front() == '0'){
                st.pop_front();
            }
        while(k--){
            st.pop_back();
        }    
        string ans = "";
        for(auto i : st){
            ans+=i;
        }
        // cout<<stoi(ans);
        if(ans == ""){
            return "0";
        }
        return ans;

    }
};
