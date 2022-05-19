#include <stdio.h>
#include <stdlib.h>

struct list{
   int value;
   struct list *next;
};

struct list *head;

void append();
void printar();

void append(int contador)
{
   struct list *new = malloc(sizeof(struct list));

   scanf("%d",&new->value);

   if(contador == 0){
      head = new;
   }else{
      new->next = head;
      head = new;
   }

}

void printar()
{
   struct list *aux = head;

   while(aux != NULL){
      printf("%d\n",aux->value);
      aux = aux->next;
   }
}

int main () 
{

   head = (struct list*)malloc(sizeof(struct list));
   int escolha = 0;
   int count = 0;
   while(escolha != 5){
      scanf("%d",&escolha);
      if(escolha == 1){
         append(count);
         count ++;
      }else if(escolha == 4){
         printar();
      }   
      else if(escolha == 5){
         printf("vai timbora triste\n");
         break;
      }

   }
}