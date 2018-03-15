#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int x, y;
int hitCounter = 0;
bool sunk = false;

//Function declaration
void printMap(char map[][9]);
void printView(char view[][9]);
void writeMapToFile(char map[][9]);
void writeToMap(char map[][9]);
void askForAttackVector(char map[][9], char view[][9]);
void checkIfShip(int, int, char map[][9], char view[][9]);


//Main function
int main()
{
    //Create a 9x9 map with battleships
    char map[9][9] = {};
    //Create a blank 9x9 view for the user
    char view[9][9] = {{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X'}};


    writeToMap(map);



    bool sunk = false;
    while(!sunk)
    {
        printView(view);
        askForAttackVector(map, view);
        if(hitCounter == 17)
        {
            sunk = true;
            printView(view);
            cout << "\n\nYou sunk my battleship. :( \n"<< endl;
        }
    }


    return 0;
}




//Receive attack coordinates from user
void askForAttackVector(char map[][9], char view[][9])
{
    cout << "Enter x coordinate|  X:~", cin >> x, cout << endl;
    cout << "Enter y coordinate|  Y:~", cin >> y, cout << endl;
    int a = x - 1;
    int b = y - 1;
    cout << "You entered X: " << x << " , and entered Y: " << x << ".\nAtacking:(" << x << "," << y << ")" << ". . ." << endl;
    checkIfShip(a,b,map,view);
}

void printMap(char map[][9])
{
    //Print out the char array map
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}


void printView(char view[][9])
{
    cout << ".____________________________________." << endl;
    cout << "|     |  1  2  3  4  5  6  7  8  9   |" << endl;
    cout << "|-----+------------------------------|" << endl;
    //Print out the char array view
    for(int i = 0; i < 9; i++)
    {
        cout << "|  " <<  i+1 << "  |  ";
        for(int j = 0; j < 9; j++)
        {
            cout << view[i][j] << "  ";
        }
        cout << " |" << endl;
    }
    cout << "|_____|______________________________|" << endl;
}

void writeMapToFile(char map[][9])
{
    ofstream outputStream;

    outputStream.open("map.dat");
    //Test Output stream
    if( outputStream.fail() )
	{
		cout << "Unable to open file map.dat";
		exit(1);
	}
	
	//Use output stream to write the map to file
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            outputStream << map[i][j] << ' ';
        }
        outputStream << endl;
    }
}

void checkIfShip(int x, int y, char map[][9], char view[][9])
{
    if(view[x][y] == 'H')
    {
        cout << "\n\nYou already hit this space.\n\n" << endl;
        return;
    }
    
    if(map[x][y] == 'O' && view[x][y] != 'M' )
    {
        cout << "\n\nYou hit a battleship!\n\n" << endl;
        view[x][y] = 'H';
        hitCounter++;
    }
    else
    {
        cout << "\n\nYou missed!\n\n" << endl;
        view[x][y] = 'M';
    }
    
}

void writeToMap(char map[][9])
{
    ifstream inputStream;

    inputStream.open("map.dat");
    //Test Input Stream
    if( inputStream.fail() )
	{
		cout << "Unable to open file map.dat";
		exit(1);
	}

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            inputStream >> map[i][j];
        }
    }


}
