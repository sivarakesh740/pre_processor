#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int i=0,j=0,k,l=0;
	char ch,*p=NULL,*r=NULL,*q=NULL,c,b[20],a[20]="/usr/include/",buf[20],*x,mac[20];
	FILE *fp=fopen(argv[1],"r");
	FILE *fs=fopen("myfile","w");
	while((ch=fgetc(fp))!=EOF)
	{
		p=realloc(p,(i+1)*sizeof(char));
		p[i++]=ch;	
	}
	x=p;
	while(x=strstr(x,"#define"))
	{

		sscanf(x+strlen("#define") ,"%s %s",mac,buf);
		x=x+strlen("#define");

	}
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
			strcat(a,b);
			printf("************%s************\n",a);
			FILE *f=fopen(a,"r");
			j=0;
			while((c=fgetc(f))!=EOF)
			{
				q=realloc(q,(j+1)*sizeof(char));
				q[j++]=c;

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
		else if((p[i]=='/') && (p[i+1])=='*')
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
   		fclose(fs);
		fs=fopen("myfile","r+");
		i=0;
		while((ch=fgetc(fs))!=EOF)
		{
		p=realloc(p,(i+1)*sizeof(char));
		p[i++]=ch;
		}
               for(i=0;p[i];i++)
               {
                if(p[i]=='#')
                {
                        for(i;p[i]!='\n';++i);
                }
                if(p[i]==mac[0])
                {
                        for(j=1;mac[j]!='(';j++)
                        {
                                if(p[i+j]!=mac[j])
                                {
                                        break;}
                        }
                        if(mac[j]=='(')
                        {i=i+8;
			 for(k=0;buf[k];k++)
                                        {
                                                if(buf[k]=='x')
                                                buf[k]='a';
                                                if(buf[k]=='y')
                                                buf[k]='b';
                                        fputc(buf[k],fs);
                                        }
                        }

                }
                fputc(p[i],fs);
        }
}

	



