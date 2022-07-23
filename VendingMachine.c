#include "VendingMachine1.c"
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
    while(products[i].name != NULL){
        printf("%d.\t%s\n ", i+1, products[i].name);
        i++;
    }
    scanf("%d", &number);
    printf("You've picked %s\t\t\t#%.2f\n", products[number-1].name, products[number-1].price); 
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