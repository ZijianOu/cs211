#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
bool debugMode;

typedef struct nodeStruct{
  char *name;
  int NumBurgers;
  int NumSalads;
  bool InRes;
  struct nodeStruct *next;
}node;

// typedef struct orderlist{
//   node* head;
// }list;

void clearToEoln();
int getNextNWSChar();
int getPosInt();
char *getName();
void printCommands();
int main (int argc, char **argv);

void doAdd ( node** head);
void doCallAhead ( node** head);
void doWaiting ( node* head);
void doRetrieve ( node** head);
void doList ( node* head);
void doDisplay ( node* head);
void doEstimateTime( node* head);

void addToList(node **head, char* name,int NumBurgers, int NumSalads, bool InRes);
bool doesNameExist(node* head, char* name);
bool updateStatus(node*head, char* name);
char* retrieveAndRemove(node** head, int NumBurgers, int NumSalads);
int countOrdersAhead(node* head, char*name);
void displayOrdersAhead(node* head, char* name);
void displayListInformation(node* head);
int displayWaitingTime(node* head, char* name);