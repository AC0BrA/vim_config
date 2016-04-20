#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"


int             main(int argc, char const *argv[]) {
    
    char nombre[5];
    char nom[12];
    int i = 0;
    
    printf("Entre un nombre :\n");
    scanf("%s", nombre);
    
    int nb = atoi(nombre);
    int millier = nb / 1000;
    int centaine = nb /100 - millier * 10;
    int dizaine = nb /10 - centaine*10 - millier*100;
    int unite = nb - centaine * 100 - dizaine * 10 - millier * 1000;
    
    //----------Traitement des milliers -----------//
    if(millier > 9){
        printf("Nombre incorrect : [1;9999]");
        exit(1);
    }
    
    if(millier != 0) {
        while(i != millier){
            i++;
            strcat(nom, "M");
        }
        i = 0;
    }

        //----------Traitement des centaines ----------//
    
        if (centaine  == 9) {
            strcat(nom,"CM");
        }
        else if (centaine == 4) {
            strcat(nom, "CD");
        }
        else if (centaine == 5) {
            strcat(nom, "D");
        }
        else if (centaine < 4) {
            while(i != centaine){
                i++;
                strcat(nom, "C");
            }
            i=0;
        }
        else if (centaine < 9 && centaine > 5) {
            strcat(nom, "D");
            while(i != centaine - 5){
                i++;
                strcat(nom, "C");
            }
            i=0;
        }

    
        //----------Traitement des dizaines -----------//
    
        if (dizaine  == 9) {
            strcat(nom,"XC");
        }
        else if (dizaine == 4) {
            strcat(nom, "XL");
        }
        else if (dizaine == 5) {
            strcat(nom, "L");
        }
        else if (dizaine < 4) {
            while(i != dizaine){
                i++;
                strcat(nom, "X");
            }
            i=0;
        }
        else if (dizaine < 9 && dizaine > 5) {
        strcat(nom, "L");
        while(i != dizaine - 5){
                i++;
                strcat(nom, "X");
            }
            i=0;
        }
    
        //----------Traitement des unitées ------------//
    
        if (unite  == 9) {
            strcat(nom,"IX");
        }
        else if (unite == 4) {
            strcat(nom, "IV");
        }
        else if (unite == 5) {
            strcat(nom, "V");
        }
        else if (unite < 4) {
            while(i != unite){
                i++;
                strcat(nom, "I");
            }
            i=0;
        }
        else if (unite < 9 && unite > 5) {
            strcat(nom, "V");
            while(i != unite - 5){
                i++;
                strcat(nom, "I");
            }
            i=0;
        }
    
    printf("\n");
    printf("%s\n", nom);
    
    return 0;
}
