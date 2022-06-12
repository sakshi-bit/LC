class Solution {
public:
    int numberOfMatches(int n) {
        //*There's a tennis tournament with 127 players. You've got 126 people paired off in 63               matches, plus 1 unpaired player as a bye.In the next round, there are 64 players and 32 matches. How many matches, total, does it take to determine a winner?Answer: 126.Explanation: It takes one match to eliminate one player. 126 players have to be eliminated to leave one winner. Therefore, there have to be 126 matches.*//
        return n-1;
    }
};