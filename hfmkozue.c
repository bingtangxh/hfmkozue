#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int freq;
    unsigned char data;
    int used;
    char code[33];
    struct node *parent;
    struct node *lchild;
    struct node *rchild;
} Node;

Node tree[2048];
short nodePtr[1024];
char version[12]="v1.0.1";

int bubble_sort(int array[],const int length) {
    int i,j,temp;
    for(i=0;i<length-1;i++)
        for(j=0;j<length-1-i;j++)
            if(array[j]<array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
}

void pushNum(Node *root, const short num)
{
    char temp[9];
    if (root->lchild == NULL && root->rchild == NULL)
    {
        if (num == 1)
            temp[0] = '1';
        else
            temp[0] = '0';
        temp[1] = '\0';
        strncat(temp, root->code, 8);
        strncpy(root->code, temp, 9);
    }
    else
    {
        pushNum((root->lchild), num);
        pushNum((root->rchild), num);
    }
}

short char2num(const char i)
{
    switch (i)
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '0':
        return 0;
    default:
        return -1;
    }
}

short num2BinaryArray(int a, short array[], const int length)
{
    if (pow(2, length) < a)
        return -1;
    for (int i = 0; i < length && a > 0; i++)
    {
        array[i] = a % 2;
        a /= 2;
    }
    return 0;
}

int binaryArray2Num(short array[], const int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i] * (int)pow(2, length - 1 - i);
    }
    return sum;
}

