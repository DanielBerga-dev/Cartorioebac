#include <stdio.h> //biblioteca de comunicacao com usuario
#include <stdlib.h> //biblioteca de alocacao de espaco de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //bibilioteca resposavel por cuidas das string

typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas




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
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}

	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");

}
int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
	
	if (remove(cpf) == 0)
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	}
}

int main ()
{
	char login[30]; // responsável por armazenar a senha inserida pelo usuário
    char senha[30]; // responsável por armazenar a senha inserida pelo usuário

    strcpy(p[0].login, "admin"); // Definindo o login "admin" na struct
    strcpy(p[0].senha, "123"); // Definindo a senha "123"  na struct

    printf("\t\tLogin de administrador\t\t");
	
	printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A função strcmp é responsável por comparar string com string
        printf("Usuário logado\n"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
    }else
	{
        printf("Login e/ou senha incorretos\n"); // senão, login ou senha incorretos.
		system("pause"); // pausa a tela
		system("cls"); // limpa a tela
		return main(); //volta pro começo da main// retorna pro login
    }
    
	
	
	
	
    int opcao=0; //definindo as variaveis
    int x=1;
    for(x=1;x=1;)
	{
		system("cls"); 		//comando responsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    
    
    
	printf("### Cartório da EBAC ###\n\n");//inicio do menu
	
	
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n");
    printf("opção:");// fim do menu
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
			printf("essa opção não está disponivel!\n");		// caso o usuario escolha uma opcao invalida
		system("pause");
		break;
			
	}
	}
    
 
	   
    

}
