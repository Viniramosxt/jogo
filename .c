#include <stdio.h>

#define TAMANHO_MAXIMO 10

typedef struct Carro {
  int placa;
} Carro;

typedef struct Pilha {
  Carro carros[TAMANHO_MAXIMO];
  int topo;
} Pilha;

void inicializar(Pilha *pilha) {
  pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
  return pilha->topo == -1;
}

int estaCheia(Pilha *pilha) {
  return pilha->topo == TAMANHO_MAXIMO - 1;
}

void push(Pilha *pilha, Carro carro) {
  if (!estaCheia(pilha)) {
    pilha->topo++;
    pilha->carros[pilha->topo] = carro;
  } else {
    printf("Estacionamento lotado. Carro não estacionado.\n");
  }
}

Carro pop(Pilha *pilha) {
  Carro carro;
  if (!estaVazia(pilha)) {
    carro = pilha->carros[pilha->topo];
    pilha->topo--;
  } else {
    printf("Estacionamento vazio. Não há carro para retirar.\n");
  }
  return carro;
}

int main() {
  Pilha estacionamento;
  Carro carro;
  int placa_carro, operacao;

  inicializar(&estacionamento);

  while (1) {
    // Lê a placa do carro
    printf("Digite a placa do carro (0 para sair): ");
    scanf("%d", &placa_carro);

    if (placa_carro == 0) {
      break;
    }

    // Lê a operação
    printf("Digite a operação (1 para entrada, 2 para saída): ");
    scanf("%d", &operacao);

    if (operacao == 1) {
      // Entrada
      carro.placa = placa_carro;
      push(&estacionamento, carro);
    } else if (operacao == 2) {
      // Saída
      carro = pop(&estacionamento);
    } else {
      printf("Operação inválida.\n");
      continue;
    }

    // Imprime a placa do carro
    printf("Placa do carro: %d\n", placa_carro);

    // Imprime a operação
    printf("Operação: %s\n", operacao == 1 ? "Entrada" : "Saída");

    // Imprime se há vaga disponível
    printf("Vaga disponível: %s\n", estaCheia(&estacionamento) ? "Não" : "Sim");

    // Imprime se o carro foi estacionado
    printf("Carro estacionado: %s\n", operacao == 1 && !estaCheia(&estacionamento) ? "Sim" : "Não");

    // Imprime se o carro foi retirado
    printf("Carro retirado: %s\n", operacao == 2 && !estaVazia(&estacionamento) ? "Sim" : "Não");
  }

  return 0;
}
