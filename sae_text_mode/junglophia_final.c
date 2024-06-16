#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


char *text;
int choice;
char *character, *first_choice;
char answer_text[100];
int enigma, nb_lifes, answer, nb_points, joyaux, price;

void read_line(int ligne_voulue, int ligne_voulue_2, char *text)
{
    /*Fonction that read the lines input into the files
    input : ligne_voulue int -> first line to read
        ligne_voulue_2 int -> last line to read
    */
    int i,j;
    j=ligne_voulue;
    char ligne[1000], c;
   

    FILE *text_languages = fopen(text, "r");
    
    for (int i = 0; i <= ligne_voulue ; i++)
    {   
        while ((c = fgetc(text_languages)) != EOF && c != '\n')
            ;
        
    }

    if (fgets(ligne, sizeof(ligne), text_languages) != NULL)
    {   
        j=ligne_voulue;
        while (j<=ligne_voulue_2)
        {   
            fgets(ligne, sizeof(ligne), text_languages);
            printf("\n %s \n", ligne);
            sleep(2);
            j=j+1;
        }
        
       
    }

    fclose(text_languages);
}

void read_img(int ligne_voulue, int ligne_voulue_2, char *text)
{
    /*Fonction that read lines for ascii img 
    Difference with read_line -> no return line for display
    input : ligne_voulue int -> first line to read
        ligne_voulue_2 int -> last line to read*/
    int i,j;
    j=ligne_voulue;
    char ligne[1000], c;
   

    FILE *text_languages = fopen(text, "r");
    for (int i = 0; i <= ligne_voulue ; i++)
    {   
        while ((c = fgetc(text_languages)) != EOF && c != '\n')
            ;
    
    }

    if (fgets(ligne, sizeof(ligne), text_languages) != NULL)
    {   
        j=ligne_voulue;
        while (j<=ligne_voulue_2)
        {   
            fgets(ligne, sizeof(ligne), text_languages);
            printf("%s", ligne);
            j=j+1;
        }
        
       
    }

    fclose(text_languages);
}



void choix_langue2()
{
    /*Function that choose the text in function of the langage choice
    If fr scan the first file "histoire_français" will be open and if it's (en) the second files will be open
    */
    char langue[100];  
    int v;
    v=0;
    while (v==0)
    {   
        printf("Choisir la langue (fr) / Select language (en) ?  ");
        scanf("\n %s",&langue);
        if (strcmp(langue, "fr") == 0)
        {  
            text="histoire_français.txt"; 
            v=1;
        } 
        else if (strcmp(langue, "en") == 0)
        {
            text="story_english.txt"; 
            v=1;
        }
        else{
            printf("Error choice \n ");
            
        }
    } 
}


void erreur(char choice, char *text)
{
    /* Function that print a message of error if the choice does not match any proposition (only for 2 choices)
    input : choice , text */
    int v;
    v=0;
    while(v==0)
    {
        if (choice!=1 && choice!=2)
        {
            read_line(506,506,text);
            scanf("\n %d",&choice);
        }
        else
        {
            v=1;
        }
}

}


void erreur3(char choice, char *text)
{
    /* Function that print a message of error if the choice does not match any proposition 
    (for 3 choices)
    input : choice , text */
    int v;
    v=0;
    while(v==0)
    {
        if (choice!=1 && choice!=2 && choice!=3)
        {
            read_line(506,506,text);
            scanf("\n %d",&choice);
        }
        else
        {
            v=1;
        }
}

}

char choice_character()
{
    /*function to choose the charactere at the beginnig*/
    read_line(18,21,text);
    scanf("\n %d",&choice);
    erreur3(choice,text);
    switch (choice)
    {
    case 1:
        character="explorer";
        read_line(502,502,text);
        break;
    
    case 2:
        character="professor";
        read_line(503,503,text);
        break;

    case 3:
        character="warrior";
        read_line(504,504,text);
        break;
    
    default:
        break;
    }
}

void victory_enigma_easy()
/* function that make victory for the easy enigma
if the user is correct he wins 1 life and the number of points increase of 25points*/
{
    if (nb_lifes<3)
       {
        nb_lifes=nb_lifes+1;
        
       }
    nb_points=nb_points+25;
    read_line(80,80,text);
    printf("vies/lifes : %d \n",nb_lifes);
}

void victory_enigma_difficult()
{
    /* function that make victory for the easy enigma
    if the user is correct he wins 1 life and the number of points increase of 25points*/
    if (nb_lifes<3)
       {
        nb_lifes=nb_lifes+1;
       }
    nb_points=nb_points+50;
    read_line(95,95,text);
    printf("vies/lifes : %d \n",nb_lifes);
    printf("Points : %d pièces \n",nb_points);
}


