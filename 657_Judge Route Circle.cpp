class Solution {
public:
	bool judgeCircle(string moves) {
		int row = 0, col = 0;
		for (int i = 0; i < moves.length(); i ++) {
			switch (moves[i]) {
				case 'L': row ++; break;
				case 'R': row --; break;
				case 'U': col ++; break;
				case 'D': col --; break;
			}
		}
		return row == 0 && col == 0;
	}
};