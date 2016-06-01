#include<stdio.h>

int main(void) {
  FILE *C = NULL, *VER = NULL, *OUTP = NULL;
  int out_ver, out_c, i;
  VER = fopen("verilog.out", "r");
  C = fopen("c.out", "r");
  OUTP = fopen("cmp.out", "w");
  for (i = 1; fscanf(VER, "%d", &out_ver) != EOF &&
         fscanf(C, "%d", &out_c) != EOF; i++)
    if (out_ver != out_c)
      fprintf(OUTP, "Valores diferentes para a saída na linha %d\n", i);
  return 0;
}
