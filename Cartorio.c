#include <stdio.h> //biblioteca de comunicacao com usuario
#include <stdlib.h> //biblioteca de alocacao de espaco de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //bibilioteca resposavel por cuidas das string

typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" � o m�ximo de pessoas com logins e senhas




int Registro()		// funcao responsavel por cadastrar os usuarios no sistema 
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); 	 // coletando informacao do usuario
	scanf("%s", cpf);		//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file;//criar o arquivo
	file = fopen(arquivo,"w");// criar o arquivo // o "w" significa escrever "write"
	fprintf(file,cpf);//salvo o arquivo variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado : ");
	scanf("%s", nome);
	
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
   	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

    
}
int Consultar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}

	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");

}
int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
	
	if (remove(cpf) == 0)
	{
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	}
}

int main ()
{
	char login[30]; // respons�vel por armazenar a senha inserida pelo usu�rio
    char senha[30]; // respons�vel por armazenar a senha inserida pelo usu�rio

    strcpy(p[0].login, "admin"); // Definindo o login "admin" na struct
    strcpy(p[0].senha, "123"); // Definindo a senha "123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usu�rio para o vetor login que est� dentro da fun��o main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usu�rio para o vetor senha que est� dentro da fun��o main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A fun��o strcmp � respons�vel por comparar string com string
        printf("Usu�rio logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da fun��o main, usu�rio ser� logado.
    }else{
        printf("Login e/ou senha incorretos"); // sen�o, login ou senha incorretos.
    }
    
	
	
	
	
    int opcao=0; //definindo as variaveis
    int x=1;
    for(x=1;x=1;)
	{
		system("cls"); 		//comando responsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    
    
    
	printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
	
	
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n");
    printf("op��o:");// fim do menu
    scanf("%d",&opcao);//armazenando a escolha do usuario
    
    system("cls");
    
    switch(opcao)
    { 
	    case 1:
	 	Registro(); 	//chamada da funcao registro
        break;
        
        case 2:
        Consultar();	//chamada da funcao consultar
    	break;
    	
    	case 3:
    	Deletar();		//chamada da funcao deletar
		break;
		
		case 4:
	    printf("Obrigado por utilizar o sistema!\n"); //agradecimento
	    return 0;
	    break;
			
		default:
			printf("essa op��o n�o est� disponivel!\n");		// caso o usuario escolha uma opcao invalida
		system("pause");
		break;
			
	}
	}
    
 
	   
    

}
