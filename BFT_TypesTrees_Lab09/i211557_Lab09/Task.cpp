#include <iostream>
#include <cmath>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value = -1)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    node(const node &temp)
    {
        data = temp.data;
        left = temp.left;
        right = temp.right;
    }

    bool isFull()
    {
        if (right && left)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isNoChild()
    {
        if (!right && !left)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        cout << "Data is: " << data;
    }
};

class BST
{
private:
    node *root;
    int numNodes;

public:
    BST()
    {
        root = NULL;
        numNodes = 0;
    }

    bool isEmpty()
    {
        if (!root)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    node *returnRoot() // getter
    {
        return root;
    }

    void insert(int val)
    {
        node *current = root;
        if (!root)
        {
            root = new node(val);
            numNodes++;
        }
        else
        {
            while (current)
            {
                if (current->data == val)
                {
                    cout << "\nData already present in the tree !\n";
                    return;
                }

                if (current->data < val)
                {
                    if (!current->right)
                    {
                        current->right = new node(val);
                        numNodes++;
                        return;
                    }
                    current = current->right;
                }
                else if (current->data > val)
                {
                    if (!current->left)
                    {
                        current->left = new node(val);
                        numNodes++;
                        return;
                    }
                    current = current->left;
                }
            }
        }
    }

    void inorderTraversal(node *input)
    {
        if (input)
        {
            inorderTraversal(input->left);
            cout << input->data << " ";
            inorderTraversal(input->right);
        }
    }
    void preorderTraversal(node *input)
    {
        if (input)
        {
            cout << input->data << " ";
            inorderTraversal(input->left);

            inorderTraversal(input->right);
        }
    }
    void postorderTraversal(node *input)
    {
        if (input)
        {

            inorderTraversal(input->left);

            inorderTraversal(input->right);
            cout << input->data << " ";
        }
    }
    bool Search(int val)
    {
        node *current = root;
        while (current)
        {
            if (current->data == val)
            {
                return true;
            }

            else if (current->data < val)
            {

                current = current->right;
            }
            else if (current->data > val)
            {
                current = current->left;
            }
        }

        return false;
    }
    int findMax()
    {
        if (!root)
        {
            cout << "\nTree is Empty!\n";
            return 0;
        }
        node *current = root;
        while (current->right)
        {
            current = current->right;
        }
        return current->data;
    }

    int findMin()
    {
        if (!root)
        {
            cout << "\nTree is Empty!\n";
            return 0;
        }
        node *current = root;
        while (current->left)
        {
            current = current->left;
        }
        return current->data;
    }

    int returnNodeCount()
    {
        return numNodes;
    }
    int treeNodeCount()
    {
        return numNodes;
    }
    node *min_inRight(node *current)
    {
        current = current->right;
        while (current->left)
        {
            current = current->left;
        }
        return current;
    }

    void DeleteNode(node *&current)
    {
        node *temp;
        if (!current->left && !current->right)
        {

            delete current;
            current = NULL;
        }
        else if (!current->left && current->right)
        {
            temp = current;
            current = current->right;
            delete temp;
        }
        else if (!current->right && current->left)
        {
            temp = current;
            current = current->left;
            delete temp;
        }
        else
        {
            
            temp = min_inRight(current);
            temp->left = current->left; // Reattach the left subtree
            if(current->data=root->data)
            {
              root=temp;
            }
            temp = current;
            current = current->right; // Reattach the right subtree
            delete temp;
        }
    }

    bool Delete(node *&current, int key)
    {
        if (key == current->data)
        {
            DeleteNode(current);
            return 1;
        }

        if (!current)
        {
            cout << "\n[-]Value not Found!\n";
            return 0;
        }

        if (key > current->data)
        {
            return Delete(current->right, key);
        }

        if (key < current->data)
        {
            return Delete(current->left, key);
        }

    }

    void deleteTree(node *node) // using postorder traverse to delete the complete tree
    {
        if (node == NULL)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        //cout << "\n Deleting Node: " << node->data;
        delete node;
    }

    int height(node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            int leftheight = height(node->left);
            int rightheight = height(node->right);
            if (leftheight > rightheight)
            {
                return (leftheight + 1);
            }
            else
            {
                return (rightheight + 1);
            }
        }
    }

    int tree_height(node *node)
    {
        int height1 = height(node);
        height1--;
        return height1;
    }

    ~BST()
    {
        deleteTree(root);
    }
};

int main()
{

    BST T1;
    T1.insert(14);
    T1.insert(11);
    T1.insert(9);
    T1.insert(4);
    T1.insert(3);
    T1.insert(29);
    T1.insert(16);
    T1.insert(18);
    T1.insert(15);
    T1.insert(20);
    node *root = T1.returnRoot();
    cout << "\nDisplaying :\n";
    T1.inorderTraversal(T1.returnRoot());

    cout << "\nHeight: " << T1.tree_height(root) << endl;
    T1.Delete(root, 29);
    cout << "\nAfter Deleting 20: \n";
    T1.inorderTraversal(T1.returnRoot());
}