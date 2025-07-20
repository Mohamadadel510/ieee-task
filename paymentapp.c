#include <stdio.h>
#include <string.h>

#define MAX_USERS 20

struct user {
    char username[20];
    char password[20];
    float balance;
};

// Users list
struct user users[MAX_USERS];
int users_count = 0;

// Function prototypes
void add_user();
int login(char *username, char* password);
void transfer(struct user* sender);
void user_menu(int userIndex);
int main() {
    int choice;
    // Menu loop
    do {
        printf("\n==== Payment App ;) ====\n");
        printf("1. Add New User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_user();
        } else if (choice == 2) {
            char username[20], password[20];
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);

            int userIndex = login(username, password);
            if (userIndex == -1) {
                printf("Invalid credentials.\n");
            } else {
                user_menu(userIndex);
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid option.\n");
        }
    } while (choice != 3);

    return 0;
}
// Add new user
void add_user() {
    if (users_count >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    char username[20], password[20];
    float balance;

    printf("Enter username: ");
    scanf("%s", username);

    // Check for duplicate username
    for (int i = 0; i < users_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter initial balance: ");
    scanf("%f", &balance);

    strcpy(users[users_count].username, username);
    strcpy(users[users_count].password, password);
    users[users_count].balance = balance;
    users_count++;

    printf("User added successfully!\n");
}

// Login function
int login(char* username, char* password) {
    for (int i = 0; i < users_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

// Transfer money
void transfer(struct user* sender) {
    char recipient[20];
    float amount;

    printf("Enter recipient username: ");
    scanf("%s", recipient);

    int receiverIndex = -1;
    for (int i = 0; i < users_count; i++) {
        if (strcmp(users[i].username, recipient) == 0 &&
            strcmp(users[i].username, sender->username) != 0) {
            receiverIndex = i;
            break;
        }
    }

    if (receiverIndex == -1) {
        printf("Recipient not found.\n");
        return;
    }

    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }

    if (sender->balance >= amount) {
        sender->balance -= amount;
        users[receiverIndex].balance += amount;
        printf("Transfer successful!\n");
    } else {
        printf("Insufficient balance.\n");
    }
}

// User menu
void user_menu(int userIndex) {
    int choice;
    do {
        printf("\nWelcome %s\n", users[userIndex].username);
        printf("1. View Balance\n");
        printf("2. Transfer Money\n");
        printf("3. Logout\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your balance: $%.2f\n", users[userIndex].balance);
                break;
            case 2:
                transfer(&users[userIndex]);
                break;
            case 3:
                printf("Logged out.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);
}
