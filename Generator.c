#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_SIZE 6
// char prefix[50];
typedef struct{
    char name[10];
    char prefix[100];
}DATA;

DATA data[DATA_SIZE];
int i = 0; 

void loading(){
    // wordlist generator from prefixnumber.txt 
    FILE *phoneBook;
    phoneBook = fopen("prefixnumber.txt", "r");
    char temp[100];

    if (phoneBook == NULL){
        printf("Error opening prefixnumber.txt file\n");
        printf("Please check if prefixnumber.txt in the same folder as .exe file\n");
        exit(1);
    }
    while(fgets(temp,100,phoneBook)){
        char *name = strtok(temp, ":");
        char *prefix = strtok(NULL, "\n");
        if(name != NULL && prefix != NULL){
            strcpy(data[i].name, name);
            strcpy(data[i].prefix, prefix);
            i++;
        }
    }
    fclose(phoneBook);
}

void generate(int option){
    // generate number and write to file
    FILE *fp2 = fopen("genNumber.txt", "w");
    if (fp2 == NULL){
        printf("Error opening file\n");
        exit(1);
    }
// under construction
    char *prefix_token = strtok(data[option].prefix, ",");
    while(prefix_token != NULL){
        int prefix = atoi(prefix_token);
        prefix_token = strtok(NULL, ",");
    }
    fclose(fp2);
}
void option(){
    int choice;
    printf("1. smart\n");
    printf("2. cellcard\n");
    printf("3. metfone\n");
    printf("4. qb\n");
    printf("5. seatel\n");
    printf("6. cootel\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while(1){
        switch (choice)
        {
        case 1:
            generate(0);
            break;
        case 2:
            generate(1);
            break;
        case 3:
            generate(2);
            break;
        case 4:
            generate(3);
            break;
        case 5:
            generate(4);
            break;
        case 6:
            generate(5);
            break;
        case 0:
            exit(1);
            break;     
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void menu(){

}


int main(){
    loading();
    return 0;
}