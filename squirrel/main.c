/* 
 * File:   main.c
 * Author: hubbey
 *
 * Created on January 6, 2019, 1:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    _hubbey_divide();
    _hubbey_randomize();
 
    
    printf("-------- welcome to the squirrel --------\n-------- programmed by hubbey -----------\n");
    printf("--                                     --\n");
    printf("--          Version: 0.0.1             --\n");
    printf("--                                     --\n");
    printf("-----------------------------------------\n");
    
    int dongudenCik = 0;
    int secim;
    printf("Login Panel\n");
    while(dongudenCik == 0){
        printf("Type in a number: \n");
        printf("1)Login\n");
        printf("2)Register\n");
        printf("3)Exit\n");
        scanf("%d", &secim);
        
        switch(secim){
            case 1:
             dongudenCik = 1;
             login();
             break;
            case 2:
                dongudenCik = 1;
                registeR();
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("You have typed invalid value.\n");
                dongudenCik = 1;
        }
    }
    
    return (EXIT_SUCCESS);
}

