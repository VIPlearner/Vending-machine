#include "VendingMachine.h"

char startMessage[10]; //This
int productNumber; //this is the variable that holds the product number that the user has selected
float amountPaid; //this holds the amount that the customer inputs into the machine

int main(){

    // Loop until the user inputs "Hi"
    do
    {
        printf("Say Hi ");
        scanf("%s", startMessage);
    } while (strcmp(startMessage, "Hi") != 0);

    // Display all the Products available with numbers so the user can choose the product they want to purchase
    printf("Pick from our Available Products\n");
    int i = 0;
    while(products[i].name != NULL){
        printf("%d.\t%s\n ", i+1, products[i].name);
        i++;
    }

    //The user inputs the productNumber they want to buy and the code displays the price of the product
    scanf("%d", &productNumber);
    printf("You've picked %s\t\t\t#%.2f\n", products[productNumber-1].name, products[productNumber-1].price); 

    //The code asks for an amount from the user and checks if the amount is lower or higher than the price of the product
    //If it's lower it returns an error until the user inputs a value that is above or equal to the price of the product
    printf("Pay for the product here: ");
    scanf("%f", &amountPaid);
    while (amountPaid < products[productNumber-1].price)
    {
        printf("Amount is too small for the Product you want to buy\n");
        printf("Pay for the product here: ");
        scanf("%f", &amountPaid);    
    }
    printf("Purchase Successful\t\t Change:\t#%.2f", amountPaid - products[productNumber-1].price);
}