short choiceMode(void)
{
    int slt;
    while (1)
    {
        system("cls");
        puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
        printf("�U   ��������������  %s\t�U\n",version);
        puts("�c�������������������Щ������������������������������������������f");
        puts("�U   [1]   ��   ����              �U");
        puts("�U   [2]   ��   ����              �U");
        puts("�U   [4]   ��   ����������ɫ      �U");
        puts("�U   [0]   ��   �˳�              �U");
        puts("�^�T�T�T�T�T�T�T�T�T�k�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
        putchar('\n');
        fputs("����������ѡ��", stdout);
        slt = char2num(getche());
        putchar('\n');
        putchar('\n');
        switch (slt)
        {
        case 1:
        case 2:
        case 4:
        case 0:
            return slt;
        default:
            puts("�������������밴�����������Ȼ���������롣");
            putchar('\n');
            getch();
            continue;
        }
    }
}

short choiceColor(void)
{
    char slt;
    short nextMode = 4;
    system("cls");
    puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
    puts("�U    �������������� - ѡȡ������ɫ   �U");
    puts("�c�������������������Щ����������������������������������������������������f");
    puts("�U   [1]   ��        ��ɫ��Ĭ�ϣ�      �U");
    puts("�U   [2]   ��        ����ɫ            �U");
    puts("�U   [3]   ��        ��ɫ              �U");
    puts("�U   [4]   ��        ��ɫ              �U");
    puts("�U   [5]   ��        ��ɫ              �U");
    puts("�U   [6]   ��        �ۺ�ɫ            �U");
    puts("�U   [0]   ��        ����              �U");
    puts("�^�T�T�T�T�T�T�T�T�T�k�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
    // puts("[1] ��ɫ��Ĭ�ϣ�\t[2] ����ɫ\t[3] ��ɫ\t[4] ��ɫ");
    // puts("[5] ��ɫ\t\t[6] �ۺ�ɫ\t[0] ����");
    fputs("\n���������ѡ��",stdout);
    slt = char2num(getche());
    putchar('\n');
    switch (slt)
    {
    case 1:
        system("color 07");
        break;
    case 2:
        system("color 0F");
        break;
    case 3:
        system("color 0A");
        break;
    case 4:
        system("color 0E");
        break;
    case 5:
        system("color 0B");
        break;
    case 6:
        system("color 0D");
        break;
    case 0:
        nextMode = -1;
        break;
    default:
        putchar('\n');
        puts("����������󣬰���������ԡ�");
        putchar('\n');
        getch();
        break;
    }
    return nextMode;
}

void help(void)
{
    puts("");
    puts("HFMKOZUE");
    puts("");
    puts("(c) 2022-2024 HHMY. All rights reversed.");
    puts("");
    puts("�� .source �ļ����й����������� .code �ļ����й��������롣");
    puts("");
    puts("HFMKOZUE [ /E | /D ] source dest [tree]");
    puts("");
    puts("/E\t�� source ָ�����ļ����б��롣");
    puts("/D\t�� source ָ�����ļ����н��롣");
    puts("source\tָ��Ҫ��������������ļ���");
    puts("dest\tָ������������洢�����ļ���");
    puts("tree\tʹ�� /D ѡ��ʱ������ָ�����ļ�����ʡ�ԣ���ʱҪ������ָ����");
    puts("");
}

int findMin(const int used, const int exculde)
{
    int min = 2147483647;
    int minNum = 0;
    for (int i = 0; i < used; i++)
    {
        if (tree[i].freq < min && tree[i].parent == NULL && tree[i].freq > -1 && i != exculde)
        {
            min = tree[i].freq;
            minNum = i;
        }
    }
    return minNum;
}

int buildtree(const int used_initially)
{
    int min1 = 0, min2 = 0, used = used_initially;
    while (used < 2 * used_initially)
    {
        used++;
        min1 = findMin(used, -1);
        min2 = findMin(used, min1);
        if (0)
            printf("�����ϲ��������: %c (%d) and %c (%d)\n",
                   tree[min1].data, tree[min1].freq,
                   tree[min2].data, tree[min2].freq);
        tree[used].freq = tree[min1].freq + tree[min2].freq;
        tree[used].lchild = &tree[min1];
        tree[used].rchild = &tree[min2];
        tree[used].data = '\002';
        tree[used].parent = NULL;
        tree[used].used = 1;
        tree[min1].parent = &tree[used];
        tree[min2].parent = &tree[used];
        pushNum(&tree[min1], 0);
        pushNum(&tree[min2], 1);
    }
    return used;
}

void eraseLFTail(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n' && str[i + 1] == '\0')
            str[i] = '\0';
    }
}

short getFreq(FILE *source)
{
    char current;
    short used = -1;
    while (1)
    {
        current = fgetc(source);
        if (current == EOF)
            break;
        if (nodePtr[current] == -1)
        {
            nodePtr[current] = ++used;
            tree[used].freq = 1;
            tree[used].used = 1;
            tree[used].data = current;
            tree[used].parent = NULL;
            tree[used].lchild = NULL;
            tree[used].rchild = NULL;
        }
        else
        {
            tree[nodePtr[current]].freq++;
        }
    }
    return used;
}

void tree2Str(const Node * root,char dest[],short reset)
{
    static int currentIndex=0;
    if(reset) currentIndex=0;
    if (root==NULL)
    {
        dest[currentIndex++]='#';
        dest[currentIndex]='\0';
    }
    else
    {
        dest[currentIndex++]=root->data;
        tree2Str(root->lchild,dest,0);
        tree2Str(root->rchild,dest,0);
        dest[currentIndex]='\0';
    }
}

void str2Tree(const char extStr[],Node ** T,Node * parent,const char code[],int position,short reset)
{
    static int currentIndex=0;
    static short used=-1;
    if(reset) 
    {
        used=-1;
        currentIndex=0;
    }
    if (!strlen(extStr)||extStr[currentIndex]=='\n'||extStr[currentIndex]=='\0') return;
    else {
        if (extStr[currentIndex]=='\001')
        {
            *T=NULL;
            currentIndex++;
            return;
        }
        else
        {
            
            char code1[9];
            strcpy(code1,code);
            if(position==1) strcat(code1,"1");
            else if (position==0) strcat(code1,"0");
            else if (position==2) used=used; //puts("Now processing root node.");
            *T=&tree[++used];
            nodePtr[extStr[currentIndex]]=used;
            (*T)->parent=parent;
            strcpy((*T)->code,code1);
            (*T)->data=extStr[currentIndex];
            (*T)->lchild=NULL;
            (*T)->rchild=NULL;
            currentIndex++;
            str2Tree(extStr,&((*T)->lchild),*T,code1,0,0);
            str2Tree(extStr,&((*T)->rchild),*T,code1,1,0);
        }
    }
}

void tree2File(const Node *root, FILE *dest)
{
    if (root->data == '\002')
    {
        tree2File(root->lchild, dest);
        tree2File(root->rchild, dest);
    }
    else
    {
        fputc(root->data, dest);
        fputc(' ', dest);
        fputs(root->code, dest);
        fputc('\n', dest);
    }
}

short file2Tree(FILE *source)
{
    char current, code[33];
    Node *root = &tree[0];
    short used = 0;
    while (1)
    {
        current = fgetc(source);
        if (current == EOF)
            break;
        fgetc(source);
        fgets(code, 33, source);
        eraseLFTail(code);
        root = &tree[0];
        for (int i = 0; code[i] != '\0'; i++)
        {
            if (code[i] == '0')
            {
                if (root->lchild == NULL)
                {
                    root->data = '\002';
                    root->lchild = &tree[++used];
                    root->lchild->parent = root;
                    root->lchild->used = 1;
                    root = root->lchild;
                }
                else
                {
                    root = root->lchild;
                }
            }
            else if (code[i] == '1')
            {
                if (root->rchild == NULL)
                {
                    root->data = '\002';
                    root->rchild = &tree[++used];
                    root->rchild->parent = root;
                    root->rchild->used = 1;
                    root = root->rchild;
                }
                else
                {
                    root = root->rchild;
                }
            }
            else
                printf("�����ļ��ж�ȡ����code�ַ������������е��ַ�������0Ҳ����1���������Դ��ַ���'%c'\n", code[i]);
        }
        strncpy(root->code, code,33);
        root->data = current;
    }
    root = &tree[0];
    // ��ʵ����root�Ļ�ȥҲûɶ�����ˣ�������������Ϊ��
    return used;
}

void encode(FILE *source, FILE *dest)
{
    char current;
    while ((current = fgetc(source)) != EOF)
    {
        fputs(tree[nodePtr[current]].code, dest);
    }
    //fputc('\n', dest);
}

void decode(FILE *code, FILE *dest)
{
    Node *current = &tree[0]; // �ӹ��������ĸ��ڵ㿪ʼ
    char bit;
    while ((bit = fgetc(code)) != EOF)
    {
        // ���� '0' �������ߣ����� '1' ��������
        if (bit == '0')
        {
            current = current->lchild;
        }
        else if (bit == '1')
        {
            current = current->rchild;
        }
        else
        {
            printf("�����˲��ó��ֵ���λ������ 0 Ҳ���� 1���������Դ�λ��'%c'\n", bit);
        }

        // �������Ҷ�ӽڵ㣬����ַ�
        if (current->lchild == NULL && current->rchild == NULL)
        {
            fputc(current->data, dest); // ����������ַ�
            current = &tree[0];         // ����Ϊ���ڵ�
        }
    }
}

int main(int argc, char *argv[])
{
    system("title HFMKOZUE");
    FILE *source, *code, *dest, *treeFile;
    Node *treeStart[2048], *root = &tree[0];
    // �˴����� Node ָ��� code �ļ�ָ����ڵ���ʱʹ�ã��Ѿ�����ʹ�á�
    for (int i = 0; i < 2048; i++)
    {
        treeStart[i] = &tree[i];
    }
    short mode = -1, isTreeAvailable = 0, used = 0;
    // unsigned char a[14]={0};
    char sourcePath[1145], treeStr[1145], treePath[1150], current;
    // �˴� treeStr �Ѿ�����ʹ�ã������� Dummy 
    // printf("%d\n",strncmp(argv[0],"hfmkozue.exe",13));
    // puts(argv[0]);
    if (argc > 1)
    {
        if (!strncmp(argv[1], "/e", 2) || !strncmp(argv[1], "-e", 2) || !strncmp(argv[1], "/E", 2) || !strncmp(argv[1], "-E", 2))
            mode = 1;
        if (!strncmp(argv[1], "/d", 2) || !strncmp(argv[1], "-d", 2) || !strncmp(argv[1], "/D", 2) || !strncmp(argv[1], "-D", 2))
            mode = 2;
        if (!strncmp(argv[1], "/?", 2) || !strncmp(argv[1], "-?", 2))
            mode = 3;
    }
    while (1)
    {
        used = 0;
        isTreeAvailable = 0;
        switch (mode)
        {
        case -1:
        default:
            mode = choiceMode();
            break;
        case 1:
            for (int i = 0; i < 512; i++)
            {
                tree[i].used = 0;
                strncpy(tree[i].code, "",1);
                tree[i].data = '\0';
                tree[i].freq = -1;
                tree[i].parent = NULL;
                tree[i].lchild = NULL;
                tree[i].rchild = NULL;
            }
            for (int i = 0; i < 256; i++)
            {
                nodePtr[i] = -1;
            }
            if (argc >= 3)
            {
                strncpy(sourcePath, argv[2],1145);
            }
            else
            {
                puts("������Դ�ļ�·��������...���stdin���루ͨ���� .source ��չ������");
                putchar('\n');
                fgets(sourcePath, 1145, stdin);
                eraseLFTail(sourcePath);
            }
            if (!strncmp(sourcePath, "...",5))
            {
                system("cls");
                puts("�����·�������Ҫ��������ݣ�������Ϻ�Ctrl+Z�ٰ�Enter��");
                putchar('\n');
                system("copy con stdinTemp.source");
                source = fopen("stdinTemp.source", "rt+");
                // treeFile = fopen("stdinTemp.tree", "w");
            }
            else
            {
                if ((source = fopen(sourcePath, "rt+")) == NULL)
                {
                    putchar('\n');
                    puts("���ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���������ص����˵���");
                    putchar('\n');
                    getch();
                    mode = -1;
                    break;
                }
            }
            putchar('\n');
            if (argc >= 4)
            {
                strncpy(sourcePath, argv[3],1145);
            }
            else
            {
                putchar('\n');
                puts("������Ŀ���ļ�·��������Ѵ��ڣ��ᱻ���ǣ�����...�������stdout��ͨ���� .code ��չ������");
                putchar('\n');
                fgets(sourcePath, 1145, stdin);
                eraseLFTail(sourcePath);
            }
            if (!strncmp(sourcePath, "...",5))
            {
                dest = stdout;
                treeFile = stdout;
            }
            else
            {
                if ((dest = fopen(sourcePath, "wt")) == NULL)
                {
                    putchar('\n');
                    puts("���ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���������ص����˵���");
                    putchar('\n');
                    getch();
                    mode = -1;
                    break;
                }
                strcpy(treePath, sourcePath);
                sprintf(treePath + strlen(sourcePath) - 0, ".tree");
                treeFile = fopen(treePath, "wt");
            }
            system("cls");
            used = getFreq(source);
            buildtree(used);
            rewind(source);
            putchar('\n');
            if(dest==stdout)
                puts("�����Ǳ���Ľ����\n");
            encode(source, dest);
            if (source != stdin)
                fclose(source);
            // tree2Str(&tree[used * 2], treeStr, 1);
            putchar('\n');
            putchar('\n');
            // fputs(treeStr, treeFile);
            if(treeFile==stdout)
                puts("�����Ǳ������ɵ�����\n");
            tree2File(&tree[used * 2], treeFile);
            if (treeFile != stdout)
                fclose(treeFile);
            if (dest != stdout)
                fclose(dest);

            if (argc >= 2)
                return 0;
            puts("\n\n�밴��������ء���\n");
            getch();
            mode = -1;
            break;

        case 2:
            for (int i = 0; i < 512; i++)
            {
                tree[i].used = 0;
                strncpy(tree[i].code, "",1);
                tree[i].data = '\0';
                tree[i].freq = -1;
                tree[i].parent = NULL;
                tree[i].lchild = NULL;
                tree[i].rchild = NULL;
            }
            if (argc >= 3)
            {
                strncpy(sourcePath, argv[2],1145);
            }
            else
            {
                putchar('\n');
                puts("������Դ�ļ�·��������...���stdin���루ͨ���� .code ��չ������");
                putchar('\n');
                fgets(sourcePath, 1145, stdin);
                eraseLFTail(sourcePath);
            }
            if (!strncmp(sourcePath, "...",5))
            {
                putchar('\n');
                puts("��ָ��һ�����ļ�·��������...��ֱ���ڿ���̨�����������������������У����Ƽ�����ʱ���޷����أ���\n");
                putchar('\n');
                fgets(treePath, 1145, stdin);
                eraseLFTail(treePath);
                system("cls");
                puts("�����·�������Ҫ��������ݣ�������Ϻ�Ctrl+Z�ٰ�Enter��");
                putchar('\n');
                system("copy con stdinTemp.code");
                source = fopen("stdinTemp.code", "rt");
            }
            else
            {
                if ((source = fopen(sourcePath, "rt")) == NULL)
                {
                    putchar('\n');
                    puts("���ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���������ص����˵���");
                    putchar('\n');
                    getch();
                    mode = -1;
                    break;
                }
                if (argc >= 5)
                {
                    strncpy(treePath, argv[4],1145);
                }
                else
                {
                    strcpy(treePath, sourcePath);
                    sprintf(treePath + strlen(sourcePath) - 0, ".tree");
                }
                if ((treeFile = fopen(treePath, "rt")) == NULL)
                {
                    putchar('\n');
                    puts("�����ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���\n");
                    puts("������ָ��һ�����ļ�·��������...��ֱ���ڿ���̨���������������չ����������У����Ƽ�����");
                    puts("��ʱ����������㽫ֻ�ܻص����˵���");
                    putchar('\n');
                    fgets(treePath, 1145, stdin);
                    eraseLFTail(treePath);
                }
                else
                    isTreeAvailable = 1;
            }
            if (!strncmp(treePath, "...",5))
            {
                system("cls");
                puts("�뿪ʼ��ı�������������ÿ�п�ͷ���ַ���Ȼ��һ���ո�����������Ʊ��룬Ȼ���С�������Ϻ� Ctrl+Z �ٰ� Enter��\n");
                putchar('\n');
                system("copy con stdinTemp.tree");
                source = fopen("stdinTemp.tree", "rt");
                isTreeAvailable = 1;
            }
            else
            {
                if (!isTreeAvailable)
                {
                    if ((treeFile = fopen(treePath, "rt")) == NULL)
                    {
                        putchar('\n');
                        puts("�����ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���\n");
                        puts("�밴������ص����˵�����");
                        putchar('\n');
                        getch();
                        mode = -1;
                        break;
                    }
                }
                for (int i = 0; (current = fgetc(treeFile)) != EOF && 0; i++)
                {
                    treeStr[i] = current;
                    treeStr[i + 1] = '\0';
                }
                rewind(treeFile);
            }
            putchar('\n');
            if (argc >= 4)
            {
                strncpy(sourcePath, argv[3],1145);
            }
            else
            {
                puts("������Ŀ���ļ�·��������Ѵ��ڣ��ᱻ���ǣ�����...�������stdout��ͨ���� .decode ��չ������");
                putchar('\n');
                fgets(sourcePath, 1145, stdin);
                eraseLFTail(sourcePath);
            }
            if (!strncmp(sourcePath, "...",5))
            {
                dest = stdout;
            }
            else
            {
                if ((dest = fopen(sourcePath, "wt")) == NULL)
                {
                    putchar('\n');
                    puts("���ļ�ʧ�ܣ������ļ��Ƿ���ڣ��Լ��Ƿ��ǲ��ܴ���Ŀ��ļ���������ص����˵���");
                    putchar('\n');
                    getch();
                    mode = -1;
                    break;
                }
            }
            system("cls");
            // str2Tree(treeStr, &root, NULL, "", 2, 1);
            used = file2Tree(treeFile);
            if(dest==stdout)
                puts("�����Ǳ��ν���õ����ļ����ݣ�\n");
            decode(source, dest);
            putchar('\n');
            if (source != stdin)
                fclose(source);
            if (treeFile != stdin)
                fclose(treeFile);
            if (dest != stdout)
                fclose(dest);
            if (argc >= 2)
                return 0;
            puts("\n\n�밴��������ء���\n");
            getch();
            mode = -1;
            break;
        case 3:
            help();
            return 0;
        case 4:
            mode = choiceColor();
            break;
        case 0:
            return 0;
        }
        // printf("%d\n",b++);
    }
    return 0;
}