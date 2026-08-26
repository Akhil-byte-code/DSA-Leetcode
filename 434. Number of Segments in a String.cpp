class Solution {
public:
    int countSegments(string s) {
        int count =0;

        for(int i=0;i<s.length();i++){
            // start of new segment 
            if(s[i]!=' ' && (i==0 || s[i-1]==' ')){
                count++;
            }
        }
        return count ;
    }
};
