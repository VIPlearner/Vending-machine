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
struct Products products[] = {{250, "Coca-Cola"}, 
                                                  {200, "Fanta"}, 
                                                  {100, "Pure-Bliss Chocolate Wafer"},
                                                  {50, "Noreos Biscuit"},
                                                  {100, "Schneider Biro"}
                                                  };

void print_available_products(int *number_of_available_products);
void input_product_number(int number_of_available_products, int *input_product_number);
void input_amount(float *amount_paid);
void checkout();

