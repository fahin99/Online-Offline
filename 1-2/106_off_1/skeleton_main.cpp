#include <iostream>
#include <fstream>
#include "arrayList.hpp"
#include "linkedList.hpp"
#include <stdio.h>
using namespace std;

void print(arrayList &list)
{
    int n = list.length();
    cout << "[ ";
    if (n == 0)
    {
        cout << ". ]\n";
        return;
    }
    int cur = list.get_curr();
    for (int i = 0; i < n; i++)
    {
        cout << list.find(i) << " ";
        if (i == cur)
            cout << "| ";
    }
    cout << "]\n";
}
void print(linkedList &list)
{
    int n = list.length();
    cout << "[ ";
    if (n == 0)
    {
        cout << ". ]\n";
        return;
    }
    int cur = list.get_curr();
    for (int i = 0; i < n; i++)
    {
        cout << list.get_elem_at(i) << " ";
        if (i == cur)
            cout << "| ";
    }
    cout << "]\n";
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    // arrayList list;
    linkedList list;
    int func, param;
    while (fscanf(file, "%d", &func) == 1 and func != 0)
    {
        if (func == 1 and fscanf(file, "%d", &param) == 1)
        {
            printf("Insert %d\n", param);
            list.insert_cur(param);
            print(list);
        }
        else if (func == 2)
        {
            printf("Delete current item\n");
            if (list.length() > 0)
            {
                int deleted = list.delete_cur();
                print(list);
                printf("%d is deleted\n", deleted);
            }
            else
            {
                printf("List is empty\n");
            }
        }
        else if (func == 3 and fscanf(file, "%d", &param) == 1)
        {
            printf("Append %d\n", param);
            list.append(param);
            print(list);
        }
        else if (func == 4)
        {
            printf("Size of the list is %d\n", list.length());
        }
        else if (func == 5 and fscanf(file, "%d", &param) == 1)
        {
            printf("Prev %d\n", param);
            list.prev(param);
            print(list);
        }
        else if (func == 6 and fscanf(file, "%d", &param) == 1)
        {
            printf("Next %d\n", param);
            list.next(param);
            print(list);
        }
        else if (func == 7 and fscanf(file, "%d", &param) == 1)
        {
            if (list.is_present(param))
            {
                printf("%d is present\n", param);
            }
            else
            {
                printf("%d is not present\n", param);
            }
        }
        else if (func == 8)
        {
            printf("Clear the list\n");
            list.clear();
            print(list);
        }
        else if (func == 9 and fscanf(file, "%d", &param) == 1)
        {
            printf("Delete item %d\n", param);
            if (list.delete_item(param))
            {
                printf("%d is deleted\n", param);
            }
            else
            {
                printf("%d is not found\n", param);
            }
            print(list);
        }
        else if (func == 10 and fscanf(file, "%d", &param) == 1)
        {
            int idx2;
            if (fscanf(file, "%d", &idx2) == 1)
            {
                printf("Swap indices %d and %d\n", param, idx2);
                list.swap_ind(param, idx2);
                print(list);
            }
        }
        else if (func == 11 and fscanf(file, "%d", &param) == 1)
        {
            printf("Search %d\n", param);
            int idx = list.search(param);
            if (idx != -1)
            {
                printf("%d found at index %d\n", param, idx);
            }
            else
            {
                printf("%d not found in the list\n", param);
            }
        }
        else if (func == 12 and fscanf(file, "%d", &param) == 1)
        {
            printf("Find %d\n", param);
            if (param >= 0 and param < list.length())
            {
                int value = list.find(param);
                printf("%d is found at %d\n", value, param);
            }
            else
            {
                printf("%d is not a valid index\n", param);
            }
        }
        else if (func == 13 and fscanf(file, "%d", &param) == 1)
        {
            int value;
            if (fscanf(file, "%d", &value) == 1)
            {
                printf("Update index %d to value %d\n", param, value);
                int old_value = list.update(param, value);
                if (old_value != -1)
                {
                    printf("Index %d updated from %d to %d\n", param, old_value, value);
                }
                else
                {
                    printf("Index %d is out of bounds\n", param);
                }
                print(list);
            }
        }
        else if (func == 14)
        {
            printf("Trim\n");
            int deleted = list.trim();
            if (deleted != -1)
            {
                printf("%d is deleted\n", deleted);
            }
            else
            {
                printf("List is empty\n");
            }
            print(list);
        }
        else if (func == 15)
        {
            printf("Reverse\n");
            int n = list.length();
            list.reverse();
            print(list);
        }
        else
        {
            printf("Unknown function %d\n", func);
        }
        printf("\n");
    }
    fclose(file);
    printf("End\n");
    return 0;
}
