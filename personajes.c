#include <stdio.h>
#define MAX_CHAR 50

int Bienvenida(void);
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
