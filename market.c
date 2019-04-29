#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct date
{
    int day,month,year;
};
struct market
{
    int nbr;
    int amount;
    int quantity;
    char name[100];
    struct date ope;//opening as nested structure
    struct date pur;
    struct date sale;
}add,check,uptd,purc,sal; //global declaration of needed variable which will used in any function

int total,total1,total_sal,total_sal1,total_purc,total_purc1,grtotal;
int pu_quantity,sa_quantity;
int main_exit;
int choice;

void create()
{
    FILE *old,*pu;
    old=fopen("create.txt","a+");
    pu=fopen("purchase.txt","a+");
    invalid:
    system("cls");
    printf("\n ADD YOUR ITEM\n --- ---- ----\n");
    printf(" Today's date(dd/mm/yy): ");
    scanf("%d/%d/%d",&add.ope.day,&add.ope.month,&add.ope.year);
    printf("\n Item No.: ");
    scanf("%d",&check.nbr);
    while(!feof(old))
    {
       fscanf(old,"\n%d %s %d %d %d %d/%d/%d",&add.nbr,&add.name,&add.quantity,&add.amount,&total,&add.ope.day,&add.ope.month,&add.ope.year);
        if(check.nbr==add.nbr)
        {
            printf("\n The No. already used take another!!");
            goto invalid;
        }
    }
    add.nbr=check.nbr;
    printf("\n Item name: ");
    scanf("%s",&add.name);
    printf("\n Quantity: ");
    scanf("%d",&add.quantity);
    printf("\n Unit price: ");
    scanf("%d",&add.amount);
    total=add.quantity*add.amount;
    fprintf(old,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
    fprintf(pu,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
    fclose(old);
    fclose(pu);
    system("cls");
    printf("\n\n\t Item added successfully!!!\n\n");
    invalid_create:
    printf("\n[1]To continue adding item\n[2]To go back to the main\n[3]To exit the program\n ");
    scanf("%d",&main_exit);
    if(main_exit==1)
        create();
    else if(main_exit==2)
        main();
    else if(main_exit==3)
        close();
    else
    {
        printf("\n!!!Invalid!!!");
        goto invalid_create;
    }
}

void close()
{
    system("cls");
    printf("\n\t!!!THANK YOU FOR USING OUR SYSTEM!!!");
}

void update()
{
    FILE *old,*newx;
    int test=0;
    old=fopen("create.txt","r");
    newx=fopen("new.txt","w");
    printf("\n Update your Item information");
    printf("\n ----------------------------\n");
    printf("\n Item No.: ");
    scanf("%d",&uptd.nbr);
    while(!feof(old))
    {
        fscanf(old,"\n%d %s %d %d %d %d/%d/%d",&add.nbr,&add.name,&add.quantity,&add.amount,&total,&add.ope.day,&add.ope.month,&add.ope.year);
        if(uptd.nbr==add.nbr)
        {
            test=1;
            invalid_update:
            system("cls");
            printf("\n[1]To change the name\n[2]To change the price\n ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n Enter the new name: ");
                scanf("%s",&uptd.name);
                fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,uptd.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
                system("cls");
                printf("\n\t!!!Changed successfully!!!\n");
            }
            else if(choice==2)
            {
                printf("\n Enter new price: ");
                scanf("%d",&uptd.amount);
                total1=add.quantity*uptd.amount;
                fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,uptd.amount,total1,add.ope.day,add.ope.month,add.ope.year);
                printf("\n\t!!!Changed successfully!!!\n");
            }
            else
            {
                printf("\n!!!Invalid!!!\n");
                goto invalid_update;
            }
        }
        else
        {
            fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
        }
    }
    fclose(old);
    fclose(newx);
    remove("create.txt");
    rename("new.txt","create.txt");
    if(test!=1)
    {
        system("cls");
        printf("\n\t!!!Record not found!!!\n");
        system("cls");
        invalid_update2:
        printf("\n[1]To try again\n[2]To return back to main\n[3]To exit the program\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            update();
        else if(main_exit==2)
            main();
        else if(main_exit==3)
            close();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_update2;
        }
    }
    else
    {

        invalid_update3:
        printf("\n[1]To return back to main\n[2]To exit the program\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            main();
        else if(main_exit==2)
            close();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_update3;
        }
    }
}

