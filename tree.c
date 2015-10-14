#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "items.h"


// Varans uppbygnad, Det här bör vara i en seperat modul senare (ifall det inte redan finns, lätt och fixa isf) //

struct item{
  char *name;
  char *desc;
  int price;
  int amount;
};

// Bör flyttas till en egen modul senare //

typedef struct item item_t;


//Trädets nodes / branches uppbyggnad //

typedef struct treenode {
  item_t *item;
  struct treenode *left;
  struct treenode *right;
} treenode_t;

//Trädets uppbygnad //

typedef struct tree{
  treenode_t *root;
} tree_t;


/// Creates a new tree
///
/// \returns: empty tree
tree_t *tree_new(){
  tree_t *emptytree = NULL;
  emptytree = calloc(1, sizeof(tree_t));
  return emptytree;
}


/// Get the size of the tree 
///
/// \returns: the number of nodes in the tree
int tree_size(treenode_t *tree)
  {
    int i = 1;
    if (tree == NULL)
      return 0;
    else {
      i += tree_size(tree->left);
      i += tree_size(tree->right);
      return i;
    }
  }     


// Get the depth of the tree 
//
// \returns: the depth of the deepest subtree
/*int tree_depth(tree_t *tree){
  if (tree == NULL) return 0;
  else {


  }
}
*/
///Calculates the maxdepth of the tree
///i.e the number of nodes from the root to the farthest leaf

int max_depth(treenode_t *tree){
  int leftDepth;
  int rightDepth;
  if (tree == NULL) return 0;
  else
    {
      leftDepth = max_depth(tree->left);
      rightDepth = max_depth(tree->right);

      if (leftDepth > rightDepth)
	return (leftDepth + 1);
      else return (rightDepth + 1);
    }
}

/* (fungerar inte bra)
int minNode(struct treenode* treenode){
  struct treenode* current = treenode;

  while (current->left != NULL){
    current = current->left;
  }
  return(current->item);
}
*/

//TODO tree_insert(tree_t *tree, TODO);


/// Deleting a node from the tree

//struct treenode_t* tree_remove(struct treenode_t *root, char *name)
//{
  /* (FUNGERAR EJ, behöver fixas stort)
  if (*treenode == NULL) return 0;

  else if(name < warename((*root->item))) root->left = tree_remove(root->left, item_t);
  else if(name > warename((*root->item))) root->right = tree_remove(root->right, item_t);
  else
    {
      /// Node has no children
      if (root->left == NULL && root->right == NULL){
	free(treenode);
      }
      /// Node has 1 left child
      else if (root->left == NULL){
	struct treenode *temp = root;
	root = root -> left;
	free(temp);

      }
      /// Node has 1 right child
      else if(root->right == NULL) {
	struct treenode *temp = root;
	root = root->right;
	free(temp);
      }
      else{
	struct treenode *temp = minNode(root->right);
	root->name = temp->name;
	root->right = tree_remove(root->right, temp->name);
      }
    }
}
return treenode;
	
  */



  
  /*  
  if(strcmp(name, warename((*treenode)->item)) < 0){
      (*treenode)->left = tree_remove(&(*treenode)->left, name);
  }
  if (strcmp(name, warename((*treenode)->item)) > 0){
    (*treenode)->right = tree_remove(&(*treenode)->right, name);
  }
      else if ((*treenode)->left == NULL) {
	treenode_t *x = (*treenode)->right;
	free(*treenode);
	return x;
    }
      else if ((*treenode)->right == NULL){
	treenode_t*x = (*treenode) ->left;
	free(*treenode);
	return x;
      }
      
  return *treenode;
  }

  */








