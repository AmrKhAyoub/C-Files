#include<iostream>
using namespace std;
class Time
{
    private :
        int hours;
        int minutes;
        int seconds;
    public :
        Time(void){}
        Time(int hours=0,int minutes=0,int seconds=0) : hours(hours),minutes(minutes),seconds(seconds) {}                                                 
       
        friend int getTimeInSecondes(Time ob);
}; 

int getTimeInSecondes(Time ob)
{
    return (ob.hours*60*60) + (ob.minutes*60) + (ob.seconds);
}
void convertSecondsToTime(int sec)
{
    int m = (sec/60);
    int h = m/60;
    m = m%60;
    int s = sec-((h*60+m)*60);
    cout<<"=====================\n";
    cout<<"TOTAL SECONDS = "<<sec<<endl;
    cout<<"TOTAL TIME = "<<(h<10?"0":"")<<h<<":"<<(m<10?"0":"")<<m<<":"<<(s<10?"0":"")<<s<<endl;
    cout<<"=====================\n";
}

int main() 
{
    system("color 3");
    int totalSeconds;
    int videoTime;
    int h,m,s;
    totalSeconds=videoTime=h=m=s=0;
    int i=1;
    while (true)
    {
        cout<<"=====================\n";
        cout<<"《▪︎▪︎Video No. "<<i<<"▪︎▪︎》\n";
        cout<<"--------------------\n";
        cout<<"Hours = "; cin>>h;
        if (h==123) 
            break;
        cout<<"Mins = "; cin>>m;
        cout<<"Sec = "; cin>>s;
        videoTime = getTimeInSecondes(Time(h,m,s));
        totalSeconds += videoTime;
        i++;
    }
    convertSecondsToTime(totalSeconds);
    return 0;
} 
