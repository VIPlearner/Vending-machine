#include "VendingMachine.h"

char startMessage[10];
int productNumber; 
int numberOfAvailableProducts;


int main(){

    printf("Press any key to start");
    scanf("%c", startMessage);

    numberOfAvailableProducts = printAvailableProducts();

    do
    {
        fflush(stdin);
        printf("Input Product Number\n");
        printf("Make sure your input tallies with the numbers on your screen\n");
    } while (scanf("%d", &productNumber)!= 1 || productNumber<0 || productNumber>numberOfAvailableProducts);
    
    printf("You've picked %s\t\t\t#%.2f\n", products[productNumber-1].name, products[productNumber-1].price); 
    checkAmount();
}

int printAvailableProducts()
{
    int i = 0;
    while(products[i].name != NULL){
        printf("%d.\t%s\n ", i+1, products[i].name);
        i++;
    }
    return i;
}

void checkAmount()
{
    float amountPaid; 
    do
    {
        fflush(stdin);
        printf("Note: Amount to be paid should be above the price tag of the Product\n");
        printf("Pay for the product here: ");
    } while (scanf("%f", &amountPaid)!= 1 || amountPaid<products[productNumber-1].price);

    printf("Purchase Successful\t\t Change:\t#%.2f", amountPaid - products[productNumber-1].price);
}