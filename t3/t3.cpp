#include <stdio.h>
#include <stdlib.h>

typedef struct{ int x, y; }ponto;

int areaTriangulo(ponto p1, ponto p2, ponto p3){
  return abs(p1.x * (p2.y-p3.y) + p2.x * (p3.y-p1.y) + p3.x * (p1.y-p2.y));
}

int estaTriangulo(ponto t[3], ponto p){
  int at, a1, a2, a3;
  at = areaTriangulo(t[0], t[1], t[2]);
  a1 = areaTriangulo(p, t[1], t[2]);
  a2 = areaTriangulo(t[0], p, t[2]);
  a3 = areaTriangulo(t[0], t[1], p);
  return (at == a1 + a2 + a3);
}

int main(void){
  int i;
  ponto t[3], p;
  for (i = 0; i < 3; i++){ 
    printf("X%d: ", i+1); scanf("%d", &t[i].x);
    printf("Y%d: ", i+1); scanf("%d", &t[i].y);
  }
  printf("Informe as coornadas do ponto:\n");
  printf("X: "); scanf("%d", &p.x);
  printf("Y: "); scanf("%d", &p.y);
  printf("%s contido no triangulo.\n", estaTriangulo(t, p) ? "Esta" : "Nao esta");
  return 0;
}
