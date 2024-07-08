#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40]; //criando um conjunto de variáveis, string
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //dando a instrução ao usuário e coletando
	scanf("%s", CPF); //instruindo ao computador em qual das string armazenar a informação
	
	strcpy(arquivo, CPF); //copia as informações colocada na string CPF e passa para outro string, no caso, o arquivo
	
	FILE *file; //cria uma pasta em arquivos
	
	file = fopen(arquivo, "w"); //cria um novo arquivo. "w" significa escrever
	fprintf(file, CPF); //coleta e salva os valores da string CPF
	fclose(file); //fecha a pasta
	
	file = fopen(arquivo, "a"); //atualiza o arquivo ser cadastrado
	fprintf(file, ","); //coloca separação entre os dados coletados para registro
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
	
	printf("Digite o cargo a ser cadastrado: "); //dando a instrução ao usuário e coletando
	scanf("%s", cargo); //instruindo ao computador em qual das string armazenar a informação
	
	file = fopen(arquivo, "a"); //atualizar o arquivo com o cargo
	fprintf(file, cargo); //coleta e salva os valores da string cargo
	fclose(file); //fecha a pasta
	
	file = fopen(arquivo, "a"); //atualiza o arquivo a ser cadastrado
	fprintf(file, ","); //coloca separação entre os dados coletados para registro
	fclose(file); //fecha a pasta
	
	printf("Registro feito com sucesso!!");
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char CPF[40]; //criando um conjunto de variáveis, string
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: "); //dando a instrução ao usuário e coletando
	scanf("%s", CPF); //instruindo ao computador em qual string procurar a informação
	
	FILE *file; //arquivos
	file = fopen(CPF, "r"); //consultar um arquivo já existente
	
	if(file == NULL) //informação não encontratada na pasta CPF
	{
		printf("Não foi possível abrir o arquivo. Não localizado!\n"); //mensagem de retorno para o usuário
	}
	
	while(fgets(conteudo, 100, file) != NULL) //informação encontratada na pasta CPF
	{
		printf("\n Essas são as informações do usuário: "); //mensagem de retorno para o usuário
		printf("%s", conteudo); //retorno do conteúdo armazenado
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	char CPF[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //dando a instrução ao usuário e coletando
	scanf("%s",CPF); //instruindo ao computador em qual string procurar a informação
	
	remove(CPF); //objetivo
	
	FILE *file; //arquivos
	file = fopen(CPF, "r"); //consultar um arquivo já existente
	
	if(file == NULL) //informação não encontratada na pasta CPF
	{
		printf("O usuário não se encontra no sitema!.\n"); //mensagem de retorno para o usuário
		system("pause");
	}
}  

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo o meu laço de repetição
	
	for(laco=1;laco=1;) //Entrada e saída do meu laço de repetição
	{
		
	   system("cls"); //Limpando tela
	
 	   setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	   printf("### Cartório da EBAC ### \n\n"); //Início do menu
	   printf("Escolha a opção desejada no menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
       printf("Opção: "); //Fim do menu
	
	   scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	   system("cls"); //Limpando tela
	
	   switch(opcao) //inicio da seleção
	   {
	   	  case 1:
	   	    registro(); //chamada de funções 
	   	  break;
	   	  	
	   	  case 2:
			consulta();
		  break;
			 
		  case 3:
		    deletar();
		  break;
			 
		  default:
		    printf("Essa opção não está disponível!Tentar novamente no menu.\n");
			system("pause");
		  break;	 	 	 	 	
	   } //fim da seleção
	   
    }  
}
