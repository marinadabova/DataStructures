#include <iostream>
#include <queue>

using namespace std;
class TreeNode {
public:
	int key;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
	TreeNode* root;

	TreeNode* insertRecursive(TreeNode* root, int value) {
		if (root == nullptr) {
			return new TreeNode(value);
		}

		if (value < root->key) {
			root->left = insertRecursive(root->left, value);
		}
		else if (value > root->key) {
			root->right = insertRecursive(root->right, value);
		}

		return root;
	}


	TreeNode* findMin(TreeNode* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	TreeNode* removeRecursive(TreeNode* root, int value) {
		if (root == nullptr) {
			return root;
		}

		if (value < root->key) {
			root->left = removeRecursive(root->left, value);
		}
		else if (value > root->key) {
			root->right = removeRecursive(root->right, value);
		}
		else {
			// Node with only one child or no child
			if (root->left == nullptr) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}

			// Node with two children: Get the inorder successor (smallest in the right subtree)
			TreeNode* temp = findMin(root->right);

			// Copy the inorder successor's content to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = removeRecursive(root->right, temp->key);
		}
		return root;
	}
	TreeNode* searchRecursive(int key) {
		TreeNode* current = root;
		while (current != nullptr) {
			if (key == current->key) {
				return current;
			}
			else if (key < current->key) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		return nullptr;
	}

	void dfsInOrder(TreeNode* node) {
		//if(node==nullptr)
		//	return;
		if (node != nullptr) {
			dfsInOrder(node->left);
			std::cout << node->key << " ";
			dfsInOrder(node->right);
		}
	}

	void dfsPreOrder(TreeNode* node) {
		if (node != nullptr) {
			std::cout << node->key << " ";
			dfsPreOrder(node->left);
			dfsPreOrder(node->right);
		}
	}

	void dfsPostOrder(TreeNode* node) {
		if (node != nullptr) {
			dfsPostOrder(node->left);
			dfsPostOrder(node->right);
			std::cout << node->key << " ";
		}
	}
	bool areEvenNodesAtEvenLevel(TreeNode* root) { //should it be in private ?
		if (root == nullptr) {
			return true;  // Empty tree satisfies the condition
		}

		queue<TreeNode*> q;
		q.push(root);
		bool isEvenLevel = true;  // Start with even level (root is at level 0)

		while (!q.empty()) {
			int levelSize = q.size();
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* current = q.front();
				q.pop();

				if (isEvenLevel==true) {
					if (current->key % 2 != 0) {
						return false;  // Even level has an odd value
					}
				}

				if (current->left != nullptr) {
					q.push(current->left);
				}

				if (current->right != nullptr) {
					q.push(current->right);
				}
			}

			isEvenLevel = !isEvenLevel;  // Toggle the level for the next iteration
			//for odd levels
		}

		return true;  // All even levels have even values
	}
	
public:
	BinarySearchTree() : root(nullptr) {}

	void insert(int value) {
		root = insertRecursive(root, value);
	}

	void remove(int value) {
		root = removeRecursive(root, value);
	}

	void search(int value) {
		root = searchRecursive(value);
	}

	void print() {
		dfsInOrder(root);
		//dfsPostOrder(root);
		//dfsPreOrder(root);
	}

	void bfs() { //should it be in private ?
		if (root == nullptr) {
			return;
		}

		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* current = q.front();
			q.pop();
			std::cout << current->key << " ";

			if (current->left != nullptr) {
				q.push(current->left);
			}

			if (current->right != nullptr) {
				q.push(current->right);
			}
		}
	}
	
	void checkEvenNodesAtEvenLevel()  {
		if (areEvenNodesAtEvenLevel(root)==true) {
			cout << "All even levels have even values." << std::endl;
		}
		else {
			cout << "Not all even levels have even values." << std::endl;
		}
	}

	// to do
	TreeNode* kthLargestInBST(TreeNode* root, int k, int& counter) {
		if (root == nullptr || counter >= k) {
			return nullptr;
		}
		TreeNode* left = kthLargestInBST(root->right, k, counter);

		if (left) {
			return left;
		}
		counter += 1;
		if (counter == k) {
			return root;
		}
		return kthLargestInBST(root->left, k, counter);
	}
	TreeNode* findKthLargestInBST(TreeNode* root, int k) {
		int counter = 0;

		return kthLargestInBST(root, k, counter);
	}
	TreeNode* deleteNode(TreeNode* root, TreeNode* kthLargest) {
		if (root == nullptr)
			return root;
		if (kthLargest->key < root->key)
			root->left = deleteNode(root->left, kthLargest);
		else if (kthLargest->key > root->key)
			root->right = deleteNode(root->right, kthLargest);
		else {
			if (root->left == nullptr && root->right == nullptr) {
				return nullptr;
			}
			if (root->left == nullptr) {
				return root->right;
			}
			else if (root->right == nullptr) {
				return root->left;
			}
			else {

				TreeNode* replace = root->right;
				while (replace->left)
					replace = replace->left;
				root->key = replace->key;
				root->right = deleteNode(root->right, root);

			}
		}
		return root;
	}

	//to do
	void checkFunc(TreeNode* root, long long& sumOdd) {
		if (root == NULL) {
			return;
		}

		if (root->left == NULL && root->right == NULL) {
			if (root->key % 2 == 1) {
				sumOdd += root->key;
			}

		}

		checkFunc(root->left, sumOdd);
		checkFunc(root->right, sumOdd);

	}
	void leaves(TreeNode* root) {
		long long summ = 0;
		checkFunc(root, summ);
		cout << summ;
	}
};

int main() {
	BinarySearchTree bst;
	/*bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(2);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);*/

	bst.insert(6);
	bst.insert(3);
	bst.insert(10);
	bst.insert(2);
	bst.insert(4);
	bst.insert(8);
	bst.insert(12);

	std::cout << "In-order traversal: ";
	bst.print();
	std::cout << std::endl;


	//std::cout << "Breadth-first traversal: ";
	//bst.bfs();
	std::cout << std::endl;

	bst.checkEvenNodesAtEvenLevel();
	return 0;
}
