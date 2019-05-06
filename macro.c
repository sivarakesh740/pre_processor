 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
        int i=0,j=0,k,l=0;
        char ch,*x,*p=NULL,c,b[20],a[20]="/usr/include/",buf[80];
        FILE *fp=fopen(argv[1],"r");
        FILE *fs=fopen("myfile","w");
        while((ch=fgetc(fp))!=EOF)
        {
                p=realloc(p,(i+1)*sizeof(char));
                p[i++]=ch;
        }
        p[i]='\0';
        puts(p);
        x=p; 
        
        while(x=strstr(x,"#define"))
        {

                sscanf(x+strlen("#define") ,"%s %s",b,buf);
                x=x+strlen("#define");

        }
        for(i=0;p[i];i++)
        {
                if(p[i]=='#')
                for(i;p[i]!='\n';++i);
                else if(p[i]==b[0])
                {
                        for(j=1;b[j]!=')';j++)
                        {
                                if(p[i+j]!=b[j])
                                        break;
                        }
                        if(b[j]==')')
                        {       
                                i=i+strlen(b);
                                for(k=0;buf[k];k++)
                                        fputc(buf[k],fs);
                        }
                }
                fputc(p[i],fs);
         }
}
            
