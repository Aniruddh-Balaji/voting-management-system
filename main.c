#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct candidate {
    char name[20];
    char voterId[20];
    char party_name[20];
    int no_of_votes;
    struct candidate *next;
} Candidate;

char username[15] = "poseidon";
char password[10] = "cgod";
char user[30];
char pwd[30];

struct voter{
    char name[20];
    char voterId[20];
    char casted_vote[20];
    struct voter *next;
};
typedef struct voter Voter;


void write_voter(char name[], char voter_id[]);
void read_voter();
void write_candidate(Candidate *candidate);
void read_candidate();
Voter *voter_linked_list(Voter *head);
Candidate *add_candidate(Candidate *head,char *name,char *voterId,char *party_name);
int check(struct voter *head,char *name,char *voterId);

int adm_login()
{
    printf("enter your username password as space seperate values: \n");
    scanf("%s %s", user, pwd);

    if (strcmp(user, username) == 0 && strcmp(pwd, password) == 0)
        return 1;
    else
        return 0;
}


int admin_logic()
{
    int a = 0, c = 0;

    while (a == 0)
    {
        a = adm_login();

        if (a == 1)
        {
            int op;
	    printf("You have logged in succesfully!\n");
            printf("---------------------------------------------------------------------------\nchoose from the following\n1)to start election\n2)to add voters\n3)to terminate election\n----------------------------------------------------\n");
            scanf("%d", &op);
            if (op == 1)
            {
                char rep[10]="yes",name[30];
                char id[20];
                while(1)
                {
                    printf("do you want to enter votername voterid to put in voter list\nType yes if so\n");
                    scanf("%s",rep);
                    if (strcmp("yes",rep)==0)
                    {
			printf("Enter votername,voterid");
                        scanf("%s %s",name,id);
                        write_voter(name,id);
                    }
                    else break;
                }
                return 1;
            }
	    if(op==2)
           {
		char rep[10]="yes",name[30];
                char id[20];
                while(1)
                {
                    printf("do you want to enter votername voterid to put in voter list\nType yes if so\n");
                    scanf("%s",rep);
                    if (strcmp("yes",rep)==0)
                    {
			    printf("enter voter name voterid");
                        scanf("%s %s",name,id);
                        write_voter(name,id);
                    }
                    else break;
                }
                return 1;
	}

            if (op == 3)
            {
                int x;
                printf("Are you sure? If yes type 1: \n");
                scanf("%d", &x);

                if (x == 1)
                {
                    return 3;
                }
            }
        }
        else
        {
            c++;
            printf("invalid login %d tries left\n", 3 - c);
        }

        if (c == 3)
        {
            printf("3 incorrect attempts, try again later.......\n");
            break;
        }
    }

    return 0;
}

void update_voter(Voter *voter)
{

    FILE *fptr = fopen("VOTER_updated.txt", "w");
    if (!fptr) return;

    while (voter != NULL)
    {
        fprintf(fptr, "%s %s %s\n",
                voter->name,
                voter->voterId,
                voter->casted_vote);

        voter = voter->next;
    }

    fclose(fptr);
}


void write_voter(char name[], char voter_id[])
{
    FILE *fptr = fopen("VOTER.txt", "a");
    if (!fptr) return;

    fprintf(fptr, "%s %s\n", name, voter_id);


    fclose(fptr);
}

void read_voter()
{
    FILE *fptr = fopen("VOTER.txt", "r");
    if (!fptr) return;

    char ch;
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);

    fclose(fptr);
}

void write_candidate(Candidate *candidate)
{
    FILE *fptr = fopen("CANDIDATE.txt", "w");
    if (!fptr) return;

    while (candidate != NULL)
    {
        fprintf(fptr, "%s %s %s %d\n",
                candidate->name,
                candidate->voterId,
                candidate->party_name,
		candidate->no_of_votes);

        candidate = candidate->next;
    }

    fclose(fptr);
}

