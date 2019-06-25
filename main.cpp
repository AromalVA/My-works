#include <iostream>

using namespace std;
 float credits;
 int n;
 int count1=0;
struct Cell
{
    float column;
    int raw;
    float value;

};
struct Player
{
    char name[100];
    float credit;
    float points;
};
    int output[100];
int req[2];
Player players[100];
Cell Ptable[100000];

float largest();
int look(int, float );




void requ()
{
    int j=0;
    for(int i=1;i<=n;i++)
    {
        if(output[i]==0 )
        {
            req[j]=i;
            j++;
            if(j==2)
            {
                return;
            }
        }
    }
}






void setcell(int raw,float col,float value)
        {   //cout<<"abcdefg: "<<value;
            int i;
    for(i=0;i<=(credits*2*(n+1));i++)   {
            {
                if(Ptable[i].raw==raw && Ptable[i].column==col)
                {
                   // cout<<"we are in !";
                    Ptable[i].value=value;
                    return;
                }
            }
        }
        }
void printcell(int raw,float col)
{
//cout<<"in\n";
   int i;
    for(i=0;i<=(credits*2*(n+1));i++)   {
       if(Ptable[i].raw==raw && Ptable[i].column==col)
       {
           cout<<Ptable[i].value;
       }
   }
}
float returncell(int raw,float col)
{
      int i;
    for(i=0;i<=(credits*2*(n+1));i++)   {
       if(Ptable[i].raw==raw && Ptable[i].column==col)
       {
           return Ptable[i].value;
       }
   }

}





int main()
    {
        cout<<"Enter max credits: ";

        cin>>credits;

        cout<<"\nEnter number of players: ";
        cin>>n;
        cout<<"\nEnter details: ";
        cout<<"\nEnter Name, Points, Credit respectively: ";
        int i;
        for(i=1;i<=n;i++)
        {
            cout<<"\nPlayer "<<i<<" :";
            cin>>players[i].name>>players[i].points>>players[i].credit;
        }

        //players[1].points=84785;
       // cout<<"print something here!"<<players[1].points<<"\n";


        //Sorting
        Player temp;
        int j;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(players[i].credit>players[j].credit)
                {
                    temp=players[i];
                    players[i]=players[j];
                    players[j]=temp;
                }
                else if(players[j].credit==players[i].credit)
                {
                    if(players[i].points>players[j].points)
                    {
                        temp=players[i];
                        players[i]=players[j];
                        players[j]=temp;
                    }

                }
            }
        }
    for(i=1;i<=n;i++)
    {
        cout<<"\n"<<players[i].name;
        cout<<"\n"<<players[i].points;
        cout<<"\n"<<players[i].credit;
        cout<<"\n";
    }
    int r;
    float c;
    i=0;
    r=0;
    c=0;

    while(i<=(credits)*2*(n+1))
    {


        while(c<=credits)
        {
            Ptable[i].raw=r;
            Ptable[i].column=c;
            i++;
            c=c+0.5;
        }
        r++;
        c=0;

    }
    float k;
        for(k=0;k<=credits;k+=0.5)
        {
            setcell(0,k,0);
        }

        for(i=0;i<=n;i++)
        {
            setcell(i,0,0);
        }
    float l;
    float extra;
    for(i=1;i<=n;i++)
    {
        setcell(i,(players[i].credit),(players[i].points));

            for(l=1;l<players[i].credit;l+=0.5)
            {
                setcell(i,l,returncell((i-1),l));
            }

             for(l=players[i].credit+0.5;l<=credits*2;l+=0.5)
            {
                extra=l-players[i].credit;
                setcell(i,l,(returncell(i-1,extra)+players[i].points));
            }

    }

          /*  for(i=0;i<=n;i++)
            {
                for(k=0;k<=credits;k+=0.5)
                {
                    printcell(i,k);
                    cout<<" ";
                }
                cout<<"\n";
            }
             */
    float x=largest();
            for(i=n;i>0;i--)
            {
                if(look(i,x)==1 && look(i-1,x)==0)
                {
                    output[i]=1;
                    x= x-players[i].points;
                    //cout<<"\nnew max:"<<x;
                }
                else
                {
                    output[i]=0;
                }
            }
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
        cout<<output[i]<<" ";
    }
     cout<<"\n";
     int count1=0;
    for(i=1;i<=n;i++)
    {
        if(output[i]==1)
        {
            credits=credits-players[i].credit;
            count1++;
        }
    }
      for(i=1;i<=n;i++)
    {
        cout<<output[i]<<" ";
    }
     cout<<"\n";
    for(i=1;i<=n;i++)
    {
        if(output[i]==1)
        {
            cout<<players[i].name<<endl;
        }
    }
    credits=100;
      for(i=1;i<=n;i++)
    {
        if(output[i]==1)
        {
            credits=credits-players[i].credit;
        }
    }
cout<<"\nCredits remaining: "<<credits;

if(count1<11)
{
     requ();
    float val;
    val=players[req[0]].credit+players[req[1]].credit-credits;
    for(i=1;i<=n;i++)
    {
        if(output[i]==1 && players[i].credit>=val)
        {
            output[i]=0;
            output[req[0]]=1;
            output[req[1]]=1;
            break;
        }
    }
  cout<<"New output: ";
  for(i=1;i<=n;i++)
    {
        cout<<output[i]<<" ";
    }
     cout<<"\n";
    for(i=1;i<=n;i++)
    {
        if(output[i]==1)
        {
            cout<<players[i].name<<endl;
        }
    }
    credits=100;
      for(i=1;i<=n;i++)
    {
        if(output[i]==1)
        {
            credits=credits-players[i].credit;
        }
    }
cout<<"\nCredits remaining: "<<credits;

}



}






float largest()
{
    float largest=Ptable[0].value;
   for(int i=0;i<=credits*2*(n+1);i++)
   {
       if(Ptable[i].value>largest)
       {
           largest=Ptable[i].value;
       }
   }
   return largest;
}
int look(int raw, float value)
{
    float k;
    for(k=0;k<=credits;k+=0.5)
    {
        if(returncell(raw,k)==value)
        {
            return 1;
        }
    }
    return 0;
}
