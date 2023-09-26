#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout<<" || CORRELATION COEFFICIENT ||"<<endl<<endl;

    int n;
    cout<<"Enter Number of Frequencies (N) :"<<endl;
    cin>>n;

    float x[n]; //X table
    float y[n]; //Y table
    float sumX = 0,sumY = 0; //Segma X and Segma Y
    float sumXX = 0,sumYY = 0; //Segma X² and Segma Y²
    float sumXY = 0; //Segma XY

    //inputting x axis and calc Sig X and Sig x²;
    cout<<"Enter X terms : "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin>>x[i];
        sumX += x[i];
        sumXX += x[i]*x[i];
    }

    //inputting y axis and calc Sig Y and Sig Y² and Sig XY
    cout<<"Enter Y terms : "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin>>y[i];
        sumY += y[i];
        sumYY += y[i]*y[i];
        sumXY += x[i]*y[i];
    }

    //calculate the law
    float r,root,numerator,denominator;
    numerator = (n*sumXY) - (sumX*sumY);
    root = ((n*sumXX) - (sumX*sumX)) * ((n*sumYY) - (sumY*sumY));
    denominator = sqrt(root);

    r = numerator/denominator;

    //showing results
    cout<<"Sum X = "<<sumX<<endl;
    cout<<"Sum Y = "<<sumY<<endl;
    cout<<"Sum XY = "<<sumXY<<endl;
    cout<<"Sum X² = "<<sumXX<<endl;
    cout<<"Sum Y² = "<<sumYY<<endl;
    cout<<"Correlation Coefficient : "<<endl;
    cout<<"r = "<<r<<endl;

    //determine strength of relationship
    const float postive = 0.5;
    const float negative = -0.5;
    if (r <= negative) 
        cout<<"there is Strong Negative liner relationsh\n";
    else
    {
        if (r >= postive)
            cout<<"there is Strong Postive liner relationsh\n";
        else
            cout<<"there is Weak liner relationship \n";
    }

    return 0;
}