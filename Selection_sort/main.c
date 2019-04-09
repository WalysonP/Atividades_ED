#include <stdio.h>
#include <stdlib.h>

void select_sort(int vet[], int n) {

	int i, j, k, p;

	for(j = 0; j < n-1; j++) {
		k = j;
		for(i = j+1; i < n; i++) {
			if(vet[k] > vet[i]) k = i;
		}
		int aux = vet[k];
		vet[k] = vet[j];
		vet[j] = aux;
	}
}

int main() {

    srand(time(NULL));
	//n representa o tamanho do vetor
	int n = 30, i, p;

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

    select_sort(vet, n);

    printf("\n\nVetor Ordenado: \n");
    for (p = 0; p < n; p++) {
        printf("%d ", vet[p]);
    }
    printf("\n");

	return 0;

}
