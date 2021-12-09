#include <stdio.h>
#include <string.h>

int hash(char *str){
    int sum = 0;
    for (int i = 0; i < strlen(str); i++){
        sum = sum + str[i]*i;
    }    
    sum = (sum +46)%90 +10;
    return sum;
}

int main() {
    char *name[17]= {"Adarsh", "Ananya", "Animesh", "Aswin", "Bhupendra", "Bighnesh", "Chinmay", "Chitrak", "Deepjyoti", "Hemojyoti", "Monika", "Neehar", "Rithik", "Soumyojit",  "Suman", "Sankar", "Sindhu"};
    int hashed[17];
    for(int i=0; i<17; i++){
        hashed[i] = hash(name[i]);
        printf("%s : %d \n",name[i],hashed[i]);
    }
    return 0;
}
