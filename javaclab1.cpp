#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trav
{
 char name[50];
 int route1;
 int route2;
 struct trav *next;
};
static char city[10][20]={"Saharanpur","Dehradun","Shimla","Chandigarh","Delhi","Tehri","Haridwar","Rishikesh","Noida","Gurgaon"};
struct trav *Insert(struct trav *first,char *Name,int a,int b)
{
 struct trav *new_node=(struct trav*)malloc(sizeof(struct trav));
 strcpy(new_node->name,Name);
 new_node->route1=a;
 new_node->route2=b;
 new_node->next=first;
 return new_node;
}
void print(struct trav *first)
{
 if(first==NULL)
 printf("No Bookings!\n");
 else
 {
 struct trav *current=first;
 printf("\t\tNAME\t\tFrom\t\tTo\n");
 printf("________________________________________________________________________\n");
 while(current!=NULL)
 {
 printf("\t\t%s",current->name);
 printf("\t\t%s",city[current->route1]);
 printf("\t\t%s",city[current->route2]);
 current=current->next;
 }
 }
}
struct trav *find(struct trav *first,char *name)
{
 for(struct trav *p=first;p!=NULL;p=p->next)
 {
 if((strcmp(p->name,name)==0))
 return p;
 }
 return NULL;
}
struct trav *Delete(struct trav *first,char *name)
{
 struct trav *cur=first,*prev=NULL;
 while(cur!=NULL&&(strcmp(cur->name,name)!=0))
 {
 prev=cur;
 cur=cur->next;
 }
 if(cur==NULL)
 return first;
 if(prev==NULL)
 first=first->next;
 else
 prev->next=cur->next;
 free(cur);
 printf("Successfully cancelled!\n");
 return first;
}
int main()
{
 int ch,fare,count;
 char name[50];
 int a;
 int b;
 char ans,ch1;
 struct trav *head=NULL,*ptr;
 do
 {
 printf("1.Book Seat\n2.Show all reservations\n3.Check reservation\n4.Cancel reservation:\n5.Exit:\t");
 scanf("%d",&ch);
 switch (ch)
 {
 case 1:
 	if(count<=3){
 for(int i=0;i<10;i++)
    {
        printf("%d.%s\n",i+1,city[i]);
    }
 printf("From:\t");
 scanf("%d",&a);
 printf("To:\t");
 scanf("%d",&b);
 printf("Traveller's Name:\t");
 scanf("%s",name);
 fare=((a-b)*(a-b))*10;
 printf("Total fare:\t%d\n",fare);
 printf("Confirm Booking?(Y/N)\n");
 scanf(" %c",&ch1);
 if((ch1=='y'||ch1=='Y')){
 head=Insert(head,name,a,b);
 count+1;
}
}
else{
	printf("No seat Available!");
}break;
 case 2:
 print(head);
 break;
 case 3:
 printf("Traveller's name?\t");
 scanf("%s",name);
 ptr=find(head,name);
 printf("\nTraveller's Name:\t%s\n",ptr->name);
 printf("\nFrom\t%s\tTo\t%s\n",city[ptr->route1],city[ptr->route2]);
 fare=((ptr->route1-ptr->route2)*(ptr->route1-ptr->route2))*10;
 printf("\nTotal fare:\t%d\n",fare);
 break;
 case 4:
 printf("Traveller name?\t");
 scanf("%s",name);
 head=Delete(head,name);
 break;
 case 5:exit(0);
 default:
 printf("Wrong choice!\n");
 break;
 }
 printf("\nContinue?(Y/N)\n");
 scanf(" %c",&ans);
 } while (ans=='y'||ans=='Y');
 return 0;
}
