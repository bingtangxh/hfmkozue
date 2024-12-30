#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>


typedef struct member {
    unsigned long num;
    char name[50];
    double noodle;
    unsigned short burger;
    double sauce;
    double milk;
    struct member * next;
}Member,*memberPtr;

void getNewPassword(char password2[],char userName[],int trustedInstaller){
    char password[50];
    char password1[100];
    int i,i1=0;
    char passwordSingleChar;
    char* password3=password2;
    while(1){
        system("cls");
        puts("请设定您的密码。\n");
        puts("密码只能是大小写字母、数字和美国信息交换标准代码中规定的普通符号。");
        if(trustedInstaller){
            printf("您的用户名%s意味着您是领导，您的密码必须多于11位。\n",userName);
            }
            puts("密码不能为空，且不能多于50位。");
            puts("密码只会被显示为\"*\"符号，密码需要输入两次以防止拼写错误。");
            puts("如有错误可以退格，也可在第二次输入不同的密码从而返回。");
            puts("输入您的密码，然后按Enter。\n");
            i=0;
            while(1){
                passwordSingleChar=getch();
                if(passwordSingleChar=='\r'){
                    password[i++]='\0';
                    break;
                }
                //这里就是\r，不是\n
                else if(passwordSingleChar!='\b'){
                    if(i<50){
                        password[i++]=passwordSingleChar;
                        putchar('*');
                    } else {
                        putchar('\a');
                    }
                    continue;
                } else {
                    if(i>0){
                        password[--i]='\0';
                        putchar('\b');
                        putchar(' ');
                        putchar('\b');
                    } else {
                        putchar('\a');
                    }
                    continue;
                }
            }
            if(trustedInstaller&&i<11){
                puts("\n\n说了你是领导，密码必须不少于12位。请按任意键重试。\n");
                getch();
                continue;
            }
            system("cls");
            puts("请再次输入您的密码，以防止笔误。\n");
            puts("如果第一次输入有误，请在这里输入明显不匹配的密码从而重试。\n");
            putchar('\n');
            i=0;
            while(1){
                passwordSingleChar=getch();
                if(passwordSingleChar=='\r'){
                    password1[i++]='\0';
                    break;
                }
                else if(passwordSingleChar!='\b'){
                    if(i<51){
                        password1[i++]=passwordSingleChar;
                        putchar('*');
                    } else {
                        putchar('\a');
                    }
                    continue;
                } else {
                    if(i>0){
                        password1[--i]='\0';
                        putchar('\b');
                        putchar(' ');
                        putchar('\b');
                    } else {
                        putchar('\a');
                    }
                    continue;
                }
            }
            system("cls");
            if(strcmp(password,password1)==0){
                break;
            } else {
                puts("您两次输入密码不一致，请确保没有手抖。按任意键从第一次重试。");
                getch();
                continue;
            }
        }
        i=0;
        while(password1[i]!='\0'){
            password1[i]=password1[i]^6;
            i++;
        }
        i=0;
        while(password1[i]!='\0'){
            i1=sprintf(password3,"%x",password1[i++]);
            password3+=i1;
        }
}

int verify(char password[],char password2[]){
    int i=0,i1;
    char* password3;
    char password1[100];
    while(password[i]!='\0'){
        password[i]=password[i]^6;
        i++;
    }
    i=0;
    i1=0;
    password3=password1;
    while(password[i]!='\0'){
        i1=sprintf(password3,"%x",password[i++]);
        password3+=i1;
    }
    if(strcmp(password1,password2)==0)return 1;
    else return 0;
}