void display_map(){
/* function tha shows the map if the user wants to
it asks yes or no and display it */
    int v;
    v=0;
    while (v==0)
    {
        read_line(623,623,text);
        scanf("%s",&answer_text);
        if (strcmp(text, "histoire_français.txt") == 0)
        {  
            if(strcmp(answer_text, "oui") == 0)
            {  
                read_img(600,620,text);
                v=1;
            }
            else if(strcmp(answer_text, "non") == 0)
            {  
                v=1;
            }
            else{
                printf("Répondez par oui ou par non");
            }
            
            
        }
        else{  
            if(strcmp(answer_text, "yes") == 0)
            {  
                read_img(600,620,text);
                v=1;
            }
            if(strcmp(answer_text, "no") == 0)
            {  
                v=1;
            }
            else{
                printf("Answer by yes or no");
            }           
        } 
    }
    
    
}


void progress_status_display(int chapter_number){
    /*Function that print the progression if the user wants to
    The progression increase of 20% for each chapter
    It reads in the file the right loading
    input : chapter_number : current chapter, int*/
    int v;
    v=0;
    while (v==0)
    {
        read_line(629,629,text);
        scanf("%s",&answer_text);
        if (strcmp(text, "histoire_français.txt") == 0)
        {  
            if(strcmp(answer_text, "oui") == 0)
            {  
                printf("progression :");
                switch (chapter_number)
                {
                case 1:
                    read_line(630,630,text);
                    break;
                case 2:
                    read_line(631,631,text);
                    break;
                case 3:
                    read_line(632,632,text);
                    break;
                case 4:
                    read_line(633,633,text);
                    break;
                case 5:
                    read_line(634,634,text);
                    break;
                default:
                    break;
                }
                v=1;
            }
            else if(strcmp(answer_text, "non") == 0)
            {  
                v=1;
            }
            else{
                printf("Répondez par oui ou par non");
            }   
        }
        else{  
            if(strcmp(answer_text, "yes") == 0)
            {  
                printf("progression :");
                switch (chapter_number)
                {
                case 1:
                    read_line(630,630,text);
                    break;
                case 2:
                    read_line(631,631,text);
                    break;
                case 3:
                    read_line(632,632,text);
                    break;
                case 4:
                    read_line(633,633,text);
                    break;
                case 5:
                    read_line(634,634,text);
                    break;
                default:
                    break;
                }
                v=1;
            }
            else if(strcmp(answer_text, "no") == 0)
            {  
                v=1;
            }
            else{
                printf("Answer by yes or no");
            }           
        } 
    }
       

}


int jewel_price(){
    /*function that generates a number between 0 et 100 randomely to be the price of the jewel
    it uses time to change at the differents executions*/
    srand(time(NULL));
    int na;
    na = rand() % 100 + 1;
    return(na);
    
}


/*-------------------------------------------JUNGLE-------------------------------------------*/


