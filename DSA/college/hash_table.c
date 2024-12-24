#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void insert(int a[], int value){
    int ind = value%MAX;
    if(a[ind]!=-1){
        printf("\nCollision Detected at ind %d for %d\n", ind, value);
        int flag = 0;
        for(int i = ind+1; i!=ind; i=(i+1)%MAX){
            if(a[i]==-1){
                a[i]=value;
                flag = 1;
                printf("Collision resolved at %d for %d\n\n", i, value);
                break;
            }
        }
        if(flag != 1){
            printf("Hash Table full\n");
        }
    }
    else{
        a[ind]=value;
    }
}

void display(int a[], int filtered){
    if(filtered==1){
        for(int i=0; i<MAX; i++){
            if(a[i]!=-1){
                printf("%d\t%d\n", i, a[i]);
            }
        }
    }
    else{
        for(int i=0; i<MAX; i++){
            printf("%d\t%d\n", i, a[i]);
        }
    }
}


int main(){
    int hash_table[MAX];
    for(int i=0; i<MAX; i++){
        hash_table[i]=-1;
    }
    while(1){
        printf("1.Insert\n2.Display All\n3.Display Filtered\n4.Exit\nEnter your choise:");
        int uin;
        scanf("%d", &uin);
        switch (uin){
            case 1:
            printf("Enter the number to hash:\n");
            scanf("%d", &uin);
            insert(hash_table,uin);
            break;
            case 2:
            display(hash_table, 0);
            break;
            case 3:
            display(hash_table, 1);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Enter a valid choise\n");
            break;
        }
    }
    return 0;
}