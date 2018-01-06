/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;

		unordered_map<int, UndirectedGraphNode*> visited;
		queue<UndirectedGraphNode*> myqueue;
		//queue<UndirectedGraphNode*> tofilled;

		UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
		visited[node->label] = newnode;
		myqueue.push(node);
		//tofilled.push(newnode);

		while (!myqueue.empty()) {
			UndirectedGraphNode *curnode = myqueue.front();
			myqueue.pop();
			
			//UndirectedGraphNode *curfill = tofilled.front();
			//tofilled.pop();

			for (UndirectedGraphNode* neighbor:curnode->neighbors) {
				if (!visited.count(neighbor->label)) {
					UndirectedGraphNode *tem = new UndirectedGraphNode(neighbor->label);
					visited[neighbor->label] = tem;
					visited[curnode->label]->neighbors.push_back(visited[neighbor->label]);
					
					myqueue.push(neighbor);
					//tofilled.push(visited[neighbor->label]);
				}
				else 
					visited[curnode->label]->neighbors.push_back(visited[neighbor->label]);
			}
		}

		return newnode;
	}
};

/* the idea: BFS + hashmap; we choose BFS to travel the graph, we only need one queue to track
 * the travesal process. Then how to track the new graph node ? using hashmap! Since each node
 * has unique value, we then can use hashmap to map the value to its correpsonding node pointer.
 * In addition the current node and the current new node shall have same value, we then can access
 * the new copy node via the current node throught hashmap!
 * Notice that: the circle might existed inside, therefore we should first check if the child-node
 * needed to be added into new copy-father's children vector is already visted, (that is also done
 * by hashmap, since if hashmap has the key, we have already visited it). One more thing: we don't need
 * to add the already-visited child into our BFS queue, otherwise we get into infinite loop!
 *
 */