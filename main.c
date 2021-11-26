#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define quantidade 50

typedef struct
{
  char nome[50];
  int idade;
  char cep[9];
  char cpf[12];
  char telefone[12];
  char endereco[50];
  int ativo;
  char comorbidade[20];
} Paciente;

Paciente pacientes[quantidade];

void altenticacao(); //prototipo da funcao
void menu();
void cadastrar();
void atribuiComorbidade(Paciente novoPaciente);
void geraArquivoComComorbidade(Paciente novoPaciente);
void geraArquivoSemComorbidade(Paciente novoPaciente);

int main(int arg, char const *argv[])
{

  altenticacao();

  menu();

  return 0;
  getchar();
}

void altenticacao()
{
  char login[15] = "admin";
  char login1[15];
  char senha[15] = "1234";
  char senha1[15];

  int continuar = 1;

  do
  {
    printf("--------Entre com Login E Senha---------\n");
    printf("LOGIN: ");
    scanf("%s", login1);

    printf("Senha: ");
    scanf("%s", senha1);

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0)
    {
      printf("-- Login realizado com Sucesso --\n");
      return 1;
    }
    else
    {

      printf("---Usuario Invalido. Tente novamente!---\n\n");
      printf("Gostaria de tentar novamente?\n1 - Tentar novamente\n0 - Sair\n");
      printf("Opção: ");
      scanf("%d", &continuar);
    }
  } while (continuar != 0);
}

void menu()
{

  int op;
  do
  {
    printf("\n1 - Cadastrar Paciente\n0 - Sair\n");
    scanf("%d", &op);
    getchar();

    switch (op)
    {
    case 1:
      cadastrar();
      break;
    }
  } while (op != 0);
}

void atribuiComorbidade(Paciente novoPaciente)
{
  int temComorbidade;

  printf("\nPaciente com comorbidade?\n1 - Sim\n2 - Não\n");
  printf("Opção: ");
  scanf("%d", &temComorbidade);

  if (temComorbidade == 1)
  {
    int comorbidade;

    printf("\nQual a comorbidade do paciente?\n1 - Diabetes\n2 - Obesidade\n3 - Hipertensão\n4 - Tuberculose\n5 - Outros\n");
    printf("Opção: ");
    scanf("%d", &comorbidade);

    switch (comorbidade)
    {
    case 1:
      strcpy(novoPaciente.comorbidade, "diabetes");
      break;
    case 2:
      strcpy(novoPaciente.comorbidade, "obesidade");
      break;
    case 3:
      strcpy(novoPaciente.comorbidade, "hipertensão");
      break;
    case 4:
      strcpy(novoPaciente.comorbidade, "tuberculose");
      break;

    default:
      strcpy(novoPaciente.comorbidade, "outros");
      break;
    }
  }
  else
  {
    strcpy(novoPaciente.comorbidade, "sem comorbidade");
  }
}

void geraArquivoSemComorbidade(Paciente novoPaciente)
{
  FILE *pacientesArquivo = fopen("sem-comorbidade.txt", "a");

  fprintf(pacientesArquivo, "%s,%d,%s,%s,%s,%s\n",
          novoPaciente.nome,
          novoPaciente.idade,
          novoPaciente.cpf,
          novoPaciente.telefone,
          novoPaciente.endereco,
          novoPaciente.cep);

  fclose(pacientesArquivo);
}

void geraArquivoComComorbidade(Paciente novoPaciente)
{
  FILE *pacientesArquivo = fopen("comorbidade.txt", "a");

  fprintf(pacientesArquivo, "%d,%s\n",
          novoPaciente.idade,
          novoPaciente.cep);

  fclose(pacientesArquivo);
}

void cadastrar()
{
  system("cls");

  int op;
  do
  {

    Paciente novoPaciente;

    system("cls");
    printf("\n---- Cadastrando paciente -----\n");
    printf("\nNome:");
    fgets(novoPaciente.nome, sizeof(novoPaciente.nome), stdin);
    fflush(stdin);

    printf("\nIdade:");
    scanf("%d", &novoPaciente.idade);
    fflush(stdin);

    printf("\nEndereço:");
    fgets(novoPaciente.endereco, sizeof(novoPaciente.endereco), stdin);
    fflush(stdin);

    printf("\nCep:");
    scanf("%s", &novoPaciente.cep);
    fflush(stdin);

    printf("\nTelefone:");
    fgets(novoPaciente.telefone, sizeof(novoPaciente.telefone), stdin);

    atribuiComorbidade(novoPaciente);

    if (strcmp(novoPaciente.comorbidade, "sem comorbidade") != 0 && novoPaciente.idade >= 65)
    {
      geraArquivoComComorbidade(novoPaciente);
    }

    geraArquivoSemComorbidade(novoPaciente);

    printf("\nPaciente cadastrado com sucesso!\n");

    printf("\n1 - Continuar\n0 - Sair\n");
    scanf("%d", &op);
    getchar();

  } while (op != 0);
}