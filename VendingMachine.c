#include "VendingMachine.h"

char startMessage[10]; //This
int productNumber; //this is the variable that holds the product number that the user has selected
int numberOfAvailableProducts;
float amountPaid;


int main(){

    while(1)
    {
    printf("Press any key to start");
    scanf("%c", startMessage);

    // Display all the Products available with numbers so the user can choose the product they want to purchase
    numberOfAvailableProducts = printAvailableProducts();

    //The user inputs the productNumber they want to buy and the code displays the price of the produ
    productNumber = inputProductNumber(numberOfAvailableProducts);

    amountPaid = inputAmount();

    printf("You've picked %s\t\t\t#%.2f\n", products[productNumber-1].name, products[productNumber-1].price); 
    checkout(amountPaid);
    return 0;
}
}

int inputProductNumber(int numberOfAvailableProducts){
    int productNumber;
    do
    {
        fflush(stdin);
        printf("Input Product Number\n");
        printf("Make sure your input tallies with the numbers on your screen\n");
    } while (scanf("%d", &productNumber)!= 1 || productNumber<0 || productNumber>numberOfAvailableProducts);
    return productNumber;
}

int printAvailableProducts()
{
    //This functions prints out all the available products
    int i = 0;
    printf("\tProduct\t\t\t\tPrice\n");
    while(products[i].name != NULL){

        printf("%d.\t%s\t\t\t%f\n ", i+1, products[i].name, products[i].price);
        i++;
    }
    return i;
}

float inputAmount()
{
    float amountPaid;
    do
    {
        fflush(stdin); //to clear stdin for the scanf
        printf("Note: Amount to be paid should be equal or above the price tag of the Product\n");
        printf("Enter Amount: ");
    } while (scanf("%f", &amountPaid)!= 1);
    return amountPaid;
}

void checkout(float amountPaid)
{
    //This function compares the amountPaid with the price of the product
    if (amountPaid<products[productNumber-1].price) inputAmount();
    else printf("Purchase Successful\t\t Change:\t#%.2f", amountPaid - products[productNumber-1].price);
}