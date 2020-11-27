#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//tratar retorno ao menu que continua marcando opcao invalida               ok
//tratar contagem de vagas ocupadas no vetor que armazena os veiculos       ok
//cadastrar veiculos                                                        ok
//ordenar veiculos por ano
//listar veiculos
//listar veiculos ano selecionado
//listar veiculos ano maior que o selecionado
//listar veiculos por modelo

int aceitar;
const NAO = 0;
const SIM = 1;

int entrada = 0;
const VALIDA = 1;
const INVALIDA = 0;

char recebe_option;
int option = 0;
const TOT_VEICULOS = 3;             //total de veículos que podem ser cadastrados

int tot_veiculos = TOT_VEICULOS;               //total de veículos que podem ser cadastrados usado para calculos
int vagas_livres = TOT_VEICULOS;               //baseado no total de vagas e usado para calculos no cadastro e impressao de lista
int vaga_ocupada = 0;               //usado para calculos no cadastro
int nova_lista = 0;					//define tamanho de lista a ser impressa

//veiculo
typedef struct{
    char marca[15];
    char modelo[15];
    int  ano_fabricacao;
    char placa[10];

}Veiculo[3]; //linguagem C nao me permitiu lançar como vetor de structs com tamanho partindo de uma constante... não entendo um motivo, talvez seja limitacao da linguagem
Veiculo veiculo;

int main(){
    system("cls");

    entrada = VALIDA;
    printf("Ola este eh um cadastro de veiculos! \n");
    printf("pode-se cadastrar e  consultar ate 10 veiculos...\n\n");

    menu();
    recebe_e_trata_entrada_menu();

    while(entrada == INVALIDA){
        system("cls");
        printf("\n----------------------------\n");
        printf("-------OPCAO INVALIDA-------\n");
        printf("----------------------------\n");
        printf("\n");
        menu();
        recebe_e_trata_entrada_menu();
    }


    if(entrada == VALIDA){
        switch(option){
            case 1:
                system("cls");
                printf("-1---cadastro de veiculo----\n");
                cadastrar();
                break;
            case 2:
                system("cls");
                printf("-2---listar veiculos--------\n");
                imprime_lista_veiculo();
                break;
            case 3:
                system("cls");
                printf("-3---listar veiculos---ano--\n");
                imprime_lista_veiculo_ano();
                break;
            case 4:
                system("cls");
                printf("-4---listar veiculos->-ano--\n");
                break;
            case 5:
                system("cls");
                printf("-5---listar veiculos-modelo-\n");
                break;
            case 100:
                system("cls");
                return 0;
                break;
        }
    }

    return 0;
}

void recebe_e_trata_entrada_menu(){

    scanf("%c", &recebe_option);

    if(recebe_option == 's'){
       recebe_option = toupper(recebe_option);
    }

        switch(recebe_option){

            case '1':
                option = 1;
                entrada = VALIDA;
                break;

            case '2':
                option = 2;
                entrada = VALIDA;
                break;

            case '3':
                option = 3;
                entrada = VALIDA;
                break;

            case '4':
                option = 4;
                entrada = VALIDA;
                break;

            case '5':
                option = 5;
                entrada = VALIDA;
                break;

            case 'S':
                option = 100;
                entrada = VALIDA;
                break;

            default:
                entrada = INVALIDA;
                break;
        }

    }

void menu(){
    printf("--------------------------------------\n");
    printf("---------------  MENU  ---------------\n");
    printf("--------------------------------------\n");
    printf("-1-----cadastro de veiculo------------\n");
    printf("-2-----listar veiculos-cadastrados----\n");
    printf("-3-----listar veiculos---ano----------\n");
    printf("-4-----listar veiculos->-ano----------\n");
    printf("-5-----listar veiculos-modelo---------\n");
    printf("--------------------------------------\n");
    printf("-S-----sair do sistema----------------\n");
    printf("--------------------------------------\n");
}

void voltar_ao_menu(aceitar){
     printf("DESEJA VOLTAR AO MENU PRINCIPAL? \t \t  DIGITE 1 PARA SIM E 0 PARA NAO.\n");
     scanf("%d", &aceitar);
    if(aceitar == NAO){
        //encerra programa
        return 0;

    } else if( aceitar == SIM) {
        //retorna ao menu
        system("cls");
        main();
    }
}

void calcular_vagas_livres(){
    //calculo para saber o total de vagas livres para cadastro
    for(int i = 0; i<TOT_VEICULOS;i++){
        if (veiculo[i].ano_fabricacao != vaga_ocupada){
            vagas_livres--;
        }
    }
}

