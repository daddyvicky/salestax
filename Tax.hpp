#ifndef TAX_H
#define TAX_H
#include <vector>
#include "ItemCategory.hpp"
#include "Item.hpp"
using namespace std;
class Tax
{
private:
    const double BASIC_RATE = 0.1;                                        
    const double IMPORT_RATE = 0.05;                                       
    const vector<ItemCategory> canTaxOnCategory = {ItemCategory::General}; 
    double round(double value);                                            

public:
    double getTaxOnItem(Item item);
    double getBasicRate() { return BASIC_RATE; }
    double getImportRate() { return IMPORT_RATE; }
};
#endif