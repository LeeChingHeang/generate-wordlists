#include <stdio.h>
#include <stdlib.h>
#define DATA_FORMAT_IN "%[^,]%[^\n]"	

typedef struct{
    char name[10];
    char number[][4];
}PHONEBOOK;
PHONEBOOK phoneBook;
void loading(){
    // wordlist generator from prefixnumber.txt 
    FILE *fp;
    fp = fopen("prefixnumber.txt", "r");
    if (fp == NULL){
        printf("Error opening prefixnumber.txt file\n");
        printf("Please check if prefixnumber.txt in the same folder as .exe file\n");
        exit(1);
    }
    while(fscanf(fp,DATA_FORMAT_IN,phoneBook.name,phoneBook.number) != EOF){
        for(int j = 0; j < sizeof(phoneBook.number)/sizeof(phoneBook.number[0]); j++){
            printf("%s\n",phoneBook.number[j]);
        }
    }
    fclose(fp);
}

/*
void generate(){
    // generate number and write to file
    FILE *fp2 = fopen("genNumber.txt", "w");
    if (fp2 == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    for(int j = 0 ; j < i ; j++){
        printf("%03d\n",prefix[j]);
        for(int k = 0 ; k < 1000000 ; k++){
            fprintf(fp2, "%03d%06d\n", prefix[j], k);
        }
        printf("Done \n");
    }
    fclose(fp2);


}
*/
void menu(){

}


int main(){
    loading();
    return 0;
}