void cadastrar(){
    printf("DESEJA REALIZAR CADASTRO? \t \t  DIGITE 1 PARA SIM E 0 PARA NAO.\n");
    scanf("%d", &aceitar);

    if(aceitar == NAO){
        //retorna ao menu
        voltar_ao_menu(aceitar);

    } else if( aceitar == SIM) {
       calcular_vagas_livres();

        //mensagem de quando todas vagas estiverem ocupadas...
        if(vagas_livres == 0){
            printf("\n-------------------------------------------\n");
            printf("-------TODAS AS VAGAS ESTAO OCUPADAS-------\n");
            printf("-------------------------------------------\n");
            printf("\n");
            voltar_ao_menu(aceitar);

        } else {
            printf("\n\n ha %d vagas livres para cadastro\n", vagas_livres);
            printf("-------------------------------------\n");

            //calcula a posicao a receber os dados com base o no  calculo de vagas livres:
            int posicao_de_cadastro = 0;

            if(TOT_VEICULOS == vagas_livres){
                posicao_de_cadastro = 0; //guarda na primeira posicao
            } else {
                //calcula posicao vazia
                posicao_de_cadastro = TOT_VEICULOS - vagas_livres;
            }



            //inicia cadastro de um veiculo
            for(int i = 0; i <= 4; i++){ //percorre os 4 atributos de veiculo
                switch(i){
                    case 1:
                        printf("digite a marca do veiculo\n");
                        scanf("%s", &veiculo[posicao_de_cadastro].marca);
                        break;
                    case 2:
                        printf("digite a modelo do veiculo\n");
                        scanf("%s", &veiculo[posicao_de_cadastro].modelo);
                        break;
                    case 3:
                    printf("digite a ano do veiculo -- formato: aaaa --\n");
                        scanf("%d", &veiculo[posicao_de_cadastro].ano_fabricacao);
                        break;
                    case 4:
                        printf("digite a placa do veiculo -- formato: xxx-yyyy --\n");
                        scanf("%s", &veiculo[posicao_de_cadastro].placa);
                        break;
                }
            }
            printf("\n\nveiculo cadastrado: \n");
            imprime_veiculo(posicao_de_cadastro);
            //ordenar_veiculos();

            voltar_ao_menu(aceitar);
        }


    }

}

/*
void ordenar_veiculos(){
    //realizar ordenacao da lista de veiculos
    int alterado = SIM; //0 = false; 1 = true   variavel de controle para saber se o item mudou de lugar
    while (alterado != NAO){
        int j = 0;
            struct Veiculo veiculo_aux;
        for(int i = 0; i < tot_veiculos; i++){
            veiculo_aux = veiculo[i]
            int teste = 0; //testa pra saber se o proximo veiculo tem o ano maior ou menor
            teste = veiculo[i].ano_fabricacao < veiculo[i+1].ano_fabricacao;

            if(teste == INVALIDA){ //se o ano de fabrica��o n�o for menor dever� haver a troca.
                veiculo[i] = veiculo[i+1];
                veiculo[i+1] = veiculo_aux;
                j++; //variavel de controle pra saber se houve troca.
            }
        }
        if(j == 0){
                //enquanto houver trocas de posicao no la�o acima ele deve ser repetir, quando n�o houver mais motivo para repetir, ou seja, doas trocas foram feitas, entao para de verificar.
           alterado = NAO;
        }
    }

}
*/
void imprime_veiculo(int i){
    printf("\n");
    printf("---------[%d]--------\n", i);
    printf("marca       %s   \n", veiculo[i].marca);
    printf("modelo:     %s   \n", veiculo[i].modelo);
    printf("ano:        %d   \n", veiculo[i].ano_fabricacao);
    printf("placa:      %s   \n", veiculo[i].placa);
    printf("--------------------\n");

}

void listar_veiculo(){
   for(int i = 0; i < TOT_VEICULOS; i++){
        if(veiculo[i].ano_fabricacao != 0){ //diferente de zero pois zero indica que nenhum foi cadastrado.
            imprime_veiculo(i);
        }
    }
    
}

void imprime_lista_veiculo(){
    calcular_vagas_livres();
        	
	if(vagas_livres == TOT_VEICULOS){ //ou seja: nao ha veiculos cadastrados
        printf("\n-------------------------------------------\n");
        printf("-------TODAS AS VAGAS ESTAO LIVRES---------\n");
        printf("-------------------------------------------\n");
        printf("\n");
        voltar_ao_menu(aceitar);
    
    } else {
        listar_veiculo();
        voltar_ao_menu(aceitar);
	
    } 

}

void imprime_lista_veiculo_ano(){
    int i = 0;
	int ano;
	
	
    if(vagas_livres == TOT_VEICULOS){
        printf("\n-------------------------------------------\n");
        printf("-------TODAS AS VAGAS ESTAO LIVRES---------\n");
        printf("-------------------------------------------\n");
        printf("\n");
        cadastrar();
    } else {
        printf("\n VEICULOS DISPONIVEIS PARA LISTAR\n");
        for(i = 0; i < TOT_VEICULOS; i++){
            if(veiculo[i].ano_fabricacao != 0){
				printf("\n");
				printf("- ano: %d   \n", veiculo[i].ano_fabricacao);
				nova_lista++;
			}			
        }

        printf("\ndigite a ano do veiculo -- formato: aaaa --\n");
        scanf("%d", ano);

        for(i = 0; i < nova_lista; i++){
            if (ano == veiculo[i].ano_fabricacao && veiculo[i].ano_fabricacao != 0){
                printf("\n");
                imprime_veiculo(i);
                printf("\n");
            }
        }
        voltar_ao_menu(aceitar); //teste
    }

}