#include <iostream>
#include <stack>
using namespace std;

class TwoSum {
private:
    struct TreeNode {
       int val;
       int height;
       TreeNode *left, *right;
       TreeNode(int val):val(val), height(1), left(NULL), right(NULL) {}
    };
    TreeNode *root;

    int height(TreeNode *node) {
       if (!node)
          return 0;
       return node->height;
    }

    TreeNode* rotateLeft(TreeNode *node) {
       TreeNode *newRoot = node->right;
       TreeNode *temp = node->right->left;
       node->right->left = node;
       node->right = temp;

       // update heights
       node->height = 1 + max(height(node->left), height(node->right));
       newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

       return newRoot;
    }

    TreeNode* rotateRight(TreeNode *node) {
       TreeNode *newRoot = node->left;
       TreeNode *temp = node->left->right;
       node->left->right = node;
       node->left = temp;

       // update heights
       node->height = 1 + max(height(node->left), height(node->right));
       newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

       return newRoot;
    }

    TreeNode* insert(TreeNode *root, int val) {
       if (!root) {
          TreeNode *newNode = new TreeNode(val);
          return newNode;
       }
       if (root->val <= val)
          root->right = insert(root->right, val);
       else
          root->left = insert(root->left, val);

       root->height = 1 + max(height(root->left), height(root->right));

       int diff = height(root->left) - height(root->right);
       if (diff > 1) { // the left cases, this will balance ultimately with right rotation
          if (root->left->val > val) { // left left case
             return rotateRight(root);
          }
          else { // left right case
             root->left = rotateLeft(root->left);
             return rotateRight(root);
          }
       }
       else if (diff < -1) { // the right cases, this will balance ultimately with left rotation
          if (root->right->val < val) { // right right case
             return rotateLeft(root);
          }
          else { // right left case
             root->right = rotateRight(root->right);
             return rotateLeft(root);
          }
       }
       return root;
    }

public:
    TwoSum() {
        root = NULL;
    }
    // Add the number to an internal data structure.
	void add(int number) {
	    root = insert(root, number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int val) {
	    stack<TreeNode *> l_s, r_s;
	    bool left = true, right = true;
	    TreeNode *l_curr = root, *r_curr = root;
	    while (1) {
	        while (left) {
	            if (l_curr) {
	                l_s.push(l_curr);
	                l_curr = l_curr->left;
	            }
	            else {
	                if (l_s.empty()) {
	                    left = false;
	                    break;
	                }
	                l_curr = l_s.top();
	                l_s.pop();
	                left = false;
	            }
	        }

	        while (right) {
	            if (r_curr) {
	                r_s.push(r_curr);
	                r_curr = r_curr->right;
	            }
	            else {
	                if (r_s.empty()) {
	                    right = false;
	                    break;
	                }
	                r_curr = r_s.top();
	                r_s.pop();
	                right = false;
	            }
	        }

	        if (!l_curr || !r_curr || l_curr == r_curr || l_curr->val > r_curr->val)
	            return false;
	        if (l_curr->val + r_curr->val == val)
	            return true;
	        else if (l_curr->val + r_curr->val < val) {
	            l_curr = NULL;
	            left = true;
	        }
	        else {
	            r_curr = NULL;
	            right = true;
	        }
	    }
	    return false;
	}
};

int main() {
// Your TwoSum object will be instantiated and called as such:
  TwoSum twoSum;
  twoSum.add(12);
  twoSum.add(11);
  if (twoSum.find(23))
     cout << "this is foobar the bar foo man\n";
  twoSum.add(-12);
  twoSum.add(25);
  twoSum.add(-20);
  twoSum.add(-22);
  twoSum.add(12);
  twoSum.add(-39);
  twoSum.add(11);
  twoSum.add(-15);
  twoSum.add(25);
  twoSum.add(47);
  twoSum.add(-24);
  twoSum.add(18);
  twoSum.add(21);
  twoSum.add(-21);
  twoSum.add(32);
  twoSum.add(-11);
  twoSum.add(-35);
  twoSum.add(37);
  twoSum.add(0);
  twoSum.add(40);
  twoSum.add(47);
  twoSum.find(-20);
  twoSum.find(20);
  twoSum.find(3);
  twoSum.find(-42);
  twoSum.find(14);
  twoSum.find(-1);
  twoSum.find(-38);
  twoSum.find(31);
  twoSum.find(40);
  twoSum.find(-31);
  twoSum.find(-26);
  twoSum.find(41);
  twoSum.find(16);
  twoSum.find(-30);
  return 0;
}
