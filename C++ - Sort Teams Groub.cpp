#include<iostream>
using namespace std;

class Team
{
    public :
		string name;
		int pt, gf, ga, gd;
	Team ()
	{}
	Team (string name,int pt,int gf,int ga)
	{
		this -> name = name;
		this -> pt = pt;
		this -> gf = gf;
		this -> ga = ga;
		gd=gf-ga;
	}
    void displaySort(Team arr[],const int length)
    {
	    cout<<"---------------------------------------------------"<<endl;
	    cout<<"|TEAM|"<<"			"<<"|PTS| "<<" |GF| "<<" |GA| "<<" |GD|"<<endl;
	    cout<<"---------------------------------------------------"<<endl;
	    for (int i=0;i<length;i++)
	        cout<<i+1<<"- "<<arr[i].name<<"		 "<<arr[i].pt<<"	"<<arr[i].gf<<"    "<<arr[i].ga<<"     "<<arr[i].gd<<endl;
	    cout<<"---------------------------------------------------"<<endl;
	    cout<<"---------------------------------------------------"<<endl;
    }
};

int main ()
{
	const int numbersOfTeams=7;
	
	Team t1("MARSEILLE",29,25,21);
	Team t2("HOLMES",45,49,4);
    Team t3("LIVERPOOL",24,19,17);
	Team t4("PARIS SG",26,19,12);
	Team t5("A MADRID",26,26,21);
	Team t6("J TURIN",28,35,25);
	Team t7("TOTTENHAM",27,21,18);
	
    Team groub[numbersOfTeams]={t1,t2,t3,t4,t5,t6,t7};
    
	for(int i=0;i<numbersOfTeams;i++)
	{
	    for (int j=i+1;j<numbersOfTeams;j++)
        {
            if (groub[i].pt<groub[j].pt)
                swap(groub[i],groub[j]);
            else if (groub[i].pt==groub[j].pt)
            {
                if (groub[i].gd<groub[j].gd)
                    swap(groub[i],groub[j]);
                else if (groub[i].gd==groub[j].gd)
				{
					if (groub[i].gf<groub[j].gf)
						swap(groub[i],groub[j]);
				}
            }
        }
    }
    t1.displaySort(groub,numbersOfTeams);
    return 0;	
}

