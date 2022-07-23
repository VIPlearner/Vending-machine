#include "VendingMachine.h"

char StartMessage[10];
int number;
int main(){

    // This code is meant to loop until the user inputs "Hi"
    do
    {
        printf("Say Hi ");
        scanf("%s", StartMessage);
    } while (strcmp(StartMessage, "Hi") != 0);

    // Display all the Products available with numbers so the user can choose the product they want to purchase
    printf("Pick from our Available Products\n");
    int i = 0;
    while(products[i].name != NULL){
        printf("%d.\t%s\n ", i+1, products[i].name);
        i++;
    }

    //The user inputs the number of the product they want to buy and the code displays the price of the product
    scanf("%d", &number);
    printf("You've picked %s\t\t\t#%.2f\n", products[number-1].name, products[number-1].price); 

    //The code asks for an amount from the user and checks if the amount is lower or higher than the price of the product
    //If it's lower it returns an error until the user inputs a value that is above or equal to the price of the product
    float amountPaid;
    printf("Pay for the product here: ");
    scanf("%f", &amountPaid);
    while (amountPaid < products[number-1].price)
    {
        printf("Amount is too small for the Product you want to buy\n");
        printf("Pay for the product here: ");
        scanf("%f", &amountPaid);    
    }
    printf("Purchase Successful\t\t Change:\t#%.2f", amountPaid - products[number-1].price);
}