class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;          // stones the current player must remove
        bool alice = true;   // whose turn it is
        while (n >= k) {
            n -= k;
            k--;
            alice = !alice;  // turn passes to the other player
        }
        // The player to move now is stuck and loses.
        // If it is Bob's turn, Alice wins.
        return !alice;
    }
};
