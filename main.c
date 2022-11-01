#include <stdio.h>
#include <stdlib.h>
typedef struct player {
   char Name[20] ;
   char Place ;
   int Number ;
   struct player *next ;
}player;
player * head = NULL ;
player*current = NULL;
int count= 0;
// add a new player
player * new_Player(char Name[20],char Place,int Number) {
    player*new_player;
   new_player = (player*)malloc(sizeof(player));
   new_player->Name[20] = Name;
   new_player->Place = Place;
   new_player->Number = Number;
   new_player->next = NULL;
   return new_player;
}
// add a new player in the first while the place at goolkeper
player * creat_team(char Name,char Place,int Number)
{   player*new_player;
   new_player = (player*)malloc(sizeof(player));
   new_player->Name[20] = Name;
   new_player->Place = 'G';
   new_player->Number = Number;
   new_player->next = head;
   head = new_player ;
   return head ;
}
player * add_player_in_Last(char Name,char Place,int Number) {
   player*new_player;
   current = head ;
   new_player = (player*)malloc(sizeof(player));
   new_player->Name[20] = Name;
   new_player->Place = Place;
   new_player->Number = Number;
   while(current->next != NULL )
      current =current->next;
   current->next = new_player;
   new_player->next = NULL;
   current = new_player;
   return head ;
}
player * add_player_in_positon (char Name,char Place,int Number)
{
   player*new_player;
   player*curr = head ;
   new_player = (player*)malloc(sizeof(player));
   new_player->Name[20] = Name;
   new_player->Place = Place;
   new_player->Number = Number;
   while(curr->Place!= Place )
      curr =curr->next;

   new_player->next = curr->next;
   curr->next = new_player ;
   return head ;
}
player *remove_player(int Number) {
    player *current_node = head;
    player *prev_node;
    int cntouer = 0;
    while ( current_node != NULL) {
        if (current_node->Number== Number) {
            if (current_node == head) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return head ;}

void afichage(player *head) {
    player *print_node = head ;
    {
        while(print_node != NULL) {
            printf(" THE NAME IS : %s \n ",print_node->Name);
            printf(" THE PLASE IS : %c \n THE NUMBER IS  : %d ",print_node->Place,print_node->Number);
            print_node = print_node->next;
            }
        }
}
player *Exchange (player * p1 ,int Number){
    player *current = head;
    while (current->Number!=Number)
        current=current->next;
    current->Name[20]=p1->Name[20];
    current->Number=p1->Number;
    current->next=p1->next;
    return head;
}
int counter (){

    player *current = head;
    while (current->next!=NULL){
        current=current->next;
        count++;
    return count ; }}
int main()
{



    char Name[20];
    char tap[3] = "YES";
    int Number;
    char place;
    int n;
    head = creat_team("FKKF","G",1);


    int chose;

 while (tap == "YES" || "yes" ) {
        printf("\n =======================\n");
        printf("\n add the your chose :\n");
        printf("\n 1. Add Player        \n");
        printf("\n 2. Remove PLayer     \n");
        printf("\n 3. Exchange PLayer   \n");
        printf("\n 4. afichage the list \n");


        printf("\n chose an opsion  | 1 TO 4 | : ");
        scanf("%d",&chose);
            if (chose == 1 ) {//add the player
                printf(" Enter a Name of the Player : ");
                scanf("%s",Name);
                printf(" Enter the Place of the Player : ");
                scanf(" %c",&place);
                printf(" Enter the Number of the Player : ");
                scanf("%d",&Number);
                if (place=='G'){
                    head = creat_team(Name,place,Number);
                    printf("Number %s is now added to the list\n ", Name);
                    printf("\n ============================== \n ");
                    printf("=> \n you want add anothor chose tap - YES - : ");
                    scanf("%s",tap);
                    }
                else if(place=='T'){
                    head = add_player_in_Last(Name,place,Number);
                    printf("Number %s is now added to the list\n ", Name);
                    printf(" \n you want add anothor chose tap - YES - :");
                    scanf("%s",tap);
                    }
                else
                    printf(" no  Potition");

            }
            if (chose == 2 ) { //remove_player player
                printf(" Enter the Number of the Player : ");
                scanf("%d",&Number);
                remove_player(Number);
                printf("\n you want add anothor chose tap - YES - :");
                scanf("%s",tap);

            }
            if (chose == 3) {
                printf(" Enter a Name of the Player : ");
                scanf("%s",Name);
                printf(" Enter the Place of the Player : ");
                scanf(" %c",&place);
                printf(" Enter the Number of the Player : ");
                scanf("%d",&Number);
                player *p1 =  new_Player(Name,place,Number);
                printf("donne the number of the player want to delate : ");
                scanf("%d",&n);
                Exchange(p1,n);
                printf(" \n you want add anothor chose tap - YES - :");
                scanf("%s",tap);
}

            if (chose == 4 )
                afichage(head);
               printf(" \n THE NUMBER PLAYER IS : %d",counter());

                printf("\n you want add anothor chose tap - YES - :");
                scanf("%s",tap);


 }



    return 0;
}
