#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char str[10000];

int main()
{
    int line,index=0,c=0,len,i;
    bool vis=0;
    FILE *in=fopen("code.txt","r");
    FILE *out=fopen("code_annotation.txt","w");
    fscanf(in,"%d\n",&line);  //Ҫ��ʼ����ע�͵���
    while (fgets(str,10000,in)!=NULL)
    {
        index++;
        ///�ӵ�һ����'{'��ʼ���㡣��֮ǰ������Ҫע��
        if (index==line || (index>line && (vis==0 || c!=0)))
        {
            len=strlen(str);
            for (i=0;i<len;i++)
                if (str[i]=='{')
                {
                    c++;
                    vis=1;
                }
                else if (str[i]=='}')
                    c--;
            ///ȥ��ע��
            fprintf(out,"%s",str+2);
        }
        else
            fprintf(out,"%s",str);
    }
    fclose(in);
    fclose(out);
    return 0;
}
/*
3
int main()
{
//    for (i=1;i<=10;i++)
//    {
//        j=i+3;
//        for (k=1;k<=10;k++)
//        {
//            j++;
//        }
//    }
    return 0;
}


7
int main()
{
    for (i=1;i<=10;i++)
    {
        j=i+3;
        for (k=1;k<=10;k++)
//        {
//            j++;
//        }
    }
    return 0;
}
*/
/*
2
int main()
//{
//    for (i=1;i<=3;i++) {i++; for (j=1;j<=3;j++) {j++ }}
//}

3
int main()
{
//    for (i=1;i<=3;i++) {i++; for (j=1;j<=3;j++) {j++ }}
}
*/
