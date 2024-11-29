#include "bits/stdc++.h"

using namespace std;

class node
{
    int val;
    node *left;
    node *right;
    friend class BST;

public:
    node()
    {
        val = 0;
        right = nullptr;
        left = nullptr;
    }
    node(int v)
    {
        val = v;
        right = nullptr;
        left = nullptr;
    }
};
class BST
{
    node *head;

public:
    BST()
    {
        head = nullptr;
    }
    void add(int val)
    {
        node *temp = new node(val);
        if (head == nullptr)
        {
            head = temp;
            return;
        }
        node *root = head;
        node *prev = root;
        while (root != nullptr)
        {
            cout << root->val << " ";
            prev = root;
            if (root->val == val)
                return;
            else if (val > root->val)
                root = root->right;
            else
                root = root->left;
        }
        if (val > prev->val)
            prev->right = temp;
        else
            prev->left = temp;
        cout << temp->val;
        cout << endl;
        return;
    }
    void preorder(node *root)
    {
        if (root == nullptr)
            return;
        stack<node *> st;
        st.push(root);
        while (!st.empty())
        {
            node *temp = st.top();
            cout << temp->val << " ";
            st.pop();
            if (temp->right != nullptr)
                st.push(temp->right);
            if (temp->left != nullptr)
                st.push(temp->left);
        }
        cout << endl;
        return;
    }
    void inorder(node *root)
    {
        stack<node *> st;
        while (true)
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            if (st.empty())
                break;
            while (!st.empty() && st.top()->right == nullptr)
            {
                cout << st.top()->val << " ";
                st.pop();
            }
            if (!st.empty())
            {
                root = st.top()->right;
                cout << st.top()->val << " ";
                st.pop();
            }
        }
        cout << endl;
    }
    void postorder2(node *root)
    {
        stack<node *> aux;
        stack<int> result;
        if (root == nullptr)return;
        aux.push(root);
        while (!aux.empty())
        {
            node *temp = aux.top();
            result.push(temp->val);
            aux.pop();
            if (temp->left != nullptr)
                aux.push(temp->left);
            if (temp->right != nullptr)
                aux.push(temp->right);
        }
        while (!result.empty())
        {
            cout << result.top() << " ";
            result.pop();
        }
        cout << endl;
    }
    void postorder1(node *root)
    {
        stack<node *> st;
        if (root == NULL)return;
        
        while (root != nullptr || !st.empty())
        {
            if(root!=nullptr){
                st.push(root);
                root = root->left;
            }
            else{
                node* temp = st.top()->right;
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    cout<<temp->val<<" ";
                    while (!st.empty() && st.top()->right == temp)
                    {
                        temp = st.top();
                        st.pop();
                        cout<<temp->val<<" ";
                    }
                }
                else{
                    root = temp;
                }
            }
        }
        cout<<endl;
    }
    node* searchNode(node* root,int num){
        if(root == NULL)return NULL;
        if(root->val == num)return root;
        else if(num > root->val)return searchNode(root->right,num);
        else return searchNode(root->left,num);
    }
    node* getSuccessor(node* root){
        root = root->right;
        while (root->left!=nullptr)
        {
            root=root->left;
        }
        return root;
    }
    node* del(int num,node* root){
        if(root == nullptr)return root;
        if(num<root->val)root->left=del(num,root->left);
        else if(num>root->val)root->right=del(num,root->right);
        else{
            if(root->left==nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* successor = getSuccessor(root);
            root->val = successor->val;
            root->right = del(successor->val,root->right);    
        }
        return root;
    }
    void delNode(int num){
        node* temp = head;
        del(num,temp);
    }
    void show()
    {
        node *root = head;
        cout << "preorder: ";
        preorder(root);
        cout << "inorder: ";
        inorder(root);
        cout << "postorder: ";
        postorder2(root);
        cout << "postorder: ";
        postorder1(root);
    }
};
int main(int argc, char const *argv[])
{
    BST bst;
    bst.add(8);
    bst.add(12);
    bst.add(4);
    bst.add(2);
    bst.add(6);
    bst.add(1);
    bst.add(3);
    bst.add(5);
    bst.add(7);
    bst.add(10);
    bst.add(14);
    bst.add(9);
    bst.add(11);
    bst.add(15);
    bst.add(13);
    // bst.add(2);
    // bst.add(1);
    bst.show();
    bst.delNode(8);
    bst.delNode(6);
    bst.show();    
    return 0;
}