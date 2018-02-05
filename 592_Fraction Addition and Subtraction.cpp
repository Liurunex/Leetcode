class Solution {
public:
	string fractionAddition(string expression) {
		int nom, dom, A = 0, B = 1;
		istringstream iss(expression);
		char c;
		while (iss >> nom >> c >> dom) {
			A = A*dom + B*nom;
			B *= dom;
			int gcdnum = gcd(abs(A), abs(B));
			A /= gcdnum;
			B /= gcdnum;
		}
		return to_string(A) + "/" + to_string(B);
	}

	int gcd(int x, int y) {
		return y == 0 ? x:gcd(y, x%y);
	}
};
/* the idea: GCD + istringstream. 利用istreaingstream来读表达式，注意格式一定是
 * number -> / -> number, 按顺序读，不断update分子分母，化简用辗转相除法（induction证明),
 * NOTICE 求最大公约数时候要求number positive 
 * */