#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct person {
    char name[30];
    char country_code[4];
    long int mble_no;
    char sex[8];
    char mail[100];
};

typedef struct person person;

void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);
void start();

int main() {
    start();
    return 0;
}

void start() {
    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_record();
                getchar();
                break;
            case 2:
                add_person();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                break;
            default:
                printf("Thanks for using phonebook, visit again :)\n");
                getchar();
                exit(1);
        }
    }
}

void print_menu() {
    int i;
    for (i = 0; i < 2; i++) {
        Beep(500, 500);
    }
    printf("\t\t****************************************************************\n");
    printf("\t\t****************************************************************\n");

    printf("\t\t*                  WELCOME TO MY PHONE BOOK                   *\n");

    printf("\t\t****************************************************************\n\n");
    printf("\t\t****************************************************************\n");
    printf("\n\nLETS INVITE NEW FRIENDS!\n");
    printf("\n");
    printf("\t\t\t1) list record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person Details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) exit Phonebook\n\n\n");
    printf("\t\t\t\tEnter your Choice : ");
}

void add_person() {
    printf("\n\nLETS INVITE NEW FRIENDS!");
    char phrase[100] = "LETS INVITE NEW FRIENDS!";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);

    printf("\n");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } else {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);

        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");
    }
}

void take_input(person *p) {
    getchar();
    printf("Enter name : ");
    char phrase[100] = "Enter name";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);
    scanf("%[^\n]s", p->name);

    printf("Enter country code : ");
    scanf("%s", p->country_code);

    printf("Enter mobile no : ");
    scanf("%ld", &p->mble_no);
    printf("Enter sex : ");
    scanf("%s", p->sex);

    printf("Enter email : ");
    scanf("%s", p->mail);
}

void list_record() {
    printf("\n\nLETS INVITE NEW FRIENDS!");

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } else {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 20 - strlen(p.country_code);
            int len3 = 10;
            int len4 = 10 - strlen(p.sex);
            printf("%s", p.name);
            for (i = 0; i < len1; i++) printf(" ");

            printf("%s", p.country_code);
            for (i = 0; i < len2; i++) printf(" ");

            printf("%ld", p.mble_no);
            for (i = 0; i < len3; i++) printf(" ");

            printf("%s", p.sex);
            for (i = 0; i < len4; i++) printf(" ");

            printf("%s", p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

void search_person() {
    long int phone;
    printf("Enter Phone number of the person you want to search : ");
    char phrase[100] = "Enter Phone number of the person you want to search";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);
    scanf("%ld", &phone);

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } else {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            if (p.mble_no == phone) {
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.country_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.sex);
                printf("%s", p.name);
                for (i = 0; i < len1; i++) printf(" ");

                printf("%s", p.country_code);
                for (i = 0; i < len2; i++) printf(" ");

                printf("%ld", p.mble_no);
                for (i = 0; i < len3; i++) printf(" ");

                printf("%s", p.sex);
                for (i = 0; i < len4; i++) printf(" ");

                printf("%s", p.mail);
                printf("\n");

                flag = 1;
                break;
            } else
                continue;
        }
        if (flag == 0) {
            printf("Person is not in the Phonebook\n");
        }
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

void remove_person() {
    printf("\n\nLET'S REMOVE THEM !");
    char phrase[100] = "LET'S REMOVE THEM";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);
    printf("\n\n");
    long int phone;
    printf("\nEnter Phone number of the person you want to remove from phonebook : ");

    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } else {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            if (p.mble_no == phone) {
                printf("Person removed successfully\n");
                flag = 1;
            } else
                fwrite(&p, sizeof(p), 1, temp);
        }
        if (flag == 0) {
            printf("No record found for %d number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        printf("Press any key to continue....\n");
    }
}

void update_person() {
    printf("\n\n WANNA KNOW MORE AND UPDATE MOREE:)\n");
    char phrase[100] = "WANNA KNOW  MORE AND UPDATE MOREE:)";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);
    printf("\n");

    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL) {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    } else {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1) {
            if (p.mble_no == phone) {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("clear");
                printf("Data updated successfully\n");
                flag = 1;
            } else
                fwrite(&p, sizeof(p), 1, temp);
        }
        if (flag == 0) {
            printf("No record found for %d number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        printf("Press any key to continue....\n");
    }
}

void remove_all() {
    printf("\n\nHmmm........NOT SATISFIED:)\n");
    printf("\n\nLets DELETE them :)\n");
    char phrase[100] = "Hmmm........NOT SATISFIED so Lets DELETE them  ";
    char charCommand[100];

    strcpy(charCommand, "espeak \"");
    strcat(charCommand, phrase);
    strcat(charCommand, "\"");

    system(charCommand);
    printf("\n");
    char choice;

    remove("./phonebook_db");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue ... \n");
}