void rhino()
/*function that make the first part of the history in the jungle
In function of the user character choice the history will be different
If the user makes a wrong choice he looses a life */
{
    read_line(24,26,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
    switch (choice)
    {
    case 1:
        if (strcmp(character, "explorer") == 0)
        {
            read_line(31,31,text);
            nb_lifes=nb_lifes-1;
        }
        if (strcmp(character, "professor") == 0)
        {
            read_line(38,38,text);
        }
        if (strcmp(character, "warrior") == 0)
        {
            read_line(47,47,text);  
            nb_lifes=nb_lifes-1;
        }
        break;
    case 2:
        if (strcmp(character, "explorer") == 0)
        {
            read_line(34,34,text);
            
        }
        if (strcmp(character, "professor") == 0)
        {
            read_line(41,41,text);
            nb_lifes=nb_lifes-1;
            
        }
        if (strcmp(character, "warrior") == 0)
        {
            read_line(50,50,text);
        }
        break;

    default:
        break;
    }
    


}

void enigma_1()
/* function for the first enigma
EASY ENIGMA 
It read in the file the enigma and asks the user his response 
If the user is right, the function victory_easy will increase lifes and points.
It prints the number of lifes*/
{
    read_line(72,78,text);
    scanf(" %d",&answer);
    if (answer==70)
    {
       read_line(80,80,text);
       if (nb_lifes<3)
       {
        nb_lifes=nb_lifes+1;
       }
       nb_points=nb_points+25;
              
       printf("vies/lifes : %d \n",nb_lifes);

    }
    else{
         read_line(81,81,text);
         printf("vies/lifes : %d \n",nb_lifes);
    }
}

void enigma_2()
{   
    /*Function for the second enigma in the jungle
    DIFFICULT ENIGMA
    It reads the enigma and print an answer */
    read_line(90,91,text);
    scanf("\n %d",&answer);
    if (answer==95)
    {
       read_line(95,95,text);
       nb_lifes=nb_lifes+1;
       nb_points=nb_points+50;

    }
    else{
         read_line(96,96,text);
    }
}



void choice_enigma()
{
    /*Function that asks the user his choice between two things
     to direct it towards an enigma */
    read_line(56,65,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        enigma_1();
    }
    if (choice==2)
    {
        enigma_2();
    }

}



void jungle()
/* function that brings together function for the jungle chapter
*/
{
    progress_status_display(1);
    display_map();
    rhino();
    choice_enigma();

}


/*-------------------------------------------MOUNTAIN-------------------------------------------*/

void path_choice()
{
    /*Function to choose a path and print the consequence for each character*/
    scanf("\n %d",&choice);
    erreur(choice,text);
    switch (choice)
    {
    case 1:
        if (strcmp(character, "explorer") == 0)
        {
            read_line(114,114,text);
            
        }
        if (strcmp(character, "professor") == 0)
        {
            read_line(122,123,text);
        }
        if (strcmp(character, "warrior") == 0)
        {
            read_line(133,133,text);  
            nb_lifes=nb_lifes-1;
            printf("vies/lifes : %d \n",nb_lifes);
        }
        break;
    case 2:
        if (strcmp(character, "explorer") == 0)
        {
            read_line(117,117,text);
            nb_lifes=nb_lifes-1;
            printf("vies/lifes : %d \n",nb_lifes);
        }
        if (strcmp(character, "professor") == 0)
        {
            read_line(127,127,text);
            nb_lifes=nb_lifes-1;
            printf("vies/lifes : %d \n",nb_lifes);
            
        }
        if (strcmp(character, "warrior") == 0)
        {
            read_line(136,136,text);
        }
        break;

    default:
        break;
    }
}


void enigma_3(){
    /*Function that do the easy enigma in the chapter mountain
    It reads the enigma in the file, scan the answer, print the solution
    The player win a life and  25 points if is he's correct 
    ENIGMA EASY*/
    char answer_text[100];
    read_line(154,182,text);
    scanf("\n %s",&answer_text);
    if(strcmp(text, "story_english.txt") == 0)
    {
        if (strcmp(answer_text, "the_solution_is_in_front_of_you") == 0)
        {
            read_line(95,95,text);
            nb_lifes=nb_lifes+1;
            nb_points=nb_points+25;
        }
        else
        {
            read_line(96,96,text);
        }
        
    }
    else
    {   
        if (strcmp(answer_text, "la_solution_est_devant_vous") == 0)
        {
            read_line(95,95,text);
            nb_lifes=nb_lifes+1;
            nb_points=nb_points+50;
        }
        else{
            read_line(96,96,text);
        }
    }

}



void enigma_4(){
    char answer_text[100];
    /*Function for the fourth enigma in the jungle
    It reads the enigma and print an answer 
    DIFFICULT ENIGMA*/
    read_line(188,193,text);
    scanf("\n %s",&answer_text);
    if (strcmp(answer_text, "l'echo") == 0)
    {
       read_line(95,95,text);

    }
    else{
         read_line(96,96,text);
    }
    
}



void choice_enigma_mountain(){
    /*Function that asks the user his choice between two things
     to direct it towards an enigma */
      
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        read_line(143,144,text);
        enigma_4();
    }
    if (choice==2)
    {   
        read_line(148,150,text);
        enigma_3();
    }
}



void montain(){
    /* function that reads text and brings together function for the moutain chapter*/
    progress_status_display(2);
    read_line(105,105,text);
    read_img(514,528,text);
    display_map();
    read_line(106,109,text);
    path_choice();
    read_line(140,140,text);
    choice_enigma_mountain();
    
}

/*-------------------------------------------FOREST-------------------------------------------*/




void enigma_forest(){
    /* function for the forest enigma 
It read in the file the enigma and asks the user his response 
If the user is right, the function victory_easy will increase lifes and points.
It prints the number of lifes*/

    read_line(275,285,text);
    scanf("\n %d",&answer);
    if (answer==22)
    {
       victory_enigma_easy();

    }
    else{
         read_line(96,96,text);
    }
    read_line(288,295,text);
}

void action_choice(){
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        read_line(263,264,text);
        
    }
    if (choice==2)
    {   
        read_line(266,267,text);
        nb_lifes=nb_lifes-1;
        printf("vies/lifes : %d \n",nb_lifes);
        
    }
}

