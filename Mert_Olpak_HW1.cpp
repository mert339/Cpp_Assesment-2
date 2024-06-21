#include <iostream>
#include <unistd.h>

using namespace std;


////////////-----------040190737 MERT OLPAK HW1------------//////////


class Cube
{ 
 public:
	int length, width, height;
	Cube(int, int, int);
	int volume();
    void print();
};


Cube :: Cube(int length_first=0, int width_first=0, int height_first=0) // Definition of the constructor
{
    //cout << "Constructor is called..." << endl;
	length = length_first;
    width  = width_first;
    height = height_first;
}


int Cube :: volume() // Defining volume function
{
    int vol = length*width*height;
    return vol;
}


void Cube :: print() // Defining print function
{
    cout << "length = " << length << ",  width = " << width << ",  height = " << height << ",  volume = " << volume() << endl;  
}

bool operator> (Cube& Cube1, Cube& Cube2) //overloading '>' operator to compare two cube classes
{
    if(Cube1.volume() > Cube2.volume())
        return true;
    else
        return false;
}

Cube operator+ (Cube& Cube1, Cube& Cube2) //overloading '+' operator to add two cube classes
{
    int Cube3length, Cube3width;
    int Cube3height = Cube1.height + Cube2.height;
    
    if(Cube1.width > Cube2.width)
        Cube3width = Cube1.width;
    else
        Cube3width = Cube2.width;

    if(Cube1.length > Cube2.length)
        Cube3length = Cube1.length;
    else
        Cube3length = Cube2.length;
    
    return Cube(Cube3length, Cube3width, Cube3height);
    //return Cube;

}

int main()
{
    sleep(1); //I had to add some delay since there was inconsistency without it

        Cube cubes[10] = {Cube(25,56,83), Cube(5,50,86), Cube(50,60,76), Cube(44,35,75), Cube(40,28,117),
    Cube(13,34,95), Cube(47,32,60), Cube(43,38,74), Cube(46,70,78), Cube(22,26,102)};  //Defining an array of objects
    
    cout << "\n\n--------- CUBES UNSORTED -----------\n" << endl; //listing unsorted cubes
    for (int i = 0; i < 10; i++)
    {
        cout << i+1 << ".Cube  "; 
        cubes[i].print(); 
        cout << endl;
    }
    

    Cube temp_cube(1,1,1); //defining a temporary cube for swapping purpose

        for (int i = 0; i < 11; i++) //using bubble sort to sort array members
        {
            for (int j = 0; j < 9; j++)
            {
                if (cubes[j] > cubes [j+1])
                {
                    temp_cube = cubes [j+1]; //swapping two neighbours if the left one is bigger
                    cubes[j+1] = cubes [j];
                    cubes[j] = temp_cube;
                }

            }
        }

    cout << ("\n\n");
    
    cout << "\n\n--------- CUBES SORTED BY VOLUME -----------\n" << endl; //listing unsorted cubes
    for (int i = 0; i < 10; i++)
    {
        cout << i+1 << ".Cube  "; 
        cubes[i].print(); 
        cout << endl;
    }
    
    cout << endl << endl;
    cout << endl << endl << "--------- CUMULATIVE SUMS OF CUBES AFTER ADDING -----------" << endl << endl;

    for (int i = 0; i < 9; i++)
    {
        if(i == 0) //if block is gonna be enabled only for the first addition
        {
        temp_cube = cubes[i] + cubes[i+1];
        cout << std::setw(10) << "Number of cubes added = " << i+2 << "  ,NewCube"; temp_cube.print(); cout << endl;
        }
        
        else //else block is ginna be enabled for the rest of the addition
        {
        temp_cube = temp_cube + cubes[i+1];
        cout << "Number of cubes added = " << i+2 << "  ,NewCube"; temp_cube.print(); cout << endl;
        }
    
    }
    
    cout << "\n\nPROGRAM FINISHED." << endl;
    system("pause");
}

