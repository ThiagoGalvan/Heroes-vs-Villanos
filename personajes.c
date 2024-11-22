#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CHAR 50
#define MAX_ATTACKS 3

typedef struct {
   char nombre[MAX_CHAR];
   int potencia;
   int usos;
} ataque_t;

typedef struct {
   char nombre[MAX_CHAR];
   int curacion;
   int proteccion;
   int usos;
} defensa_t;

typedef struct {
   char nombre[MAX_CHAR];
   ataque_t ataques[MAX_ATTACKS];
   defensa_t defensas[MAX_ATTACKS];
   int vida;
   int vida_maxima;
   int velocidad;
} personaje_t;

// Prototipos de funciones
int Bienvenida(void);
void mostrarStats(const personaje_t *pj);
void combate(personaje_t *pj1, personaje_t *pj2);
void elegirAtaque(personaje_t *pj, personaje_t *oponente);

// Definición de personajes
const personaje_t batman = {
   "Batman",
   {{"Batarang", 10, 10}, {"Batarang Explosivo", 25, 5}, {"Batipatada", 15, 5}},
   {{"Curación", 10, 0, 5}},
   120, 120, 15};

const personaje_t joker = {
   "Joker",
   {{"Gas De La Risa", 25, 3}, {"Revolver Largo", 10, 8}, {"Golpe De Secuaz", 15, 5}},
   {{"Curación", 10, 0, 5}},
   90, 90, 15};

const personaje_t flecha = {
   "Flecha",
   {{"Disparo", 12, 5}, {"Arco", 20,3},{"Patada Medialuna", 10, 5}},
   {{"Curación", 10, 0, 5}},
   120, 120, 12};

const personaje_t john = {
   "John Constantine",
   {{"Hechizo De Fuego", 25, 5}, {"Invocacion Satanica", 30, 3},{"Cadenas Diabolicas", 20, 10}},
   {{"Curación", 10, 0, 5}},
   70, 70, 8};


const personaje_t deathstroke = {
   "Deathstroke",
   {{"Golpe De Katana", 20, 5}, {"Guillotina", 45, 1}, {"Disparo", 10, 8}},
   {{"Curación", 10, 0, 5}},
   150, 150, 5};

const personaje_t robin = {
   "Robin",
   {{"Estocada De Espada", 15, 3}, {"Corte Profundo", 20, 5}, {"Patada Giratoria", 10, 5}}
   {{"Curación", 10, 0, 5}}
   
}
int main() {
   srand(time(NULL));
   int eleccion = Bienvenida();
   personaje_t pj1, pj2;

   if (eleccion == 1) {
      pj1 = batman;
      pj2 = joker;
   } else if (eleccion == 2) {
      pj1 = joker;
      pj2 = batman;
   }
   mostrarStats(&pj1);
   mostrarStats(&pj2);
   combate(&pj1, &pj2);
   return 0;
}

int Bienvenida(void) {
   const char personajes[2][MAX_CHAR] = {"Batman", "Joker"};
   int eleccion;

   printf("Bienvenido a \"Lluvia de Sopapos\"\n");
   printf("Elija un personaje:\n");
   printf("1 - Batman\n");
   printf("2 - Joker\n");
   printf("3 - Flecha\n");
   printf("4 - John Constantine\n");
   printf("5 - Deathstroke\n");
   printf("6 - Robin\n");
   printf("7 - Red Hood\n");
   printf("8 - Nightwing\n");
   printf("9 - Damian Wayne\n");
   printf("10 - Azrael\n");
   printf("11 - Bane\n");
   printf("12 - Ra's al Ghul\n");

   scanf("%d", &eleccion);

   if (eleccion >= 1 && eleccion <= 2) {
      printf("Elegiste a %s\n", personajes[eleccion - 1]);
   } else {
      eleccion = rand() % 2 + 1;
      printf("Elección inválida. Se te asignó al azar: %s\n", personajes[eleccion - 1]);
   }
   return eleccion;
}

void mostrarStats(const personaje_t *pj) {
   printf("\nEstadísticas de %s:\n", pj->nombre);
   printf("Vida: %d/%d\n", pj->vida, pj->vida_maxima);
   printf("Velocidad: %d\n", pj->velocidad);
   printf("Evasión: %d%%\n", pj->evasion);
   printf("Ataques:\n");
   for (int i = 0; i < MAX_ATTACKS; i++) {
      printf("  %d. %s (Potencia: %d, Usos: %d)\n",
         i + 1, pj->ataques[i].nombre, pj->ataques[i].potencia, pj->ataques[i].usos);
   }
}

void combate(personaje_t *pj1, personaje_t *pj2) {
   int JokerDown;
   printf("\nComienza el combate entre %s y %s!\n", pj1->nombre, pj2->nombre);
   while (pj1->vida > 0 && pj2->vida > 0) {
      if (pj1->velocidad >= pj2->velocidad) {
         elegirAtaque(pj1, pj2);
         if (pj2->vida <= 0) {
            printf("%s ha sido derrotado!\n", pj2->nombre);
            break;
            }
            elegirAtaque(pj2, pj1);
         } else {
            elegirAtaque(pj2, pj1);
            if (pj1->vida <= 0) {
               printf("%s ha sido derrotado!\n", pj1->nombre);
               break;
            }
            elegirAtaque(pj1, pj2);
            
      }
   }
}

void elegirAtaque(personaje_t *pj, personaje_t *oponente) {
   printf("\n%s, elige un ataque:\n", pj->nombre);
   for (int i = 0; i < MAX_ATTACKS; i++) {
      printf("%d. %s (Potencia: %d, Usos: %d)\n",
         i + 1, pj->ataques[i].nombre, pj->ataques[i].potencia, pj->ataques[i].usos);
   }

   int eleccion;
   scanf("%d", &eleccion);

   if (eleccion < 1 || eleccion > MAX_ATTACKS || pj->ataques[eleccion - 1].usos <= 0) {
      printf("Opción inválida o ataque sin usos restantes. Turno perdido.\n");
      return;
   }

   ataque_t *ataque = &pj->ataques[eleccion - 1];
   oponente->vida -= ataque->potencia;
   if (oponente->vida < 0) oponente->vida = 0;
   ataque->usos--;

   printf("%s usó %s e infligió %d de daño a %s.\n",
         pj->nombre, ataque->nombre, ataque->potencia, oponente->nombre);
   printf("%s ahora tiene %d de vida restante.\n", oponente->nombre, oponente->vida);
}
