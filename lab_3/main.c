#include "student.h"
#include "product.h"
 int main() {
    //1 diakkal kapcsolatos
    Student_t student1 = {"George Smith", "AVKM07", "Toronto", {1999, 2, 20},1, 7.85f};
    Student_t student2;
    if(!freopen("date.in", "r", stdin)){
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    printStudent(student1);
    readStudentDetails(&student2);
    printStudent(student2);
    freopen("CON", "r", stdin);
    //2 diakkal kapcsolatos
    Student_t *students;
    int numberOfStudents;
     readAllStudentsDetails(&students,&numberOfStudents,"students.txt");
     printf("All students:\n");
     printAllStudents(students,numberOfStudents,"CON");
     printf("fiuk szama: %i\n", getNumberOfStudentsByGender(students,numberOfStudents,MALE));
     printf("azok a diakok akik Budapesten szulettek: \n");
     printStudentsFromSpecificCity(students,numberOfStudents,"Budapest");
     Student_t *result = findStudentByNeptunCode(students,numberOfStudents,"QSTRG9");
     if(!result){
         printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
         exit(NULL_POINER_EXCEPTION_ERROR_CODE);
     }
     else {
         printf("A QSTRG9 neptun koddal rendelkezo diak:\n");
         printStudent(*result);
     }
     sortStudentsByName(students,numberOfStudents);
     printAllStudents(students,numberOfStudents,"abc_order.txt");
     sortStudentsByAgeAndExam(students,numberOfStudents);
     printAllStudents(students,numberOfStudents,"birth_exam_order.txt");
     //hazi feladat
     printf("\n\n\t\tHazi feladat: \n");
     //1 product
     Product_t product1 ={"Hell", "59998840","Hell Energy Magyarorszag Kft.",{2001, 01, 1},3,3.50};
     printProduct(product1);
     if(!freopen("product.txt", "r", stdin)){
         printf(FILE_OPENING_ERROR_MESSAGE);
         exit(FILE_OPENING_ERROR_CODE);

     }
     Product_t product2;
     readProductDetails(&product2);
     printProduct(product2);
     freopen("CON","r", stdin);
     //2 or more product
     Product_t *products;
     int n;//number of products
     printf("Products:\n");
     readAllProductsDetails(&products,&n,"products.txt");
     printAllProducts(products,n,"CON");
     printf("%i FRUIT kategoriaju termek talalhato", getNumberOfProductsByCategory(products,n,FRUIT));
     printProductsFromSpecificSupplier(products,n,"Merkur");
     Product_t *result2 = findProductByBarcode(products,n,"0011" );
     if(!result2){
         printf(NULL_POINTER_EXCEPTION_ERROR_MESSAGE);
         exit(NULL_POINER_EXCEPTION_ERROR_CODE);
     }
     else{
         printf("a megadott vonalkoddal rendelkezo termek:\n ");
         printProduct(*result2);
     }
     sortProductsByName(products,n);
     printAllProducts(products,n,"abc_order_products.txt");
     sortProductsByManufactureDateAndPrice(products,n);
     printAllProducts(products,n,"manufacture_price_order.txt");
    return 0;

}