void read_candidate()
{
    FILE *fptr = fopen("CANDIDATE.txt", "r");
    if (!fptr) return;

    char ch;
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);

    fclose(fptr);
}


Voter *new_voter(char name[],char casted_vote[],char voterId[])
{
    Voter *v=malloc(sizeof(Voter));
    strcpy(v->name,name);
    strcpy(v->casted_vote,casted_vote);
    strcpy(v->voterId,voterId);
    v->next=NULL;
    return v;
}


Voter *voter_linked_list(Voter *head)
{
    FILE *fp = fopen("VOTER.txt", "r");
    if (fp == NULL) {
        printf("Cannot open VOTER.txt\n");
        return head;
    }

    char name[20], id[20];

    while (fscanf(fp, "%19s %19s", name, id) == 2)
    {
        Voter *node = malloc(sizeof(Voter));
        strcpy(node->name, name);
        strcpy(node->voterId, id);
        strcpy(node->casted_vote, "");
        node->next = NULL;

        if (head == NULL) head = node;
        else {
            Voter *c = head;
            while (c->next) c = c->next;
            c->next = node;
        }
    }

    fclose(fp);
    return head;
}


Voter *add_single_voter(Voter *head,char name[],char voterId[])
{
    Voter *c=head;
    while(c->next!=NULL) c=c->next;

    Voter *newv = malloc(sizeof(Voter));
    strcpy(newv->name,name);
    strcpy(newv->voterId,voterId);
    strcpy(newv->casted_vote,"");
    newv->next=NULL;

    c->next=newv;
    return head;
}


void casting_vote(Voter *voter_guy,Candidate *candidate_head)
{
    printf("Enter the candidate you wish to vote\n");
    char voted_candidate[20];
    scanf("%s",voted_candidate);
    Candidate *c=candidate_head;
    bool voted=false;

    while(c!=NULL)
    {
        if (strcmp(c->party_name,voted_candidate)==0)
        {
            strcpy(voter_guy->casted_vote,voted_candidate);
            c->no_of_votes++;
            voted=true;
            return;
        }
        c=c->next;
    }
    if(voted==false)
    {
        printf("Wrong candidate name. Try again? 1=yes: \n");
        int tr;
        scanf("%d",&tr);
        if(tr==1) casting_vote(voter_guy,candidate_head);
    }
}


void update_vote(Voter *voter_guy,Candidate *candidate_head)
{
    Candidate *c1=candidate_head;
    while(c1!=NULL)
    {
        if(strcmp(voter_guy->casted_vote,c1->party_name)==0)
        {
            strcpy(voter_guy->casted_vote,"");
            c1->no_of_votes--;
            break;
        }
        c1=c1->next;
    }
    casting_vote(voter_guy,candidate_head);
}

void delete_vote(Voter *voter_guy,Candidate *candidate_head)
{
    Candidate *c=candidate_head;
    while(c!=NULL)
    {
        if(strcmp(c->party_name,voter_guy->casted_vote)==0)
        {
            c->no_of_votes--;
            strcpy(voter_guy->casted_vote,"");
            return ;
        }
        c=c->next;
    }
}


int check(struct voter *head,char *name,char *voterId){
    struct voter *l=NULL;
    for (l=head;l!=NULL;l=l->next){
        if ((strcmp(l->name,name)==0) && (strcmp(l->voterId,voterId)==0)) return 1;
    }
    return 0;
}


Candidate *new_candidate(char *name,char *voterId,char *party_name){
    Candidate *temp=malloc(sizeof(Candidate));
    strcpy(temp->name,name);
    strcpy(temp->voterId,voterId);
    strcpy(temp->party_name,party_name);
    temp->no_of_votes=0;
    temp->next=NULL;
    return temp;
}

Candidate *add_candidate(Candidate *head,char *name,char *voterId,char *party_name){
    Candidate *l=head;
    if (l==NULL){
        l=new_candidate(name,voterId,party_name);
        return l;
    }
    for (;l!=NULL;l=l->next){
        if (l->next==NULL){
            l->next=new_candidate(name,voterId,party_name);
            return head;
        }
    }
    return head;
}


