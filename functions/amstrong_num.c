#include <stdio.h>
#include <math.h>

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
    char uin[32];
    printf("Enter a number:\n");
    scanf("%s", uin);
    long int num = str2int(uin);
    int ams=0;
    int i=0;
    long int sum=0;
    while(sum<num){
        sum=0;
        i++;
        for(int j=0; uin[j]!='\0';j++){
            sum += pow((uin[j]-'0'),i);
        }
        if(num==sum){
            ams=1;
            break;
        }
    }
    if(ams==1){
        printf("The number is a Amstrong Number at power %d\n", i);
    }
    else{
        printf("The number is not a Amstrong Number and the sum of power exceeds the original value at power %d\n",i);
    }
    return 0;
}