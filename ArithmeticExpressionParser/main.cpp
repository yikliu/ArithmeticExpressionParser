#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
//#include <vld.h> //for detecting memory leak

#include "strategy/Expr_Evaluator_Strategy.h"
#include "strategy/Postfix_Evaluator_Strategy.h"
#include "strategy/ExprTree_Evaluator_Strategy.h"

// For high resolution counter
double PCFreq = 0.0;
__int64 CounterStart = 0;

double duration;
int result;
//clock_t start, end;

int strategy = 4; // 1 = postfix, 2 = tree, 3 = flyweight, 4 = functor

/**
* Get the pointer to strategy
* 
* @param[in]  int	 	   
* @return     Pointer to the new initlized strategy object
* @exception  
*/
template<typename T>
Expr_Evaluator_Strategy<T> * getStrategy(int i)
{
	switch (i)
	{
	case 1:
		return new Postfix_Evaluator_Strategy<T>(false); // original postfix
	case 2:
		return new ExprTree_Evaluator_Strategy<T>(false); // original tree
	case 3:
		return new Postfix_Evaluator_Strategy<T>(true); //postfix using flyweight
	case 4:
		return new  ExprTree_Evaluator_Strategy<T>(true); //Tree with Functors;
	default:
		return 0;
	}
}

/**
* Start the clock
* 
* @param[in]   	   
* @return     
* @exception  
*/
void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

/**
* Stop the clock and return the time diffence in seconds
* 
* @param[in]   	   
* @return   double    time between the start and stop of the clock   
* @exception  
*/
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

/**
* One single run, excluding the allocation and deallocation of strategy object, this 
* is the time period which is timed by the clock.
* 
* @param[in]  pointer to the strategy
* @param[in]  string of the infix expression
* @return     
* @exception  
*/
void run(Expr_Evaluator_Strategy<int> * impl, std::string & infix)
{	
	//start = clock();
	StartCounter();
	if(!impl->parse_expression(infix)){
		std::cout<<"Parse Error"<<std::endl;
	}
	if(!impl->evaluate_expression(result)){
		std::cout<<"Evaluate Error"<<result<<std::endl;
	}
	//end = clock();
	//duration = (double)(end - start ) / CLOCKS_PER_SEC;
	duration = GetCounter();
}

/**
* Utility function to convert an integer to string
* 
* @param[in]   	   
* @return     
* @exception  
*/
std::string IntToString(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();		
}

/**
* display the contents of the memory state structure...
* 
* @param[in]   	   
* @return     
* @exception  
*/
void print_mem_state (_CrtMemState& ckpt1)
{	
	std::cout << "Displaying the Debug heap state..." << std::endl;
	
	size_t num_free_blocks =0;
	num_free_blocks = ckpt1.lCounts[_FREE_BLOCK];
	std::cout << "Number of free blocks: " << num_free_blocks << std::endl;
	size_t num_normal_blocks = 0;
	num_normal_blocks = ckpt1.lCounts[_NORMAL_BLOCK];
	std::cout << "Number of normal blocks: " << num_normal_blocks <<std::endl;
	size_t num_crt_blocks = 0;
	num_crt_blocks = ckpt1.lCounts[_CRT_BLOCK];
	std::cout << "Number of CRT_ blocks: " << num_crt_blocks << std::endl;	
	size_t num_ignore_blocks = 0;
	num_ignore_blocks = ckpt1.lCounts[_IGNORE_BLOCK];
	std::cout << "Number of ignore blocks: " << num_ignore_blocks << std::endl;
	size_t num_client_blocks = 0;
	num_client_blocks = ckpt1.lCounts[_CLIENT_BLOCK];
	std::cout << "Number of client blocks: " << num_client_blocks << std::endl;
}


/**
* Do the test
* Altering the comment/uncomment in the following segment to change from test approaches
*	int length = 70000;
*	//int level = 500;
*	for (int level = 100; level <= 10000; level += 100){
*	//for (int length = 1000; length <= 100000; length +=1000){		
* 
* @param[in]   	   
* @return     
* @exception  
*/
void DoTest()
{		
	std::ifstream infile;
	std::ofstream outfile;
	std::string outfile_path= "files/output/output_"+IntToString(strategy)+".csv";	
	outfile.open(outfile_path);
	if (!outfile) 
		std::cerr << "Can't open outfile file " << std::endl;	
	
	std::string s_length, s_level;	
	std::string infix;		
	
	outfile <<"length,level,strategy,result,duration,"<<std::endl;
	
	int length = 70000;
	//int level = 500;
	for (int level = 100; level <= 10000; level += 100){
	//for (int length = 1000; length <= 100000; length +=1000){			
		s_length = IntToString(length);
		s_level = IntToString(level);
		infile.open("files/input/input_"+s_length+"_"+s_level+".txt");					
		
		if (!infile) 
			std::cerr << "Can't open input file " << std::endl;	

		while(!infile.eof())
		{
			getline(infile, s_length);				
			getline(infile, s_level);

			std::istringstream sin(s_length);
			sin >> length;

			std::istringstream sin2(s_level);
			sin2 >> level;				

			if(!getline(infile, infix))
			{
				std::cout<<"Error reading"<<std::endl;
			}							

            //implementation of the strategy
			Expr_Evaluator_Strategy<int> * impl = getStrategy<int>(strategy);
			
			run(impl, infix);
			outfile <<length<<","<<level<<","<<strategy<<","<<result<<","<<duration<<std::endl;

			std::cout <<"L: "<<length<<" Lv: "<<level<<" Stg: "<<strategy<<" R: "<<result<<" T: "<<duration<<std::endl;
			if(impl != 0)
				delete impl;					
		}
		infile.close();	
				
	}
	outfile.close();
}

//
// main
//
int main (int argc, char * const argv[]) { 
#ifdef Debug
	_CrtMemState ckpt0;
	_CrtMemCheckpoint(&ckpt0);	
#endif
	
	DoTest();

#ifdef DEBUG
	_CrtMemState ckpt1;
	_CrtMemCheckpoint(&ckpt1);	
	_CrtMemState ckpt3;
	if(_CrtMemDifference(&ckpt3, &ckpt0, &ckpt1))
	{		
		std::cout << "printing memory state showing the difference..." << std::endl;
		_CrtMemDumpStatistics(&ckpt3);
		print_mem_state(ckpt3);
	}
#endif

	std::cout<<"Press Enter to Exit"<<std::endl;
	std::cin.get();
	return 0;
}
