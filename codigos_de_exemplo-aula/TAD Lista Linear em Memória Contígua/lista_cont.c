#include "lista_cont.h"
#include <stdio.h>

// Funcao que cria uma lista
void criaLista(ListaCont *lista){
   lista->ini = 0;
   lista->fim = 0;
}

// Funcao que destroi uma lista
void destroiLista(ListaCont *lista){
   lista->ini = 0;
   lista->fim = 0;
}

// Funcao que retorna a cardinalidade de uma lista
int tamanhoLista(ListaCont lista){
   return lista.fim - lista.ini;  
}

// Funcao que insere um nodo em uma posicao de uma lista
int insereLista(ListaCont *lista, NodoLCont nodo, int pos){
   int indice;
   int tamLista = tamanhoLista(*lista);
   
   if (TAM_MAX_LISTA == tamLista) // verifica se a lista esta cheia
      return 0;
      
   if (pos < lista->ini || pos > lista->fim) // verifica se a posicao eh valida
      return 0;

   for (indice = lista->fim-1; indice >= pos; indice--)
      lista->nodos[indice+1] = lista->nodos[indice];
   lista->fim += 1;
   lista->nodos[pos] = nodo;
   
   return 1;
}

// Funcao que remove um nodo em uma posicao de uma lista
int removeLista(ListaCont *lista, int pos){
   int indice;
   
   if (pos < lista->ini || pos >= lista->fim) // verifica se a posicao eh valida
      return 0;

   // Sempre puxa tudo para o comeco
   for (indice = pos; indice < lista->fim; indice++) 
      lista->nodos[indice] = lista->nodos[indice+1];
   lista->fim -= 1;   
   
   return 1;
}

// Funcao que resgata um nodo de uma posicao de uma lista
NodoLCont buscaLista(ListaCont lista, int pos){
   if (pos < lista.ini || pos >= lista.fim){ // verifica se a posicao eh valida
      NodoLCont auxiliar;
      auxiliar.matricula = -1; // um nodo com matricula = -1 eh um nodo invalido
      return auxiliar;
   }
   return lista.nodos[pos];
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLCont buscaInfoLista(ListaCont lista, int matricula){
   int indice;
   for (indice = lista.ini; indice < lista.fim; indice++)
      if(lista.nodos[indice].matricula == matricula)
         return lista.nodos[indice];
   NodoLCont auxiliar;
   auxiliar.matricula = -1; // um nodo com matricula = -1 eh um nodo invalido
   return auxiliar;
}

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaCont lista){
   int i;
   printf("-----------------------------------------\n");
   for (i = lista.ini; i < lista.fim; i++)
      printf("%d | %s (%s)\n", lista.nodos[i].matricula,
                               lista.nodos[i].nome,
                               lista.nodos[i].email);
   printf("-----------------------------------------\n");
}
   

