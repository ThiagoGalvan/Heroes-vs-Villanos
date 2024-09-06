#include <stdio.h>
#define MAX_CHAR 50


typedef struct{
    char nombre[MAX_CHAR];
    int resistencia;
    int resistencia_fuego;
    int resistencia_elec;
    int vida;
    int fuerza;
    int velocidad;
    int edad;
    int iq;
    char franquicia[MAX_CHAR];
}personaje_t;

//Batman
personaje_t batman = {"Batman", 100, 100, 100, 100,100,100,100,100,"DC"};
int main(){
    printf("Nombre:%s\n",batman.nombre);
    printf("Resistencia:%d\n",batman.resistencia);
    printf("Resistencia al fuego:%d\n",batman.resistencia_fuego);
    printf("Resistencia electrica:%d\n",batman.resistencia_elec);
    printf("Vida:%d\n",batman.vida);
    printf("Fuerza:%d\n",batman.fuerza);
    printf("Velocidad:%d\n",batman.velocidad);
    printf("Edad:%d\n",batman.edad);
    printf("IQ:%d\n",batman.iq);
    printf("Franquicia:%s\n",batman.franquicia);
}