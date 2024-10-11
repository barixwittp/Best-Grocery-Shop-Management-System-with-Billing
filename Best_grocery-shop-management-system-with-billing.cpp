#include <stdio.h>
#include <string.h>

struct item
{
    char name[20];
    float price;
    int quantity;
};

struct item Groceries[] = {{"Apples", 25}, {"Bananas", 5}, {"Bread", 25}, {"Butter", 30}, {"Carrots", 20}, {"Cheese", 50}, {"Milk", 25}, {"Oranges", 20}, {"Potatoes", 20}, {"Rice", 30}, {"Salt", 20}, {"Sugar", 30}, {"Tomatoes", 15}};
struct item electronics[] = {{"Laptop", 40000}, {"Desktop computer", 35000}, {"Tablet", 20000}, {"Smart phone", 18000}, {"Headphones", 5000}, {"Wireless speaker", 6000}, {"Television", 35000}, {"Gaming console", 50000}, {"Smart watch", 1500}};
struct item home_essentials[] = {{"Towels", 75}, {"Laundry detergent", 80}, {"Trash bags", 10}, {"Light bulbs", 50}, {"Batteries", 20}, {"First aid kit", 30}, {"Candles", 15}, {"Matches", 5}};
struct item snacks[] = {{"Potato chips", 25}, {"Popcorn", 30}, {"Nuts", 30}, {"Crackers", 25}, {"Chocolate bars", 30}, {"Cookies", 15}, {"Candy", 10}};
struct item store_data[100];

int j = 0; // Global variable

