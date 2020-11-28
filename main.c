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

int tot_veiculos = TOT_VEICULOS;    //total de veículos que podem ser cadastrados usado para calculos
int vagas_livres = 3;               //baseado no total de vagas e usado para no cadastro e impressao de listacalculos 
int ano;                            //usado para comparacao nas funcoes de listagem
int modelo;                            //usado para comparacao nas funcoes de listagem

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
                imprime_lista_veiculo_ano(1); //tipo 1 verifica se e igual
                break;
            case 4:
                system("cls");
                printf("-4---listar veiculos->-ano--\n");
                imprime_lista_veiculo_ano(2); //tipo 2 veifica se e maior
                break;
            case 5:
                system("cls");
                printf("-5---listar veiculos-modelo-\n");
                imprime_lista_veiculo_modelo();
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

void cadastrar(){
    printf("DESEJA REALIZAR CADASTRO? \t \t  DIGITE 1 PARA SIM E 0 PARA NAO.\n");
    scanf("%d", &aceitar);

    if(aceitar == NAO){
        //retorna ao menu
        voltar_ao_menu(aceitar);

    } else if( aceitar == SIM) {
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
            vagas_livres--; //diminui uma vaga pois houve cadastro
            //printf("\n\n ha %d vagas livres para cadastro\n", vagas_livres);

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

void listar_veiculo(int nova_lista){
   for(int i = 0; i < nova_lista; i++){
        if(veiculo[i].ano_fabricacao != 0){ //diferente de zero pois zero indica que nenhum foi cadastrado.
            imprime_veiculo(i);
        }
    }
    
}

void imprime_lista_veiculo(){
    if(vagas_livres == TOT_VEICULOS){ //ou seja: nao ha veiculos cadastrados
        printf("\n-------------------------------------------\n");
        printf("-------TODAS AS VAGAS ESTAO LIVRES---------\n");
        printf("-------------------------------------------\n");
        printf("\n");
        voltar_ao_menu(aceitar);
    
    } else {
        listar_veiculo(TOT_VEICULOS); //passa TOT_VEICULOS como parâmetro para função pois a lista é baseada na lista original, checando apenas se o índice a ser impresso possui dados ou não.
        voltar_ao_menu(aceitar);
	
    } 

}

void imprime_lista_veiculo_ano(int tipo){
    int i = 0;
    int count = 0;
	
    if(vagas_livres == TOT_VEICULOS){
        printf("\n-------------------------------------------\n");
        printf("-------TODAS AS VAGAS ESTAO LIVRES---------\n");
        printf("-------------------------------------------\n");
        printf("\n");
        voltar_ao_menu(aceitar); //teste
    } else {
       
       //mostra o ano de cada veículo para que o usuario possa escolher qual ano desejado...
        printf("\n VEICULOS DISPONIVEIS PARA LISTAR\n");
        printf("|");
        for(int i = 0; i < TOT_VEICULOS; i++){
            if(veiculo[i].ano_fabricacao != 0){ //diferente de zero pois zero indica que nenhum foi cadastrado.
                printf("  %d  |", veiculo[i].ano_fabricacao);
            }
        }
        printf("\n");

        printf("\ndigite o ano do veiculo -- formato: aaaa --\n");
        scanf("%d", ano);

        if(tipo == 1){
            for(i = 0; i < TOT_VEICULOS; i++){
                if (ano == veiculo[i].ano_fabricacao){
                    imprime_veiculo(i);
                    count++;
                }
            }

        } else if(tipo == 2){
            for(i = 0; i < TOT_VEICULOS; i++){
                if (ano < veiculo[i].ano_fabricacao){
                    imprime_veiculo(i);
                    count++;
                }
            }
        }


        if(count == 0){
            printf("Não foi encontrado o ano desejado...");
        } 

        voltar_ao_menu(aceitar); //teste
    }    
        
}

void imprime_lista_veiculo_modelo(){
    int i = 0;
    int count = 0;
	
    if(vagas_livres == TOT_VEICULOS){
        printf("\n-------------------------------------------\n");
        printf("-------TODAS AS VAGAS ESTAO LIVRES---------\n");
        printf("-------------------------------------------\n");
        printf("\n");
        voltar_ao_menu(aceitar); //teste
    } else {
       
       //mostra o ano de cada veículo para que o usuario possa escolher qual ano desejado...
        printf("\n VEICULOS DISPONIVEIS PARA LISTAR\n");
        printf("|");
        for(int i = 0; i < TOT_VEICULOS; i++){
            if(veiculo[i].modelo != NULL){ //diferente de zero pois null indica que nenhum foi cadastrado.
                printf("  %d  |", veiculo[i].modelo);
            }
        }
        printf("\n");

        printf("\ndigite o modelo do veiculo:\n");
        scanf("%d", modelo);

        for(i = 0; i < TOT_VEICULOS; i++){
            if (modelo == veiculo[i].modelo){
                imprime_veiculo(i);
                count++;
            }
        }

        if(count == 0){
            printf("Não foi encontrado o modelo desejado...");
        } 

        voltar_ao_menu(aceitar); //teste
    }    
        
}