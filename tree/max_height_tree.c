/* Find the Maximum Depth or Height of a Tree */
/* Data Structures Using C by Shoriful Shine */
#include<stdio.h>
#include<stdlib.h>

struct node
 {
   int data;
   struct node* left;
   struct node* right;
  };

int maxDepth(struct node* node)
 {
   if (node==NULL)
     return 0;
   else
     {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        /* use the larger one */
        if (lDepth > rDepth)
           return(lDepth+1);
        else
           return(rDepth+1);
      }
                                                                                                  }
 struct node* newNode(int data)
   {
     struct node* node = (struct node*) malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
    }

  int main()
     {
      
      struct node *root = newNode(5);
      root->left = newNode(2);
      root->right = newNode(8);
      root->left->left = newNode(14);
      root->left->left->left= newNode(24);
      root->left->right = newNode(25);
      printf("Height of tree is %d", maxDepth(root));
      getchar();
      return 0;
      }
