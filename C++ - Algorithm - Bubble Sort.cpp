#include <iostream>
using namespace std; 
int main() 
{
   int temp;
   int pass=0;
   bool exchange = true;
   int k[5]={6,5,14,31,2};

	
    cout<<"--------------\n";
	cout<<"Before:"<<endl;
	for (int i=0;i<5;i++)
		cout<<k[i]<<"  ";

	while (exchange)
		{
			exchange = false;
			for (int i=0;i<5;i++)
				{
					if (k[i]<k[i+1])
					{
						k[i]^=k[i+1];
						k[i+1]^=k[i];
						k[i]^=k[i+1];
						exchange = true;
					}
					pass++;
				}
		}

    cout<<"\n\n--------------\n";
	cout<<"After:"<<endl;
	for (int i=0;i<5;i++)
		cout<<k[i]<<"  ";
	cout<<"\n no. of pass = "<<pass<<endl;
}