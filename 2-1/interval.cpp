#include<bits/stdc++.h>
using namespace std;

class avl{
    struct node{
        int id=0, start, end, max_end, height=0;
        node *left, *right;
        node(int s, int e){
            id++;
            start=s;
            end=e;
            height=1;
            left=nullptr;
            right=nullptr;
        }
    };
    int compr(node* k, node* n){
        if(k->start!=n->start){
            if(k->start>n->start) return 1;
            else if(k->start<n->start) return -1;
            else return 0;
        }
        else{
            if(k->id>n->id) return -1;
            else if(k->id<n->id) return 1;
            else return 0;
        }
    }
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
    bool get_find(node *n, int s, int e){
        if(n==nullptr) return false;
        if(compr(get_node(s, e), n)==-1) return get_find(n->left, s, e);
        else if(compr(get_node(s, e), n)==1) return get_find(n->right, s, e);
        else return true;
    }
    int get_balance(node *n){
        if(n==nullptr) return 0;
        return get_height(n->left)-get_height(n->right);
    }
    node *get_insert(node *n, int s, int e){
        if(n==nullptr) return new node(s, e);
        if(compr(get_node(s, e), n)==-1) n->left=get_insert(n->left, s, e);
        else if(compr(get_node(s, e), n)==1) n->right=get_insert(n->right, s, e);
        n->height=max(get_height(n->left), get_height(n->right))+1;
        int balance=get_balance(n);
        if(balance>1 && s, e<n->left->id) return right_rotate(n);
        if(balance<-1 && s, e>n->right->id) return left_rotate(n);
        if(balance>1 && s, e>n->left->id){
            n->left=left_rotate(n->left);
            return right_rotate(n);
        }
        if(balance<-1 && s, e<n->right->id){
            n->right=right_rotate(n->right);
            return left_rotate(n);
        }
        return n;
    }
    node* get_erase(node *n, int s, int e){
        if(n==nullptr) return n;
        if(s, e<n->id) n->left=get_erase(n->left, s, e);
        else if(s, e>n->id) n->right=get_erase(n->right, s, e);
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
                n->id=temp->id;
                n->right=get_erase(n->right, temp->id);
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
    int length(int s, int e){
        node *n=get_node(s, e);
        if(n==nullptr) return 0;
        return get_height(n);
    }
    int get_id(node *n){
        return n->id;
    }
    int balance(int s, int e){
        node *n=get_node(s, e);
        if(n==nullptr) return 0;
        return get_balance(n);
    }
    node* get_root(){
        return root;
    }
    node* get_node(int s, int e, int i){
        node *n=root;
        while(n!=nullptr){
            if(s!=n->start){
                if(s>n->start) n=n->right;
                else if(s<n->start) n=n->left;
            }
            else{
                if(i>n->id) n=n->right;
                else if(i<n->id) n=n->left;
                else return n;
            }
        }
        return n;
    }
    bool find(int s, int e){
        return get_find(root, s, e);
    }
    bool insert(int s, int e){
        if(find(s, e)) return false;
        root=get_insert(root, s, e);
        return true;
    }
    bool erase(int s, int e){
        if(!find(s, e)) return false;
        root=get_erase(root, s, e);
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
            res.push_back(n->id);
            n=n->right;
        }
        return res;
    }
    void parentheses(node *n, ostream &out){
        if(n==nullptr) return;
        out<<n->id;
        if(n->left or n->right){
            out<<"(";
            if(n->left) parentheses(n->left, out);
            out<<",";
            if(n->right) parentheses(n->right, out);
            out<<")";
        }
    }
};