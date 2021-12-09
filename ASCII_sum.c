#include <stdio.h>
int sum=0;
char info[20];
int summate(char x[], int i);
int main()
{
    printf("Enter your name: ");
    scanf("%[^\n]%*c", info); //takes in entire line including spaces (%s doesn't work, /n works as a delimiter(keep reading until \n is encountered), %*c makes sure the same line isnt read again by discarding after reading)
    printf("ASCII sum: %d\n\n",summate(info,0)); //prints sum after calculating recursively
    sum=0;//reset
    printf("Enter your roll number: ");
    scanf("%[^\n]%*c", info);
    printf("ASCII sum: %d\n",summate(info,0)); 
    return 0;
}
int summate(char x[], int i){ //takes the string and index as arguments
    if(x[i]!=32) //ignores whitespaces
        sum += x[i]; //calculates sum
    if(x[i]!=0) //stops recursion once terminating charchter is encountered
        summate(x,++i); //calls function with the next index
    return sum;
}
