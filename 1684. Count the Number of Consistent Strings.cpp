class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> present(26,false);

        for(char ch : allowed){
            present[ch-'a'] = true ;
        }

        int ans =0;

        for(string word : words){
            bool consistent = true ;

            for(char ch : word ){
                if(!present[ch-'a']){
                    consistent = false ;
                    break ;
                }
            }
            if(consistent){
                ans++;
            }
        }
        return ans ;
    }
};
