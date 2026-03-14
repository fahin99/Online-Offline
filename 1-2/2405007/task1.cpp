#include <iostream>
#include <fstream>
#include "listBST.hpp"
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst)
    {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c)
    {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        switch (c)
        {
        case 'I':
            in_file >> val;
            if (bst->insert(val, val))
            {
                cout << "Key " << val << " inserted in BST, ";
                bst->print('D');
            }
            else
            {
                cout << "Insertion failed! Key " << val << " already exists in BST, ";
                bst->print('D');
            }
            break;
        case 'D':
            in_file >> val;
            if (bst->remove(val))
            {
                cout << "Key " << val << " removed from BST, ";
                bst->print('D');
            }
            else
            {
                cout << "Removal failed! Key " << val << " not found in BST, ";
                bst->print('D');
            }
            break;
        case 'F':
            in_file >> val;
            if (bst->find(val))
                cout << "Key " << val << " found in BST\n";
            else
                cout << "Key " << val << " not found in BST\n";
            break;
        case 'M':
            in_file >> str;
            if (strcmp(str, "Min") == 0)
                cout << "Minimum value: " << bst->find_min() << "\n";
            else if (strcmp(str, "Max") == 0)
                cout << "Maximum value: " << bst->find_max() << "\n";
            else
                cout << "Error: Invalid command\n";
            break;
        case 'S':
            cout << "Size: " << bst->size() << "\n";
            break;
        case 'E':
            if (bst->empty())
                cout << "Empty\n";
            else
                cout << "Not empty\n";
            break;
        case 'T':
            in_file >> str;
            if (strcmp(str, "Pre") == 0)
                bst->print('P');
            else if (strcmp(str, "In") == 0)
                bst->print('I');
            else if (strcmp(str, "Post") == 0)
                bst->print('O');
            else
                cout << "Error: Invalid traversal type\n";
            break;
        default:
            cout << "Error: Invalid command\n";
        }
    }
    in_file.close();
    delete bst;
    return 0;
}
