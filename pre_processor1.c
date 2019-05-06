#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("a.out filename\n");
		return ;
	}
	FILE*fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		perror("fopen");
		return;
	}
	char ch[100],ch1,str[100];
	int i=0,l=0; 
	while(fscanf(fp,"%s",ch)!=EOF)
	{
		if(strcmp(ch,"#include")==0)
		{
			while((ch1=fgetc(fp))!=EOF)
			{
				str[i++]=ch1;
				if(ch1=='>')
					break;
			}
			str[i]='\0';
		}

	}
	int j,tmp=0,len=strlen(str),m=0;
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
			str[i]=str[i+1];
		if((str[i]=='<') || (str[i]=='>'))
		{
			for(j=i;j<len;j++)
			{
				str[j]=str[j+1];
			}
			i--;
		}
	}
	rewind(fp);
	char p[100]="/usr/include/",a;
        strcat(p,str);
        printf("<----------------%s-------------->\n",p);
        FILE*fp1=fopen(p,"w");
        FILE*fp2=fopen("myfile","w");
	char ch3;int k=0;
        while((ch3=fgetc(fp1))!=EOF)
        {
                l++;
		fputc(ch3,fp2);
        }
        printf("l=%d\n",l);
	fseek(fp,18,0);
	while((ch3=fgetc(fp))!=EOF)
        {      m++;
		fputc(ch3,fp2);
             
        }
        printf("m=%d\n",m);
         
        for(i=0;i<m+l;i++)
        {
           if(p[i]=='/' && p[i+1]=='*')
                {
                  for(j=i;p[j];j++,i++)
                     {
                        if(p[j]=='*' && p[j]=='/')
                         {j++;
                             break;
                        } 
                  }
                }
               fputc(p[i],fp);
        }

    }

