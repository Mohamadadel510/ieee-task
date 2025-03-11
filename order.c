// a order program for a clothing brand
#include <stdio.h>
#include <string.h>

char winter_cloth[11][20] = {"Plain Hoodie", "Printed Hoodie", "Plain Sweatshirt", "Printed Sweatshirt", 
    "Plain Sweater", "Printed Sweater", "Plain Jacket", "Printed Jacket", "Leather Jacket",
    "Plain Coat", "Printed Coat"};
int winter_prices[11] = {1, 1, 2,2, 2, 4, 3, 4, 5, 6, 7};

char summer_cloth[10][20] = {"Plain T-shirt", "Printed T-shirt", "Plain Polo", "Printed Polo", 
    "Plain Shirt", "Printed Shirt", "Plain Shorts", "Printed Shorts", "Plain Pants", "Printed Pants"};
int summer_prices[10] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

char shoes[5][15] = {"Sneakers", "Boots", "Sandals", "Loafers", "Dress Shoes"};
int shoes_prices[5] = {3, 4, 2, 2, 5};

char colours[10][10] = {"Red", "Blue", "Green", "Yellow", "Black", "White", "Purple", "Orange", "Pink", "Brown"};
char sizes[5][5] = {"S", "M", "L", "XL", "XXL"};


int welcome_func();
int colour_func();
int size_func();
int shipping_func();
void winter_func(int *colour, int *size, int *quantity,  int *items, char (*item_type)[20] ,int *item_cost);
void summer_func(int *colour, int *size, int *quantity,  int *items ,  char (*item_type)[20],int *item_cost);
void shoes_func(int *colour, int *size, int *quantity,  int *items, char (*item_type)[20],int *item_cost);
void receipt_function(int items, int *colour, int *size, int *quantity ,int shipping_choice, char (*item_type)[20] , int *item_cost);

int main() {
    int quantity[100], size[100], colour[100], items = 0;
    int shipping_choice, choice , complete_shopping ;
    char item_type[100][20];
    int item_cost[100];
    
    choice = welcome_func();
    
    if (choice == 1) {
        winter_func(colour, size, quantity, &items , item_type ,item_cost);
    } else if (choice == 2) {
        summer_func(colour, size, quantity,  &items , item_type, item_cost);
    } else if (choice == 3) {
        shoes_func(colour, size, quantity,  &items , item_type , item_cost);
    }
    printf("Want to explore the other collections? (1.yes 2.no)\n");
    scanf("%d", &choice);
    if(choice == 1){
        choice = welcome_func();
        if (choice == 1) {
            winter_func(colour, size, quantity, &items , item_type ,item_cost);
        } else if (choice == 2) {
            summer_func(colour, size, quantity, &items , item_type, item_cost);
        } else if (choice == 3) {
            shoes_func(colour, size, quantity, &items , item_type, item_cost);        
    }
    }

    if(items < 2 ){
        printf("You have to buy atleast 2 items\n");
        printf("Would you like to buy another item? (1.yes 2.no)\n");
        scanf("%d", &complete_shopping);
        if(complete_shopping == 1){
            choice = welcome_func();
            if (choice == 1) {
                winter_func(colour, size, quantity, &items , item_type ,item_cost);
            } else if (choice == 2) {
                summer_func(colour, size, quantity, &items , item_type, item_cost);
            } else if (choice == 3) {
                shoes_func(colour, size, quantity, &items , item_type, item_cost);        
        }
        else {
            printf("THANK YOU FOR STOPPING BY ;)\n");
            return 0;
        }
    }}
    shipping_choice =shipping_func();
    receipt_function(items, colour, size, quantity, shipping_choice , item_type ,item_cost);
    return 0;
}

int welcome_func() {
    int choice;
    printf("<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>\n");
    printf("WELCOME TO OUR CLOTHING STORE\n");
    printf("<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>\n");
    printf("What are you looking for?\n");
    printf("1. Winter clothes\n2. Summer clothes\n3. Shoes\n");
    scanf("%d", &choice);
    return choice;
}
int colour_func() {
    int choice;
    printf("Available Colours:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, colours[i]);
    }
    printf("Choose a colour: ");
    scanf("%d", &choice);
    return choice - 1;
}

