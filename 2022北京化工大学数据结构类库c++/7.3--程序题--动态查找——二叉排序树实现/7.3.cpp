#include<iostream>
using namespace std;

//二叉排序树
typedef struct Node
{
    int key;
    Node *left;
    Node *right;
}*Tree;

Tree insert(Tree root, int key)
{
    if (root == NULL)
    {
        root = new Node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        cout<<"插入函数中的root:    "<<root<<endl;
        //这里的root是指向根节点的指针 在递归中返回到上一层，不一定是主函数
        return root;
    }
    else if (key < root->key)
        root->left=insert(root->left, key);
    else
        root->right=insert(root->right, key);
}


//输出排序结果
void print(Node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}

int main(){
    Tree root = NULL;
    int key;
    cout<<"请输入数据，输入-1结束"<<endl;
    while (cin >> key)
        if (key != -1)
            {root=insert(root, key); //这里不是每一次都要赋值，因为每次都是指向根节点的指针
            cout<<"主函数里的root:  "<<root<<endl;}
        else
            break;
    print(root);
    return 0;
}