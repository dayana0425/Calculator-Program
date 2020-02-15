//Daiana Bilbao - HW2
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
//all functions

int determineArgument(string);
string trim (string input);
int add(string);
int sub (string input);
int multi(string);
int div(string);
int dist(string);
vector<int> vectorGenerator (string input);
//entry point of program

//global variable to hold filename 
string filename = "";
int main(int argc, char *argv[]) {
	(void)argc;
	filename = argv[0];
	string orig = ""; //will hold the original input
	//variables
	int result = -1; //result that will be returned 
	string input = ""; //reading input into a string
	int typeOfArgument;	
	//loop
	while(getline(cin,input)) {
		orig = input;
		cout << "input: " << orig << "\n";
		input = trim(input);
		typeOfArgument = determineArgument(input);
		string operands = "";

		//eliminating the optional arguments so that the string contains just the operands
		if(typeOfArgument == 0) {
		//hex
		operands = input.substr(3);
		}
		else if(typeOfArgument == 1){
		//oct
		operands = input.substr(3);
		}
		else if(typeOfArgument == 2){
		//dec
		operands = input.substr(3);
		}
		else if(typeOfArgument == 3) {
		//default - dec
		operands = input;
		}
		else {
		//error
		}

		//eliminating operator
		size_t foundPlus = operands.find("+");
		size_t foundMinus = operands.find("-");
		size_t foundMult = operands.find("*");
		size_t foundDiv = operands.find("/");
		size_t foundDist = operands.find("@");
	
		if(foundPlus != std::string::npos) {
			operands = operands.substr(foundPlus + 1); 
			operands = trim(operands);
			cout << "0\n"; 
			result = add(operands);
			}	
		else if (foundMinus != std::string::npos){
			operands = operands.substr(foundMinus + 1); 
			operands = trim(operands);
			cout << "1\n"; 
			result = sub(operands);
		}
		else if (foundMult != std::string::npos){
			operands = operands.substr(foundMult + 2); 
			operands = trim(operands);
			cout << "2\n"; 
			result = multi(operands);
		}
		else if (foundDiv != std::string::npos){
			operands = operands.substr(foundDiv + 1); 
			operands = trim(operands);
			cout << "3\n"; 
			result = div(operands);
		}
		else if (foundDist != std::string::npos) {
			operands = operands.substr(foundDist + 1); 
			operands = trim(operands);
			cout << "4\n"; 
			result = dist(operands);
		}
		else {
			cout << "5\n"; 
			return 0;
		}
	//final result
	cout <<"result: " << result << "\n";
	}
	
    	return 0;
}
//Optional argument of -h, -o, -d, default is a decimal
int determineArgument(string input) {
	//return 0 if -h
	//return 1 if -o
	//return 2 if -d
	//return 3 if default decimal
	string argument = input.substr(0,2);
	if(argument.compare("-h")==0){
		return 0; 
	}
	else if(argument.compare("-o")==0){
		return 1;
	}
	else if(argument.compare("-d")==0){
		return 2;
	}
	else{ //default
		return 3;
	}
}

//Vector of ints generator 
vector<int> vectorGenerator (string input) {
	vector<int> operands;
	trim(input);
	istringstream in(input);	
	int num = 0;

		while (in >> num){
			operands.push_back(num);
		}	
	
	return operands;
}
//Addition
int add (string input) {
	int result = 0; 
	vector<int> operands = vectorGenerator(input);
	vector<int>::iterator ptr;
	//adding together operands in vector
	for(ptr = operands.begin(); ptr < operands.end();ptr++){
		result = result + *ptr;
	}

	return result; 
}

//Subtraction
int sub (string input) {
	cout << "sub Function " << input << " \n";
	vector<int> operands = vectorGenerator(input);
	int result = operands[0];
	int index = 0;	
	for(int num : operands) {
		if((!index == 0)) {
		result = result - num;
		}	
	index++;
	}
	return result; 
}

//Multiplication 
int multi(string input) {
	cout << "multi Function " << input << " \n";
	vector<int>operands = vectorGenerator(input);
	int result = operands[0]; 
	int index = 0; 
	for(int num: operands){
		if(index!=0){
		result = result * num;
		} 
	index++;
	} 
	return result;
}

//Division
int div(string input) {
	cout << "div Function " << input << " \n"; 
	vector<int>operands = vectorGenerator(input);
	int result = operands[0]; 
	int index = 0;
	for(int num: operands){
		if(index!=0){
		result = result / num;
		}
	index++;	
	}
	return result; 
}

//Distance
int dist(string input) {
	cout << "dist Function " << input << " \n"; 
	vector<int>operands = vectorGenerator(input);
	int result = 0;
	vector<int>dist;
	for(int num: operands) {
		dist.push_back(abs(45 - num));
	}
	
	//find max
	result = dist[0];
	for(int vals: dist) {
		if(vals > result){
			result = vals; 
		}
	}
	return result;
}

string trim (string input) {
	size_t start = input.find_first_not_of(' ');
	size_t end = input.find_last_not_of(' '); 
        string trimmedInput = input.substr(start, end + 1);
	
	return trimmedInput;
}
