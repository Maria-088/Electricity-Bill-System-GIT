#include <stdio.h>

#define MAX 100
#define RATE 6.0

struct Consumer
{
    char name[50];
    int previous, current;
    int units;
    float bill;
};

int main()
{
    struct Consumer c[MAX];
    int n = 0, choice, i;

    do
    {
        printf("\n--- ELECTRICITY BILL SYSTEM ---\n");
        printf("1. Add Consumer\n");
        printf("2. Calculate Bills\n");
        printf("3. View All Consumers\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(n >= MAX)
                {
                    printf("Consumer limit reached!\n");
                    break;
                }

                printf("Enter consumer name: ");
                scanf(" %49[^\n]", c[n].name);

                printf("Enter previous meter reading: ");
                scanf("%d", &c[n].previous);

                printf("Enter current meter reading: ");
                scanf("%d", &c[n].current);

                if(c[n].previous < 0 ||
                   c[n].current < c[n].previous)
                {
                    printf("Invalid meter reading!\n");
                    break;
                }

                c[n].units = c[n].current - c[n].previous;

                c[n].bill = c[n].units * RATE;

                n++;

                printf("Consumer added successfully!\n");
                break;

            case 2:
                if(n == 0)
                {
                    printf("No consumers available!\n");
                    break;
                }

                printf("\n--- ELECTRICITY BILLS ---\n");

                for(i = 0; i < n; i++)
                {
                    c[i].units = c[i].current - c[i].previous;
                    c[i].bill = c[i].units * RATE;

                    printf("\nConsumer: %s\n", c[i].name);
                    printf("Units Used: %d\n", c[i].units);
                    printf("Bill Amount: Rs. %.2f\n", c[i].bill);
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("No consumers available!\n");
                    break;
                }

                printf("\n--- CONSUMER DETAILS ---\n");
                printf("Name\tUnits\tBill\n");

                for(i = 0; i < n; i++)
                {
                    printf("%s\t%d\tRs. %.2f\n",
                    c[i].name, c[i].units, c[i].bill);
                }
                break;

            case 4:
                printf("Exiting the system...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
