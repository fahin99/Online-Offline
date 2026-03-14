#include <iostream>
using namespace std;
struct node
{
    int element;
    node *next;
    node *prev;
};

class linkedList
{
    node *head;
    node *tail;
    int curr;
    int size;

    node *node_at(int idx)
    {
        if (idx < 0 or idx >= size)
            return nullptr;
        node *temp = head;
        for (int i = 0; i < idx; i++)
            temp = temp->next;
        return temp;
    }

public:
    linkedList()
    {
        head = nullptr;
        tail = head;
        curr = -1;
        size = 0;
    }
    int get_curr()
    {
        return curr;
    }
    void set_curr(int idx)
    {
        if (idx < 0 or idx >= size)
            return;
        curr = idx;
    }
    node *get_curr_node()
    {
        return node_at(curr);
    }
    node *get_head()
    {
        return head;
    }
    node *get_tail()
    {
        return tail;
    }
    int get_elem_at(int idx)
    {
        node *temp = node_at(idx);
        if (temp != nullptr)
            return temp->element;
        return -1;
    }
    void insert_cur(int value)
    {
        node *newNode = new node;
        newNode->element = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (size == 0)
        {
            head = newNode;
            tail = head;
            curr++;
            size++;
        }
        else if (curr == size - 1)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
            curr++;
        }
        else
        {
            node *temp = node_at(curr);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
            curr++;
        }
    }

    int delete_cur()
    {
        if (size == 0 or curr < 0 or curr >= size)
            return -1;
        else if (head == nullptr)
            return -1;
        node *temp = node_at(curr);
        int temp_elem = temp->element;
        if (size == 1)
        {
            head = nullptr;
            tail = head;
            curr = -1;
            size--;
        }
        else if (temp == head)
        {
            head = head->next;
            head->prev = nullptr;
            size--;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            curr--;
            size--;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            size--;
        }
        delete temp;
        return temp_elem;
    }
    void append(int value)
    {
        node *newNode = new node;
        newNode->element = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (size == 0)
        {
            head = newNode;
            tail = head;
            size++;
            curr++;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    int length()
    {
        return size;
    }
    void prev(int n)
    {
        if (curr - n < 0 or curr - n >= size)
            curr = 0;
        else
            curr -= n;
    }
    void next(int n)
    {
        if (curr + n < 0 or curr + n >= size)
            curr = size - 1;
        else
            curr += n;
    }
    int is_present(int value)
    {
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->element == value)
                return 1;
            temp = temp->next;
        }
        return 0;
    }
    void clear()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        tail = head;
        curr = -1;
        size = 0;
    }
    int delete_item(int value)
    {
        node *temp = head;
        int del_idx = 0;
        while (temp != nullptr)
        {
            if (temp->element == value)
            {
                set_curr(del_idx);
                delete_cur();
                return 1;
            }
            temp = temp->next;
            del_idx++;
        }
        return 0;
    }
    // void swap_ind(int idx1, int idx2)
    // {
    //     node *node1 = node_at(idx1);
    //     node *node2 = node_at(idx2);
    //     if (node1 == nullptr or node2 == nullptr)
    //         return;
    //     int temp = node1->element;
    //     node1->element = node2->element;
    //     node2->element = temp;
    // }
    void swap_ind(int idx1, int idx2)
    {
        if (idx1 == idx2)
            return;
        if (idx1 > idx2)
        {
            int temp = idx1;
            idx1 = idx2;
            idx2 = temp;
        }
        node *n1 = node_at(idx1);
        node *n2 = node_at(idx2);
        if (!n1 or !n2)
            return;
        if (n1->next == n2)
        {
            node *p = n1->prev;
            node *n = n2->next;
            if (p)
                p->next = n2;
            else
                head = n2;
            if (n)
                n->prev = n1;
            else
                tail = n1;
            n2->prev = p;
            n2->next = n1;
            n1->prev = n2;
            n1->next = n;
        }
        else
        {
            node *p1 = n1->prev;
            node *n1Nex = n1->next;
            node *p2 = n2->prev;
            node *n2Nex = n2->next;
            if (p1)
                p1->next = n2;
            else
                head = n2;
            if (n1Nex)
                n1Nex->prev = n2;
            if (p2)
                p2->next = n1;
            else
                head = n1;
            if (n2Nex)
                n2Nex->prev = n1;
            n2->prev = p1;
            n2->next = n1Nex;
            n1->prev = p2;
            n1->next = n2Nex;
            if (!n1->next)
                tail = n1;
            if (!n2->next)
                tail = n2;
        }
    }

    int search(int value)
    {
        node *temp = head;
        int idx = 0;
        while (temp != nullptr)
        {
            if (temp->element == value)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int find(int idx)
    {
        node *temp = node_at(idx);
        if (temp != nullptr)
            return temp->element;
        return -1;
    }
    int update(int idx, int value)
    {
        node *temp = node_at(idx);
        if (temp != nullptr)
        {
            int old_value = temp->element;
            temp->element = value;
            return old_value;
        }
        return -1;
    }
    int trim()
    {
        if (size == 0)
            return -1;
        if (curr >= size - 1)
            curr = size - 2;
        node *temp = tail;
        int temp_elem = tail->element;
        if (size == 1)
        {
            head = nullptr;
            tail = head;
            curr = -1;
            size--;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            size--;
        }
        delete temp;
        return temp_elem;
    }
    // void reverse()
    // {
    //     if (size <= 1)
    //         return;
    //     node *mid = node_at(size / 2);
    //     node *temp = head;
    //     node *end = tail;
    //     while (temp != mid)
    //     {
    //         int temp_elem = temp->element;
    //         temp->element = end->element;
    //         end->element = temp_elem;
    //         temp = temp->next;
    //         end = end->prev;
    //     }
    // }
    void reverse()
    {
        node *currNode = head;
        node *temp = nullptr;
        while (currNode != nullptr)
        {
            temp = currNode->prev;
            currNode->prev = currNode->next;
            currNode->next = temp;
            currNode = currNode->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }

    ~linkedList()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};
