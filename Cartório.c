#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40]; //criando um conjunto de vari�veis, string
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //dando a instru��o ao usu�rio e coletando
	scanf("%s", CPF); //instruindo ao computador em qual das string armazenar a informa��o
	
	strcpy(arquivo, CPF); //copia as informa��es colocada na string CPF e passa para outro string, no caso, o arquivo
	
	FILE *file; //cria uma pasta em arquivos
	
	file = fopen(arquivo, "w"); //cria um novo arquivo. "w" significa escrever
	fprintf(file, CPF); //coleta e salva os valores da string CPF
	fclose(file); //fecha a pasta
	
	file = fopen(arquivo, "a"); //atualiza o arquivo ser cadastrado
	fprintf(file, ","); //coloca separa��o entre os dados coletados para registro
	fclose(file); //fecha a pasta
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file, sobrenome); 
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: "); //dando a instru��o ao usu�rio e coletando
	scanf("%s", cargo); //instruindo ao computador em qual das string armazenar a informa��o
	
	file = fopen(arquivo, "a"); //atualizar o arquivo com o cargo
	fprintf(file, cargo); //coleta e salva os valores da string cargo
	fclose(file); //fecha a pasta
	
	file = fopen(arquivo, "a"); //atualiza o arquivo a ser cadastrado
	fprintf(file, ","); //coloca separa��o entre os dados coletados para registro
	fclose(file); //fecha a pasta
	
	printf("Registro feito com sucesso!!");
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char CPF[40]; //criando um conjunto de vari�veis, string
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: "); //dando a instru��o ao usu�rio e coletando
	scanf("%s", CPF); //instruindo ao computador em qual string procurar a informa��o
	
	FILE *file; //arquivos
	file = fopen(CPF, "r"); //consultar um arquivo j� existente
	
	if(file == NULL) //informa��o n�o encontratada na pasta CPF
	{
		printf("N�o foi poss�vel abrir o arquivo. N�o localizado!\n"); //mensagem de retorno para o usu�rio
	}
	
	while(fgets(conteudo, 100, file) != NULL) //informa��o encontratada na pasta CPF
	{
		printf("\n Essas s�o as informa��es do usu�rio: "); //mensagem de retorno para o usu�rio
		printf("%s", conteudo); //retorno do conte�do armazenado
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	char CPF[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //dando a instru��o ao usu�rio e coletando
	scanf("%s",CPF); //instruindo ao computador em qual string procurar a informa��o
	
	remove(CPF); //objetivo
	
	FILE *file; //arquivos
	file = fopen(CPF, "r"); //consultar um arquivo j� existente
	
	if(file == NULL) //informa��o n�o encontratada na pasta CPF
	{
		printf("O usu�rio n�o se encontra no sitema!.\n"); //mensagem de retorno para o usu�rio
		system("pause");
	}
}  

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo o meu la�o de repeti��o
	
	for(laco=1;laco=1;) //Entrada e sa�da do meu la�o de repeti��o
	{
		
	   system("cls"); //Limpando tela
	
 	   setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	   printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
	   printf("Escolha a op��o desejada no menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
       printf("Op��o: "); //Fim do menu
	
	   scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	   system("cls"); //Limpando tela
	
	   switch(opcao) //inicio da sele��o
	   {
	   	  case 1:
	   	    registro(); //chamada de fun��es 
	   	  break;
	   	  	
	   	  case 2:
			consulta();
		  break;
			 
		  case 3:
		    deletar();
		  break;
			 
		  default:
		    printf("Essa op��o n�o est� dispon�vel!Tentar novamente no menu.\n");
			system("pause");
		  break;	 	 	 	 	
	   } //fim da sele��o
	   
    }  
}
