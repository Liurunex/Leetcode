int WidthOfTheTree(Node* root) {
	if(!root) return 0;

	queue<Node*> thqueue;
	thqueue.push(root);
	int width = 1, curwidth = 1, nextwidth = 0;

	while(!thqueue.empty()) {
		while(curwidth!=0) {
			Node* node = thqueue.front();
			thqueue.pop();
			curwidth --;
			if(node->left) {
				thqueue.push(node->left);
				nextwidth ++;
			}
			if (node->right) {
				thqueue.push(node->right);
				nextwidth++;
			}
		}
		width = max(nextwidth, width);
		curwidth = nextwidth;
		nextwidth = 0;
	}
	return width;
}
/* the idea: Level Traversal. 用queue进行正常level
 * traversal，设定3个值，width, cur_width, next_width,
 * 不断从queue里面pop直到cur_width == 0, 此时queue只有下一层的所有nodes了，
 * 此时更新width*/