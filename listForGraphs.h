#include <stdio.h>
#include <stdlib.h>

//Struct que representa um elemento de uma lista.
typedef struct linked_list
{
    //Valor do elemento.
    int destino;
    int custo;
    //Ponteiro para o proximo elemento na lista.
    struct linked_list* next;
} llist;

//Insere elemento na primeira posicao de uma lista.
void laddToStart(llist** aList, int add, int add2)
{
    //Criando elemento da lista. newElement e um ponteiro para esse elemento
    llist* newElement = 
    (llist*) malloc(sizeof(llist));
    
    //Modificando informacao do elemento
    newElement->destino = add; //ok
    newElement->custo = add2;

    newElement->next = *aList; //Novo elemento aponta para o segundo elemento (que antes era o primeiro)
    *aList = newElement; //Ponteiro apontado por aList (inicio da cadeia) comeca a apontar para esse novo elemento
}

//Insere elemento na posicao da lista indicada.
void linsert(llist** aList, int index, int add, int add2)
{
    //Criando elemento da lista. newElement e um ponteiro para esse elemento
    llist* newElement = 
    (llist*) malloc(sizeof(llist));
    
    //Modificando informacao do elemento
    newElement->destino = add;
    newElement->custo = add2;
    
    //Elementos analisados durante busca
    llist* before = NULL;
    llist* current = *aList;
    
    for(int i = 0; i <= index; i++)
    {
        //Encontrado
        if(i == index)
        {
            newElement->next = current; //O novo elemento passa a apontar para o que esta no indice
            
            //O anterior passa a apontar para o novo elemento
            if(index != 0) before->next = newElement; //Mudando o ponteiro do anterior para o posterior
            else *aList = newElement; //Caso o elemento seja o primeiro da lista, mudamos a quem aponta o ponteiro inicial
        }
        //Nao Encontrado
        else
        {
            before = current;
            current = current->next;
        }
    }
}

//Troca o valor do elemento na posicao da lista indicada.
void lchange(llist** aList, int index, int change, int change2)
{
    //Elementos analisados durante busca
    llist* current = *aList;
    for(int i = 0; i <= index; i++)
    {
        //Encontrado
        if(i == index)
        {
            current->destino = change;
            current->custo = change2;
        }
        //Nao Encontrado
        else
        {
            current = current->next;
        }
    }
}

//Apaga um elemento numa posicao da lista
void lerase(llist** aList, int destino, int custo)
{
    llist* before = NULL;
    llist* current = *aList;
    for(int i = 0; current != NULL; i++)
    {
        //Encontrado
        if(current->destino == destino && current->custo == custo)
        {
            if(i != 0) before->next = current->next; //Mudando o ponteiro do anterior para o posterior
            else *aList = current->next; //Caso o elemento seja o primeiro da lista, mudamos a quem aponta o ponteiro inicial
            free(current); //Apagando o atual da memoria
          break;
        }
        //Nao Encontrado
        else
        {
            before = current;
            current = current->next;
            if(current == NULL) break;
        }
    }

}

//Cria uma lista com elemento inicial de valor especificado.
llist* lcreate(int add, int add2)
{
    //Cria o ponteiro para o primeiro elemento da lista encadeada
    llist* l = (llist*) malloc(sizeof(llist));
    l->destino = add;
    l->custo = add2;
    l->next = NULL;
    return l;
}

//Retorna o valor de um elemento numa lista na posicao index.
int lget(llist* aList, int index)
{
    for(int i = 0; i <= index; i++)
    {
        if(i == index) return aList->destino;
        else aList = aList->next;
    }
}

//Retorna o ponteiro para um elemento numa lista com posicao index. Caso o elemento nao exista, retorna NULL.
llist* lgetPointer(llist* aList, int index)
{
    for (int i = 0; i <= index; i++)
    {
        if (i == index) return aList;
        else aList = aList->next;
    }
    return NULL;
}

//Retorna o indice do primeiro elemento de valor value. Retorna -1 caso nao exista.
int lfind(llist* aList, int value)
{
    for(int i = 0; aList != NULL; i++)
    {
        if(aList->destino == value) return i;
        else aList = aList->next;
    }
    return -1;
}

//Retorna o ponteiro do primeiro elemento de valor value. Retorna NULL caso nao exista.
llist* lfindPointer(llist* aList, int value)
{
    for (int i = 0; aList != NULL; i++)
    {
        if (aList->destino == value) return aList;
        else aList = aList->next;
    }
    return NULL;
}

//Imprime uma lista.
void lprint(llist* aList)
{
    printf("{");
    for(int i = 0; aList != NULL; i++)
    {
        if(aList->next != NULL)
            printf("%d (%d), ", aList->destino, aList->custo);
        else
            printf("%d (%d)", aList->destino, aList->custo);
        aList = aList->next;
    }
    printf("}");
}