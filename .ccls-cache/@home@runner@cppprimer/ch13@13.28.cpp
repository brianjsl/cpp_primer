#include <iostream>
#include <string>
using namespace std;

class BinStrTree;

class TreeNode {

  friend BinStrTree;

public:
  TreeNode() : count(1), left(nullptr), right(nullptr){};

  TreeNode(std::string val)
      : count(1), value(val), left(nullptr), right(nullptr){};

  TreeNode(std::string val, TreeNode *t_left, TreeNode *t_right)
      : count(1), value(val), left(nullptr), right(nullptr) {
    if (t_left) {
      left = new TreeNode(*t_left);
      count += left->count;
    }
    if (t_right) {
      right = new TreeNode(*t_right);
      count += right->count;
    }
  };

  // Copy Constructors
  TreeNode(const TreeNode &t) // Want to make a deep copy of a tree
      : value(t.value), count(t.count), left(nullptr), right(nullptr) {
    if (t.left)
      left = new TreeNode(*t.left);
    if (t.right)
      right = new TreeNode(*t.right);
  };

  TreeNode &operator=(const TreeNode &rhs) {
    TreeNode *new_l = nullptr;
    TreeNode *new_r = nullptr;
    if (rhs.left)
      new_l = new TreeNode(*rhs.left);
    if (rhs.right)
      new_r = new TreeNode(*rhs.right);
    if (left)
      delete left;
    if (right)
      delete right;
    left = new_l;
    right = new_r;
    value = rhs.value;
    count = rhs.count;
    return *this;
  }

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  };

private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;

  void print() {
    cout << "[";
    print_r();
    cout << "]" << endl;
  }

  void print_r() {
    if (left) {
      left->print_r();
      cout << ", ";
    }
    cout << value;
    if (right) {
      cout << ", ";
      right->print_r();
    }
  }
};

class BinStrTree {
public:
  BinStrTree(TreeNode *rt) : root(nullptr) {
    if (rt)
      root = new TreeNode(*rt);
  };

  BinStrTree(const BinStrTree &orig) : root(nullptr) {
    if (orig.root)
      root = new TreeNode(*orig.root);
  }

  BinStrTree &operator=(const BinStrTree &rhs) {
    auto r_copy = new TreeNode(*root);
    delete root;
    if (r_copy)
      root = r_copy;
    return *this;
  };

  ~BinStrTree() {
    if (root) {
      delete root;
    }
  }

  void print() { root->print(); }

private:
  TreeNode *root;
};

int main() {
  TreeNode tom("tom");
  TreeNode sam("sam");
  TreeNode daddy("daddy", &tom, &sam);
  TreeNode daddy2(daddy);
  BinStrTree b(&daddy2);
  b.print();
}