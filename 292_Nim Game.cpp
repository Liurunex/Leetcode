class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
/* the idea: game play, no need for minimax:
 * x < 4, A must win, winner n: 1..3
 * x = 4, A must lost,
 * x < 8, A can reduce the x to 4 when B's turn, so A win, winner n: 5..7
 * x = 8, if A win, A wil deal with 5..7 left, but that is B faceing, B win
 * using induction, we now know n%4 == 0 -> B win, ohterwise A win
 */