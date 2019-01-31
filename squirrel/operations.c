#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
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
    int numberofUsers;
    FILE* logOku;
    FILE* logYaz;
    FILE* kayitDosyasi;
    if((logOku = fopen("log.txt", "r")) == NULL){
        printf("A trouble occurred while loading the files.");
    }
    if((kayitDosyasi = fopen("accounts.txt","a+")) == NULL){
        printf("A trouble occurred while loading the files.");
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
    fseek(logOku, 16, SEEK_SET);
    fscanf(logOku,"%d", &numberofUsers);
    numberofUsers++;
    if((logYaz = fopen("log.txt", "w")) == NULL){
        printf("A trouble occurred while loading the files");
    }
    fprintf(logYaz,"NumberofUsers = %d", numberofUsers);
    fclose(logOku);
    fclose(logYaz);
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
        printf("A problem has occurred while loading files.");
    }
    if((library = fopen("library.txt", "w")) == NULL){
        printf("A problem has occurred while loading files.");
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
    int numberofUsers;
    FILE* log;
    if((log = fopen("log.txt", "r")) == NULL){
         printf("A problem has occurred while loading files.");
    }
    fseek(log, 16, SEEK_SET);
    fscanf(log,"%d", &numberofUsers);
    int rowNumber = numberofUsers * 2; //kaç adet dosya oluşturulacağını gösteren değişken
    fclose(log);
    
    DIR* dirMain;
    struct dirent* list;
    if((dirMain = opendir("c:\\")) == NULL){
        printf("A problem has occurred while accessing directories");
        return EXIT_FAILURE;
    }
    FILE* randomLoc;
    if((randomLoc = fopen("randomLoc.txt","w")) == NULL){
        printf("A problem has occurred while loading files.");
    }
    int i = 0;
    while((list = readdir(dirMain)) != NULL){
        i++;
        fprintf(randomLoc,"%d %s\n", i, list->d_name);
    }
    fclose(randomLoc);
    FILE* randomLoc2;
    if((randomLoc2 = fopen("randomLoc.txt","r")) == NULL){
        printf("A problem has occurred while loading files.");
    }
    luckmeAgain:
    srand(time(NULL));
    int luckyNumber = (int)rand() % (i - 2);
    int count = 0;
    char nameofFile[40];
    int chosen;
    while((fgets(nameofFile, 40, randomLoc2)) != NULL){
        count++;
        if(count == luckyNumber){
            break;
        }
    }
    for(int a = 0; a < strlen(nameofFile); a++){
        if('.' == nameofFile[a]){
            goto luckmeAgain;
        }
    }
    // Only folders will show up hereupon;
    printf("%s\n", nameofFile);
    char fileNu[3];
    sprintf(&fileNu[0],"%c", nameofFile[0]);
    sprintf(&fileNu[1],"%c", nameofFile[1]);
    int number = atoi(fileNu);
    if(number < 10){
        strcpy(&nameofFile[0], &nameofFile[2]);
    }
    else if(number >= 10){
        strcpy(&nameofFile[0], &nameofFile[3]);
    }
    printf("%s\n", nameofFile);
    fclose(randomLoc2);
    closedir(dirMain);
    // AŞAMA 2;
    
    DIR* second;
    struct dirent* sList;
    char directory[60] = "c:\\";
    snprintf(directory, 60, "%s%s", directory, nameofFile);
    printf("%s\n", directory);
    if((second = opendir(directory)) == NULL){  //birleştirilmiş stringi kabul etmiyor.
         printf("A problem has occurred while accessing directories\n");
    }
    FILE* randomLoc3;
    if((randomLoc3 = fopen("randomLoc.txt","a")) == NULL){
        printf("A problem has occurred while loading files.\n");
    }
    fseek(randomLoc3, 0 , SEEK_END);
    int i2 = 0;
    while((sList = readdir(second)) != NULL){
        i2++;
        fprintf(randomLoc3, "%d %s\n", i2, sList->d_name);
    }
    // namofFile değişkeninde sadece klasör adını aldır. Daha sonra o klasörün içine girdir.
    fclose(randomLoc3);
    closedir(second);
}

/* void _readDirectoryTest(){
    FILE* test;
    test = fopen("test.txt","w");
   DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("c:\\")) == NULL) {
        perror ("");
        return EXIT_FAILURE;
    }
    while ((ent = readdir (dir)) != NULL) {
        printf ("%s\n", ent->d_name);
        fprintf(test, "%s\n", ent->d_name);
  }
  closedir (dir);
  
}
*/
void delay(int seconds){
    int ms = 1000 * seconds;
    clock_t start_time = clock();
    while(clock() < start_time + ms)
        ;
}

void successful_login(char userName[], char password[]){
    // kullanıcı şifresine ulaşmak için = password stringi kullanılabilir.
    printf("Welcome to the program %s\n", userName);
    if((strcmp(userName, "hubbey")) == 0){
        admin_panel(userName);
    }
    
}

void admin_panel(char adminName[]){
    
    int secim;
    printf("Great power comes with great responsibility\n");
    printf("----------Admin Panel----------\n");
    printf("1)Wipe All Data\n");
    scanf("%d", &secim);
    if(secim == 1){
        int succes;
        int succes1;
        int succes2;
        FILE* log;
        FILE* accounts;
        FILE* library;
        
        succes = remove("accounts.txt");
        succes1 = remove("library.txt");
        succes2 = remove("log.txt");
        if(succes == 0 && succes1 == 0 && succes2 == 0){
            printf("All data wiped successfully\n");
        }
        log = fopen("log.txt", "w");
        fprintf(log,"NumberofUsers = 0");
        accounts = fopen("accounts.txt","w");
        library = fopen("library.txt", "w");
        fclose(library);
        fclose(accounts);
        fclose(log);
        printf("You're being directed to main menu.\n");
        delay(2);
        main();
    }
    else{
        printf("I haven't programmed that path yet\n");
    }
}