void purchase()
{
    FILE *old,*newx,*pu;
    int test=0;
    old=fopen("create.txt","r");
    newx=fopen("new.txt","w");
    pu=fopen("purchase.txt","a+");
    printf("\n Purchased list");
    printf("\n --------------\n");
    printf(" Today's date(dd/mm/yy): ");
    scanf("%d/%d/%d",&purc.ope.day,&purc.ope.month,&purc.ope.year);
    printf("\n Item No.: ");
    scanf("%d",&purc.nbr);
    while(!feof(old))
    {
        fscanf(old,"\n%d %s %d %d %d %d/%d/%d",&add.nbr,&add.name,&add.quantity,&add.amount,&total,&add.ope.day,&add.ope.month,&add.ope.year);
        if(purc.nbr==add.nbr)
        {
            test=1;
            printf(" Item name: %s",add.name);
            printf("\n New quantity: ");
            scanf("%d",&purc.quantity);
            pu_quantity=purc.quantity+add.quantity;
            total_purc=pu_quantity*add.amount;
            total_purc1=purc.quantity*add.amount;
            fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,pu_quantity,add.amount,total_purc,add.ope.day,add.ope.month,add.ope.year);
            fprintf(pu,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,purc.quantity,add.amount,total_purc1,purc.ope.day,purc.ope.month,purc.ope.year);
        }
        else
        {
            fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
        }

    }
    fclose(old);
    fclose(newx);
    fclose(pu);
    remove("create.txt");
    rename("new.txt","create.txt");
    if(test!=1)
    {
        system("cls");
        printf("\n\t!!!Record not found!!!\n");
        system("cls");
        invalid_purchase:
        printf("\n[1]To try again\n[2]To return back to main\n[3]To exit the program\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            purchase();
        else if(main_exit==2)
            main();
        else if(main_exit==3)
            close();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_purchase;
        }
    }
    else
    {

        invalid_purchase2:
        printf("\n[1]To return back to main\n[2]To exit the program\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            main();
        else if(main_exit==2)
            close();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_purchase2;
        }
    }
}

void sale()
{
    FILE *old,*newx,*sa,*newc;
    old=fopen("create.txt","r");
    newx=fopen("new.txt","w");
    sa=fopen("sale.txt","a+");
    //newc=fopen("newsale.txt","a+");
    int test=0;
    printf("\n Welcome to our shop");
    printf("\n -------------------\n");
    printf(" Today's date(dd/mm/yy): ");
    scanf("%d/%d/%d",&sal.ope.day,&sal.ope.month,&sal.ope.year);


    sale:
    printf("\n Item No.: ");
    scanf("%d",&sal.nbr);

    printf("\n Quantity: ");
    scanf("%d",&sal.quantity);
    while(!feof(old))
    {
        fscanf(old,"\n%d %s %d %d %d %d/%d/%d",&add.nbr,&add.name,&add.quantity,&add.amount,&total,&add.ope.day,&add.ope.month,&add.ope.year);
        if(sal.nbr==0)
        {
            break;

        }
        else if(sal.nbr==add.nbr)
        {
            test=1;
           //printf(" Item name: %s",add.name);

           sa_quantity=add.quantity-sal.quantity;
           total_sal=sa_quantity*add.amount;
           total_sal1=sal.quantity*add.amount;
           fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,sa_quantity,add.amount,total_sal,add.ope.day,add.ope.month,add.ope.year);
           fprintf(sa,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,sal.quantity,add.amount,total_sal1,sal.ope.day,sal.ope.month,sal.ope.year);
      //     fprintf(newc,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,sal.quantity,add.amount,total_sal1,add.ope.day,add.ope.month,add.ope.year);

        }
        else
        {
            fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,add.quantity,add.amount,total,add.ope.day,add.ope.month,add.ope.year);
        }

    }
     //fprintf(newx,"\n%d %s %d %d %d %d/%d/%d",add.nbr,add.name,sa_quantity,add.amount,total_sal,add.ope.day,add.ope.month,add.ope.year);
    fclose(old);
    fclose(newx);
    fclose(sa);
    //fclose(newc);
    remove("create.txt");
    rename("new.txt","create.txt");
    if(test!=1)
    {
        system("cls");
        printf("\n\t!!!Record not found!!!\n");
        system("cls");
        invalid_sale:
        printf("\n[1]To try again\n[2]To return back to main\n[3]To exit the program\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            sale();
        else if(main_exit==2)
            main();
        else if(main_exit==3)
            close();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_sale;
        }
    }
    else
    {

        invalid_sale2:
        printf("\n[1]To return back to main\n[2]To exit the program\n[3]Report\n ");
        scanf("%d",&main_exit);
        if(main_exit==1)
        {
            printf("\n[1]main\n[2]report");
            scanf("%d",&choice);
            if(choice==1)
            main();
             else if(choice==2)
                reportt();
        }
        else if(main_exit==2)
               close();
        //else if(main_exit==3)
               //bill();
        else
        {
            printf("\n!!!Invalid!!!\n");
            goto invalid_sale2;
        }
    }
}
void reportt()
{
    FILE *sa;
    sa=fopen("sale.txt","r");
    while(!feof(sa))
    {
        fscanf(sa,"\n%d %s %d %d %d %d/%d/%d",&add.nbr,&add.name,&sal.quantity,&add.amount,&total_sal1,&sal.ope.day,&sal.ope.month,&sal.ope.year);
        printf("\n%d\t%s\t%d\t%d\t%d\t%d/%d/%d\n",add.nbr,add.name,sal.quantity,add.amount,total_sal1,sal.ope.day,sal.ope.month,sal.ope.year);
    }
    fclose(sa);
}
void main()
{
    int a;
    printf("\n\t\t\tWelcome to our system\n");
    printf("\n\t\t\t------------------------\n\n");
    printf("\tChoose an option corresponding to your choice:\n");
    printf("\n\t1.Record\n\t2.Purchase\n\t3.Sale\n\t4.Update\n\t5.Sale's report\n\t6.Exit\n\n\t");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            create();
            break;
        case 2:
            purchase();
            break;
        case 3:
            sale();
            break;
        case 4:
               update();
               break;
        case 5:
            reportt();
            break;
        case 6:
            close();
            break;
        default:
            printf("Invalid input\n");
            break;
    }

}
