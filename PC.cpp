#include <stdio.h>

int main() {
  float rendaMes, rendaTotal;
  int mes = 1;
  rendaTotal = 0;

  for (int cont = 0; cont < 5; cont++) {
    printf("Qual foi sua renda do m�s %d?\n", mes); // Mostrar o n�mero do m�s
    scanf("%f", &rendaMes);

    if (rendaMes < 0) {
      printf("Erro: Valor de renda inv�lido. Digite um valor positivo.\n");
      continue; // Ignorar o m�s atual se a renda for inv�lida
    }

    rendaTotal += rendaMes;
    printf("Sua renda do m�s %d foi de: R$ %.2f e sua renda total � de: R$ %.2f\n", mes, rendaMes, rendaTotal);
    mes++;
  }

  if (rendaTotal > 3500) {
    printf("PARABENS, VOC� CONSEGUIU DINHEIRO PARA MONTAR O PC!");
  } else {
    printf("Que pena, n�o rolou de montar seu pc dessa vez.");
  }
  
  return 0;
}
