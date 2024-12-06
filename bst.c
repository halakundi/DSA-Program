#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node in the binary search tree
struct node
{
 struct node *leftchild;
 int data;
 struct node *rightchild;
};
typedef struct node *treePointer;
treePointer root = NULL; // Initialize an empty tree
treePointer createNode(int value);
treePointer insertBST(treePointer root, int value);
void inorder(treePointer root);
void preorder(treePointer root);
void postorder(treePointer root);
void search(treePointer root,int key);
int main()
{
 // Array of values to create the binary search tree
 // Can take any array values Sample values given..
 int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 10};
 int i, ch, key, n = 10; // n is Size of the above array...
 while (1)
 {
printf("1.Create BST\n 2.Traversals \n3.Search \n4.Exit \nEnter Your Choice:");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 /* Create BST by inserting given elements into the tree */
 for (i = 0; i < n; i++)
 {
 root = insertBST(root, values[i]);
 }
 printf("Binary Search Tree Constructed.\n ");
 break;
 case 2:
 printf("\n Inorder: ");
 inorder(root);
 printf("\n Pre order: ");
 preorder(root);
 printf("\n Post order: ");
 postorder(root);
 printf("\n");
 break;
 case 3:
 printf("\n Enter the key to Search: ");
 scanf("%d", &key);
 search(root, key);
 case 4:
 exit(0);
 }
 }
 return 0;
}
// Function to create a new node
treePointer createNode(int value)
{
 treePointer temp = malloc(sizeof(struct node));
 temp->data = value;
 temp->leftchild = NULL;
 temp->rightchild = NULL;
 return temp;
}
// Function to insert a value into the binary search tree
treePointer insertBST(treePointer root, int value)
{
 // If the tree is empty, create a new node and make it the root
 if (root == NULL)
 {
 root = createNode(value);
 }
 // If the value is less than the root,
 //insert into the leftchild subtree
 else if (value < root->data)
 {
 root->leftchild = insertBST(root->leftchild, value);
 }
 // If the value is greater than or equal to the root,
 // insert into the rightchild subtree
 else
 {
 root->rightchild = insertBST(root->rightchild, value);
 }
 return root;
}
/* Function to perform inorder(L V R) traversal of the binary */
void inorder(treePointer root)
{
 if (root != NULL)
 {
 inorder(root->leftchild); // Visit Left Child
 printf("%d ", root->data); // Visit Root
 inorder(root->rightchild); // Visit Right Child
 }
}
/*Function to perform preorder (V L R) traversal of the binary*/
void preorder(treePointer root)
{
 if (root != NULL)
 {
 printf("%d ", root->data);
 preorder(root->leftchild);
 preorder(root->rightchild);
 }
}
// Function to perform postorder(L R V) traversal of the binary
void postorder(treePointer root)
{
 if (root != NULL)
 {
 postorder(root->leftchild);
 postorder(root->rightchild);
 printf("%d ", root->data);
 }
}
/* Function to search a key in the BST */
void search(treePointer root, int key)
{
 treePointer temp ;
 temp= root;
 while (temp != NULL)
 {
 if (key == temp->data) // Compare the node data with key
 {
 printf("Key found!\n");
 return;
 }
 else if (key < temp->data) // If key less the node data search left subtree
 {
 temp = temp->leftchild;
 }
 else // If key greater than the node data search right subtree
 {
 temp = temp->rightchild;
 }
 }
} 
