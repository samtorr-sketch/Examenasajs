#include <stdio.h>
#include <stdlib.h>

int main() {
    float *calificaciones = NULL;
    int n, adicional, total_estudiantes;
    float suma = 0, promedio;

    printf("Cuantos estudiantes quiere registrar? ");
    scanf("%d", &n);

    calificaciones = (float *)malloc(n * sizeof(float));		    //memoria inicial con malloc()
    if (calificaciones == NULL) {		// checar si malloc devolvió NULL
        printf("Error: No se pudo dar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Ingrese la calificacion del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    total_estudiantes = n;

    promedio = suma / total_estudiantes;
    printf("\n     Resultados Iniciales  \n");
    printf("Promedio general: %.2f\n", promedio);

    printf("\n Quiere agregar estudiantes? (Ingrese la cantidad, 0 para no): ");
    scanf("%d", &adicional);

    if (adicional > 0) {
        // Usar realloc para hacerlo mas grande
        float *temp = (float *)realloc(calificaciones, (total_estudiantes + adicional) * sizeof(float));
        
        // Verificar realloc
        if (temp == NULL) {
            printf("Error: No se pudo ampliar la memoria.\n");
            free(calificaciones); // Liberar lo anterior antes de salir
            return 1;
        }
        calificaciones = temp;

        // nuevas calificaciones y actualizar promedio
        for (int i = total_estudiantes; i < (total_estudiantes + adicional); i++) {
            printf(" Calificacion del nuevo estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }
        total_estudiantes += adicional;
    }

    // Mostrar lista completa y promedio final
    printf("\n     Final de Calificaciones \n");
    for (int i = 0; i < total_estudiantes; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }
    printf("Promedio total: %.2f\n", suma / total_estudiantes);

    // 7. Liberar la memoria
    free(calificaciones);
    printf("\nMemoria liberada .\n");

    return 0;
}