void printBill()
{
    printf("======================================================================================\n");
    printf("                                     MAXUS STORES                                     \n");
    printf("                                Contact: 123-456-7890                                 \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("S.No.    Item Name           Price     Quantity      Amount       GST%%     GST Amount\n");
    printf("--------------------------------------------------------------------------------------\n");

    float total = 0.0;
    for (int i = 0; i < j; i++)
    {
        float itemPrice = store_data[i].price * store_data[i].quantity;
        float gstPercent = 0.0;
        if (strcmp(store_data[i].name, "Apples") == 0 || strcmp(store_data[i].name, "Bananas") == 0 || strcmp(store_data[i].name, "Bread") == 0 || strcmp(store_data[i].name, "Butter") == 0 || strcmp(store_data[i].name, "Carrots") == 0 || strcmp(store_data[i].name, "Cheese") == 0 || strcmp(store_data[i].name, "Milk") == 0 || strcmp(store_data[i].name, "Oranges") == 0 || strcmp(store_data[i].name, "Potatoes") == 0 || strcmp(store_data[i].name, "Rice") == 0 || strcmp(store_data[i].name, "Salt") == 0 || strcmp(store_data[i].name, "Sugar") == 0 || strcmp(store_data[i].name, "Tomatoes") == 0)
        {
            gstPercent = 5.0;
        }
        else if (strcmp(store_data[i].name, "Laptop") == 0 || strcmp(store_data[i].name, "Desktop computer") == 0 || strcmp(store_data[i].name, "Tablet") == 0 || strcmp(store_data[i].name, "Smart phone") == 0 || strcmp(store_data[i].name, "Headphones") == 0 || strcmp(store_data[i].name, "Wireless speaker") == 0 || strcmp(store_data[i].name, "Television") == 0 || strcmp(store_data[i].name, "Gaming console") == 0 || strcmp(store_data[i].name, "Smart watch") == 0)
        {
            gstPercent = 18.0;
        }
        else if (strcmp(store_data[i].name, "Towels") == 0 || strcmp(store_data[i].name, "Laundry detergent") == 0 || strcmp(store_data[i].name, "Trash bags") == 0 || strcmp(store_data[i].name, "Light bulbs") == 0 || strcmp(store_data[i].name, "Batteries") == 0 || strcmp(store_data[i].name, "First aid kit") == 0 || strcmp(store_data[i].name, "Candles") == 0 || strcmp(store_data[i].name, "Matches") == 0)
        {
            gstPercent = 12.0;
        }
        else if (strcmp(store_data[i].name, "Potato chips") == 0 || strcmp(store_data[i].name, "Popcorn") == 0 || strcmp(store_data[i].name, "Nuts") == 0 || strcmp(store_data[i].name, "Crackers") == 0 || strcmp(store_data[i].name, "Chocolate bars") == 0 || strcmp(store_data[i].name, "Cookies") == 0 || strcmp(store_data[i].name, "Candy") == 0)
        {
            gstPercent = 10.0;
        }
        
        float gstAmount = (itemPrice * gstPercent) / 100.0;
        total += itemPrice + gstAmount;

        printf("%-8d %-20s %-9.2f %-12d %-12.2f %-8.2f %-9.2f \n", i + 1, store_data[i].name, store_data[i].price, store_data[i].quantity,itemPrice, gstPercent, gstAmount);
    }

    printf("--------------------------------------------------------------------------------------\n");
    printf("TOTAL BILL:                                                                %.2f       \n", total);
    printf("--------------------------------------------------------------------------------------\n");
    printf("======================================================================================\n");
    printf("                                THANK YOU FOR SHOPPING!                               \n");
    printf("                                    Do Visit again!                                   \n");
    printf("======================================================================================\n");

}

int main()
{
    int category, quantity = 0;
    int categoryChoice, run_again;

    printf(" * * * * * * * * * * * * * Welcome to Maxus Stores * * * * * * * * * * * * * *\n");
    printf("What would you like to buy today?\n");
    // printf("\n");

    while (1)
    {   
        printf("--------------------------------------------------------------------------------\n");
        printf("1) Groceries\n2) Electronics\n3) Home essentials\n4) Snacks\nEnter the number of the category you want to purchase: ");
        scanf("%d", &category);
        printf("\n");

        switch (category)
        {
        case 1:
            printf("Available Groceries:\n");
            for (int i = 0; i < 13; i++)
            {
                printf("%d. %s - \u20B9%.2f\n", i + 1, Groceries[i].name, Groceries[i].price);
            }
            printf("Enter the item number you want to purchase: ");
            scanf("%d", &categoryChoice);
            if (categoryChoice>13 || categoryChoice<1)
            {   
                printf("***********************\n");
                printf("\n");
                printf("Invalid Input!!\n");
                continue;
            }
            
            printf("Enter the quantity you want to purchase: ");
            scanf("%d", &quantity);

            strcpy(store_data[j].name, Groceries[categoryChoice - 1].name);
            store_data[j].price = Groceries[categoryChoice - 1].price;
            store_data[j].quantity = quantity;
            break;
        case 2:
            printf("Available Electronics:\n");
            for (int i = 0; i < 9; i++)
            {
                printf("%d. %s - \u20B9%.2f\n", i + 1, electronics[i].name, electronics[i].price);
            }
            printf("Enter the item number you want to purchase: ");
            scanf("%d", &categoryChoice);

            if (categoryChoice>9 || categoryChoice<1)
            {   
                printf("***********************\n");
                printf("\n");
                printf("Invalid Input!!\n");
                continue;
            }
            printf("Enter the quantity you want to purchase: ");
            scanf("%d", &quantity);

            strcpy(store_data[j].name, electronics[categoryChoice - 1].name);
            store_data[j].price = electronics[categoryChoice - 1].price;
            store_data[j].quantity = quantity;
            break;
        case 3:
            printf("Available Home Essentials:\n");
            for (int i = 0; i < 8; i++)
            {
                printf("%d. %s - \u20B9%.2f\n", i + 1, home_essentials[i].name, home_essentials[i].price);
            }
            printf("Enter the item number you want to purchase: ");
            scanf("%d", &categoryChoice);

            if (categoryChoice>8 || categoryChoice<1)
            {   
                printf("***********************\n");
                printf("\n");
                printf("Invalid Input!!\n");
                continue;
            }
            printf("Enter the quantity you want to purchase: ");
            scanf("%d", &quantity);

            strcpy(store_data[j].name, home_essentials[categoryChoice - 1].name);
            store_data[j].price = home_essentials[categoryChoice - 1].price;
            store_data[j].quantity = quantity;
            break;
        case 4:
            printf("Available Snacks:\n");
            for (int i = 0; i < 7; i++)
            {
                printf("%d. %s - \u20B9%.2f\n", i + 1, snacks[i].name, snacks[i].price);
            }
            printf("Enter the item number you want to purchase: ");
            scanf("%d", &categoryChoice);

            if (categoryChoice>7 || categoryChoice<1)
            {   
                printf("***********************\n");
                printf("\n");
                printf("Invalid Input!!\n");
                continue;
            }
            printf("Enter the quantity you want to purchase: ");
            scanf("%d", &quantity);

            strcpy(store_data[j].name, snacks[categoryChoice - 1].name);
            store_data[j].price = snacks[categoryChoice - 1].price;
            store_data[j].quantity = quantity;
            break;
        default:
            printf("***********************\n");
            printf("\n");
            printf("Invalid choice!!\n");
            printf("Try again\n");
            continue;
        }

        j++;

        printf("Want to add anything extra?\nType 1 to go to the list or type any other number to continue to the payment: ");
        scanf("%d", &run_again);
        if (run_again != 1)
        {
            break;
        }
    }

    printf("\n");
    printBill();
    return 0;
}
