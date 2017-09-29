/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		int res = 0;
		unordered_map<int, Employee*> employees_map;
		for (Employee* employee:employees)
			employees_map[employee->id] = employee;

		queue<Employee*> bfsqueue;
		bfsqueue.push(employees_map[id]);

		while (!bfsqueue.empty()) {
			Employee* curemp = bfsqueue.front();
			bfsqueue.pop();

			res += curemp->importance;
			employees_map.erase(curemp->id);
			for (int subemp:curemp->subordinates)
				if (employees_map.find(subemp) != employees_map.end())
					bfsqueue.push(employees_map[subemp]);
		}
		return res;
	}
};

/* the idea: very simple and strightforward BFS problem; notice the 
 * visited map was replaced by the hashtable, keep erase a node in hashmap 
 * each time when visiting a node
 */
