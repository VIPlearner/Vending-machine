#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUMBEROFPRODUCTS 20

struct products;

struct Products{
  float price;
  char *name;
};

//list of all the products in the vending machine with their prices saved in a struct Products
struct Products products[MAXNUMBEROFPRODUCTS] = {{250, "Coca-Cola"}, 
                                                  {200, "Fanta"}, 
                                                  {100, "Pure-Bliss Chocolate Wafer"},
                                                  {50, "Noreos Biscuit"},
                                                  {100, "Schneider Biro"}
                                                  };

int printAvailableProducts();
void checkAmount();