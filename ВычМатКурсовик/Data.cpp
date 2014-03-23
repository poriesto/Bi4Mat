#include "Data.h"

std::vector<double> GetDoubleRow(std::string str){
	std::vector<double> row;
	int cpos = 0, pos = 0;
	std::string tmp;
	std::string::iterator striter = str.begin();
	while(striter != str.end()){
		cpos = str.find(" ", pos);
		tmp = str.substr(pos, cpos - pos);
		row.push_back(atof(tmp.c_str()));
		striter = str.begin();
		striter = striter + (cpos+1);
		pos = cpos + 1;
		if(cpos == -1) break;
	}
	return row;
}

double GetDoubleElement(std::string str){
	double element;
	int cpos = 0, pos = 0;
	std::string tmp;
	std::string::iterator striter = str.begin();
	while(striter != str.end()){
		cpos = str.find(" ", pos);
		tmp = str.substr(pos, cpos - pos);
		element = atof(tmp.c_str());
		striter = str.begin();
		striter = striter + (cpos+1);
		pos = cpos + 1;
		if(cpos == -1) break;
	}
	return element;
}

std::vector<std::vector<double> > ReadFromFile(const std::string &filename){
	std::ifstream matrix;
	std::vector<std::vector<double> > A;
	std::string str;
	matrix.open(filename.c_str());
	if(matrix.is_open()){
		while(!matrix.eof()){
			getline(matrix, str);
			A.push_back(GetDoubleRow(str));
		}
	}
	return A;
}

std::vector<double>ReadFromFile(const std::string &filename, int size){
	std::ifstream matrix;
	std::vector<double> tm;
	std::string str;
	matrix.open(filename.c_str());
	if(matrix.is_open()){
		while(!matrix.eof()){
			getline(matrix, str);
			tm.push_back(GetDoubleElement(str));
		}
	}
	return tm;
}

void show(std::vector<std::vector<double> > A){
	std::for_each(A.begin(), A.end(), [](std::vector<double> value){
				show(value);
			});
}

void show(std::vector<double>A){
	std::for_each(A.begin(), A.end(), [](double value){
		   	std::cout << value << " ";
			});
	std::cout << std::endl;
}
