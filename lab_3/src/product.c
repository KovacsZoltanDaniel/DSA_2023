//
// Created by Dani on 2023. 03. 06..
//

#include "product.h"

void readProductDetails(Product_t *pProduct) {
    scanf("%s", pProduct->name);
    scanf("%s\n", pProduct->barcode);
    scanf("%[^\n]", pProduct->supplier);
    scanf("%i%i%i", &pProduct->dateOfManufacture.year, &pProduct->dateOfManufacture.month,
          &pProduct->dateOfManufacture.day);
    scanf("%i", &pProduct->category);
    scanf("%lf", &pProduct->price);
}

char *getCategory(enum Category category) {
    switch (category) {
        case 0 : {
            return "FRUIT";
        }
        case 1 : {
            return "VEGETABLE";
        }
        case 2 : {
            return "DIARY";
        }
        case 3 : {
            return "OTHER";
        }
        default: {
            "ERROR";
        }
    }
}

void printProduct(Product_t product) {
    printf("%s:\n", product.name);
    printf("\tBarcode: %s\n", product.barcode);
    printf("\tSupplier: %s\n", product.supplier);
    printf("\tDate of manufacture: %i/%i/%i\n", product.dateOfManufacture.year, product.dateOfManufacture.month,
           product.dateOfManufacture.day);
    printf("\tCategory: %s\n", getCategory(product.category));
    printf("\tPrice/piece: %.2lf\n", product.price);
}

void allocateMemoryForProducts(Product_t **dpProducts, int numberOfProducts) {
    *dpProducts = (Product_t *) malloc(numberOfProducts * sizeof(Product_t));
    if (!(*dpProducts)) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void readAllProductsDetails(Product_t **dpProducts, int *numberOfProducts, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", numberOfProducts);
    allocateMemoryForProducts(dpProducts, *numberOfProducts);
    for (int i = 0; i < *numberOfProducts; ++i) {
        readProductDetails((*dpProducts) + i);
    }
    freopen("CON", "r", stdin);
}

void printAllProducts(Product_t *pProducts, int numberOfProducts, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i = 0; i < numberOfProducts; ++i) {
        printProduct(pProducts[i]);
    }
    freopen("CON", "w", stdout);
}

int getNumberOfProductsByCategory(Product_t *pProducts, int numberOfProducts, enum Category category) {
    int db = 0;
    for (int i = 0; i < numberOfProducts; ++i) {
        if (pProducts[i].category == category) {
            db++;
        }
    }
    return db;
}

void printProductsFromSpecificSupplier(Product_t *pProducts, int numberOfProducts, const char *supplier) {
    printf("\nugyanattol a forgalmazotol szarmaznak:\n");
    for (int i = 0; i < numberOfProducts; ++i) {
        if (strcmp(pProducts[i].supplier, supplier) == 0) {
            printProduct(pProducts[i]);
        }
    }
}

void *findProductByBarcode(Product_t *pProducts, int numberOfProducts, const char *barcode) {
    for (int i = 0; i < numberOfProducts; ++i) {
        if (strcmp(pProducts[i].barcode, barcode) == 0) {
            return pProducts + i;
        }
    }
    return NULL;
}

void sortProductsByName(Product_t *pProducts, int numberOfProducts) {
    qsort(pProducts, numberOfProducts, sizeof(Product_t), compareABC);
}

int compareABC(const void *a, const void *b) {
    Product_t *p1 = (Product_t *) a;
    Product_t *p2 = (Product_t *) b;
    return strcmp(p1->name,p2->name);
}





int compareByManufactureDate(const void *a, const void *b) {
    Product_t *p1 = (Product_t *) a;
    Product_t *p2 = (Product_t *) b;
    if(p1->dateOfManufacture.year == p2->dateOfManufacture.year){
        if(p1->dateOfManufacture.month == p2->dateOfManufacture.month){
            return p1->dateOfManufacture.day - p2->dateOfManufacture.day;
        }
    }
    return p1->dateOfManufacture.year - p2->dateOfManufacture.year;
}

int compareByPrice(const void *a, const void *b) {
    Product_t *p1 = (Product_t *) a;
    Product_t *p2 = (Product_t *) b;
    if(p1->price > p2->price){
        return -1;
    }
    else if(p1->price < p2->price){
        return 1;
    }
    return 0;
}
int compareByManufactureDateAndPrice(const void *a, const void *b) {
int result = compareByManufactureDate(a,b);
    if(result == 0){
        compareByPrice(a,b);
    }
    return result;
}
void sortProductsByManufactureDateAndPrice(Product_t *pProducts, int numberOfProducts) {
    qsort(pProducts,numberOfProducts, sizeof(Product_t), compareByManufactureDateAndPrice);
}