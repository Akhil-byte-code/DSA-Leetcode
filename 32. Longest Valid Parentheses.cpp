class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int open =0;
        int close =0;

        int result = 0;
        
        // travesing from left to right 
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else close++;

            if(open==close){
                result = max(result , open+close);
            }else if(close>open){ //going from left to right, if close is more, it's no more valid
                open = 0;
                close =0;
            }
        }
        open = 0;
        close =0;
        // travesing from right to left 
        for(int i= n-1 ;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;

            if(open==close){
                result = max(result , open+close);
            } else if(open>close){
                open = 0;
                close =0;
            }
        }
        return result ;
    }
};
