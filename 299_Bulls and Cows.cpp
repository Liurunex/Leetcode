class Solution {
public:
	string getHint(string secret, string guess) {
		int cows  = 0;
		int bulls = 0;
		unordered_map<char, int> diction;
		for (int i = 0; i < secret.length(); ++ i) {
			if (secret[i] == guess[i]) bulls ++;
			diction[secret[i]] ++;
		}

		for (int i = 0; i < secret.length(); ++ i) {
			if (diction.find(guess[i]) != diction.end()) {
				cows ++;
				diction[guess[i]] --;
				if (!diction[guess[i]]) 
					diction.erase(guess[i]);
			}
		}

		cows -= bulls;
		return to_string(bulls)+"A"+to_string(cows)+"B";
	}
};