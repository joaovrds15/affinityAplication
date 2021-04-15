#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RESULT{
    char name[10];
    int score;
}RESULT;

typedef struct PERSON{
    int choices[4];
    char name[10];
    char phoneNumber[10];
    char resultado[100];
}PERSON;

void fillPeopleInformation(PERSON *people,int size);
void fillPeopleChoices(PERSON *people,int numberQuestion,int numberPeople);
int calculatePoints(PERSON person1,PERSON person2,int questions);
void atribute(PERSON *person,int participantsNumber,int questionsNumber);
void listPeoplePoints(PERSON *person,int participantsNumber);

int main(void){
    int participants;
    printf("How many people are going to paticipate?");
    scanf("%d",&participants);
    PERSON *people = (PERSON *) malloc(participants * sizeof(PERSON));
    printf("Welcome to the rank system\n");
    fillPeopleInformation(people,participants);
    fillPeopleChoices(people,4,participants);
    atribute(people,participants,4);
    listPeoplePoints(people,participants);

}

void fillPeopleInformation(PERSON *people,int size){
    for(int i = 0; i < size;i++){
        printf("Enter the data for person number %d\n", i +1);
        printf("Enter your name:");
        scanf("%s",people[i].name);
        printf("Enter your phone number:");
        scanf("%s",people[i].phoneNumber);
    }
}

void fillPeopleChoices(PERSON *people,int numberQuestion,int numberPeople){
    for(int j = 0; j < numberPeople;j++){
        printf("Choices of %s\n",people[j].name);
        for(int i = 0; i < numberQuestion;i++){
            switch(i){
                case 0:
                printf("What is your favorite food?\n");
                printf("1 for pizza, 2 for barbecue, 3 for sandwich\n");
                break;

                case 1:
                printf("What is your favorite kind of music?\n");
                printf("1 for rock, 2 fo rap, 3 for pop\n");
                break;

                case 2:
                printf("What would be for your the best date?\n");
                printf("1 go to the Movie, 2 Go out for dinner, 3 Go to the park \n");
                break;

                case 3:
                printf("What is your favorite type of tv show:\n");
                printf("1 sitcom, 2 horror, 3 fiction\n");
                break;

                default:
                printf("End of questions\n");
                break;
            }
        scanf("%d",&people[j].choices[i]);
        }
    }    
}
int calculatePoints(PERSON person1, PERSON person2,int numberQuestions){
    int points = 0;
    for(int i = 0; i < numberQuestions;i++){
        if(person1.choices[i] == person2.choices[i]){
            points++;
        }
    }
    return points;
}

void atribute(PERSON *person,int participantsNumber,int questionsNumber){
    for(int i = 0; i < participantsNumber;i++){
        for(int j = 0; j < participantsNumber;j++){
            if(i != j){
                char result[10];
                sprintf(result,"%d",calculatePoints(person[i],person[j],4));
                strcat(person[i].resultado,person[j].name);
                strcat(person[i].resultado," ");
                strcat(person[i].resultado,result);
                strcat(person[i].resultado," points ");
            }
        }
    }
}

void listPeoplePoints(PERSON *person,int participantsNumber){
    for(int i = 0; i < participantsNumber;i++){
        printf("Result for %s: %s \n",person[i].name,person[i].resultado);
    }
}