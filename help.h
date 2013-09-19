#include <iostream>
#include <fstream>

void Help();

void Help()
{
    char buff[1024];
	
	ifstream fin("Ajuda.txt");
	
    while(fin)
    {
      fin.getline(buff,1024);         
      cout<< buff << "\n";
    }
	fin.close();
}

