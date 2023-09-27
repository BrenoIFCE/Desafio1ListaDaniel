#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(){//Função que inicializa o menu de escolha
puts("  ==========Sistema de armários==========\n");
puts("Insira 1 para ocupar um armário aleatório:\n");
puts("Insira 2 para liberar um armário aleatório:\n");
puts("Insira 3 para encerrar o programa:\n");
}

int main(void) {//Função principal do sistema de armários
srand(time(NULL));
unsigned char armario = 0;
int escolha;
int armarioAleatorio;

while(1){
menu();

printf("Insira uma opção:");
scanf("%d", &escolha);

switch (escolha) {
case 1:
  if (armario == 255) {
  printf("\nTodos os armários estão ocupados.\n");
  
} else {
  do {
  armarioAleatorio = rand() % 8;
  
  } while (armario & (1 << armarioAleatorio));
  armario |= (1 << armarioAleatorio);
  printf("\nArmário %d foi ocupado.\n", armarioAleatorio + 1);
  }

break;

case 2:
  if (armario == 0) {
  printf("\nTodos os armários estão livres.\n");

} else {
  printf("Digite o número do armário a ser liberado entre 1 e 8: ");
  scanf("%d", &armarioAleatorio);

if (armarioAleatorio < 1 || armarioAleatorio > 8) {
  printf("Número de armário inválido!\n");

} else if (armario & (1 << (armarioAleatorio - 1))) {
  armario &= ~(1 << (armarioAleatorio - 1));
  printf("\nArmário %d liberado.\n", armarioAleatorio);

} else {
  printf("\nArmário %d já está livre.\n", armarioAleatorio);
}
}
break;

case 3:
  printf("\nPrograma encerrado.\n");
  exit(0);
  
default:
printf("Opção inválida. Tente novamente.\n");
}
}
return 0;
}
