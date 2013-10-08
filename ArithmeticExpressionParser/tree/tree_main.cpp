/**
* @file     main.cpp
* @brief	main 
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/18/2012
*/

#include <iostream>
#include <fstream>
#include "Calculator.h"
int tree_main (int argc, char * const argv[]) { 
	std::ifstream infile;
	infile.open ("out2.txt");
	if (!infile) {
		std::cerr << "Can't open input file " << std::endl;		
	}
	Calculator<int> c;
	int result;	
	if(!c.do_calculation(infile, result))
	{
		std::cout<<"Try Again!"<<std::endl;		
	}
	else
	{
		std::cout<<"Result: "<<result<<std::endl;
	}

	infile.close();
	system("Pause");
	return 0;
}