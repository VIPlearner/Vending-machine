#include "VendingMachine.h"
char StartMessage[10];
int number;
int main(){
    do
    {
        printf("Say Hi ");
        scanf("%s", StartMessage);
    } while (strcmp(StartMessage, "Hi") != 0);

    printf("Pick from our Available Products\n");
    int i = 0;
    while(ListOfAvailableProducts[i] != NULL){
        printf("%d.\t%s\n ", i+1, ListOfAvailableProducts[i]);
        i++;
    }
    scanf("%d", &number);
    printf("You've picked %s\t\t\t#%.2f\n", ListOfAvailableProducts[number-1], ListOfPrices[number-1]); 
    float AmountPaid;
    printf("Pay for the product here: ");
    scanf("%f", &AmountPaid);
    while (AmountPaid < ListOfPrices[number-1])
    {
        printf("Amount is too small for the Product you want to buy\n");
        printf("Pay for the product here: ");
        scanf("%f", &AmountPaid);    
    }
    printf("Purchase Successful\t\t Change:\t#%.2f", AmountPaid - ListOfPrices[number-1]);
}