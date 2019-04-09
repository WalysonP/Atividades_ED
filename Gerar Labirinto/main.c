#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> // time()

const char WALL  = '0';
const char EMPTY = ' ';

//left, up, right, down
int deltaL[] = {0, -1, 0, 1};
int deltaC[] = {-1, 0, 1, 0};
int lados = sizeof(deltaL)/sizeof(int);

void shuffle(int vet[], int size){

    for(int i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }

}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
    getchar();
}

void quebrar_parede(int nl, int nc, char mat[nl][nc], int l, int c){

    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;

    if(mat[l][c] != WALL)
        return;

    if((l == 0) || (c == 0) || (l == (nl - 1)) || (c == (nc - 1)))
        return;

    int cont = 0;
    for(int i = 0; i < 4; i++){
        if(mat[l + deltaL[i]][c + deltaC[i]] == EMPTY)
            cont++;
    }
    if(cont < 2){
        mat[l][c] = EMPTY;
    }else{
        return;
    }

    show(nl, nc, mat);
    printf("\n");

    int neib[] = {0, 1, 2, 3};
    shuffle(neib, lados);

    for(int v = 0; v < lados; v++){
        int i = neib[v];
        quebrar_parede(nl, nc, mat, l + deltaL[i], c + deltaC[i]);
    }

}

int main(){

    srand(time(NULL));
    int nl = 0;
    int nc = 0;
    puts("Digite dimensoes do labirinto");
    scanf("%d %d", &nl, &nc);

    char mat[nl][nc];

    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++) {
            mat[i][j] = WALL;
        }
    }

    show(nl, nc, mat);

    puts("Onde queres comecar?");
    int l = 0;
    int c = 0;
    scanf("%d %d", &l, &c);

    quebrar_parede(nl, nc, mat, l, c);

}