void forest(){
    /* function that reads text and brings together function for the forest chapter*/
    display_map();
    read_line(252,255,text);
    read_img(574,583,text);
    read_line(256,261,text);
    action_choice();
    read_line(272,272,text);
    enigma_forest();
}







/*-------------------------------------------CANYONS-------------------------------------------*/


void path_canyons(){
    /*function that asks the user to make a choice between two path
    It reads the lines associates to the choice*/
    read_line(310,313,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        read_line(317,317,text);
        

    }
    else{
        read_line(321,321,text);
        nb_lifes=nb_lifes-1;
        printf("vies/lifes : %d \n",nb_lifes);
    }
}




void canyons(){
    /* function that reads text and brings together function for the canyons chapter*/
    display_map();
    path_canyons();
    read_line(324,326,text);
    
    
}




/*-------------------------------------------DUNE-------------------------------------------*/





void epreuve_marchand(){
    /*Function that do an enigma for the user*/

}

void enigma_6(){
    /* function for the dune enigma 
    EASY ENIGMA
    It read in the file the enigma and asks the user his response 
    If the user is right, the function victory_easy will increase lifes and points.
    It prints the number of lifes*/
    read_line(227,233,text);
    scanf("\n %d",&answer);
    if (answer==876)
    {
        victory_enigma_easy();
    }
    else{
        read_line(96,96,text);
    }
    

}

void enigma_7(){
    /* function for the dune enigma 
    DIFFICULTENIGMA
    It read in the file the enigma and asks the user his response 
    If the user is right, the function victory_enigma_difficult will increase lifes and points.
    It prints the number of lifes*/
    read_line(240,243,text);
    scanf("\n %s",&answer_text);
    if(strcmp(text, "histoire_français.txt") == 0)
    {
        if (strcmp(answer_text, "le_secret") == 0)
        {
        victory_enigma_difficult();

        }
        else{
            read_line(96,96,text);
        }
    }
    else{
        if (strcmp(answer_text, "the_secret") == 0)
        {
        victory_enigma_difficult();

        }
        else{
            read_line(96,96,text);
        }
        
    }

}

void dune()
{
    /* function that reads text and brings together function for the dune chapter
    If the user choose 1 it do the enigma of the marchand
    After the user chooses the place he wants to go in
    If he chooses the forest he will do the canyon after.And vice-versa
    */
    progress_status_display(3);
    display_map();
    read_line(198,199,text);
    read_img(549,564,text);
    read_line(200,201,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
     if (choice==1)
    {
        read_line(204,204,text);
        epreuve_marchand();
        
    }
    if (choice==2)
    {   
        read_line(212,212,text);
        
    }
    read_line(218,218,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        enigma_6();
        
    }
    if (choice==2)
    {   
       enigma_7();
        
    }
    read_line(247,248,text);
    scanf("\n %d",&choice);
    erreur(choice,text);
    if (choice==1)
    {
        progress_status_display(4);
        forest();
        first_choice="forest";
        
    }
    else
    {   
        progress_status_display(4);
        canyons();
        first_choice="canyons";
        
    }
    if (strcmp(first_choice, "forest") == 0)
    {
        progress_status_display(5);
        canyons();
    }
    else{
        progress_status_display(5);
        forest();
    }
}


/*--------------------------------------- ENDING --------------------------------------*/


void achat_joyaux(){
    /*Function that show the price of the jewel and ask the player if he has enough money to buy it
    If he buys it the number of jewel will increase */
    read_line(344,346,text);
    printf("%d \n",price);
    read_line(347,348,text);
    printf("%d \n",nb_points);
    if (nb_points>=price)
    {
        read_line(351,351,text);
        joyaux=1;
    }
    else{
        read_line(353,353,text);
        joyaux=0;
    }
    

}

void ending(){
    achat_joyaux();
    if (joyaux==1)
    {
        read_line(360,361,text);
    }
    else{
        read_line(365,366,text);
    }
    
}




int main()
{
    text="readme.txt";
    char name, choice;
    int v,x;
    nb_lifes=3;
    nb_points=0;
    x=0;
    v=0;
    price=jewel_price();

    while (nb_lifes>0 || x==0)
    {
        /* Introduction Rules*/
        choix_langue2(text);
        read_img(491,496,text);
        printf("\n");
        read_line(1,11,text);

        /* Name in the game */
        read_line(15,17,text);
        scanf("%s",&name);

        /*Character choice*/
        choice_character();
     
        /*Chapter Jungle*/
        jungle();

        /* Chapter Mountain*/
        montain();
   
    
        /*Chapter Dune*/
        dune();

    
        ending();
        read_line(362,362,text);
        scanf("\n %d",&choice);
        v=1;
    }
    
    
    



}