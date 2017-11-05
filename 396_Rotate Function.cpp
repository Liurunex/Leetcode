class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		if (!A.size()) return 0;
		int sum = 0;
		vector<int> Fu (A.size(), 0);
		for (int i = 0; i < A.size(); ++ i) {
			Fu[0] += A[i]*i;
			sum   += A[i];
		}
		
		int res = Fu[0];
		for (int i = 1; i < Fu.size(); ++ i) {
			Fu[i] = Fu[i-1] + sum - Fu.size()*A[Fu.size()-i];
			res = max(res, Fu[i]);
		}
		return res;
	}
};


/* the idea: math problem, get the induction relation fucntion:

F(0) = 0*A[0] 	+ 1*A[1] 	+ 2*A[2] 	+ ... (n-1)*A[n-1];
F(1) = 0*A[n-1] + 1*A[0] 	+ 2*A[1] 	+ ... (n-1)*A[n-2];
F(2) = 0*A[n-2] + 1*A[n-1] 	+ 2*A[0] 	+ ... (n-1)*A[n-3];
F(3) = 0*A[n-3] + 1*A[n-2] 	+ 2*A[n-1] 	+ ... (n-1)*A[n-4];
...

F(k)   = 0*A[n-k]  	+ 1*A[n-k+1] + 2*A[n-l+2] + ... (n-1)*A[n-k-1]
F(k+1) = 0*A[n-k-1] + 1*A[n-k]   + 2*A[n-k+1] + ... (n-1)*A[n-k-2]

F(k+1) - F(k) = A[n-k] + A[n-k+1] + ... + A[n-1] + A[0] + A[1] + ... + A[n-k-2] + (1-n)*A[n-k-1]
 			  = Sum(A) - n*A[n-k-1]
F(k) = F(k-1) + Sum(A) - n*A[n-k]; k > 0

Acutally we don't even need the vector

*/

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		if (!A.size()) return 0;
		int sum = 0, res = 0, tem = 0;
		for (int i = 0; i < A.size(); ++ i) {
			tem += A[i]*i;
			sum += A[i];
		}
		
		res = tem;
		for (int i = 1; i < A.size(); ++ i) {
			tem = tem + sum - A.size()*A[A.size()-i];
			res = max(res, tem);
		}
		return res;
	}
};