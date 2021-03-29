#include "allfunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool debugMode;

void addToList(node **head, char* name,int NumBurgers, int NumSalads, bool InRes){
  node *newNode = (node*)malloc(sizeof(node));
  newNode->name = name;
  newNode->NumSalads=NumSalads;
  newNode->NumBurgers=NumBurgers;
  newNode->InRes=InRes;
  newNode->next=NULL;
  if(*head!=NULL){
      if(debugMode){
        printf( "Visiting node %s with values %d and %d\n", (*head)->name, (*head)->NumBurgers, (*head)->NumSalads);
      }
    }
  if(*head==NULL){
    *head=newNode;
  }
  else{
    //if(debugMode){//------------------------------DEBUG MODE
    //   node* prev=NULL;
       node* curr=*head;
    while(curr->next!=NULL){
      // if(debugMode){
      //   printf( "Visiting node %s with values %d and %d\n", curr->name, curr->NumBurgers, curr->NumSalads);
      // }
      curr=curr->next;
      if(debugMode){
        printf( "Visiting node %s with values %d and %d\n", curr->name, curr->NumBurgers, curr->NumSalads);
      }

    }
    curr->next=newNode;
    //   prev=curr;
    //   curr=curr->next;
    // //}
    //    prev->next=newNode;
  //}
  }
}


bool doesNameExist(node* head, char* name){
  while(head!=NULL){
    //if(debugMode==true){
//printf("%s \n", head->name);
//printf("%s \n", name);

      if(strcmp(head->name, name)==0){
        return true;
      }

      head=head->next;
    //}
  }
  //printf("No match found for the given name.Try again!\n");
  return false;
}

bool updateStatus(node*head, char* name){
  //bool InRes;
  node* curr=head;
  while(curr!=NULL){
    if(debugMode==true){
        printf( "Visiting node %s with values %d and %d\n", curr->name, curr->NumBurgers, curr->NumSalads);

    }

      if(strcmp(curr->name, name)==0){
        if(curr->InRes==true){
          return false;
        }
        else{
          curr->InRes=true;
          //printf("Call-ahead order %s is now waiting in the restaurant\n", curr->name);
          return true;
        }
      }
      curr=curr->next;  //------------------------------DEBUG MODE
    
  }
  return false;
}

char* retrieveAndRemove(node** head, int NumBurgers, int NumSalads){
  node *prev=NULL;
  node *curr=*head;
  char* Name;
  //bool InRes;
    //if(curr==*head){

      if(NumBurgers>=curr->NumBurgers && NumSalads>=curr->NumSalads && curr->InRes==true){
        *head=curr->next;
        Name=curr->name;
        free(curr);
        return Name;
      }
    // else{
    //   prev->next=curr->next; //------------------------------DEBUG MODE
    //   free(curr);
    // }
  while(curr!=NULL){
    if(debugMode==true){
        printf( "Visiting node %s with values %d and %d\n", curr->name, curr->NumBurgers, curr->NumSalads);
    }
      if(NumBurgers>=curr->NumBurgers && NumSalads>=curr->NumSalads && curr->InRes==true){
        //*head=curr->next;
        Name=curr->name;
        prev->next=curr->next;
        free(curr);
        return Name;
      }
      else{
        prev=curr;
        curr=curr->next;
      }
  }
  if(curr==NULL){
    printf("No matching orders found.\n");
    return NULL;
  }
  //printf("Retrieve and remove the first group that can pick up the order of %d burgers and %d salads\n", NumBurgers, NumSalads);
  
   //  if(debugMode==true){
   //      printf( "Visiting node %s with values %d and %d\n", curr->name, curr->NumBurgers, curr->NumSalads);
   //  }
   //  if(curr==*head){
   //    *head=(*head)->next;
   //    free(curr);
   //  }
   //  else{
   // //char Name = curr->name;
   // //prev=curr;
   //    prev->next=curr->next; //------------------------------DEBUG MODE
   //    free(curr);
   //  }
  
  return Name;
}


int countOrdersAhead(node* head, char*name){
  int  counter=0;
  //node* curr=head;
  while(strcmp(head->name, name)!=0){
    counter++;
    head=head->next;
  }
  return counter;
}


void displayOrdersAhead(node* head, char* name){
  int counter = countOrdersAhead(head, name);
  node *curr = head;
  //printf("%d\n", counter);
  //while(curr!=NULL){

    for(int i =0;i<counter;i++){
      
        printf(" %s: %d burgers and %d salads \n", curr->name, curr->NumBurgers, curr->NumSalads);
        curr=curr->next;
    }
  
}
void displayListInformation(node* head){
  while(head!=NULL){
    if(head->InRes){
      printf("%s: %d burgers and %d salads, currently in the restaurant.\n", head->name, head->NumBurgers, head->NumSalads);
    }
    else{
      printf("%s: %d burgers and %d salads, currently not in the restaurant.\n", head->name, head->NumBurgers, head->NumSalads);
    }
    head=head->next;
  }
}

int displayWaitingTime(node* head, char* name){
  int time=0;
  //int counter = countOrdersAhead(head, name);
    // if(debugMode==true){
    //     printf( "Visiting node %s with values %d and %d\n", head->name, head->NumBurgers, head->NumSalads);

    // }
    //for(int i =0;i<counter;i++){
    //while(head->name!=name){
      while(strcmp(head->name, name)!=0){
      // if(debugMode){
      //   printf( "Visiting node %s with values %d and %d\n", head->name, head->NumBurgers, head->NumSalads);
      // }
      time+=head->NumBurgers*5 + head->NumSalads*2;
      if(debugMode){
        printf( "Visiting node %s with values %d and %d\n", head->name, head->NumBurgers, head->NumSalads);
      }
      head=head->next;    //------------------------------DEBUG MODE
      // if(debugMode){
      //   printf( "Visiting node %s with values %d and %d\n", head->name, head->NumBurgers, head->NumSalads);
      // }
    }
  
  return time;
} 