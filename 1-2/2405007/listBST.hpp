#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;
/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    bool get_insert(Node *&curr, Key key, Value value)
    {
        if (!curr)
        {
            node_count++;
            curr = new Node(key, value);
            return true;
        }
        if (key < curr->key)
            return get_insert(curr->left, key, value);
        else if (key > curr->key)
            return get_insert(curr->right, key, value);
        else
            return false;
    }

    bool get_rmv(Node *&curr, Key key)
    {
        if (!curr)
            return false;
        if (key < curr->key)
            return get_rmv(curr->left, key);
        else if (key > curr->key)
            return get_rmv(curr->right, key);
        else
        {
            if (!curr->left and !curr->right)
            {
                delete curr;
                curr = nullptr;
                node_count--;
            }
            else if (!curr->left)
            {
                Node *temp = curr;
                curr = curr->right;
                delete temp;
                node_count--;
            }
            else if (!curr->right)
            {
                Node *temp = curr;
                curr = curr->left;
                delete temp;
                node_count--;
            }
            else
            {
                Node *nxt = curr->right;
                while (nxt->left)
                    nxt = nxt->left;
                curr->key = nxt->key;
                curr->value = nxt->value;
                get_rmv(curr->right, nxt->key);
            }
            return true;
        }
    }

    bool get_find(Node *curr, Key key) const
    {
        if (!curr)
            return false;
        if (key == curr->key)
            return true;
        else if (key < curr->key)
            return get_find(curr->left, key);
        else
            return get_find(curr->right, key);
    }

    Value get_value(Node *curr, Key key) const
    {
        if (!curr)
            throw runtime_error("Key not found");
        if (key == curr->key)
            return curr->value;
        else if (key < curr->key)
            return get_value(curr->left, key);
        else
            return get_value(curr->right, key);
    }

    void get_update(Node *curr, Key key, Value value)
    {
        if (!curr)
            throw runtime_error("Key not found");
        if (key == curr->key)
            curr->value = value;
        else if (key < curr->key)
            get_update(curr->left, key, value);
        else
            get_update(curr->right, key, value);
    }

    void get_clear(Node *node)
    {
        if (!node)
            return;
        get_clear(node->left);
        get_clear(node->right);
        delete node;
    }

    Node* get_lca(Node* node, Key a, Key b) override{
        if(!node) return nullptr;
        if(a<node->key and b<node->key) return get_lca(Node* node->left, a, b);
        else if(a>node->key and b>node->key) return get_lca(Node* node->right, a, b);
        return node;
    }

    Key kth_smallest(Node *node, int &k) const{
        if(!node) throw runtime_error("Not found");
        Key left=kth_smallest(node->left, k);
        if(k==0) return left;
        k--;
        if(k==0) return node->key;
        return kth_smallest(node->right,k);
    }
    void print_def(Node *node) const
    {
        if (!node)
            return;
        cout << "(" << node->key << ":" << node->value;
        if (!node->left and !node->right)
        {
            cout << ")";
            return;
        }
        cout << " ";
        if (node->left)
            print_def(node->left);
        if (node->right)
        {
            if (!node->left)
                cout << "() ";
            else
                cout << " ";
            print_def(node->right);
        }
        cout << ")";
    }

    void print_in(Node *node) const
    {
        if (!node)
            return;
        if (node->left)
            print_in(node->left);
        cout << "(" << node->key << ":" << node->value << ") ";
        if (node->right)
            print_in(node->right);
    }

    void print_pre(Node *node) const
    {
        if (!node)
            return;
        cout << "(" << node->key << ":" << node->value << ") ";
        if (node->left)
            print_pre(node->left);
        if (node->right)
            print_pre(node->right);
    }

    void print_post(Node *node) const
    {
        if (!node)
            return;
        if (node->left)
            print_post(node->left);
        if (node->right)
            print_post(node->right);
        cout << "(" << node->key << ":" << node->value << ") ";
    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear();
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        return get_insert(root, key, value);
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        return get_rmv(root, key);
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        return get_find(root, key);
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic
        return get_value(root, key);
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        get_update(root, key, value);
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic
        get_clear(root);
        root = nullptr;
        node_count = 0;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        return node_count == 0;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if (!root)
        {
            throw runtime_error("BST is empty");
        }
        Node *curr = root;
        while (curr->left)
            curr = curr->left;
        return curr->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if (!root)
            throw runtime_error("BST is empty");
        Node *curr = root;
        while (curr->right)
            curr = curr->right;
        return curr->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
        if (toupper(traversal_type) == 'D')
        {
            cout << "BST (Default): ";
            print_def(root);
        }
        else if (toupper(traversal_type) == 'I')
        {
            cout << "BST (In-order): ";
            print_in(root);
        }
        else if (toupper(traversal_type) == 'P')
        {
            cout << "BST (Pre-order): ";
            print_pre(root);
        }
        else if (toupper(traversal_type) == 'O')
        {
            cout << "BST (Post-order): ";
            print_post(root);
        }
        else
            throw invalid_argument("Invalid traversal type");
        cout << "\n";
    }

    Key lca(Key a, Key b) const{
        Node* temp=get_lca(root, a ,b);
        if(!temp) throw runtime_error("Lca not found");
        return temp->key;
    }

    Key get_median() const{
        int k=(node_count+1)/2;
        return kth_smallest(root,k);
    }

    Key successor(Key a){
        Node* curr=root;
        Node* succ=nullptr;
        while(curr){
            if(a<curr->key){
                succ=curr;
                curr=curr->left;
            }
            else
                curr=curr->right;
        }
        if(!succ) throw runtime_error("Successor not found");
        return succ->key;
    }

    Key predecessor(Key a){
        Node* curr=root;
        Node* pred=nullptr;
        while(curr){
            if(a>curr->key){
                pred=curr;
                curr=curr->right;
            }
            else
                curr=curr->left;
        }
        if(!pred) throw runtime_error("Predecessor not found");
        return pred->key;
    }
};

#endif // LISTBST_H