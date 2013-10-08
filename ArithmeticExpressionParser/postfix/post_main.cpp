/**
* @file     main.cpp
* @brief	main for postfix impl
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/18/2012
*/
#include "Calculator.h"

///Main
int post_main (int argc, char * const argv[]) {    
	Calculator<int> c;
	bool exit = false;
	int result;	
	while(!exit)
	{
		std::cout<<"Enter infix expression: "<<std::endl;	

		if(!c.do_calculation(std::cin, result))
		{
			std::cout<<"Try Again!"<<std::endl;		
		}	

		std::cout<<"Postfix Express: "<<c.get_postfix()<<std::endl;

		std::cout<<"Result: "<<result<<std::endl;

		char response = ' ';
		while(response  != 'Y' && response != 'y' && response != 'N' && response != 'n' )
		{
			std::cout<<"Do another one? Y(y) or N(n)"<<std::endl;
			std::cin >> response;
			std::cin.ignore();
			if (response == 'Y' || response == 'y')
			{
				exit = false;
				c.reset(); //reset calculator for next round
			} 
			else if (response == 'N' || response == 'n')
			{
				exit = true;			
			}	
		}
		
	}
	
	system("Pause");
	return 0;
}