int main(int argc,char *argv[]){
    
    FILE* data=fopen("data.csv","rt+");
    FILE* data1=fopen("data1.csv","wt");
    int slt,i=0,i1;
    int trustedInstaller;
    char temp[1000];
    system("title 会员制餐厅会员管理系统");
    logon:
    system("cls");
    putchar('\n');
    puts("╔════════════════════════════════════════════╗");
    puts("║            会员制餐厅会员管理系统          ║");
    puts("╟─────────┬──────────────────────────────────╢");
    puts("║   [1]   │         登录系统                 ║");
    puts("║   [2]   │         退出系统                 ║");
    puts("║   [3]   │         关闭电脑                 ║");
    puts("╚═════════╧══════════════════════════════════╝");
    puts("\n请输入您的选择对应的编号。");
    slt=getch();
    switch (slt)
    {
    case '1':
        system("cls");
        goto logon1;

    case '3':
        system("shutdown -s -t 60");
    case '2':
        exit(0);

    default:
        goto logon;
    }
    logon1:
    system("if not exist user.txt copy nul user.txt");
    char userName[50],userName1[50],* userName2,password[50],password1[100],password2[100],passwordSingleChar;
    char * password3;
    FILE * user=fopen("user.txt","rt+");
    if(fgetc(user)==-1){
        system("cls");
        puts("您好，当前没有用户。\n\n请新建一个。");
        typeNewUserName:
        putchar('\n');
        puts("请输入用户名：");
        while(fgets(userName,50,stdin)==NULL){
            puts("您的输入过长或有误。\n\n最多只能输入50个字符。\n");
        }
        i=0;
        while(userName[i]!='\n'&&userName[i]!='\0'){
            if(userName[i]==' '){
                puts("您的用户名含有空格，这是不允许的。");
                goto typeNewUserName;
            }
            i++;
        }
        if(i==0){
            puts("用户名不能为空。");
            goto typeNewUserName;
        }
        userName[i]='\0';
        i=0;
        rewind(user);
        while(1){
            if(fscanf(user,"%50s %100s\n",userName1,password2)==-1){
                break;
            } else {
                if(strcmp(userName,userName1)==0){
                    puts("您输入的用户名已经存在，请重新指定一个不重复的。");
                    goto typeNewUserName;
                }
            }
        }
        // printf("%d\n",i);
        // getch();
        i=0;
        if((strcmp(userName,"Junpei")==0||strcmp(userName,"Mahiro")==0)){
            trustedInstaller=1;
        } else {
            trustedInstaller=0;
        }
        fseek(user,0,2);
        fputs(userName,user);
        fputc(' ',user);
        getNewPassword(password2,userName,trustedInstaller);
        fputs(password2,user);
        fputc('\n',user);
        addUserEnd:
        fclose(user);
        user=fopen("user.txt","rt+");
    } else {
        typeUserName:
        puts("请输入用户名，然后按Enter。");
        putchar('\n');
        puts("留空可返回。");
        fgets(userName,50,stdin);
        i=0;
        while(userName[i]!='\n'&&userName[i]!='\0'){i++;}
        if(i==0) goto logon;
        userName[i]='\0';
        i=0;
        rewind(user);
        while(1){
            if(fscanf(user,"%50s %100s\n",userName1,password2)==-1){
                rewind(user);
                system("cls");
                puts("\n您输入的用户名不存在。");
                goto typeUserName;
            }
            if(strcmp(userName,userName1)==0){break;}
            else {continue;}
        }
        putchar('\n');
        typePassword:
        fputs("请输入密码：",stdout);
        /*这里用fputs是为了用户输入紧挨提示文字的冒号*/
        i=0;
        while(1){
            passwordSingleChar=getch();
            if(passwordSingleChar=='\r'){
                password[i++]='\0';
                break;
            }
            else if(passwordSingleChar!='\b'){
                if(i<50){
                    password[i++]=passwordSingleChar;
                    putchar('*');
                } else {
                    putchar('\a');
                }
                continue;
            } else {
                if(i>0){
                    password[--i]='\0';
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                } else {
                    putchar('\a');
                }
                continue;
            }
        }
        if(i==1) goto typeUserName;
        i=0;
        
        if(verify(password,password2)==1){
            goto mainMenu;
        } else {
            puts("\n密码错误，请按任意键重新输入用户名……");
            getch();
            system("cls");
            goto typeUserName;

        }
    }
    
    mainMenu:
    if((strcmp(userName,"Junpei")==0||strcmp(userName,"Mahiro")==0)){
        trustedInstaller=1;
    } else {
        trustedInstaller=0;
    }
    system("cls");
    printf("当前用户：%s\n\n",userName);
    puts("╔════════════════════════════════════════════╗");
    puts("║            会员制餐厅会员管理系统          ║");
    puts("╟─────────┬──────────────────────────────────╢");
    puts("║   [1]   │     会员查询、编辑和删除         ║");
    puts("║   [2]   │     会员添加                     ║");
    puts("║   [3]   │     将会员按雪堡肉数目排序       ║");
    puts("║   [4]   │     将会员按牛奶布丁数目排序     ║");
    puts("║   [5]   │     添加管理员                   ║");
    puts("║   [6]   │     修改本管理员密码             ║");
    puts("║   [7]   │     退出                         ║");
    puts("╚═════════╧══════════════════════════════════╝");
    puts("\n请输入您的选择对应的编号。");
    slt=getch();
    Member current,current1;
    switch (slt)
    {
    case '1':
        search:
        system("cls");

        putchar('\n');
        puts("╔════════════════════════════════════════════╗");
        puts("║            会员制餐厅会员管理系统          ║");
        puts("╟─────────┬──────────────────────────────────╢");
        puts("║   [1]   │         按编号查找               ║");
        puts("║   [2]   │         按名字查找               ║");
        puts("║   [3]   │         列出所有                 ║");
        puts("║   [0]   │         返回                     ║");
        puts("╚═════════╧══════════════════════════════════╝");
        puts("\n请输入您的选择对应的编号。");
        slt=getch();
        switch(slt)
        {
            case '1':
                system("cls");
                typeNum:
                puts("编号从1开始数，而不是从0开始。");
                putchar('\n');
                puts("请输入您要查找的编号，然后按Enter：");
                putchar('\n');
                while(scanf("%lu",&slt)!=1){goto typeNum;}
                rewind(data);
                for(i=0;i<slt;i++){
                    fseek(data,-1,1);
                    fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk);
                    if(fgetc(data)==-1){
                        puts("没有找到您输入的编号，任意键重试……");
                        getch();
                        goto typeNum;
                    }
                }
                printf("%d,%s\t,%lg\t,%hu\t,%lg\t,%lg\n",i,current.name,current.noodle,current.burger,current.sauce,current.milk);
                putchar('\n');
                puts("请按任意键继续……");
                getch();
                break;
            case '2':
                typeSearchWord:
                system("cls");
                puts("请输入您要寻找的顾客名称，然后按Enter。");
                putchar('\n');
                puts("不输入任何内容就按Enter可返回。");
                putchar('\n');
                fgets(userName1,50,stdin);
                i=0;
                while(userName1[i]!='\n'&&userName1[i]!='\0'){
                    if(userName1[i]==' '||userName1[i]==','){
                        puts("您的用户名含有空格或逗号，这是不允许的。");
                        goto typeSearchWord;
                    }
                    i++;
                }
                if(i==0){
                    puts("用户名不能为空。");
                    goto typeSearchWord;
                }
                userName1[i]='\0';
                rewind(data);
                i=0;
                while(1){
                    if(fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk)==-1){
                        printf("未找到你查找的用户名%s，任意键重试……",userName1);
                        getch();
                        goto typeSearchWord;
                    }
                    i++;
                    //printf("%s %s\n",current.name,userName1);
                    if(strcmp(current.name,userName1)==0){break;}
                }
                printf("%d,%s\t,%lg\t,%hu\t,%lg\t,%lg\n",i,current.name,current.noodle,current.burger,current.sauce,current.milk);
                puts("请按任意键继续……");
                getch();
                break;
            case '3':
                rewind(data);
                i=0;
                system("cls");
                puts("序号 姓名\t雪酱拌面 雪堡肉\t牛奶布丁 特制酱料");
                while(fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf ",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk)!=-1){
                    printf("%d %s",++i,current.name);
                    if(strnlen(current.name,50)<=(4+(i<10)))putchar('\t');
                    printf("\t%lg\t%hu\t%lg\t%lg\n",current.noodle,current.burger,current.sauce,current.milk);
                }
                printf("一共有%d个顾客。\n",i);
                puts("请按任意键返回……");
                getch();
                goto search;
            case '0':
                goto mainMenu;
        }
        edit:
        system("cls");
        printf("当前顾客：%s %s\n",current.name,userName1);
        puts("╔════════════════════════════════════════════╗");
        puts("║            会员制餐厅会员管理系统          ║");
        puts("╟─────────┬──────────────────────────────────╢");
        puts("║   [1]   │         编辑                     ║");
        puts("║   [2]   │         删除                     ║");
        puts("║   [0]   │         返回                     ║");
        puts("╚═════════╧══════════════════════════════════╝");
        puts("\n请输入您的选择对应的编号。");
        slt=getch();
        switch(slt)
        {
            case '1':
                typeMemberName:
                printf("%d,%s\t,%lg\t,%hu\t,%lg\t,%lg\n",i,current.name,current.noodle,current.burger,current.sauce,current.milk);

                fputs("请输入顾客名称，留空则保持不变：",stdout);
                fgets(current1.name,50,stdin);
                i=0;
                while(current1.name[i]!='\n'&&current1.name[i]!='\0'){
                    if(current1.name[i]==' '||current1.name[i]==','){
                        puts("您的用户名含有逗号，这是不允许的。");
                        system("pause");
                        system("cls");
                        goto typeNewMemberName;
                    }
                    i++;
                }
                if(i==0){
                    strcpy(current1.name,userName1);
                } else {
                    current1.name[i]='\0';
                }
                i=0;
                puts("请在下方分别输入这些数值，每个数值各占一行。");
                fputs("\n雪酱拌面（克）：",stdout);
                while(scanf("%lf",&current1.noodle)!=1){goto typeMemberName;}
                fputs("\n雪堡肉（0~65535的整数）：",stdout);
                while(scanf("%hu",&current1.burger)!=1){goto typeMemberName;}
                fputs("\n特制酱料（克）：",stdout);
                while(scanf("%lf",&current1.sauce)!=1){goto typeMemberName;}
                fputs("\n牛奶布丁（克）：",stdout);
                while(scanf("%lf",&current1.milk)!=1){goto typeMemberName;}
                rewind(data);
                while(fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk)!=-1){
                    //printf("%s %s\n",current.name,current1.name);
                    if(strcmp(current.name,current1.name)==0){
                        fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",current1.name,current1.noodle,current1.burger,current1.sauce,current1.milk);
                    } else {
                        fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",current.name,current.noodle,current.burger,current.sauce,current.milk);
                    }
                }
                fclose(data);
                fclose(data1);
                system("pause");
                system("move /y data1.csv data.csv");
                data=fopen("data.csv","rt+");
                data1=fopen("data1.csv","wt");
                goto search;
            case '2':
                current1=current;
                rewind(data);
                while(fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk)!=-1){
                    if(strcmp(current.name,current1.name)!=0){
                        fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",current.name,current.noodle,current.burger,current.sauce,current.milk);
                    }
                }
                fclose(data);
                fclose(data1);
                system("move /y data1.csv data.csv");
                data=fopen("data.csv","rt+");
                data1=fopen("data1.csv","wt");
                goto search;
            case '0':
                system("cls");
                goto search;
            default:
                system("cls");
                goto edit;
        }
        searchComplete:
        system("cls");
        goto search;
    case '2':
        Member new;
        system("cls");
        typeNewMemberName:
        fputs("请输入新顾客名称：",stdout);
        fgets(new.name,50,stdin);
        i=0;
        while(new.name[i]!='\n'&&new.name[i]!='\0'){
            if(new.name[i]==' '||new.name[i]==','){
                puts("您的用户名含有逗号，这是不允许的。");
                goto typeNewMemberName;
            }
            i++;
        }
        if(i==0){
            puts("用户名不能为空。");
            goto typeNewMemberName;
        }
        new.name[i]='\0';
        i=0;
        rewind(data);
        while(fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk)!=-1){
                    if(strcmp(current.name,new.name)==0){
                        printf("名字已存在，请重试。\n\n");
                        goto typeNewMemberName;
                    }
                }
        system("cls");
        puts("请在下方分别输入这些数值，每个数值各占一行。如输入无效，会被忽略，需要重新输入。");
        fputs("\n雪酱拌面（克）：",stdout);
        while(scanf("%lf",&new.noodle)!=1){goto typeNewMemberName;}
        fputs("\n雪堡肉（0~65535的整数）：",stdout);
        while(scanf("%hu",&new.burger)!=1){goto typeNewMemberName;}
        fputs("\n特制酱料（克）：",stdout);
        while(scanf("%lf",&new.sauce)!=1){goto typeNewMemberName;}
        fputs("\n牛奶布丁（克）：",stdout);
        while(scanf("%lf",&new.milk)!=1){goto typeNewMemberName;}
        fputs("\n顾客编号（输入0则添加到末尾）：",stdout);
        while(scanf("%lu",&new.num)!=1){goto typeNewMemberName;}
        for(i=1,rewind(data);i!=new.num;i++){
            i1=fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk);
            if(i1!=-1){
                fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",current.name,current.noodle,current.burger,current.sauce,current.milk);
            } else {break;}
        }
        fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",new.name,new.noodle,new.burger,new.sauce,new.milk);
        for(;1;i++){
            i1=fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",current.name,&current.noodle,&current.burger,&current.sauce,&current.milk);
            if(i1!=-1){
                fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",current.name,current.noodle,current.burger,current.sauce,current.milk);
            } else {break;}
        }
        fclose(data);
        fclose(data1);
        system("move /y data1.csv data.csv");
        data=fopen("data.csv","rt+");
        data1=fopen("data1.csv","wt");
        break;
        

    case '3':
    case '4':
        int is;
        if(slt==3) is=1;
        else is=2;
        rewind(data);
        Member *head,*temp1,*temp2,*temp3,*temp4,temp5,*temp6;
        head=(Member*)malloc(sizeof(Member));
        temp2=head;
        i=0;
        while(1){
            i++;
            i1=fscanf(data,"%[^,],%lf ,%hu,%lf ,%lf \n",temp2->name,&temp2->noodle,&temp2->burger,&temp2->sauce,&temp2->milk);
            if(i1==-1){
                free(temp1->next);
                temp1->next=NULL;
                break;
            } else {
                //printf("%s\t,%lg\t,%hu\t,%lg\t,%lg\t\n",temp2->name,temp2->noodle,temp2->burger,temp2->sauce,temp2->milk);
                temp2->next=(Member*)malloc(sizeof(Member));
                temp1=temp2;
                temp2=temp2->next;
            }
        }
        system("cls");
        puts("[1] 升序\t[0]降序");
        puts("输入你的选择：");
        modeSelect:
        slt=getch();
        switch(slt){
            case '1':
                slt=1;
                break;
            case '0':
                slt=0;
                break;
            default:
                putchar('x');
                goto modeSelect;
        }
        for(i1=0;i1<i;i1++){
            temp1=head;
            temp2=temp1->next;
            for(int i2=0;i2<i-i1;i2++){
                //printf("%d",i2);
                if(((((temp1->burger)>(temp2->burger))==slt)&&is==1)||((((temp1->milk)>(temp2->milk))==slt)&&is==2)){
                    temp5=*temp1;
                    *temp1=*temp2;
                    *temp2=temp5;
                    temp6=temp1->next;
                    temp1->next=temp2->next;
                    temp2->next=temp6;
                }
                temp1=temp1->next;
                temp2=temp2->next;
                if(temp2==NULL)break;
            }
            //putchar('\n');
        }
        temp1=head;
        while(temp1!=NULL){
            fprintf(data1,"%s,%lg ,%hu,%lg ,%lg \n",temp1->name,temp1->noodle,temp1->burger,temp1->sauce,temp1->milk);
            printf("%s\t,%lg\t,%hu\t,%lg\t,%lg\t\n",temp1->name,temp1->noodle,temp1->burger,temp1->sauce,temp1->milk);
            temp1=temp1->next;
        }
        fclose(data);
        fclose(data1);
        system("move /y data1.csv data.csv");
        data=fopen("data.csv","rt+");
        data1=fopen("data1.csv","wt");
        break;

    case '5':
        goto typeNewUserName;
        break;

    case '6':
        rewind(user);
        FILE * user1=fopen("user1.txt","wt");
        while(1){
            if(fscanf(user,"%50s %100s\n",userName1,password2)==-1){
                break;
            } else {
                if(strcmp(userName,userName1)==0){
                    fputs(userName1,user1);
                    fputc(' ',user1);
                    getNewPassword(password2,userName,trustedInstaller);
                    fprintf(user1,"%s",password2);
                    fputc('\n',user1);
                } else {
                    fprintf(user1,"%s %s\n",userName1,password2);
                }
            }
        }
        fclose(user);
        fclose(user1);
        system("move /y user1.txt user.txt");
        user=fopen("user.txt","rt+");
        break;

    case '7':
        fclose(user);
        fclose(data);
        goto logon;

    default:
        goto mainMenu;
    }
    goto mainMenu;
    end:
}
