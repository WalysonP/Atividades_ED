#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vet[], int n) {

	int i, j, p;

	for(i = 0; i < n; i++) {
	  	for(j = 0; j < n - 1; j++) {
			if(vet[j] > vet[j+1]) {
				int aux = vet[j+1];
				vet[j+1] = vet[j];
				vet[j] = aux;
			}
		}
	}
}

int main() {

    srand(time(NULL));
	//n representa o tamanho do vetor
	int n = 20, i, p;

	//declaracao do vetor dinamicamente alocado
	int *vet = malloc(n * sizeof(int));

    //preenchimento automatico do vetor
    for (p = 0; p < n; p++) {
        vet[p] = 1 + rand() % (2*n);
    }

    printf("Vetor Desordenado: \n");
    for (p = 0; p < n; p++) {
        printf("%d ", vet[p]);
    }

    bubble_sort(vet, n);

    printf("\n\nVetor Ordenado: \n");
    for (p = 0; p < n; p++) {
        printf("%d ", vet[p]);
    }
    printf("\n");

	return 0;

}
