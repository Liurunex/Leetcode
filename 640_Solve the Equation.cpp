class Solution {
public:
	string solveEquation(string equation) {
		char presymbol = '+';
		int prefix = 0, normsum = 0, reverse = 1;
		
        for (int i = 0; i < equation.size(); ++ i) {
			if (equation[i] >= '0' && equation[i] <= '9') {
				int number = 0;
				while (i < equation.size() && equation[i] >= '0' && equation[i] <= '9')
					number = number*10 + equation[i ++] - '0';
				i --;
				
				if (i+1 < equation.size() && equation[i+1] == 'x') {
					switch (presymbol) {
						case '+': prefix += reverse*number; break;
						case '-': prefix -= reverse*number; break;
					}
				}
				else {
					switch (presymbol) {
						case '+': normsum += reverse*number; break;
						case '-': normsum -= reverse*number; break;
					}
				}
			}
			
            else {
				switch (equation[i]) {
                    case 'x' :
                        if (i == 0 || (i-1 >= 0 && equation[i-1] < '0' || equation[i-1] > '9')) {
                            switch (presymbol) {
                                case '+': prefix += reverse; break;
                                case '-': prefix -= reverse; break;
                            }
                        }
				        break;
					case '=' : reverse = -1; presymbol = '+'; break;
                    default: presymbol = equation[i];
				}
				
			}
            
		}
		if (!prefix && normsum) return "No solution";
		if (!prefix && !normsum) return "Infinite solutions";
		return "x=" + to_string(-1*normsum/prefix);
	}
};

/* the idea: math problem, transfer the fucntion to ax=b, the key point is to
 * use a reverse symbol to denote if we have reach the other side of function,
 * so that just move right side to left side, that the reason we keep multiple
 * reverse with our local resutl, NOTICE there is no priority computation needed
 * so that we don't need to use local and gloabl!
 */