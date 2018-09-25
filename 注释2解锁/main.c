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
    fscanf(in,"%d %d\n",&x,&y);  //要开始解锁注释的行
    while (fgets(str,10000,in)!=NULL)
    {
        index++;
        len=strlen(str);
        for (i=0;i<len;i++)
        {
            if (x==index && y==i+1)
            {
                i+=2;
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
                        i+=2;
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