int size_func() {
    int choice;
    printf("Available Sizes:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, sizes[i]);
    }
    printf("Choose a size: ");
    scanf("%d", &choice);
    return choice - 1;
}
int shipping_func() {
    int choice;
    printf("Shipping Options:\n");
    printf("1. Standard Shipping 2. Overnight Shipping\n");
    printf("Choose a shipping option: ");
    scanf("%d", &choice);
    return choice - 1;
}

void winter_func(int *colour, int *size, int *quantity,  int *items, char (*item_type)[20],int *item_cost) {
    int choice;
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("WELCOME TO OUR WINTER COLLECTION\n");
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("Available Winter Clothes:\n");
    for (int i = 0; i < 11; i++) {
        printf("%d. %s - $%d\n", i + 1, winter_cloth[i], winter_prices[i]);
    }
    printf("Choose an item: ");
    scanf("%d", &choice);
    strcpy(item_type[*items], winter_cloth[choice - 1]);
    colour[*items] = colour_func();
    size[*items] = size_func();
    printf("Enter quantity: ");
    scanf("%d", &quantity[*items]);
    item_cost[*items] = winter_prices[choice-1];
    (*items)++;
    printf("Want to buy anther item? (1.yes 2.no)\n");
    scanf("%d", &choice);
    if(choice == 1){
        winter_func(colour, size, quantity, items, item_type , item_cost);
    }
    else{
        return;
    }
}

void summer_func(int *colour, int *size, int *quantity,  int *items ,  char (*item_type)[20],int *item_cost){
    int choice;
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("WELCOME TO OUR SUMMER COLLECTION\n");
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("Available Summer Clothes:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%d\n", i + 1, summer_cloth[i], summer_prices[i]);
    }
    printf("Choose an item: ");
    scanf("%d", &choice);
    strcpy(item_type[*items], summer_cloth[choice - 1]);

    colour[*items] = colour_func();
    size[*items] = size_func();
    printf("Enter quantity: ");
    scanf("%d", &quantity[*items]);
    item_cost[*items] = summer_prices[choice];
    (*items)++;
    printf("Want to buy anther item? (1.yes 2.no)\n");
    scanf("%d", &choice);
    if(choice == 1){
        winter_func(colour, size, quantity, items, item_type, item_cost);
    }
    else{
        return;
    }
}

void shoes_func(int *colour, int *size, int *quantity, int *items, char (*item_type)[20], int *item_cost) {
    int choice;
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("WELCOME TO OUR SHOES COLLECTION\n");
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("Available Shoes:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%d\n", i + 1, shoes[i], shoes_prices[i]);
    }
    printf("Choose an item: ");
    scanf("%d", &choice);
    strcpy(item_type[*items], shoes[choice - 1]);
    colour[*items] = colour_func();
    size[*items] = size_func();
    printf("Enter quantity: ");
    scanf("%d", &quantity[*items]);
    item_cost[*items] = shoes_prices[choice-1];
    (*items)++;
    printf("Want to buy anther item? (1.yes 2.no)\n");
    scanf("%d", &choice);
    if(choice == 1){
        shoes_func(colour, size, quantity, items, item_type, item_cost);
    }
    else{
        return;
    }
}

void receipt_function(int items, int *colour, int *size, int *quantity ,int shipping_choice, char (*item_type)[20] , int *item_cost) {
    int total_cost = 0;
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("\n--- Receipt ---\n");
    printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    for (int i = 0; i < items; i++) {
        int cost = quantity[i] * item_cost[i];
        total_cost += cost;
        printf("Item type:%s\n", item_type[i]);
        printf("Colour: %s\n", colours[colour[i]]);
        printf("Size: %s\n", sizes[size[i]]);
        printf("Quantity: %d\n", quantity[i]);
        printf("Item cost: %d\n", cost);
        printf("<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    }
    int shipping_cost =0;
    if( total_cost < 10 ){
        shipping_cost += 2;
    }
    else if( total_cost > 10)
    {
        shipping_cost += 3;
    }
    if(shipping_choice == 2)
    {
        shipping_cost += 5;
    }
    printf("Shipping Cost:$%d\n", shipping_cost);
    printf("Total Cost: $%d\n", total_cost + shipping_cost);
    printf("Thank you for shopping with us!\n");
}
