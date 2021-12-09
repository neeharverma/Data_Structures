#include <stdio.h>
#include <math.h>
float mod;
struct ComplexNum {//make structure
    float real;
    float imaginary;
};
float findMod(struct ComplexNum x);
int main() {
    struct ComplexNum c;
    //take values for complex number 'c'
    printf("Enter Complex Number:\nReal Part: ");
    scanf("%f", &(c.real));
    printf("Imaginary Part: ");
    scanf("%f", &(c.imaginary));
    printf("Modulus is: %f",findMod(c));//pass c into function and print returned value
    return 0;
}
float findMod(struct ComplexNum x){
    mod = sqrt(x.real*x.real + x.imaginary*x.imaginary);//calculate mod
    return mod;
}
