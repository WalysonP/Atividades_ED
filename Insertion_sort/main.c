#include <stdio.h>
#include <stdlib.h>

void insert_sort(int vet[], int n) {

	int i, j, p;

	for(j = 1; j < n; j++) {
		int aux = vet[j];
		for(i = j-1; i >=0 && vet[i] > aux; i--) {
			vet[i+1] = vet[i];
		}
		vet[i+1] = aux;
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

    insert_sort(vet, n);

    printf("\n\nVetor Ordenado: \n");
    for (p = 0; p < n; p++) {
        printf("%d ", vet[p]);
    }
    printf("\n");

	return 0;

}
