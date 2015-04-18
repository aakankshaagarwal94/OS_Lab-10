#include<stdio.h>
#include<string.h>

void getData();
void display();
void turnAroundTime();
void waitTime();

int i,j,num,Bt[10],wt[10],At[10],z[50],Tt=0,w=0,temp,t;
char c[10][10],pn[10][10],s[10];
float Twt=0.0,Awt;

void getData()
{
	printf("\n Enter the number of processes: ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		printf("\n Enter the Burst time for process %d::",i+1);
		scanf("%d",&Bt[i]);
		
		printf("\n Enter the Arrival time for process %d::",i+1);
		scanf("%d",&At[i]);
		
		s[i]='T';
		Tt+=Bt[i];
	}
}

void turnAroundTime()
{
	 for(i=0;i<num;i++)
    {
        for(j=2;j<num;j++)
        {
            if(Bt[j-1]>Bt[j])
            {
                temp=Bt[j];
                Bt[j]=Bt[j-1];
                Bt[j-1]=temp;
                temp=At[j];
                At[j]=At[j-1];
                At[j-1]=temp;
                strcpy(c[j-1],pn[j-1]);
                strcpy(pn[j-1],pn[j]);
                strcpy(pn[j],c[j-1]);
            }
        }
    }

    wt[0]=0;
    z[0]=0;
    w+=Bt[0];
    t=w;
    s[0]='F';

    while(w<Tt)
    {
		i=1;
		while(i<=num)
		{
		    if(s[i]=='T' && At[i]<=t)
		    {
		        z[i]=w;
		        wt[i]=w-At[i];
		        s[i]='F';
		        w+=Bt[i];
		        t=w;
		        i=1;
		    }
		    else
		        
               i++;
		}
	}
}


void display()
{
	printf("\n..............................................\n");
	printf("\nProcess\tBurst Time\tAround Time\tWait Time");
	printf("\n..............................................\n");
	
	for(i=0;i<num;i++)
		printf("\n%s\t%d\t%d\t%d",i+1,Bt[i],At[i],wt[i]);
	
	printf("\n..............................................\n");
	
	for(i=0;i<num;i++)
	Twt+=wt[i];
	printf("\n\n Total waiting Time ::%f",Twt);

	Awt=Twt/num;
	printf("\n\n Average waiting Time ::%f",Awt);	
}

void main()
{
	getData();
	turnAroundTime();
	//waitTime();
	display();
	
}
