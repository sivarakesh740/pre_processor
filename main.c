#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
        if(argc!=2)
        {
           printf("file name ?\n");
           return;
        }
        int i=0,j=0,k=0;
        char ch,*p=NULL,*q=NULL,v,*x,b[20],a[20]="/usr/include/",buf[1000],c[100];
        FILE *fp=fopen(argv[1],"r");
        FILE *fs=fopen("myfile","w");
        while((ch=fgetc(fp))!=EOF)
        {
                p=realloc(p,(i+1)*sizeof(char));
                p[i++]=ch;
        }
        p[i]='\0';
        for(i=0;p[i];i++)
        {
                if(p[i]=='<')
                {
                        j=0;
                        for(++i;p[i]!='>';i++)
                        {
                                b[j++]=p[i];
                        }
                        ++i;
                        b[j]='\0';
                        puts(b);
                        strcat(a,b);
                        printf("************%s************\n",a);//header file include
                        FILE *f=fopen(a,"r");
                        j=0;
                        while((v=fgetc(f))!=EOF)
                        {
                                q=realloc(q,(j+1)*sizeof(char));
                                q[j++]=v;

                        }
                        q[j]='\0';

                        for(j=0;q[j];j++)
                        {
                                if((q[j]=='/') && (q[j+1])=='*')
                                {
                                        for(++j;q[j];j++)
                                        {
                                                if((q[j]=='*') && (q[j+1])=='/')
                                                {
                                                        ++j;
                                                        break;
                                                }
                                        }
                                }


                                else
                                {
                                        fputc(q[j],fs);
                                }
                        }
                }

                if((p[i]=='/') && (p[i+1])=='*')
                {
                        for(++i;p[i];i++)
                        {
                                if((p[i]=='*') && (p[i+1])=='/')
                                {
                                        ++i;
                                        break;
                                }
                        }
                }
                else if((p[i]=='/') &&(p[i+1]=='/'))
                {
                        for(++i;p[i]!='\n';i++);
                }
                else
                {
                        fputc(p[i],fs);
                }
        }


 while(x=strstr(x,"#define"))
        {

                sscanf(x+strlen("#define") ,"%s %s",c,buf);
                x=x+strlen("#define");

        }
        for(i=0;p[i];i++)
        {
                if(p[i]=='#')
                for(i;p[i]!='\n';++i);
                else if(p[i]==c[0])
                {
                        for(j=1;c[j]!=')';j++)
                        {
                                if(p[i+j]!=c[j])
                                        break;
                        }
                        if(c[j]==')')
                        {
                                i=i+strlen(c);
                                for(k=0;buf[k];k++)
                                        fputc(buf[k],fs);
                        }
                }
                fputc(p[i],fs);
        }
}

