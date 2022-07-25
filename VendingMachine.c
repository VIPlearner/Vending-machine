#include "VendingMachine.h"

char start_message[10]; //This
int product_number; //this is the variable that holds the product number that the user has selected
int number_of_available_products;

int main(){

    while(1)
    {
    printf("Press any key to start");
    scanf("%c", start_message);

    // Display all the Products available with numbers so the user can choose the product they want to purchase
    print_available_products(&number_of_available_products);

    //The user inputs the product_number they want to buy and the code displays the price of the product
    input_product_number(number_of_available_products, &product_number);

    printf("You've picked %s\t\t\t#%.2f\n", products[product_number-1].name, products[product_number-1].price); 

    checkout();

    }
    return 0;

}

void input_product_number(int number_of_available_products, int *input_product_number){
    int product_number;
    do
    {
        fflush(stdin);
        printf("Input Product Number\n");
        printf("Make sure your input tallies with the numbers on your screen\n");
    } while (scanf("%d", &product_number)!= 1 || product_number<0 || product_number>number_of_available_products);
    *input_product_number = product_number;
}

void print_available_products(int *number_of_available_products)
{
    //This functions prints out all the available products
    int i = 0;
    printf("\tProduct\t\t\t\tPrice\n");
    while(products[i].name != NULL){
        printf("%d.\t%s\t\t\t%f\n ", i+1, products[i].name, products[i].price);
        i++;
    }
    *number_of_available_products = i;
}

void input_amount(float* amount_paid)
{
    float input_amount_paid;
    do
    {
        fflush(stdin); //to clear stdin for the scanf
        printf("Note: Amount to be paid should be equal or above the price tag of the Product\n");
        printf("Enter Amount: ");
    } while (scanf("%f", &input_amount_paid)!= 1);
    *amount_paid = input_amount_paid;
}

void checkout()
{
    //This function compares the amount_paid with the price of the product
    float amount_paid;
    do
    {
        input_amount(&amount_paid);
    } while (amount_paid<products[product_number-1].price);
    printf("Purchase Successful\t\t Change:\t#%.2f", amount_paid - products[product_number-1].price);
}