void votes(Candidate *head){
    Candidate *l=head;
    int i=0;
    while (l) {
        i++;
        l=l->next;
    }
    l=head;

    int *arr=malloc(i*sizeof(int));
    int j=0;
    for (;l!=NULL;l=l->next){
        arr[j++]=l->no_of_votes;
    }

    for (int m=0;m<i-1;m++){
        for (int n=0;n<i-1;n++){
            if (arr[n+1]>arr[n]) {
                int t=arr[n];
                arr[n]=arr[n+1];
                arr[n+1]=t;
            }
        }
    }

    for (int x=0;x<i;){
        int count=0;
        for (Candidate *p=head;p!=NULL;p=p->next){
            if (p->no_of_votes==arr[x]) {
                printf("%s %d\n",p->party_name,arr[x]);
                count++;
            }
        }
        x+=count;
    }
    free(arr);
}


Candidate  *Candidate_enrollment(Voter *head,Candidate *start){
    char name[20];
    char voterId[20];
    printf("Enter your name :\n");
    scanf("%s",name);
    printf("Enter your voterId :\n");
    scanf("%s",voterId);
    int verify=check(head,name,voterId);
    if (verify==1) {
        printf("Enter party name :\n");
        char party_name[20];
        scanf("%s",party_name);
        start=add_candidate(start,name,voterId,party_name);
        printf("Your enrollment is successful\n");
        return start;
    }
    else printf("Invalid credentials\n");
    return start;
}


int main(){
    Candidate *cand_head=NULL;
    Voter *voter_head=NULL;

        cand_head = new_candidate("NONE", "NONE", "NOTA");

    while (1){
        int opt;
        printf("---------------------------------------\n1.Admin\n2.Voter\n3.Candidate enrollment\n4.Exit\n---------------------------------\n");
        scanf("%d",&opt);

        if (opt==1){
            int a=admin_logic();
            if (a==1) {
                voter_head=voter_linked_list(voter_head);
            }
            if (a==3) {
		FILE *f=fopen("VOTER.txt","w");
		fclose(f);
		write_candidate(cand_head);
		update_voter(voter_head);
               votes(cand_head);
	       break;
            }
        }
        else if (opt==2){
            int correct_identification=0;
            printf("Enter your name enter your voter Id as space seperated values\n");
            char name[20];
            char voterId[20];
            scanf("%s %s",name,voterId);

            Voter *v=voter_head;
            while(v!=NULL)
            {
                if(strcmp(v->name,name)==0 && strcmp(v->voterId,voterId)==0)
                {
                    correct_identification=1;
                    break;
                }
                v=v->next;
            }
            if(correct_identification==1)
            {
                printf("--------------------------------------\n1.Cast vote\n2.Update Vote\n3.Delete vote\n---------------------------------\n");
                int choice;scanf("%d",&choice);
                if(choice==1)
                {
                    if(strcmp(v->casted_vote,"")==0)
                    {
                        casting_vote(v,cand_head);
                        printf("You have casted vote\n");
                    }
                    else{
                        printf("You have already voted\n");
                    }
                }
                else if(choice==2)
                {
                    if(strcmp(v->casted_vote,"")==0)
                    {
                        printf("You have not casted vote yet\n");
                    }
                    else{
                        update_vote(v,cand_head);
                        printf("You have updated your vote\n");
                    }
                }
                else if(choice==3)
                {
                    if(strcmp(v->casted_vote,"")!=0)
                    {
                        delete_vote(v,cand_head);
                        printf("You have deleted your vote\n");
                    }
                    else{
                        printf("You have not voted\n");
                    }
                }
                else{
                    printf("Invalid choice\n");
                }

            }
            else{
                printf("Invalid credentials\n");
            }

        }
        else if (opt==3){
            cand_head=Candidate_enrollment(voter_head,cand_head);
        }
        else if (opt==4){
            printf("Exiting...\n");
            break;
        }
        else break;
    }
    return 0;
}
