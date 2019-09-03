#include<stdio.h>
#include<conio.h>
#include<string.h>
int leap=0;
int input()
{
 char name[10];
 char month[12][10]={"january",
		     "february",
		     "march",
		     "april",
		     "may",
		     "june",
		     "july",
		     "august",
		     "september",
		     "october",
		     "november",
		     "december"};

 int i;
 printf("Enter month \n");
 scanf("%s",name);
  for(i=0;i<12;i++)
  {
  if(strcmpi(name,month[i])==0)
     return i+1;

  }

}

int year(int year1)
{
 int i,count=2;
 for(i=1901;i<=year1;i++)
 {
  if(i==1901)
   continue;

  if(i%4==1)
     count++;

     count++;

 }
  if(year1%4==0)
    leap=1;

 count=count%7;
 return count;
}

int month_day(int day,int month)
{
 int i;
 for(i=1;i<=month;i++)
 {
   if(leap==0)
   {
    if(i==3||i==5||i==7||i==8||i==9||i==11)  //for months having 31 days
     day=day+3;

    if(i==4||i==6||i==10||i==12)
     day=day+2;

    }   //leap if close

    if(leap==1)
    {
     if(i==3||i==5||i==7||i==8||i==9||i==11)  //for months having 31 days
     day=day+3;

    if(i==4||i==6||i==10||i==12)
     day=day+2;

     if(i==2)
      day=day+1;
     }

 }  //for loop close

 day=day%7;

 return day;
}  //function close

void print(int first_day,int month)
{
 int i=month,j,day;

 if(leap==0)
   {
    if(i==3||i==5||i==7||i==8||i==10||i==12)  //for months having 31 days
     day=31;

    if(i==4||i==6||i==9||i==11)
     day=30;

    if(i==2)
    day=28;

    }

    if(leap==1)
    {
     if(i==3||i==5||i==7||i==8||i==10||i==12)  //for months having 31 days
     day=31;

    if(i==4||i==6||i==9||i==11)
     day=30;

     if(i==2)
      day=29;
    }

   for(j=1;j<=day;j++)
   {
    if(first_day==0)
    printf("On %2d is SUNDAY     ",j);

    if(first_day==1)
    printf("On %2d is MONDAY     ",j);

    if(first_day==2)
    printf("On %2d is TUESDAY    ",j);

    if(first_day==3)
    printf("On %2d is WEDNSEDAY  ",j);

    if(first_day==4)
    printf("On %2d is THRUSDAY   ",j);

    if(first_day==5)
    printf("On %2d is FRIDAY     ",j);

    if(first_day==6)
    printf("On %2d is SATURDAY   ",j);

    if(j%2==0)
    printf("\n");

    first_day++;
    first_day=first_day%7;
 }

}

void main()
{
int month1,year1,first_day,first_day_month;
clrscr();
month1=input();

printf("Enter year\n");
scanf("%d",&year1);

first_day=year(year1);

first_day_month=month_day(first_day,month1);

print(first_day_month,month1);

getch();
}