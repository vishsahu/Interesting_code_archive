#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node(int s, int l, int r) : sum{s}, si{l}, ei{r} {};

    Node *left, *right;
    int sum;
    int si;
    int ei;
};

class NumArray {
private:
    Node* root_;
    vector<int> nums_;

    Node* makeTree(vector<int>& n, int l, int r) {
        if (l > r)
            return NULL;
        int sum = 0;
        for (int i = l; i <= r; i++)
            sum += n[i];
        Node *root = new Node(sum, l, r);
        if (l == r) {
            root->left = NULL;
            root->right = NULL;
        }
        else {
            int mid = l + (r-l)/2;
            root->left = makeTree(n, l, mid);
            root->right = makeTree(n, mid + 1, r);
        }
        return root;
    }

    void updateTree(Node *root, int i, int val, int diff) {
        if (!root)
            return;
        root->sum -= diff;
        if (!root_->left && !root_->right) { // reached at leaf
            return;
        }
        int mid = root->si + (root->ei - root->si)/2;
        if (i <= mid)
            updateTree(root->left, i, val, diff); // dive in left sub tree
        else
            updateTree(root->right, i, val, diff); // dive in right sub tree
        return;
    }

    int queryTree(Node *root, int i, int j) {
        if (i > j)
            return 0;
        else if (root->si == i && root->ei == j) {
            return root->sum; // perfect match node
        }
        int mid = root->si + (root->ei - root->si) / 2;
        if (j <= mid) { // entire interval is in left subtree
            return queryTree(root->left, i, j);
        }
        else if (i > mid) { // entire interval is in right subtree
            return queryTree(root->right, i, j);
        }
        else { // interval is in both sub-trees
            return queryTree(root->left, i, mid) + queryTree(root->right, mid + 1, j);
        }
    }

public:
    NumArray(vector<int> &nums) {
        // construct tree here
        nums_ = nums;
        root_ = makeTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        int diff = nums_[i] - val;
        nums_[i] = val; // update the array
        updateTree(root_, i, val, diff);
    }

    int sumRange(int i, int j) {
        return queryTree(root_, i, j);
    }
};

int main () {
   // Your NumArray object will be instantiated and called as such:
   int a[] = {3,1,4,6,3,1,5,8,9,45,2,6,34};
   int size = sizeof(a)/sizeof(int);
   cout << "size is:" << size << endl;
   vector<int> nums(a, a + size);
   for (auto s:nums)
      cout << s << " ";
   cout << endl;

   NumArray numArray(nums);

   int i = 3, j = 6, k = 5, val = 129;
   cout << "sum of [" << i << "," << j << "] is:" << numArray.sumRange(i, j) <<
      endl;
   cout << "updating nums["<< k << "] to:" << val << endl;
   numArray.update(k, val);
   cout << "sum of [" << i << "," << j << "] now is:" << numArray.sumRange(i, j) <<
      endl;
   return 0;
}
