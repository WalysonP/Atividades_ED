#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int vet[], int ini, int meio, int fim) {

	int n1 = meio - ini + 1;
	int i, j, k, p;
	int n2 = fim - meio;
	int l[n1+1], r[n2+1];

	for(i = 0; i < n1; i++) l[i] = vet[ini + i];
	for(i = 0; i < n2; i++) r[i] = vet[meio + 1 + i];

	i = 0, j = 0, l[n1] = INT_MAX, r[n2] = INT_MAX;

	for(k = ini; k <= fim; k++) {
		if(l[i] < r[j]) {
			vet[k] = l[i];
			i++;
		}else {
			vet[k] = r[j];
			j++;
		}
	}

}

void merge_sort(int vet[], int ini, int fim) {

	if(ini < fim) {
		int meio = (ini + fim)/2;
		merge_sort(vet, ini, meio);
		merge_sort(vet, meio + 1, fim);
		merge(vet, ini, meio, fim);
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
    for (p = 0; p < 30; p++) {
        printf("%d ", vet[p]);
    }

    merge_sort(vet, 0, n-1);

    printf("\n\nVetor Ordenado: \n");
    for (p = 0; p < 30; p++) {
        printf("%d ", vet[p]);
    }
    printf("\n");

	return 0;

}
