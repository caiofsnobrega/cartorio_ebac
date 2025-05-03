#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //vai armazenar o cpf digitado em uma variável do tipo string, por isso o %s (string são conjuntos de chars(caracteres))
	
	
	strcpy(arquivo, cpf); //estamos copiando o valor da variável CPF para a variável arquivo, para que o nome do arquivo tenha o mesmo valor
	
	
	FILE *file; //criando o arquivo no banco de dados. FILE é a função que cria arquivos. file é o arquivo sendo criado.
	file = fopen(arquivo, "w"); //como é um arquivo novo se usa o "W" de write
	fprintf(file, cpf); //armazena no arquivo file a variável CPF
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //estamos abrindo o arquivo criado usando o "a" para atualizar o arquivo
	fprintf(file, ", "); //aqui inserimos a atualizaçao, no caso, a vírgula, para organizar os dados no arquivo
	fclose(file);
	
	
	
	printf("Digite o nome a ser cadastrado: "); //aqui voltamos a falar com o usuário, pedindo mais um dado
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //uma vez já tendo criado o arquivo, é só abrir usando o "a" para atualizar com os outros dados
	fprintf(file, nome); //armazena no arquivo file a variável nome
	fclose(file);
	
	file = fopen(arquivo, "a"); //adicionando outra vírgula
	fprintf(file, ", "); 
	fclose(file);
	
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //adicionando outra vírgula
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

	char cpf[40]; //precisa criar a variavel de novo pois estamos em outra função
	char conteudo[200]; //onde será armazenado o arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //aqui abre o arquivo criado usando o "r" de read
	
	if(file == NULL) //caso o usuario digite um dado não cadastrado
	{
		printf("\nArquivo não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informaçoes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	//o cpf também será o parâmetro a ser usado para deletar o usuário
	//o PC não sabe o conteúdo das outras funções
	//então tem que criar uma nova variável nesta função de deletar para isso:
	
	char cpf[40]; //char também pode receber números e para gerenciamento de strings ele funciona melhor
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf); // o valor a ser inserido vai ser armazenado na string cpf (strings são conjuntos de variáveis)
	
	//agora é um código pra validar que o cpf a ser deletado já está cadastrado, e se não estiver vai aparecer a mensagem de erro para o usuário
	
	FILE *file; //acessar a função FILE para abrir os arquivos
	file = fopen(cpf, "r"); //ler o cpf inserido no scanf acima
	fclose(file);
	
	if(file == NULL) // se o arquivo não existe...
	{
		printf("Usuário não cadastrado\n");
		system("pause"); //congela a tela para o usuario ler, se não ela iria aparecer e sumir rapidamente
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso\n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0;  //criação da variável chamada de opcao
	int x = 1;  //criação da variável x para usar na função "for" abaixo
	
	for(x=1; x=1;)  //função "for" usada para que o programa sempre volte para o menu de opções
	{
	
		system("cls");  //função de limpar a tela
	
		setlocale(LC_ALL, "Portuguese");
	
		printf
		("### Cartório da EBAC ###\n\n"
	 	"Escolha a opção desejada do menu:\n\n"
		 "\t1 - Registrar nomes\n"
		 "\t2 - Consultar nomes\n"
		 "\t3 - Deletar nomes\n\n"
		);
		printf ("Opção: ");
	
		scanf("%d", &opcao);  //armazena na variável "opcao" o valor que o usuário inserir
	
		system("cls");  //depois que o ususário digitar o valor, o programa vai esconder todas as mensagens anteriores do menu
		
		switch(opcao)
		{
			case 1:  //caso a variável for 1...
			registro();
			break; 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:  //para qualquer outra opção inserida 
			printf("Esta opção não está disponível\n\n");
			system("pause");
			break;
		}		
	}
}
