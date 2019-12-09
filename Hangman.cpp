#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    char strguess[20], strout[20]="",temp[20],uin[2],uguess[26]="",cont;
    int i,flag,gflag,glength,length,tries;
    double score,wordcount;
    char staticdata[][20]={"london","delhi","accra", "amsterdam", "paris", "washington", "victoria"};
    cont=1;
    wordcount=0;
    score=0;
    do
    {
        wordcount=0;
        cout<<"\t\t\t\t  HANGMAN"<<endl<<endl<<endl;
        cout<<"Enter a letter:"<<endl<<endl;
        wordcount++;
        for(i=0;i<20;i++)
            strguess[i]='\0';
        for(i=0;i<26;i++)
            uguess[i]='\0';
        for(i=0;i<20;i++)
            temp[i]='\0';
        for(i=0;i<20;i++)
            strout[i]='\0';
        strcpy(strguess,staticdata[rand()%10]);
        length=strlen(strguess);
        tries=0;
        for(i=0;i<length;i++)
            strout[i]='-';
        cout<<strout;
        cout<<"    Fails Left: "<<tries<<"/7"<<endl;
        do
        {
            flag=1;
            strcpy(temp,strguess);
            cin>>uin;
            strlwr(uin);
            for(i=0;i<length;i++)
            {
                if(temp[i]==uin[0])
                {
                    strout[i]=uin[0];
                    flag=0;
                }
            }
        if(flag==1) tries++;
        glength=strlen(uguess);
        gflag=0;
        for(i=0;i<glength;i++)
        {
            if(uguess[i]==uin[0])
            {
                gflag=1;
                break;
            }
        }
        if(gflag==0)
            strcat(uguess,uin);
        cout<<strout;
        cout<<"    Fails Left: "<<tries<<"/7"<<"    Guessed Letters: "<<uguess<<endl;
        }while(tries<=7&&strcmp(strguess,strout));
           score+=tries;
           cout<<endl<<endl<<endl<<"YOUR SCORE = "<<score/wordcount<<endl<<endl;
           cout<<"Enter 'q' to Quit, other key to continue"<<endl;
           cin>>cont;
    }while(cont!='q');
    return 0;
}
