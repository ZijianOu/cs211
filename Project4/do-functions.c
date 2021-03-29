#include "allfunctions.h"

void doAdd (node** head)
{
 /* get number of burgers ordered from input */
 int NumBurgers = getPosInt();
 if (NumBurgers < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(); 
 if (NumSalads < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    return;
   }  

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command format: a <# burgers> <# salads> <name>\n");
    free(name);
    return;
   }

  if(doesNameExist(*head, name)!=true){
     printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);

     addToList(head, name, NumBurgers, NumSalads, true);
   }
   else{
    printf("An order with the given name already exists. Try another name.\n");
   }
 //addToList(head, name, NumBurgers, NumSalads, true);
 // add code to perform this operation here
}


void doCallAhead (node** head)
{
   /* get number of burgers ordered from input */
 int NumBurgers = getPosInt();
 if (NumBurgers < 0)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 0\n");
    printf ("Call-ahead command format: c <# burgers> <# salads> <name>\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(); 
 if (NumSalads < 0)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 0\n");
    printf ("Call-ahead command format: c <# burgers> <# salads> <name>\n");
    return;
   }  


 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command format: c <# burgers> <# salads> <name>\n");
    free(name);
    return;
   }
 if(doesNameExist(*head, name)){
  printf("An order with the given name already exists. Try another name.\n");
  return;
 }


 printf ("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
 addToList(head, name, NumBurgers, NumSalads, false);
 // add code to perform this operation here
}

void doWaiting (node*head)
{
 /* get order name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Wait command format: w <name>\n");
    free(name);
    return;
   }
 if(!doesNameExist(head, name)){
  printf("No match found for the given name.Try again!\n");
  return;
 }

 printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
 updateStatus(head, name);

 // add code to perform this operation here
}

void doRetrieve (node** head)
{
 /* get info of prepared food ready on the counter from input */
 int PreparedBurgers = getPosInt();
 if (PreparedBurgers < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command format: r <# burgers> <# salads>\n");
  
    return;
   }

 int PreparedSalads = getPosInt();
 if (PreparedSalads < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command format: r <# burgers> <# salads>\n");
    return;
   }   

 clearToEoln();
 printf ("Retrieve and remove the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);
retrieveAndRemove(head, PreparedBurgers, PreparedSalads);
 // add code to perform this operation here
}

void doList (node* head)
{
 /* get order name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command format: l <name>\n");
      free(name);

    return;
   }

   if(doesNameExist(head, name)==true){
      printf ("Order for \"%s\" is behind the following orders\n", name);

    displayOrdersAhead(head, name);
   }
   else{
 //printf ("Starting Fast Food Order Management Program\n\n");

       //  free(head);
    printf("No match found for the given name.Try again!\n");
   }
     //free(name);

 // add code to perform this operation here
}
 
void doDisplay (node* head)
{
   //char *name = getName();
 // if (NULL == name)
 //   {
 //    printf ("Error: List command requires a name to be given\n");
 //    printf ("List command format: l <name>\n");
 //    return;
 //   }
 clearToEoln();
 printf ("Display information about all orders\n");
// if(doesNameExist(head, name)==true){
   displayListInformation(head);
 // }
 // else{
 //      printf("No match found for the given name. Try again!\n");
 // }
}
  
 // add code to perform this operation here



void doEstimateTime(node* head)
{
  /* get order name from input */
 
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Time command requires a name to be given\n");
    printf ("Time command format: t <name>\n");
    free(name);
    return;
   }

   if(doesNameExist(head, name)==true){
     int mins = displayWaitingTime(head, name);
    printf(" Estimated wait time for %s is %d minutes.\n", name , mins);  
   }
   else{
    printf("No match found for the given name.Try again!\n");
   }
  //free(name);
  // add code to perform this operation here 
  // int mins = displayWaitingTime(head, name);
  // printf(" Estimated wait time for %s is %d minutes:\n", name , mins);  

}