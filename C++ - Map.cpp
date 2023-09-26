#include <iostream>
using namespace std;
template<class keyType,class valueType>                                            
///***** Map Using Arrays ******///
class Map
{
    private :
    int counter = 0;
    keyType* keys = new keyType [5];
    valueType* values = new valueType [5];                                  
    public :
    int length ()
    {
        return counter;
    }
    bool isEmpty () 
    {
        return counter==0 ;
    }
    
    ///***MAIN FUNCTIONS***///
    
    //APPENDING FUNCTION
    //to add a value to the map
    void add (keyType key,valueType value)
    {
        if (findIndex(key)==-1)
        {
            keys[counter] = key;
            values[counter] = value;
            counter ++;
        }
        else
            values[findIndex(key)] = value;
    }
    //DELETEING FUNCTION 
    //to delete a specific value by a given key
    void pop (keyType key)
    {
        int index = findIndex(key);
        if (index!=-1)
        {
            for (int i=index; i+1<counter ;i++)
            {
                keys[i] = keys[i+1];
                values[i] = values[i+1];
            }
            keys[counter-1] = NULL;
            values[counter-1] = NULL;
            counter --;
        }
        else
            cout<<"Key Not Found !!\n";
    }
    //DISPLAY FUNCTION
    //to print the whole map
    void print ()
    {
        if (isEmpty())
            cout<<"map = {}"<<endl;
        else
        {
            cout<<"map = {";
            for(int i=0;i<counter;i++)
            {
                cout<<keys[i]<<":"<<values[i];
                if (i!=counter-1)
                    cout<<", ";
            }
            cout<<"}"<<endl;
        }
    }
    //GET VALUE BY KEY
    //to return a specific value by a given key
    valueType get (keyType key)
    {
        return findIndex(key) == -1 ? NULL : values[findIndex(key)];                                         
    }
    valueType operator [] (keyType key)
    {
        return findIndex(key) == -1 ? NULL : values[findIndex(key)];                                         
    }
    //SEARCH FUNCTION
    //to return the position of a specific value by a given key
    int findIndex (keyType key)
    {
        if (!isEmpty())
        {
            for (int i=0;i<counter;i++)
            {
                if (keys[i] == key)
                    return i;
            } 
        }
        return -1;
    }
};

int () 
{
   ("color 3");
    Map <int,int> map;
    map.add(10,100);
    map.add(20,200);
    map.add(30,300);
    map.print();
    cout<<map[50]<<endl;
    
    Map <string,int> marks;
    marks.add("dart",50);
    marks.add("flutter",30);
    marks.add("math",90);
    marks.add("software",50);
    marks.print();

    return 0;
} 

