// CPP program to print levels in sorted order.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// A Binary Tree Node
struct Node {
	int data;
	struct Node *left, *right;
};

// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<Node*> q;

	// A priority queue (or min heap) of integers for
	// to store all elements of current level.
	priority_queue<int, vector<int>, greater<int> > current_level;

	// A priority queue (or min heap) of integers for
	// to store all elements of next level.
	priority_queue<int, vector<int>, greater<int> > next_level;

	// push the root for traverse all next level nodes
	q.push(root);

	// for go level by level
	q.push(NULL);

	// push the first node data in previous_level queue
	current_level.push(root->data);

	while (q.empty() == false) {

		// Get top of priority queue
		int data = current_level.top();

		// Get top of queue
		Node* node = q.front();

		// if node == NULL (Means this is boundary
		// between two levels), swap current_level
		// next_level priority queues.
		if (node == NULL) {
			q.pop();

			// here queue is empty represent
			// no element in the actual
			// queue
			if (q.empty())
				break;

			q.push(NULL);
			cout << "\n";

			// swap next_level to current_level level
			// for print in sorted order
			current_level.swap(next_level);

			continue;
		}

		// print the current_level data
		cout << data << " ";

		q.pop();
		current_level.pop();

		/* Enqueue left child */
		if (node->left != NULL) {
			q.push(node->left);

			// Enqueue left child in next_level queue
			next_level.push(node->left->data);
		}

		/*Enqueue right child */
		if (node->right != NULL) {
			q.push(node->right);

			// Enqueue right child in next_level queue
			next_level.push(node->right->data);
		}
	}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node* root = newNode(7);
	root->left = newNode(6);
	root->right = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(3);
	root->right->left = newNode(2);
	root->right->right = newNode(1);

	/*	 7
		/ \
		6	 5
	/ \	 / \
	4 3	 2 1		 */

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}
