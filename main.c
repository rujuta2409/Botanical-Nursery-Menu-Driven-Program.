#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct plant {
    char plant_name[20];
    char species_name[20];
    int quantity;
    float price;
} p[100], t;

int n = 0;

int main() {
    int i, j, c, flag = 0;
    char search_name[20];

    while(1) {
        printf("\n\n MENU");
        printf("\n1. Add Plant Records");
        printf("\n2. Display Plant Records");
        printf("\n3. Sort by Quantity");
        printf("\n4. Search by Plant Name");
        printf("\n5. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &c);

        switch(c) {

            // Add Records
            case 1:
                printf("\nEnter number of plants to add: ");
                scanf("%d", &n);

                for(i=0; i<n; i++) {
                    printf("\nEnter Plant Name: ");
                    scanf("%s", p[i].plant_name);

                    printf("Enter Species Name: ");
                    scanf("%s", p[i].species_name);

                    printf("Enter Quantity Available: ");
                    scanf("%d", &p[i].quantity);

                    printf("Enter Price: ");
                    scanf("%f", &p[i].price);
                }
                break;

            // Display Records
            case 2:
                for(i=0; i<n; i++) {
                    printf("\n------------------------------------------");
                    printf("\nPlant Name: %s", p[i].plant_name);
                    printf("\nSpecies Name: %s", p[i].species_name);
                    printf("\nQuantity: %d", p[i].quantity);
                    printf("\nPrice: %.2f", p[i].price);
                }
                break;

            // Sort Records by Quantity
            case 3:
                for(i=0; i<n-1; i++) {
                    for(j=0; j<n-i-1; j++) {
                        if(p[j].quantity > p[j+1].quantity) {
                            t = p[j];
                            p[j] = p[j+1];
                            p[j+1] = t;
                        }
                    }
                }
                printf("\nRecords sorted by quantity! Use display option to view.");
                break;

            // Search by Plant Name
            case 4:
                flag = 0;
                printf("\nEnter Plant Name to Search: ");
                scanf("%s", search_name);

                for(i=0; i<n; i++) {
                    if(strcmp(p[i].plant_name, search_name) == 0) {
                        printf("\nRecord Found:");
                        printf("\nPlant Name: %s", p[i].plant_name);
                        printf("\nSpecies Name: %s", p[i].species_name);
                        printf("\nQuantity: %d", p[i].quantity);
                        printf("\nPrice: %.2f", p[i].price);
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    printf("\nRecord NOT FOUND!");
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}
