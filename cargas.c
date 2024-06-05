/*

Construir un programa que calcule el campo eléctrico creado en un punto del plano XY
por un conjunto de cargas. El programa debe pedir al usuario que introduzca por línea de comandos
el número de cargas que se van a considerar (hasta un número máximo). Después deberá pedir que
introduzca para cada carga los datos de la misma, esto es, su posición definida por las coordenadas
(x, y) y el valor de su carga q. Los datos de cada carga serán almacenados en una estructura, y las
cargas en un vector de estructuras. Finalmente, deberá pedir el punto del espacio donde se quiere
obtener el campo y calculará dicho campo.
Recordamos que el campo generado por una carga q en un punto del espacio tiene la forma
E = (k*q)/r^3 (->r), siendo '->r' el vector director del radio

siendo r el vector que va de la carga al punto y r su módulo, y k = 9*E9 (N*m^2)/C^2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Position;

typedef struct {
    Position pos;
    float q;
} Charge;

void main() {

    const float K = 9E9;

    int max = 400, n;

    printf("Introduce el numero 'n' de cargas a evaluar: ");
    scanf("%d", &n);

    if (n > max) {
        printf("El número de cargas es superior al permitido. Por favor, indroduzca un número inferior a %d ", max);
        scanf("%d", &n);
    }

    Charge *charges = (Charge*) malloc(n * sizeof(Charge));

    Position p = {.x = 0.0, .y = 0.0};
    
    float q = 0.0, r = 0.0, sum_x = 0.0, sum_y = 0.0, pos_x = 0.0, pos_y = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Introduce las carga junto a su posicion de la siguiente forma:=x,y,q\nCarga: ");
        scanf("%f,%f,%f", &p.x, &p.y, &q);
        
        charges[i] = (Charge) {.pos = {.x = p.x, .y = p.y}, .q = q};
    }
    
    printf("Introduce la posicion donde quieres evaluar el campo: ");
    scanf("%f,%f", &pos_x, &pos_y);

    for(int i = 0; i < n; i++) {
        r = sqrt(pow(pos_x - charges[i].pos.x, 2) + pow(pos_x - charges[i].pos.y, 2));
        printf("Radio: %f\n", r);
        sum_x += (pos_x - charges[i].pos.x) * charges[i].q/pow(r, 3);
        sum_y += (pos_y - charges[i].pos.y) * charges[i].q/pow(r, 3);
    }

    printf ("El  campo   electrico  en el  punto  (%g, %g) es (%g, %g)\n", pos_x , pos_y , K * sum_x , K * sum_y);
}