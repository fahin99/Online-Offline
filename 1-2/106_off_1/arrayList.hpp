#include <iostream>
#include <stdio.h>
using namespace std;
class arrayList
{
private:
    int *arr;
    int capacity;
    int size;
    int curr_idx;
    void mov_to_new_arr(int new_capac)
    {
        int *new_arr = new int[new_capac];
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capac;
    }
    void incr_capac()
    {
        mov_to_new_arr(capacity * 2);
    }
    void decr_capac()
    {
        mov_to_new_arr(capacity / 2);
    }

public:
    arrayList()
    {
        capacity = 2;
        size = 0;
        curr_idx = -1;
        arr = new int[capacity];
    }
    int get_curr()
    {
        return curr_idx;
    }
    int length()
    {
        return size;
    }
    void insert_cur(int value)
    {
        if (size * 2 >= capacity)
        {
            incr_capac();
        }
        if (curr_idx < size - 1)
        {
            for (int i = size; i > curr_idx + 1; i--)
            {
                arr[i] = arr[i - 1];
            }
        }
        arr[++curr_idx] = value;
        size++;
    }
    int delete_cur()
    {
        if (size == 0)
        {
            return -1;
        }
        int deleted_value = arr[curr_idx];
        for (int i = curr_idx; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size == 0)
        {
            curr_idx = -1;
        }
        else if (curr_idx >= size)
        {
            curr_idx = size - 1;
        }
        if (size < capacity / 4.0 && capacity > 2)
        {
            decr_capac();
        }
        return deleted_value;
    }
    void append(int value)
    {
        if (size * 2 >= capacity)
        {
            incr_capac();
        }
        arr[size++] = value;
        if (curr_idx == -1)
        {
            curr_idx = 0;
        }
    }
    void prev(int n)
    {
        if (curr_idx - n >= size - 1)
            curr_idx = size - 1;
        else if (curr_idx - n < 0)
            curr_idx = 0;
        else
            curr_idx -= n;
    }
    void next(int n)
    {
        if (curr_idx + n >= size)
            curr_idx = size - 1;
        else if (curr_idx + n < 0)
            curr_idx = 0;
        else
            curr_idx += n;
    }
    int is_present(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
                return 1;
        }
        return 0;
    }
    void clear()
    {
        delete[] arr;
        capacity = 2;
        size = 0;
        curr_idx = -1;
        arr = new int[capacity];
    }
    int delete_item(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                curr_idx = i;
                delete_cur();
                return 1;
            }
        }
        return 0;
    }
    void swap_ind(int idx1, int idx2)
    {
        if (idx1 < 0 or idx2 < 0 or idx1 >= size or idx2 >= size)
            return;
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    int search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }
    int find(int idx)
    {
        if (idx < size and idx >= 0)
            return arr[idx];
        return -1;
    }
    int update(int idx, int value)
    {
        if (idx < size and idx >= 0)
        {
            int temp = arr[idx];
            arr[idx] = value;
            return temp;
        }
        return -1;
    }
    int trim()
    {
        if (size == 0)
            return -1;
        if (curr_idx >= size - 1)
            curr_idx = size - 2;
        int temp = arr[size - 1];
        size--;
        if (size == 0)
            curr_idx = -1;
        if (size * 4 <= capacity and capacity > 2)
            decr_capac();
        return temp;
    }
    void reverse()
    {
        if (size <= 1)
            return;
        for (int i = 0; i < size / 2; i++)
        {
            swap_ind(i, size - i - 1);
        }
    }
    ~arrayList()
    {
        delete[] arr;
    }
};