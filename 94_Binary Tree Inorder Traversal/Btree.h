#include <iostream>
#include <cstdlib>


//Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	
	
class Btree
{
    public:
        Btree()
        {
        	root=NULL;
        }
        
        ~Btree(){}

        TreeNode *insert(int key);  //For root
        TreeNode *search(int key);   //For root
        void destroy_tree();  //For root
        
		TreeNode * contruct_tree();

    private:
        void destroy_tree(TreeNode *leaf);
        TreeNode *insert(int key, TreeNode *leaf);
        TreeNode *insert_nocompare(int key, TreeNode *leaf);
        TreeNode *search(int key, TreeNode *leaf);
        
        TreeNode *root;
};
