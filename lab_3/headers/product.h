//
// Created by Dani on 2023. 03. 06..
//

#ifndef LAB_3_PRODUCT_H
#define LAB_3_PRODUCT_H
#include <constant.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Category{FRUIT, VEGETABLE,DIARY,OTHER};
typedef  struct Date{
    int year;
    int month;
    int day;
}Date;
typedef struct {
    char name[30];
    char barcode[10];
    char supplier[50];
    Date dateOfManufacture;
    enum Category category;
    double price;
}Product_t;
/**
Reads all details of a product, product must be passed by reference
@param pProduct - pointer to a product
*/
void readProductDetails(Product_t *pProduct);
/**
Prints all details of a product
@param product
*/
void printProduct(Product_t product);
/**
Allocates memory for an array of Product_t types, array must be passed by reference
@param dpProducts - double pointer to a Product_t type
@param numberOfProducts
*/
void allocateMemoryForProducts(Product_t **dpProducts, int numberOfProducts);
/**
Reads all products' data from an input
This function should call first the @allocateMemoryForProducts function
@param dpProducts - double pointer to a Product_t type
@param numberOfProducts
@param input CON or input file name
*/
void readAllProductsDetails(Product_t **dpProducts, int *numberOfProducts, const char *input);
/**
Prints all products to a given destination
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
@param destination CON or output file name
*/
void printAllProducts(Product_t *pProducts, int numberOfProducts, const char *destination);
/**
Returns the number of products with a specific category
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
@param category - one of the Category enum values
@return - number of products with a specific category
*/
int getNumberOfProductsByCategory(Product_t *pProducts, int numberOfProducts, enum Category category);
/**
Prints all products from a specific supplier
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
@param supplier
*/

void printProductsFromSpecificSupplier(Product_t *pProducts, int numberOfProducts, const char *supplier);
/**
Finds a product with a specific barcode
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
@return A Product_t with the provided barcode, otherwise NULL
*/
void* findProductByBarcode(Product_t *pProducts, int numberOfProducts, const char *barcode);
/**
Sorts the array of products by name in ABC order
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
*/
void sortProductsByName(Product_t *pProducts, int numberOfProducts);
/**
Sorts the array of products by their date of manufacture (ASC) and price (ASC)
@param pProducts - pointer to a product, start of the array
@param numberOfProducts
*/
void sortProductsByManufactureDateAndPrice(Product_t *pProducts, int numberOfProducts);
int compareABC(const void *a, const void *b);
int compareByManufactureDateAndPrice(const void *a, const void *b);
int compareByManufactureDate(const void *a, const void *b);
int compareByPrice(const void *a, const void *b);
#endif //LAB_3_PRODUCT_H
