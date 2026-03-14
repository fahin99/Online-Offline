#include <iostream>
#include <fstream>
#include <string>
#include "listBST.hpp"
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
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item
    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    ListBST<string, int> price_bst;
    ListBST<string, int> net_bst;
    ListBST<string, int> succ_bst;
    ListBST<string, int> rej_bst;
    string *items = new string[10];
    int size = 0;
    int capacity = 10;
    int net_bids = 0, succ_bids = 0, rej_bids = 0;
    // End your code here

    int n;
    in_file >> n;
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        string item;
        int start;
        in_file >> item >> start;
        price_bst.insert(item, start);
        net_bst.insert(item, 0);
        succ_bst.insert(item, 0);
        rej_bst.insert(item, 0);
        if (size == capacity)
        {
            capacity *= 2;
            string *new_items = new string[capacity];
            for (int j = 0; j < size; j++)
                new_items[j] = items[j];
            delete[] items;
            items = new_items;
        }
        items[size++] = item;
        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout << "Initial auction items:\n";
    price_bst.print('I');
    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation)
    {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        if (operation == "ADD")
        {
            string item;
            int amount;
            in_file >> item >> amount;
            if (price_bst.find(item))
            {
                if (amount <= price_bst.get(item))
                {
                    cout << item << " already exists with a higher or equal starting bid.\n";
                    price_bst.print('I');
                }
                else
                {
                    price_bst.update(item, amount);
                    cout << item << " already exists. Starting bid updated to " << amount << "\n";
                    price_bst.print('I');
                }
            }
            else
            {
                price_bst.insert(item, amount);
                net_bst.insert(item, 0);
                succ_bst.insert(item, 0);
                rej_bst.insert(item, 0);
                if (size == capacity)
                {
                    capacity *= 2;
                    string *new_items = new string[capacity];
                    for (int j = 0; j < size; j++)
                        new_items[j] = items[j];
                    delete[] items;
                    items = new_items;
                }
                items[size++] = item;
                cout << "Item " << item << " added with starting bid " << amount << "\n";
                price_bst.print('I');
            }
        }
        else if (operation == "BID")
        {
            string item;
            int amount;
            in_file >> item >> amount;
            int net = net_bst.get(item);
            net++;
            net_bst.update(item, net);
            net_bids++;
            int curr = price_bst.get(item);
            if (amount > curr)
            {
                price_bst.update(item, amount);
                int succ = succ_bst.get(item);
                succ++;
                succ_bst.update(item, succ);
                succ_bids++;
                cout << "Bid of " << amount << " on " << item << " accepted. Current bid: " << amount << "\n";
            }
            else
            {
                int rej = rej_bst.get(item);
                rej++;
                rej_bst.update(item, rej);
                rej_bids++;
                cout << "Bid of " << amount << " on " << item << " rejected. Current bid remains: " << curr << "\n";
            }
            price_bst.print('I');
        }
        else if (operation == "CHECK")
        {
            string item;
            in_file >> item;
            cout << "Current bid for " << item << ": " << price_bst.get(item) << "\n";
            price_bst.print('I');
        }
        else if (operation == "STATS")
        {
            string item;
            in_file >> item;
            cout << "Statistics for " << item << ":\n";
            cout << "  Current highest bid: " << price_bst.get(item) << "\n";
            cout << "  Total Bids placed: " << net_bst.get(item) << "\n";
            cout << "  Successful Bids: " << succ_bst.get(item) << "\n";
            cout << "  Rejected Bids: " << rej_bst.get(item) << "\n";
        }
        else if (operation == "REPORT")
        {
            cout << "Auction Report:\n";
            for (int i = 0; i < size - 1; i++)
            {
                int idx = i;
                for (int j = i + 1; j < size; j++)
                {
                    if (items[idx] > items[j])
                        idx = j;
                }
                if (idx != i)
                {
                    string temp = items[i];
                    items[i] = items[idx];
                    items[idx] = temp;
                }
            }
            cout << "Total items: " << size << "\nTotal Bids placed: " << net_bids << "\nTotal Successful Bids: " << succ_bids << "\nTotal Rejected Bids: " << rej_bids << "\n";
            cout << "\nItem statistics:\n";
            for (int i = 0; i < size; i++)
            {
                cout << "  " << items[i] << ": Current bid: " << price_bst.get(items[i]) << ", Total Bids: " << net_bst.get(items[i]) << ", Successful: " << succ_bst.get(items[i]) << ", Rejected: " << rej_bst.get(items[i]) << "\n";
            }
            delete[] items;
        }
        // End your code here
        cout << "==============================\n";
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    price_bst.clear();
    net_bst.clear();
    succ_bst.clear();
    rej_bst.clear();
    // End your code here
    return 0;
}
