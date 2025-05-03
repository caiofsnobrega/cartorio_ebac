#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //vai armazenar o cpf digitado em uma vari�vel do tipo string, por isso o %s (string s�o conjuntos de chars(caracteres))
	
	
	strcpy(arquivo, cpf); //estamos copiando o valor da vari�vel CPF para a vari�vel arquivo, para que o nome do arquivo tenha o mesmo valor
	
	
	FILE *file; //criando o arquivo no banco de dados. FILE � a fun��o que cria arquivos. file � o arquivo sendo criado.
	file = fopen(arquivo, "w"); //como � um arquivo novo se usa o "W" de write
	fprintf(file, cpf); //armazena no arquivo file a vari�vel CPF
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo criado usando o "a" para atualizar o arquivo
	fprintf(file, ", "); //aqui inserimos a atualiza�ao, no caso, a v�rgula, para organizar os dados no arquivo
	fclose(file);
	
	
	
	printf("Digite o nome a ser cadastrado: "); //aqui voltamos a falar com o usu�rio, pedindo mais um dado
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //uma vez j� tendo criado o arquivo, � s� abrir usando o "a" para atualizar com os outros dados
	fprintf(file, nome); //armazena no arquivo file a vari�vel nome
	fclose(file);
	
	file = fopen(arquivo, "a"); //adicionando outra v�rgula
	fprintf(file, ", "); 
	fclose(file);
	
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //adicionando outra v�rgula
	fprintf(file, ", "); 
	fclose(file);
	
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
}

int consulta()
{

    setlocale(LC_ALL, "Portuguese");

	char cpf[40]; //precisa criar a variavel de novo pois estamos em outra fun��o
	char conteudo[200]; //onde ser� armazenado o arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //aqui abre o arquivo criado usando o "r" de read
	
	if(file == NULL) //caso o usuario digite um dado n�o cadastrado
	{
		printf("\nArquivo n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa�oes do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	//o cpf tamb�m ser� o par�metro a ser usado para deletar o usu�rio
	//o PC n�o sabe o conte�do das outras fun��es
	//ent�o tem que criar uma nova vari�vel nesta fun��o de deletar para isso:
	
	char cpf[40]; //char tamb�m pode receber n�meros e para gerenciamento de strings ele funciona melhor
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf); // o valor a ser inserido vai ser armazenado na string cpf (strings s�o conjuntos de vari�veis)
	
	//agora � um c�digo pra validar que o cpf a ser deletado j� est� cadastrado, e se n�o estiver vai aparecer a mensagem de erro para o usu�rio
	
	FILE *file; //acessar a fun��o FILE para abrir os arquivos
	file = fopen(cpf, "r"); //ler o cpf inserido no scanf acima
	fclose(file);
	
	if(file == NULL) // se o arquivo n�o existe...
	{
		printf("Usu�rio n�o cadastrado\n");
		system("pause"); //congela a tela para o usuario ler, se n�o ela iria aparecer e sumir rapidamente
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso\n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0;  //cria��o da vari�vel chamada de opcao
	int x = 1;  //cria��o da vari�vel x para usar na fun��o "for" abaixo
	
	for(x=1; x=1;)  //fun��o "for" usada para que o programa sempre volte para o menu de op��es
	{
	
		system("cls");  //fun��o de limpar a tela
	
		setlocale(LC_ALL, "Portuguese");
	
		printf
		("### Cart�rio da EBAC ###\n\n"
	 	"Escolha a op��o desejada do menu:\n\n"
		 "\t1 - Registrar nomes\n"
		 "\t2 - Consultar nomes\n"
		 "\t3 - Deletar nomes\n\n"
		);
		printf ("Op��o: ");
	
		scanf("%d", &opcao);  //armazena na vari�vel "opcao" o valor que o usu�rio inserir
	
		system("cls");  //depois que o usus�rio digitar o valor, o programa vai esconder todas as mensagens anteriores do menu
		
		switch(opcao)
		{
			case 1:  //caso a vari�vel for 1...
			registro();
			break; 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:  //para qualquer outra op��o inserida 
			printf("Esta op��o n�o est� dispon�vel\n\n");
			system("pause");
			break;
		}		
	}
}
