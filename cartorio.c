
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro() //Fun��o respons�velpor cadastrar os usu�rios no sitema
{
	setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
	
	char arquivo[40]; //in�cio da cria��o das vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valorda variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n\n\nO usu�rio n�o se encontra no sistema!.\n\n\n");
		system("pause");
		
	}
}


int main()
{    
    int opcao=0; //Defini��o de variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	    system("cls"); //Respons�vel por limpar a tela
	    
        setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
    
        printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
        printf("Clique na op��o desejada:\n\n");
        printf("\t1. Registrar nome\n");
        printf("\t2. Consultar nome\n");
        printf("\t3. Deletar nome\n\n");
        printf("\t4. Sair do sistema\n\n");
	    printf("Op��o: "); //Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usuario
    
        system("cls");
        
         switch(opcao)
		{
		    case 1:
			registro(); //Chamada de fun��es
		    break;
		
		    case 2:
		    consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
    	    system("pause");
    	    break;
		} //Fim da sele��o
    
    }    
}
