#include <iostream>

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node (int num)
    {
        val = num;
        left = NULL;
        right = NULL;
    }
};

class BSearchTree {
private:
    Node *root;
    void addNode (Node *head, int num)
    {
        if (head->val < num) {
                if (head->right != NULL)  {
                    addNode(head->right, num);
                } else {
                    head->right = new Node(num);
                }
        } else if (head->val > num) {
            if (head->left != NULL) {
                addNode(head->left, num);
            } else {
                head->left = new Node(num);
            }
        }
    }
    Node * searchItem(Node *head, int num)
    {
        if (NULL == head) {
            return NULL;
        } else if (head->val == num) {
            return head;
        } else if (head->val < num) {
            return searchItem(head->right, num);
        } else if (head->val > num) {
            return searchItem(head->left, num);
        }
    }
    void preOrder(Node * head)
    {
        if (head != NULL) {
            std::cout << " " << head->val << " ";
            if(head->left) preOrder(head->left);
            if(head->right) preOrder(head->right);
        }
    }
    void inOrder(Node *head)
    {
        if (head != NULL) {
            if(head->left) inOrder(head->left);
            std::cout << " " << head->val << " ";
            if(head->right) inOrder(head->right);
        }
    }
    void postOrder(Node *head)
    {
        if (head != NULL) {
            if (head->left) postOrder(head->left);
            if (head->right) postOrder(head->right);
            std::cout << " " << head->val << " ";
        }
    }

public:
    BSearchTree() : root(NULL) {}
    void addNode (int num)
    {
        if (NULL != root) {
            addNode(root, num);
        } else {
            root = new Node(num);
        }
    }
    Node * searchItem(int num)
    {
        return searchItem(root, num);
    }
    void preOrder()
    {
        std::cout << " Pre order btree ... " << std::endl;
        preOrder(root);
        std::cout << std::endl;
    }
    void inOrder(void)
    {
        std::cout << " In order btree ... " << std::endl;
        inOrder(root);
        std::cout << std::endl;
    }
    void postOrder(void)
    {
        std::cout << " Post order btree ... " << std::endl;
        postOrder(root);
        std::cout << std::endl;
    }
};
int main(void)
{
    BSearchTree bTree;
    bTree.addNode(10);
    bTree.addNode(20);
    bTree.addNode(5);
    bTree.addNode(50);
    bTree.addNode(6);
    bTree.preOrder();
    bTree.inOrder();
    bTree.postOrder();

    Node *ptr = NULL;
    ptr = bTree.searchItem(6);
    if (ptr)
        std::cout << "Item found " << ptr->val << std::cout << std::endl;
    else
        std::cout << "Item not found " << std::endl;

    ptr = bTree.searchItem(7);
    if (ptr)
        std::cout << "Item found " << ptr->val << std::cout << std::endl;
    else
        std::cout << "Item not found " << std::endl;

    return 0;
}
