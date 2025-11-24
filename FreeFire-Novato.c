#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct{
    char nome[30];
    char tipo[20];
    int quantidade;
}Item;

Item Mochila[10];

int quant = 0; // contador global de item
int remover = 999; // numero do item removido, só faz um.
void limpaentrada(){
    char entrada;
    while(
        (entrada = getchar()) != '\n' && entrada != EOF
    );
}

void pesquisa(){
    system("clear");
    if(quant == 0){
        printf("Não há itens na mochila ou nenhum foi cadastrado!\n");
        return;
    }
    
    char nomeitem[50];
    printf("Que item você deseja procurar?\n");
    scanf("%[^\n]", nomeitem);
    limpaentrada();

    for(int i = 0; i < 10; i++){ // busca linear simples
        if(strncmp(nomeitem, Mochila[i].nome, sizeof(nomeitem)) == 0){
            printf("O item está no slot %d.\n", i + 1);
        }else{
            printf("Não está no slot %d.\n", i + 1);
        }
    }
    usleep(500000);
    return;
}

void cadastrodeitem(){
    system("clear");
    char resposta[2];
    char temp[50];
    if(quant != 0){
        printf("Já existem itens cadastrados, você tem certeza de que quer recadastrar todos os itens?\n");
        // insert pergunta
    }

    if(remover != 999){

    for(int i = 0; i < 10; i++){ // busca linear simples, copiada do pesquisa
        if(strncmp("NULL", Mochila[i].nome, 20) == 0){
            printf("Item vazio encontrado no slot %d, deseja cadastrar? Y\\N\n", i + 1);
            scanf("%[^\n]", resposta);
            limpaentrada();

            if(strcmp(resposta, "N") == 0){
                return;
            }else{
        printf("Favor informar Nome do item #%d. (No máximo 30 caractéres.)\n", i + 1);
        scanf("%[^\n]", temp);
        strncpy(Mochila[i].nome, temp, 30);
        limpaentrada();

        printf("Favor informar Tipo do item #%d. (No máximo 20 caractéres.)\n", i + 1);
        scanf("%[^\n]", temp);
        strncpy(Mochila[i].tipo, temp, 20);
        limpaentrada();

        printf("Favor informar quantidade do item #%d na mochila do jogador.\n", i + 1);
        scanf("%d", &Mochila[i].quantidade);
        limpaentrada();
        return;
            }
        }
    }
    }

    
    printf("Quantos itens você quer cadastrar? (No máximo 10 itens.)\n");
    scanf("%d", &quant);
    limpaentrada();

    for(int i = 0; i < quant; i++){ 
        printf("Favor informar Nome do item #%d. (No máximo 30 caractéres.)\n", i + 1);
        scanf("%[^\n]", temp);
        strncpy(Mochila[i].nome, temp, 30);
        limpaentrada();

        printf("Favor informar Tipo do item #%d. (No máximo 20 caractéres.)\n", i + 1);
        scanf("%[^\n]", temp);
        strncpy(Mochila[i].tipo, temp, 20);
        limpaentrada();

        printf("Favor informar quantidade do item #%d na mochila do jogador.\n", i + 1);
        scanf("%d", &Mochila[i].quantidade);
        limpaentrada();
    }
    system("clear"); // limpar a tela, se não fica cheio demais
}

void vermochila(){
    system("clear");

    if(quant == 0){
        printf("Não há itens na mochila ou nenhum foi cadastrado!\n");
        return;
    }
    for(int i = 0; i < quant; i++){
        printf("Item #%d: %s\n", i + 1, Mochila[i].nome);
        printf("Item #%d: %s\n", i + 1, Mochila[i].tipo);
        printf("Item #%d: %d\n", i + 1, Mochila[i].quantidade);
        printf("------------\n");
    }
    printf("Pressione enter para sair da visualização.");
    scanf("%*d");
    system("clear");
}

void removeritem(){
    system("clear");
    if(quant == 0){
        printf("Não há itens na mochila!!\n");
        return;
    }
    printf("Qual item você quer remover?\n");
    scanf("%d", &remover);
    remover--;
    strcpy(Mochila[remover].nome, "NULL"); // troca o nome do item com NULL, poderia ser "removido" também.
    strcpy(Mochila[remover].tipo, "NULL");
    Mochila[remover].quantidade = 0;
    remover++; // meio irresponsável fazer isso, mas é pra ter o numero certo qnd for mostrar na tela.
    printf("Item #%d removido! Este espaço do inventário foi liberado e pode ser cadastrado outro item em seu lugar.\n", remover);
    usleep(500000);
}

void autocad(){ // auto cadastro de 10 itens aleatórios, porquê cadastrar os itens várias vezes só pra testar é cansativo. opção #6 (escondida) no menu.
    strcpy(Mochila[0].nome, "Clips de papel");
    strcpy(Mochila[0].tipo, "Utilitário");
    Mochila[0].quantidade = rand() % 10;
    strcpy(Mochila[1].nome, "Faca AK-47");
    strcpy(Mochila[1].tipo, "Arma corpo-a-corpo");
    Mochila[1].quantidade = rand() % 10;
    strcpy(Mochila[2].nome, "Lagrimas do mago Patolino");
    strcpy(Mochila[2].tipo, "Magia");
    Mochila[2].quantidade = rand() % 10;
    strcpy(Mochila[3].nome, "Bolo de pote");
    strcpy(Mochila[3].tipo, "Consumível");
    Mochila[3].quantidade = rand() % 10;
    strcpy(Mochila[4].nome, "Brigadeiro");
    strcpy(Mochila[4].tipo, "Consumível");
    Mochila[4].quantidade = rand() % 10;
    strcpy(Mochila[5].nome, "Ramal");
    strcpy(Mochila[5].tipo, "Comunicação");
    Mochila[5].quantidade = rand() % 10;
    strcpy(Mochila[6].nome, "Ratinho de estimação");
    strcpy(Mochila[6].tipo, "Companheiro");
    Mochila[6].quantidade = rand() % 10;
    strcpy(Mochila[7].nome, "Camundongo");
    strcpy(Mochila[7].tipo, "Inimigo");
    Mochila[7].quantidade = rand() % 10;
    strcpy(Mochila[8].nome, "Merthiolate");
    strcpy(Mochila[8].tipo, "Cura");
    Mochila[8].quantidade = rand() % 10;
    strcpy(Mochila[9].nome, "Machado");
    strcpy(Mochila[9].tipo, "Ferramenta");
    Mochila[9].quantidade = rand() % 10;
    quant = 10;
}

int main(){
    int saida = 1;
    int escolha = 0;
    do{
        printf("Bem-vindo ao desafio de mochila FreeFire, programado por JSF2006.\n");
        printf("O que você deseja fazer?\n1: Cadastrar itens\n2: Visualizar sua mochila\n3: Procurar um item\n4: Remover um item\n5: Sair do programa.\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                limpaentrada();
                cadastrodeitem();
            break;

            case 2:
                limpaentrada();
                vermochila();
            break;

            case 3:
                limpaentrada();
                pesquisa();
            break;

            case 4:
                limpaentrada();
                removeritem();
            break;

            case 5:
            saida = 0;
            break;

            case 6:
            autocad();
            break;

            default:
            break;
        }
    }while(saida == 1);
    
    system("clear");
    return 0;
}