#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y; }ponto;

int areaTriangulo(ponto p1, ponto p2, ponto p3) {
  return abs(p1.x * (p2.y-p3.y) + p2.x * (p3.y-p1.y) + p3.x * (p1.y-p2.y));
}

int estaTriangulo(ponto t[3], ponto p) {
  int at, a1, a2, a3;
  at = areaTriangulo(t[0], t[1], t[2]);
  a1 = areaTriangulo(p, t[1], t[2]);
  a2 = areaTriangulo(t[0], p, t[2]);
  a3 = areaTriangulo(t[0], t[1], p);
  return (at == a1 + a2 + a3);
}

int main(void) {
  ponto t[3], p;
  while (scanf("%d %d", &t[0].x, &t[0].y) != EOF) {
    scanf("%d %d %d %d %d %d",
          &t[1].x, &t[1].y, &t[2].x, &t[2].y, &p.x, &p.y);
    printf("%d\n", estaTriangulo(t, p));
  }
  return 0;
}
