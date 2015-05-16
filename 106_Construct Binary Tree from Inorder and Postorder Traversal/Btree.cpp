#include <iostream>
#include <cstdlib>
#include "Btree.h"
using namespace std;


void Btree::destroy_tree(TreeNode *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

//Binary tree insert:only insert value without compare
TreeNode *Btree::insert_nocompare(int key, TreeNode *leaf)
{
	if(leaf->left!=NULL && leaf->right!=NULL)
		insert(key, leaf->left);
    else
    {
      if(leaf->left==NULL)
      {
	      cout << "Leaf:(" << leaf->val<< ")..." << endl; 
		  cout << "Build new lnode(" << key << ")..." << endl;  
		  leaf->left=new TreeNode;
	      leaf->left->val=key;
	      leaf->left->left=NULL;    //Sets the left child of the child node to null
	      leaf->left->right=NULL;   //Sets the right child of the child node to null
	      leaf=leaf->left; 
      }
      else //leaf->right==NULL
      {
      	  cout << "Leaf:(" << leaf->val<< ")..." << endl; 
	  	  cout << "Build new rnode(" << key<< ")..." << endl;  
	      leaf->right=new TreeNode;
          leaf->right->val=key;
          leaf->right->left=NULL;  //Sets the left child of the child node to null
          leaf->right->right=NULL; //Sets the right child of the child node to null
          leaf=leaf->right;
      }
	  
    } 
	
  
  return leaf;
}


TreeNode *Btree::insert(int key, TreeNode *leaf)
{
  if(key< leaf->val)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      cout << "Leaf:(" << leaf->val<< ")..." << endl; 
	  cout << "Build new lnode(" << key << ")..." << endl;  
	  leaf->left=new TreeNode;
      leaf->left->val=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
      leaf=leaf->left; 
    } 
	
  }
  else if(key>=leaf->val)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      cout << "Leaf:(" << leaf->val<< ")..." << endl; 
	  cout << "Build new rnode(" << key<< ")..." << endl;  
	  leaf->right=new TreeNode;
      leaf->right->val=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
      leaf=leaf->right;
    }
    
  }
  
  return leaf;
}

TreeNode *Btree::search(int key, TreeNode *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->val)
      return leaf;
    if(key<leaf->val)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

/*
The public version of the insert function takes care of the case where the root has not 
been initialized by allocating the memory for it and setting both child nodes to NULL and 
setting the key_value to the value to be inserted. If the root node already exists, 
insert is called with the root node as the initial node of the function, and the recursive 
insert function takes over.
*/
TreeNode *Btree::insert(int key)
{
  
  if(root!=NULL)
    insert(key, root);
  else
  {
    cout << "Build root(" << key << ")..." << endl;  
	root=new TreeNode;
    root->val=key;
    root->left=NULL;
    root->right=NULL;
  }
  return root;
}
/*
The public version of the search function is used to set off the search recursion at 
the root node, keeping it from being necessary for the user to have access to the root node.
*/
TreeNode *Btree::search(int key)
{
  return search(key, root);
}

/*
The public version of the destroy tree function is merely used to initialize the recursive 
destroy_tree function which then deletes all the nodes of the tree. 
*/
void Btree::destroy_tree()
{
  destroy_tree(root);
}
