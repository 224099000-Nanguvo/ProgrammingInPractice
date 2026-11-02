#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "";
    char email[100] = "";
    char phone[20] = "";
    char town[50] = "";
    int supplierAdded = 0;

    char original[100] = "ABC Office Supplies";
    char backup[100];

    char company[50] = "ABC Office Supplies";
    char sentence[150] = "";

    int choice;

    do {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                printf("\nEnter supplier name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0;

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = 0;

                supplierAdded = 1;
                printf("Supplier added successfully!\n");
                break;

            case 2:
                if (!supplierAdded) {
                    printf("\nNo supplier found. Please add a supplier first (Option 1).\n");
                    break;
                }

                printf("\n--- SUPPLIER DETAILS ---\n");
                printf("Name : %s\n", name);
                printf("Email: %s\n", email);
                printf("Phone: %s\n", phone);
                printf("Town : %s\n", town);

                strcpy(backup, name);
                printf("\nCopied Name (Backup): %s\n", backup);

                strcpy(sentence, name);
                strcat(sentence, " operates in ");
                strcat(sentence, town);
                strcat(sentence, ".");
                printf("Description: %s\n", sentence);
                break;

            case 3: {
                char searchName[100];
                char supplier1[] = "ABC Office Supplies";
                char supplier2[] = "Namibia Stationery";

                printf("\nPre-registered suppliers: %s, %s\n", supplier1, supplier2);
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = 0;

                if (strcmp(searchName, supplier1) == 0 || strcmp(searchName, supplier2) == 0) {
                    printf("Supplier found.\n");
                } else {
                    printf("Supplier not found.\n");
                }
                break;
            }

            case 4:
                if (!supplierAdded && strlen(name) == 0) {
                    printf("\nNo supplier name available. Please add a supplier first.\n");
                } else {
                    printf("\nSupplier name length: %zu\n", strlen(name));
                    printf("Email length: %zu\n", strlen(email));
                    printf("Town length: %zu\n", strlen(town));
                }
                break;

            case 5:
                printf("\nExiting program. \nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}