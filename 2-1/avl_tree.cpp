#include<bits/stdc++.h>
using namespace std;

class avl{
    int key, height;
    avl *left, *right;

    avl* right_rotate(avl *node){
        avl *root=node->left;
        avl *temp=root->right;
        root->right=node;
        node->left=temp;
        node->height=max(get_height(node->left), get_height(node->right))+1;
        root->height=max(get_height(root->left), get_height(root->right))+1;
        return root;
    }
public:
    avl(int k){
        key=k;
        height=1;
        left=nullptr;
        right=nullptr;
    }
    int get_height(avl *node){
        if(node==nullptr) return 0;
        return node->height;
    }
    int get_key(){
        return key;
    }
    bool is_balanced(){
        int bal=get_height(left)-get_height(right);
        return (bal>=-1 && bal<=1);
    }

};