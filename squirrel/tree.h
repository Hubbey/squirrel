/* 
 * File:   tree.h
 * Author: hubbey
 *
 * Created on January 6, 2019, 2:18 AM
 */

#ifndef TREE_H
#define TREE_H

typedef struct userInfo{
    char userName[26];
    char password[41];
};

void login();
void registeR();
int checkup(char*, char*);
void delay(int);
void successful_login(char*, char*);

#endif /* TREE_H */

