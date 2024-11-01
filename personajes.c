#include <stdio.h>
#define MAX_CHAR 50

void Bienvenida(void);
void stats_Batman(void);
void stats_Joker(void)

typedef struct{
    char nombre[MAX_CHAR];
    int potencia;
    int usos;
}ataque_t;
typedef struct{
    char nombre[MAX_CHAR];
    int curacion;
    int proteccion;
    int usos;
}defensa_t;


typedef struct{
    char nombre[MAX_CHAR];
    ataque_t ataques[3];
    defensa_t defensas[3];
    int vida;
    int vida_maxima;
    int velocidad;
    int evasion;
}personaje_t;
//Batman
const personaje_t batman = {"Batman",};
//Joker
const personaje_t joker = {"Joker", 100, 100, 100, 100, 100, 100, 100, 100};

int main(){
    Bienvenida()
    
}

void Bienvenida(){
    printf("Bienvenido a nuestro juego de Heroes contra Villanos");
}

void stats_Batman(){
    printf("Elegiste a Batman, estas son sus estadisticas:\n")
    printf("Nombre:%s\n",batman.ataque);
    printf("Ataque:%d\n",batman.ataque_especial);
    printf("Defensa:%d\n",batman.defensa);
    printf("Defensa especial:%d\n",batman.defensa_especial);
    printf("Vida:%d\n",batman.vida);
    printf("Vida maxima:%d\n",batman.vida_maxima);
    printf("Velocidad:%d\n",batman.velocidad);
    printf("Inteligencia:%d\n",batman.iq);
}

void stats_Joker(){
    printf("Elegiste al Joker, estas son sus estadisticas:\n")
    printf("Nombre:%s\n",joker.ataque);
    printf("Ataque:%d\n",joker.ataque_especial);
    printf("Defensa:%d\n",joker.defensa);
    printf("Defensa especial:%d\n",joker.defensa_especial);
    printf("Vida:%d\n",joker.vida);
    printf("Vida maxima:%d\n",joker.vida_maxima);
    printf("Velocidad:%d\n",joker.velocidad);
    printf("Inteligente:%d\n",joker.iq);
}
