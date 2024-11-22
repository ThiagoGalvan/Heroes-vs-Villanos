#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 50
#define MAX_ATACKS 3

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
   ataque_t ataques[MAX_ATACKS];
   defensa_t defensas[MAX_ATACKS];
   int vida;
   int vida_maxima;
   int velocidad;
   int evasion;
} personaje_t;

// Prototipos de funciones
int Bienvenida(void);
void mostrarStats(const personaje_t *pj);
void combate(personaje_t *pj1, personaje_t *pj2);
void elegirAtaque(personaje_t *pj, personaje_t *oponente);

// Definición de personajes
const personaje_t batman = {
   "Batman",
   {{"Batarang", 20, 5}, {"Golpe", 15, 5}, {"Gadget", 25, 3}},
   {{"Curación", 10, 0, 5}},
   100, 100, 10, 5};

const personaje_t joker = {
   "Joker",
   {{"Risa Tóxica", 18, 5}, {"Bomba de Nafta", 22, 4}, {"Truco", 15, 5}},
   {{"Curación", 10, 0, 5}},
   100, 100, 8, 3};

int main() {
   srand(time(NULL)); // Inicializar la semilla para rand
   int eleccion = Bienvenida();
   personaje_t pj1, pj2;

   if (eleccion == 1) {
      pj1 = batman;
      pj2 = joker;
   } else if (eleccion == 2) {
      pj1 = joker;
      pj2 = batman;
   } else {
      printf("Opción no válida. Saliendo...\n");
      return 1;
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
   for (int i = 0; i < MAX_ATACKS; i++) {
      printf("  %d. %s (Potencia: %d, Usos: %d)\n",
         i + 1, pj->ataques[i].nombre, pj->ataques[i].potencia, pj->ataques[i].usos);
   }
}

void combate(personaje_t *pj1, personaje_t *pj2) {
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
   for (int i = 0; i < MAX_ATACKS; i++) {
      printf("%d. %s (Potencia: %d, Usos: %d)\n",
         i + 1, pj->ataques[i].nombre, pj->ataques[i].potencia, pj->ataques[i].usos);
   }

   int eleccion;
   scanf("%d", &eleccion);

   if (eleccion < 1 || eleccion > MAX_ATACKS || pj->ataques[eleccion - 1].usos <= 0) {
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
