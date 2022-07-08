#include <iostream>
using namespace std;
 
class BST {
    public: 
    int data;
    BST *left, *right;

    BST();
    BST(int);
    BST* Insert(BST*, int);
    void Inorder(BST*);
    void printLevelOrder(BST* root);
    void printCurrentLevel(BST* root, int level);
    int height(BST* node);
    BST* newNode(int data);
};

BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
BST* BST ::Insert(BST* root, int value)
{ 
    if (!root) {
        return new BST(value);
    }
    if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    else if(value < root->data){
        root->left = Insert(root->left, value);
    }

    return root;
}

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
 
// Driver code
int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 35);
    b.Insert(root, 6);
    b.Insert(root, 984);
    b.Insert(root, 2);
    b.Insert(root, 5);
    b.Insert(root, 19);
    b.Insert(root, 9);
    b.Insert(root, 20);
    b.Insert(root, 4);
    b.Insert(root, 13);
    b.Insert(root, 14);
    b.Insert(root, 111);
    b.Insert(root, 985);
    b.printLevelOrder(root);
    b.Insert(root, 65);
    b.printLevelOrder(root);
    return 0;
}


 
/* Function to print level
order traversal a tree*/
void BST ::printLevelOrder(BST* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void BST ::printCurrentLevel(BST* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int BST ::height(BST* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
 