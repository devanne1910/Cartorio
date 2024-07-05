#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar()
{
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s",cpf);
	
    strcpy(arquivo,cpf); //responsavel por criar os valores das strings
    
    FILE *file; //Cria o arquivo no banco de dados
    file = fopen(arquivo,"w"); //Cria o arquivo no banco de dados
    fprintf(file,cpf); //Salvo o valor da variavel
    fclose(file); //Fecho o arquivo
    
    file = fopen(arquivo,"a"); //Atualiar a informa�ao
    fprintf(file,","); //Adicionando a virgula para ficar mais organizado visualmente
    fclose(file);
    
    printf("Digite o nome a ser cadastrado/ ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a"); //Atualiar a informa�ao
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado/ ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
	
    char cpf[50];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL);
    {
    	printf("Nao foi possivel abrir o arquivo. Arquivo nao localizado!\n");
    	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informa�oes do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	printf("Voc� escolheu deletar um nome.\n");
		    system("pause");
}

int main()
{    
    int opcao=0; //Defini��o de variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	    system("cls");
	    
        setlocale(LC_ALL, "portuguese"); //Defini��o da linguagem
    
        printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
        printf("Clique na op��o desejada:\n\n");
        printf("\t1. Registrar nome\n");
        printf("\t2. Consultar nome\n");
        printf("\t3. Deletar nome\n\n");
	    printf("Op��o: "); //Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usuario
    
        system("cls");
        
         switch(opcao)
		{
		    case 1:
			registrar();
		    break;
		
		    case 2:
		    consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
    	    system("pause");
    	    break;
		}
    
    }    
}


