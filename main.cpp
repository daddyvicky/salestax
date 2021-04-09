#include <bits/stdc++.h>
#include "Item.hpp"
#include "Tax.hpp"
using namespace std;

vector<Item> basket;
vector<string> order;
Tax tax;
void printReceipt()
{
    cout << "------------------------------------------RECEIPT-----------------------------------------" << endl;
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << ": " << (basket[i].getPrice() + tax.getTaxOnItem(basket[i])) << "\n";

    double salesTax = 0.0, total = 0.0;
    for (auto item : basket)
    {
        total += item.getPrice();
        salesTax += tax.getTaxOnItem(item);
    }
    total += salesTax;
    cout << "Sales Taxes: " << salesTax << "\n";
    cout << "Total: " << total << "\n";
    cout << "------------------------------------------------------------------------------------------" << endl;
}
int main()
{
    string str;
    cout << "Please read instructions first:\n Enter orders line by line\n Press S to stop.\n Enter Your orders here:" << endl;
    while (getline(cin, str))
    {
        if (str == "s" || str == "S")
            break;
        order.push_back(str.substr(0, str.length() - 8));
        stringstream strs(str);
        string temp;
        ItemCategory itemCategory = ItemCategory::General;
        bool imported = false;
        while (strs >> temp)
        {
            if (temp == "imported")
                imported = true;
            if (temp == "chocolate" or temp == "chocolates")
                itemCategory = ItemCategory::Food;
            else if (temp == "pill"||temp=="pills")
                itemCategory = ItemCategory::Medical;
            else if (temp == "book"||temp=="books")
                itemCategory = ItemCategory::Book;
        }
        double price = stod(temp);
        basket.push_back(Item(itemCategory, price, imported));
    }
    printReceipt();
    return 0;
}