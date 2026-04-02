#include <stdio.h>
#include <stdlib.h>

struct product {
    int product_no;
    char name[50];
    float cost;
};

void displayProducts(struct product *p, int n) {
    printf("\nProducts with cost between 100 and 1000:\n");
    for (int i = 0; i < n; i++) {
        if (p[i].cost >= 100 && p[i].cost <= 1000) {
            printf("Product No : %d\n", p[i].product_no);
            printf("Name       : %s\n", p[i].name);
            printf("Cost       : %.2f\n\n", p[i].cost);
        }
    }
}

int main() {
    int n;
    struct product *p;

    printf("Enter number of products: ");
    scanf("%d", &n);

    p = (struct product *)malloc(n * sizeof(struct product));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of product %d:\n", i + 1);
        printf("Product No: ");
        scanf("%d", &p[i].product_no);
        printf("Name      : ");
        scanf("%s", p[i].name);
        printf("Cost      : ");
        scanf("%f", &p[i].cost);
    }

    displayProducts(p, n);
    free(p);
    return 0;
}