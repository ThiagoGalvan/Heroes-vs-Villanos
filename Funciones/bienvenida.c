#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE_NOMBRE 20
#define LIMITE_PERSONAJES 13

int Bienvenida (void);

int main(){
    srand(time(NULL));
    Bienvenida();
}

int Bienvenida (void){
    const char personajes[LIMITE_PERSONAJES][LIMITE_NOMBRE]={"Batman","Superman","Flash","Flecha Verde","Aquaman","Shazam","Joker","Lex Luthor","Flash Reverso","Deathstroke","Manta Negra","Black Adam"};

    int eleccion;
    printf("Bienvenido a \"Lluvia de Sopapos\"\n");
    printf("Elija un personaje:\n");
    printf("1-Batman\n");
    printf("2-Superman\n");
    printf("3-Flash\n");
    printf("4-Flecha Verde\n");
    printf("5-Aquaman\n");
    printf("6-Shazam\n");
    printf("7-Joker\n");
    printf("8-Lex Luthor\n");
    printf("9-Flash Reverso\n");
    printf("10-Deathstroke\n");
    printf("11-Manta Negra\n");
    printf("12-Black Adam\n");
    printf("13-Aleatorio\n");
    scanf("%d",&eleccion);

    if (eleccion>=1 && eleccion<=12){
        printf("Elegiste a %s\n",personajes[eleccion-1]);
    }
    if(eleccion==13){
        eleccion= rand() % 12+1;
        printf("Elegiste a %s\n",personajes[eleccion-1]);
    }
    if(eleccion<1 || eleccion>13){
        printf("Eliga una opcion valida\n");
    }
    return eleccion;
}