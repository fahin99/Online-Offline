#include<bits/stdc++.h>
using namespace std;

class avl{
    struct node{
        int key, height=0;
        node *left, *right;
        node(int k){
            key=k;
            height=1;
            left=nullptr;
            right=nullptr;
        }
    };
    node* root=nullptr;
    node* right_rotate(node *n){
        node *new_root=n->left;
        node *temp=new_root->right;
        new_root->right=n;
        n->left=temp;
        n->height=max(get_height(n->left), get_height(n->right))+1;
        new_root->height=max(get_height(new_root->left), get_height(new_root->right))+1;
        return new_root;
    }
    node *left_rotate(node* n){
        node *new_root=n->right;
        node *temp=new_root->left;
        new_root->left=n;
        n->right=temp;
        n->height=max(get_height(n->left), get_height(n->right))+1;
        new_root->height=max(get_height(new_root->left), get_height(new_root->right))+1;
        return new_root;
    }

    int get_height(node *n){
        if(n==nullptr) return 0;
        return n->height;
    }
    bool get_find(node *n, int k){
        if(n==nullptr) return false;
        if(k<n->key) return get_find(n->left, k);
        else if(k>n->key) return get_find(n->right, k);
        else return true;
    }
    int get_balance(node *n){
        if(n==nullptr) return 0;
        return get_height(n->left)-get_height(n->right);
    }
    node *get_insert(node *n, int k){
        if(n==nullptr) return new node(k);
        if(k<n->key) n->left=get_insert(n->left, k);
        else if(k>n->key) n->right=get_insert(n->right, k);
        n->height=max(get_height(n->left), get_height(n->right))+1;
        int balance=get_balance(n);
        if(balance>1 && k<n->left->key) return right_rotate(n);
        if(balance<-1 && k>n->right->key) return left_rotate(n);
        if(balance>1 && k>n->left->key){
            n->left=left_rotate(n->left);
            return right_rotate(n);
        }
        if(balance<-1 && k<n->right->key){
            n->right=right_rotate(n->right);
            return left_rotate(n);
        }
        return n;
    }
    node* get_erase(node *n, int k){
        if(n==nullptr) return n;
        if(k<n->key) n->left=get_erase(n->left, k);
        else if(k>n->key) n->right=get_erase(n->right, k);
        else{
            if(n->left==nullptr || n->right==nullptr){
                node *temp;
                if(n->left) temp=n->left;
                else temp=n->right;
                if(temp==nullptr){
                    temp=n;
                    n=nullptr;
                }
                else *n=*temp;
                delete temp;
            }
            else{
                node *temp=n->right;
                while(temp->left!=nullptr) temp=temp->left;
                n->key=temp->key;
                n->right=get_erase(n->right, temp->key);
            }
        }
        if(n==nullptr) return n;
        n->height=max(get_height(n->left), get_height(n->right))+1;
        int balance=get_balance(n);
        if(balance>1 && get_balance(n->left)>=0) return right_rotate(n);
        if(balance<-1 && get_balance(n->right)<=0) return left_rotate(n);
        if(balance>1 && get_balance(n->left)<0){
            n->left=left_rotate(n->left);
            return right_rotate(n);
        }
        if(balance<-1 && get_balance(n->right)>0){
            n->right=right_rotate(n->right);
            return left_rotate(n);
        }
        return n;
    }
public:
    int length(int k){
        node *n=get_node(k);
        if(n==nullptr) return 0;
        return get_height(n);
    }
    int get_key(node *n){
        return n->key;
    }
    int balance(int k){
        node *n=get_node(k);
        if(n==nullptr) return 0;
        return get_balance(n);
    }
    node* get_root(){
        return root;
    }
    node* get_node(int k){
        node *n=root;
        while(n!=nullptr){
            if(k<n->key) n=n->left;
            else if(k>n->key) n=n->right;
            else return n;
        }
        return nullptr;
    }
    bool find(int k){
        return get_find(root, k);
    }
    bool insert(int k){
        if(find(k)) return false;
        root=get_insert(root, k);
        return true;
    }
    bool erase(int k){
        if(!find(k)) return false;
        root=get_erase(root, k);
        return true;
    }
    vector<int> in_order(){
        vector<int> res;
        stack<node*> st;
        node *n=root;
        while(n!=nullptr || !st.empty()){
            while(n!=nullptr){
                st.push(n);
                n=n->left;
            }
            n=st.top();
            st.pop();
            res.push_back(n->key);
            n=n->right;
        }
        return res;
    }
    void parentheses(node *n, ostream &out){
        if(n==nullptr) return;
        out<<n->key;
        if(n->left or n->right){
            out<<"(";
            if(n->left) parentheses(n->left, out);
            out<<",";
            if(n->right) parentheses(n->right, out);
            out<<")";
        }
    }
};


int main(int argc, char *argv[]){
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if(!in or !out){
        cout<<"Could not open"<<endl;
        return 1;
    }
    char cmd;
    int k;
    avl tree;
    while(in>>cmd){
        if(cmd=='I'){
            in>>k;
            if(tree.insert(k)){
                tree.parentheses(tree.get_root(), out);
                out<<endl;
            }
            else out<<"duplicate"<<endl;
        }
        else if(cmd=='D'){
            in>>k;
            if(tree.erase(k)){
                tree.parentheses(tree.get_root(), out);
                out<<endl;
            }
            else out<<"not found"<<endl;
        }
        else if(cmd=='F'){
            in>>k;
            if(tree.find(k)) out<<"found"<<endl;
            else out<<"not found"<<endl;
        }
        else if(cmd=='T'){
            vector<int> res=tree.in_order();
            for(auto it: res) out<<it<<" ";
            out<<endl;
        }
    }
    in.close();
}