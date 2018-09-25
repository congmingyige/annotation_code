#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char str[10000];

int main()
{
    int x,y,index=0,c=0,len,i;
    bool use=0;
    FILE *in=fopen("code.txt","r");
    FILE *out=fopen("code_annotation.txt","w");
    fscanf(in,"%d %d\n",&x,&y);  //要开始注释的行
    while (fgets(str,10000,in)!=NULL)
    {
        index++;
        len=strlen(str);
        for (i=0;i<len;i++)
        {
            if (x==index && y==i+1)
            {
                fprintf(out,"/*");
                use=1;
            }
            fprintf(out,"%c",str[i]);
            if (use==1)
            {
                if (str[i]=='{')
                    c++;
                else if (str[i]=='}')
                {
                    c--;
                    if (c==0)
                    {
                        fprintf(out,"*/");
                        use=0;
                    }
                }
            }
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
/*
int main()
{
    for (i=1;i<=10;i++)
    {
        j=i+3;
        for (k=1;k<=10;k++)
        {
            j++;
        }
    }
    return 0;
}

3
7
*/
/*
int main()
{
    for (i=1;i<=3;i++) {i++; for (j=1;j<=3;j++) {j++ } }
}

2 1
3 1
3 30
*/
