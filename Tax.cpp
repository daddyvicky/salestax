#include <iostream>
#include <math.h>
#include "Item.hpp"
#include "Tax.hpp"
using namespace std;

double Tax::getTaxOnItem(Item item)
{
    double tax = 0.0;
    if (item.isImported())
        tax += round(item.getPrice() * IMPORT_RATE);
    for (auto c : canTaxOnCategory)
    {
        if (item.getItemCategory() == c)
            tax += round(item.getPrice() * BASIC_RATE);
    }

    return tax;
}
double Tax::round(double value)
{
    return ceil(value * 20) / 20;
}