#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prefix[20];

void loading(){
    // wordlist generator from prefixnumber.txt 
    FILE *phoneBook;
    int i = 0;
    phoneBook = fopen("prefixnumber.txt", "r");
    if (phoneBook == NULL){
        printf("Error opening prefixnumber.txt file\n");
        printf("Please check if prefixnumber.txt in the same folder as .exe file\n");
        exit(1);
    }
    while(fgets(prefix,200,phoneBook) != NULL){
        printf("%s",&prefix[i]);// not sure what happen but somehow it print missing character after the first line of prefixnumber.txt
        i++;

    }
    fclose(phoneBook);
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