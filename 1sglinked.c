#include <stdio.h>
#include <stdlib.h>

typedef struct N { int d; struct N *n; } N;
void I(N** h, int v, int m) {
    if (m) while (*h) h = &(*h)->n; 
    N* a = malloc(sizeof(N));
    a->d = v; a->n = *h; *h = a;
}
void D(N** h, int v) {
    while (*h && (*h)->d != v) h = &(*h)->n;
    N* t = *h; if (t) { *h = t->n; free(t); 
    }}
int main() {
    N* h = NULL; int c, v;
    while (1) {
        printf("\n1.Insert Beg 2.Insert End 3.Delete 4.Display 5.Exit\nChoice: ");
        scanf("%d", &c);
        if (c == 5) break;
        if (c == 4) { for (N* t = h; t; t = t->n) printf("%d -> ", t->d); printf("NULL\n"); }
        else {
            printf(c == 3 ? "Delete value: " : "Value: "); scanf("%d", &v);
            c == 3 ? D(&h, v) : I(&h, v, c == 2);
        }}
    return 0;
}