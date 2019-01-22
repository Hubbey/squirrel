#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LENGTH_UNAME 25
#define LENGTH_PW 41


void login(){
    char inUser[LENGTH_UNAME];
    char inPass[LENGTH_PW];
    printf("Type in your username: ");
    scanf("%s", inUser);
    printf("Type in your password. ");
    scanf("%s", inPass);
    int okay = checkup(inUser, inPass);
    if(okay == 0){
        printf("There is no account like that. You are being directed to main menu.\n");
        delay(3);
        main();
    }
    
}

void registeR(){
    
    char userName[LENGTH_UNAME];
    char password[LENGTH_PW];
    char passwordCheck[LENGTH_PW];
    FILE* kayitDosyasi;
    if((kayitDosyasi = fopen("accounts.txt","a+")) == NULL){
        printf("A trouble accoured while loading the files.");
    }
    int dongudenCik = 0;
    
    start:
    while(dongudenCik == 0){
        printf("Type in the username you want: ");
        scanf("%s", userName);
        if((strlen(userName)) < 2 ){
            printf("Length of username must be grater than 2\n");
            goto start;
        }
        printf("Type in the password you want: ");
        scanf("%s", password);
        if((strlen(password)) < 6 ){
            printf("Length of password must be greater than 6\n");
            goto start;
        }
        printf("Type in the password again: ");
        scanf("%s", passwordCheck);
        if((strcmp(password, passwordCheck)) != 0){
            printf("passwords you have typed in are not the same\n");
            goto start;
        }
        dongudenCik = 1;
       
    }
    fprintf(kayitDosyasi, "\n%s %s", userName, password);
    fclose(kayitDosyasi);
    printf("You have registered successfully! You're being directed to main menu.\n");
    delay(3);
    main();
}

int checkup(char inUser[LENGTH_UNAME], char inPass[LENGTH_PW]){

    FILE* lFile;
    int thereIs = 0;
    if((lFile = fopen("accounts.txt", "r")) == NULL){
        printf("A problem accoured while loading files.");
    }
   
    fseek(lFile, 0, SEEK_END);
    long int bayt = ftell(lFile); //dosyanın kaç bayt olduğunu gösteren değişken.
    rewind(lFile);
   
    char userName[LENGTH_UNAME];
    char password[LENGTH_PW];
    char rememberUname[LENGTH_UNAME];
    char rememberPass[LENGTH_PW];
    
    while(!feof(lFile)){   
        
        fscanf(lFile, "%s %s", userName, password);
        if((strcmp(userName,inUser)) == 0 && (strcmp(password,inPass)) == 0){
            
            thereIs = 1;
            strcpy(rememberUname, userName);
            strcpy(rememberPass, password); 
        }
    }
    fclose(lFile);
    if(thereIs == 1){
        successful_login(rememberUname, rememberPass);
    }
    else{
        return 0;
    }
}

void _hubbey_divide(){
    FILE* sourceFile;
    FILE* library;
    if((sourceFile = fopen("accounts.txt", "r")) == NULL){
        printf("A problem has accoured while loading files.");
    }
    if((library = fopen("library.txt", "w")) == NULL){
        printf("A problem has accoured while loading files.");
    }
   
    int numberofColumns = 2; // accounts dosyasındaki sütun sayısı 
    _hucre eleman;
    eleman._satir = 64; // A'dan önceki karakterin ASCII değeri
    eleman._sutun;
    
    while(!feof(sourceFile)){
        eleman._satir++;
        for(eleman._sutun = 0; eleman._sutun < numberofColumns; eleman._sutun++){
            char deger[LENGTH_PW];
            fscanf(sourceFile,"%s ", deger);
            strcpy(eleman._deger, deger);
            fprintf(library, "%d |  %d |  %s\n", eleman._satir, eleman._sutun, eleman._deger);
        }
    }
    fclose(sourceFile);
    fclose(library);
}

void _hubbey_randomize(){
    
}


void delay(int seconds){
    int ms = 1000 * seconds;
    clock_t start_time = clock();
    while(clock() < start_time + ms)
        ;
}

void successful_login(char userName[], char password[]){
    // kullanıcı şifresine ulaşmak için = password stringi kullanılabilir.
    printf("Welcome to the program %s\n", userName);
}