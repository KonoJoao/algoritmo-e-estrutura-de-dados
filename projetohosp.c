
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
                char nomePaciente[50];
	            char descricaoProblema[120];
	            char dataDeInclusao[12];
	            int cor;
	            char status[20];
	            char cadcpf[15];
	            char cadtelefone[15];
			}PACIENTE;
			
typedef struct {PACIENTE indice[MAX];
	            int ult;
			}HOSPITAL;
			
void inserir_paciente(PACIENTE novoCadastro, HOSPITAL *clinica){
    clinica->indice[clinica->ult] = novoCadastro;
    clinica->ult++;
}

void cadastrar_paciente(PACIENTE novoCadastro, HOSPITAL *clinica){
        printf("Insira o nome do paciente\n");
        scanf("%[^\n]", novoCadastro.nomePaciente);
        getchar();
        
        printf("Insira a descricao do problema\n");
        scanf("%[^\n]", novoCadastro.descricaoProblema);
        getchar();  
        
        printf("Insira a data\n");
        scanf("%[^\n]", novoCadastro.dataDeInclusao);
        getchar();
       
        printf("Insira seu cpf\n");
        scanf("%[^\n]", novoCadastro.cadcpf);
        getchar();
        
        printf("Insira seu numero de telefone\n");
        scanf("%[^\n]", novoCadastro.cadtelefone);
        getchar();
        
        do{
        printf("digite o numero de prioridade do atendimento\n");
        printf("urgência baixa - verde (1)\n");
        printf("urgência media - amarelo (2)\n");
        printf("urgência alta - vermelho (3)\n");
        scanf("%d", &novoCadastro.cor);
        }
        while(novoCadastro.cor>3 || novoCadastro.cor<1);
        getchar();
        
        inserir_paciente(novoCadastro, clinica); // colocar os dados do paciente no hospital
}

void listar_pacientes(HOSPITAL clinica){
    int i;
    for(i=0;i<clinica.ult;i++){
        printf("Posicao do paciente na fila: %d\n", clinica.ult);
        printf("Nome do paciente: %s\n", clinica.indice[i].nomePaciente);
        printf("Descricao do problema: %s\n", clinica.indice[i].descricaoProblema);
        printf("Data de inclusao: %s\n", clinica.indice[i].dataDeInclusao);
        printf("cadasto de cpf: %s\n", clinica.indice[i].cadcpf);
        printf("cadastro de telefone:%s\n", clinica.indice[i].cadtelefone);
        if(clinica.indice[i].cor==1){
        printf("urgencia de atendimento baixa - VERDE\n");
    }
    else if(clinica.indice[i].cor==2){
        printf("urgencia de atendimento media - AMARELO\n");
    }
    else{
        printf("urgencia de atendimento alta - VERMELHO\n");
    }
}}

int main(){
    PACIENTE novoCadastro;
    HOSPITAL clinica;
    int opcao;
    
    clinica.ult = 0;
    
    do{
	 printf("**************************\n");
     printf("*          menu          *\n");
     printf("*  1-Registrar paciente  *\n");
	 printf("*  2-listar pacientes    *\n");
     printf("*         3-Sair         *\n");
     printf("**************************\n");
     
     scanf("%d", &opcao);
     getchar();  
     
     switch(opcao){
        case 1:
        cadastrar_paciente(novoCadastro, &clinica);
        break;
        
        case 2:
        listar_pacientes(clinica);
        break;
        
	}
    } while(opcao!=3);
    
}






