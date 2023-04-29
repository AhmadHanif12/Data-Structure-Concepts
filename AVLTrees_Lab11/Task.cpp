#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

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

class AVL
{
public:
    node *root;
    int numNodes;
    AVL()
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

    bool insert(node *&root, int val)
    {
        bool flag = false;

        if (!root)
        {
            root = new node(val);
            return true;
        }
        else if (val > root->data)
        {
            flag = insert(root->right, val);
        }
        else if (val < root->data)
        {
            flag = insert(root->left, val);
        }
        else if (val == root->data)
        {
            cout << "\nData already present in the tree.\n";
            return false;
        }

        if (!flag)
        {
            return flag;
        }
        else
        {
            balance(root, val);
        }
        return true;
    }

    node *leftrotate(node *&current)
    {
        bool flag = false;

        node *temp1 = current->right;
        node *temp2 = temp1->left;

        temp1->left = current;
        current->right = temp2;
        current = temp1;
        return temp1;
    }

    node *rightrotate(node *&current)
    {
        bool flag = false;

        node *temp1 = current->left;
        node *temp2 = temp1->right;

        temp1->right = current;
        current->left = temp2;
        current = temp1;
        return temp1;
    }

    void balance(node *&root, int data)
    {
        int height1 = height(root->left) - height(root->right);

        if (height1 < -1 && data < root->right->data && root->right)
        {

            root->right = rightrotate(root->right);
            leftrotate(root);
        }
        else if (height1 < -1)
        {
            leftrotate(root);
        }
        else if (height1 > 1 && root->left && data > root->left->data)
        {
            root->left = leftrotate(root->left);
            rightrotate(root);
        }
        else if (height1 > 1)
        {
            rightrotate(root);
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
            // if (current->data = root->data)
            // {
            //     root = temp;
            // }
            temp = current;
            current = current->right; // Reattach the right subtree
            delete temp;
        }
    }

    bool Delete(node *&current, int key)
    {

        if (!current)
        {
            cout << "\n[-]Value not Found!\n";
            return 0;
        }
        else if (key == current->data)
        {
            DeleteNode(current);
        }

        else if (key > current->data)
        {
            Delete(current->right, key);
        }

        else if (key < current->data)
        {
            Delete(current->left, key);
        }

        if (current)
        {
            balance(current, key);
        }

        return false;
    }

    void deleteTree(node *node) // using postorder traverse to delete the complete tree
    {
        if (node == NULL)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        // cout << "\n Deleting Node: " << node->data;
        delete node;
    }

    int height(node *node)
    {
        if (node == NULL)
        {
            return -1;
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
    bool CheckBalanced(node *node)
    {
        if (node == NULL)
        {
            return true;
        }
        int leftheight = height(node->left);
        int rightheight = height(node->right);

        if ((leftheight - rightheight) <= 1)
        {
            if (CheckBalanced(node->left) && CheckBalanced(node->right))
            {
                return true;
            }
        }

        return false;
    }
    // Function to get the height of the complete tree
    int tree_height(node *node)
    {
        int height1 = height(node);
        height1--;
        return height1;
    }

    void queue1(node *root)
    {
        if (!root)
        {
            return;
        }
        queue<node *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            node *temp = nodes.front();
            cout << temp->data << " ";

            if (temp->left)
            {
                nodes.push(temp->left);
            }

            if (temp->right)
            {
                nodes.push(temp->right);
            }
            nodes.pop();
        }
    }

    ~AVL() // Destructor
    {
        deleteTree(root);
    }
};

int main()
{

    AVL T1;
    T1.insert(T1.root, 20);
    T1.insert(T1.root, 17);
    T1.insert(T1.root, 25);
    T1.insert(T1.root, 14);
    T1.insert(T1.root, 18);

    T1.Delete(T1.root, 14);;
    cout << endl;
    if (T1.CheckBalanced(T1.returnRoot()))
    {
        cout << "\nIt is a Balanced Binary Tree!\n";
    }
    else
    {
        cout << "\nIt isn't a Balanced binary tree\n";
    }

    T1.inorderTraversal(T1.root);
}