#include <stdio.h>
#include <string.h>  
int length;
char info[20];
char temp;
char* reverse(char x[], int i){ //takes the string and index as arguments
    temp = x[i];  
    x[i] = x[length - i - 1];  
    x[length - i - 1] = temp;       //swaps 
    if(i<length/2-1) //stops recursion once terminating character is encountered
        summate(x,++i); //calls function with the next index
    return x;
}
int main()
{
    printf("Enter your name: ");
    scanf("%[^\n]%*c", info); //takes in entire line including spaces (%s doesn't work, /n works as a delimiter(keep reading until \n is encountered), %*c makes sure the same line isnt read again by discarding after reading)
    length = strlen(info);
    printf("Reverse: %s\n\n",reverse(info,0)); //prints reverse after calculating recursively
    return 0;
}