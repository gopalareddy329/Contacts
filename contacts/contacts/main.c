#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read();
int r=0;
void database();
void display();
int contacts=0;
int a=0;
struct node{
    char firstname[15];
    char lastname[15];
    char number[15];
    struct node *next;
};

struct node *head=NULL;

void add(char *fn,char *ln,char *number){
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->next=NULL;
    int i=0;
        for(i=0;i<sizeof(fn);i++){
            temp->firstname[i]=*(fn+i);
        }
        for(i=0;i<sizeof(ln);i++){
            temp->lastname[i]=*(ln+i);
        }
        for(i=0;i<=10;i++){
            temp->number[i]=*(number+i);
           
        }
        struct node *t=head;
        while (t->next!=NULL)
        {
            t=t->next;
        }

        t->next=temp;
        
}
void  create(char *fn,char *ln,char *number){
    
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->next=NULL;
    if(head!=NULL){
        add(fn,ln,number);
    }
    if(head==NULL){
    head=temp;
    }
      for(int i=0;i<sizeof(fn);i++){
            temp->firstname[i]=*(fn+i);
        }
    for(int i=0;i<sizeof(ln);i++){
            temp->lastname[i]=*(ln+i);
        }
    for(int i=0;i<=10;i++){
            temp->number[i]=*(number+i);
           
        }
}

void read(){
    char first[15],ln[15],nn[15];
    FILE *fp;
    fp=fopen("/Users/gopalareddy/Desktop/Desktop - Gopala’s MacBook Air/origin/dev/web/contacts/contacts/stdb.txt","r");
    while(fscanf(fp,"%s\t%s\t%s\n",first,ln,nn)!=EOF){
        create(first,ln,nn);
    }
    fclose(fp);
}


void display(){
    struct node *temp=head;
    char first[15],lastn[15],no[10];
    while(temp!=NULL){
        printf("%s %s %s\n",temp->firstname,temp->lastname,temp->number);
        temp=temp->next;
     }
}


void database(){

    FILE *fp;
    fp=fopen("/Users/gopalareddy/Desktop/Desktop - Gopala’s MacBook Air/origin/dev/web/contacts/contacts/stdb.txt","w");
    struct node *temp=head;

     while(temp!=NULL){
        fprintf(fp,"%s\t%s\t%s\n",temp->firstname,temp->lastname,temp->number);
        temp=temp->next;
     }
    
    fclose(fp);

}
void base(){

    FILE *fp;
    fp=fopen("/Users/gopalareddy/Desktop/Desktop - Gopala’s MacBook Air/origin/dev/web/contacts/contacts/stdb.txt","w");
    struct node *temp=head;

     while(temp!=NULL){
        fprintf(fp,"%s\t%s\t%s\n",temp->firstname,temp->lastname,temp->number);
        temp=temp->next;
     }
    
    fclose(fp);

}
void remov(char *fn,char *ln,char *number){
    struct node *temp=head,*p=head;
    if(strcmp(head->firstname,fn)==0 && strcmp(head->lastname,ln)==0 && strcmp(head->number,number)==0){
         head=head->next;
         free(p);
     }
     else{
        while(temp!=NULL){
            
            if(strcmp(temp->next->firstname,fn)==0 && strcmp(temp->next->lastname,ln)==0 && strcmp(temp->next->number,number)==0){
                    p=temp->next;
                    temp->next=temp->next->next;
                    free(p);
                    break;
            }
            else{
            temp=temp->next;
            }
        }
     }
        
    }


int delet(char *fn,char *ln,char *number){
    if(r==0){
    read();
    r=1;
    }
    remov(fn,ln,number);
    display();
    base();
    return 1;
    }
int insert(char *fn,char *ln,char *number){
    create(fn,ln,number);
    database();
    return 1;
}

int main(){
}