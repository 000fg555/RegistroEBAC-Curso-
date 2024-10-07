#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int cadastro() //fun��o respons�vel por cadastrar usu�rios no sistema
{ 
	//inicio de cria��o de vari�veis/string
	char arquivo[40];  //Strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char datanasc[40];
	char cargo[40];
	//fim da cria��o de vari�veis
	
	printf("\t\t\t   EBAC \n\n");
	printf("\t\t   ___Cadastro Geral___ \n\n\n");
	printf("\t\t  Cadastro de novo aluno\n\n\n");
	printf("\tDigite o CPF a ser cadastrado:");
	scanf("%s", cpf); // pedir para armazenar a infirma��o na string cpf
	
	strcpy(arquivo, cpf);  //Respons�vel por copiar valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //W = wright - cria um novo arquivo
		fprintf(file,"\t\tCPF: ");
		fprintf(file,cpf); // salva o valor da string CPF
		fprintf(file, "\n");
	fclose(file); // fecha o arquivo
	
		
	printf("\tDigite o NOME:");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
		fprintf(file,"\t\tNOME: ");
		fprintf(file,nome);
		fprintf(file, "\n");
	fclose(file);
	
	
	printf("\tDigite o SOBRENOME:");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo, "a");
		fprintf(file, "\t\tSOBRENOME: ");
		fprintf(file,sobrenome);
		fprintf(file, "\n");
	fclose(file);


	printf("\tDigite a DATA DE NASCIMENTO:");
	scanf("%s", datanasc);
	
	file=fopen(arquivo, "a");
		fprintf(file,"\t\tDATA DE NASCIMENTO: ");
		fprintf(file,datanasc);
		fprintf(file, "\n");
	fclose(file);
	
		
	printf("\tDigite o CARGO:");
	scanf("%s",cargo);

	file=fopen(arquivo, "a");
	fprintf(file,"\t\tCARGO: ");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n      Cadastro efetuado com sucesso! \n\n\n");
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem

	char cpf[40];
	char conteudo[200];
	
	
	printf("\t\t\t   EBAC  \n\n");
	printf("\t\t   ___Cadastro Geral___ \n\n\n");
	printf("\t\t   Consulta de cadastros\n\n\n");
	printf("\tDigite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo cpf e consulta r=read
	
	if(file == NULL)
	{
		printf("\n\tCadastro n�o localizado.\n\n\n");
	}
	
	printf("\n");
	printf("\n    Informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	fclose(file);
	
	system("pause");
	
}

int deleta()
{	
	char cpf[40];
	int opcao=0;
	
	printf("\t\t\t   EBAC  \n\n");
	printf("\t\t   ___Cadastro Geral___ \n\n\n");
	printf("\t\t     Deletar cadastro\n\n\n");
	printf("\tDigite o CPF a ser deletado:");
	scanf("%s",cpf);
	printf("\n\n\tATEN��O: O cadastro com CPF n�: ");
	printf("%s",cpf);
	printf(" ser� DELETADO:\n\n");
	printf("\tDigite 1 para DELETAR e 2 para N�O DELETAR:");
	scanf("%d", &opcao);
	
	if(opcao == 1)
	{
		remove(cpf);
		
		FILE *file;
		file=fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("\n\n\tCadastro deletado com sucesso.\n\n\n");
			system("pause");
		}
	}
		
	if(opcao == 2)
	{
		printf("\n\n\tCadastro n�o deletado.\n\n\n");
		system("pause");
	}
	
}


int main()
{
	int escolha=0; //definir vari�vel
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem


		printf("\t\t\t   EBAC \n\n"); // \t=espa�o tipo tab notexto
		printf("\t\t   ___Cadastro Geral___ \n\n\n"); // \n=pular uma linha
		printf("\t\t Escolha a op��o desejada\n\n"); 
		printf("\t\t  1 - Novo cadastro\n"); // inicio do menu
		printf("\t\t  2 - Consultar cadastro\n");
		printf("\t\t  3 - Deletar cadastro\n");
		printf("\t\t  4 - Sair do programa\n\n"); // fim do menu
		printf("\t  Op��o: ");
	
		scanf("%d", &escolha); //armazenando escolha do usu�rio
	
		system("cls"); //limpar tela
		
		switch(escolha) // conjunto de IF's
		{
			case 1:  //inicio do primeiro IF
			cadastro();
			break;  // fim do primeiro IF
			
			case 2:
			consulta();
			break;
			
			case 3:
			deleta();
			break;
			
			case 4:
			printf("\t\t\t   EBAC  \n\n");
			printf("\t\t   ___Cadastro Geral___ \n\n\n");
			printf("\t\t  Saindo do sistema...\n\n\n");
			return 0;
			break;
			
			default:
			printf("\t\t\t   EBAC  \n\n");
			printf("\t\t   ___Cadastro Geral___ \n\n\n");
			printf("\t\t A op��o escolhida n�o existe\n\n");
			printf("\tPressione qualquer tecla para voltar ao menu inicial \n\n\n");
			system("pause");
			break;
		}
	}
}
