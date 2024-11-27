#include <stdio.h>
#include <math.h>

unsigned int size(char num[]){
    unsigned int i=0;
    while(num[i]!='\0'){
        i++;
    }
    return i;
}

long int str2int(char num[]){
    int i=0;
    long int intnum=0;
    while(num[i]!='\0'){
        intnum = (intnum*10)+(num[i]-'0');
        i++;
    }
    return intnum;
}

int main(){
    char uin[32]; // Declaring a String

    //Taking the user input as string
    printf("Enter a number:\n");
    scanf("%s", uin);

    //Calling the str2int function to convert the string user input to an integer
    long int num = str2int(uin);

    int i=size(uin); //size or length or the number of digits
    long int sum=0; //a variable to store the sum of the power of each digit

    // for loop to loop until the end of string and calculate the sum of power of each digits
    for(int j=0; uin[j]!='\0';j++){
        sum += pow((uin[j]-'0'),i); //(uin[j]-'0') this converts char to int by using the ASCII table
    }

    if(num==sum){
        printf("The number is a Amstrong Number\n");
    }
    else{
        printf("The number is not a Amstrong Number\n");
    }
    return 0;
}