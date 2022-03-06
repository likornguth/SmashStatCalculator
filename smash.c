#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "linkedlist.h"
#include <string.h>
struct fighter{
        
        char *name;
        char tier;
        double weight;
        double airspeed;
        double fallingspeed;
        double fastfall;
        double dash;
        double runspeed;
};

void printball(){
        FILE *fp = fopen("ball.txt", "r");
        char chunk[100];

        while(fgets(chunk, sizeof(chunk), fp) != NULL){
                fputs(chunk, stdout);
        }
        printf("\n");
        fclose(fp);
}

int comp(struct fighter *p1,struct fighter *p2, char armed, char terrain){
        int speed1 = p1 -> runspeed + p1 ->dash;
        int speed2 = p2 -> runspeed + p2 -> dash;
        int sdiff = (speed1 - speed2)/100; // positive if player 1 is faster
        float weight1 = p1-> weight;
        float weight2 = p2 -> weight;
        float wdiff = weight1 - weight2; // positive if player 1 is heavier
        if(armed == 1){
                wdiff *= .5;
                sdiff *= 2;
        }
        
        if(terrain == 2){
                wdiff *= .25;
                sdiff = (p1->airspeed - p2->airspeed)/100;
        }
        else if(terrain == 4){
                sdiff *= .5;
        }

        return wdiff + sdiff;
}

void printstats(void *ptr){
        
        struct fighter *p = (struct fighter*)ptr;
        printf("%s:\n", p -> name);
        printf("tier: %c\n", p->tier);
        printf("weight: %f\n", p -> weight);
        printf("airspeed: %f\n", p-> airspeed);
        printf("falling speed: %f\n", p-> fallingspeed);
        printf("fastfall: %f\n", p-> fastfall);
        printf("dash: %f\n", p-> dash);
        printf("runspeed: %f\n", p->runspeed);

        printf("\n");
}
int myStrcmp(const void *f, const void *str1){
        char *charstr1 = (char *)str1;
        struct fighter* player = (struct fighter*)f;
        char *charstr2 = player->name;

        int i = 0;
        while(charstr2[i] != 0){
                if(charstr1[i] != charstr2[i]){
                        return -1;
                }
                i++;
        }
        printf("\n");
        return 0;
}

int main(int argc,char **argv){
        
        printball();
        struct fighter Bayonetta = {"Bayonetta",'D',81,1019,1770,2832,1936,1760};
        struct fighter Bowser = {"Bowser",'F',135,1155,1770,2832,2255,1971};
        struct fighter CaptainFalcon = {"CaptainFalcon",'E',104,1218,1865,2984,980,2552};
        struct fighter DonkeyKong = {"DonkeyKong",'E',127,1208,1630,2608,2090,1873};
        struct fighter Kirby = {"Kirby", 'F',79,840,1230,1968,1900,1727};
        struct fighter Link = {"Link", 'G',104,924,1600,3040,1980,1534};
        struct fighter Mario = {"Mario", 'E', 98,1208,1500,2400,1936,1760};
        struct fighter Peach = {"Peach",'D',89,1029,1190,1904,1826,1595};
        struct fighter Sonic = {"Sonic",'D',86,1208,1650,2640,2310,3850};
        struct fighter Pikachu = {"Pikachu",'B',79,957,1550,2480,1980,2039};

        struct fighter options[] = {Bayonetta, Bowser, CaptainFalcon, DonkeyKong, Kirby, Link, Mario, Peach, Sonic, Pikachu};
        int n = sizeof(options)/sizeof(options[0]);
        struct List list;
        initList(&list);
        for(int i = 0; i<n; i++){
                addFront(&list, options+i);
        }        

        //traverseList(&list, &printstats);

        char str1[20];
        char str2[20];
        printf("Enter Player 1:");
        fgets(str1,sizeof(str1),stdin);
        printf("Enter Player 2:");
        fgets(str2, sizeof(str2),stdin);
        printf("\n %s vs %s \n", str1,str2);
                
        struct fighter **p1 =  (struct fighter **)findNode(&list, str1, &myStrcmp);
        struct fighter **p2 =  (struct fighter **)findNode(&list, str2, &myStrcmp);
        struct fighter *player1 = *p1;
        struct fighter *player2 = *p2; 
        if(player1->name && player2->name){  
                printstats(player1);
                printstats(player2); 
        }
        else{
                printf("Invalid selection: \n");
                exit(1);
        }
        if(player1 ->tier == player2->tier){
                printf("Same class\n");
        }
        else if(player1->tier < player2->tier){
                printf("%s outranks %s in class\n", player1->name, player2->name);
                
        }
        else if(player1->tier > player2->tier){
                printf("%s outranks %s in class\n", player2->name, player1->name);
        }
        if(player1 ->weight > player2->weight){
                printf("%s has %.1f lbs on %s\n", player1->name, player1->weight - player2->weight,player2->name);
        }
        else{
                printf("%s has %.1f lbs on %s\n", player2->name, player2->weight - player1->weight, player1->name);
        }
        char armed;
        char terrain;
        printf("Type of combat (1 for armed, 0 for unarmed):");
        armed = getc(stdin);
        printf("Type of terrain (1 - earth, 2 - air, 3 - fire, 4 - water)");
        if(getc(stdin)){
                 terrain = getc(stdin);
 
        }
        printf("\n");
        printf("armed: %c, terrain: %c\n", armed, terrain);
        if(comp(player1, player2, armed, terrain) > 0){
                printf("%s wins this round!\n", player1->name);
        }
        else if(comp(player1,player2,armed,terrain)){
                printf("%s wins this round!\n", player2 -> name);
        }
        else{
                printf("It's a tie!\n");
        }
        

}
