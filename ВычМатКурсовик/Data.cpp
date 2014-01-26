#include "Data.h"

std::vector<double> GetDoubleRow(std::string str){
	std::vector<double> row;
	int cpos = 0, pos = 0;
	std::string tmp;
	std::string::iterator striter = std::str.begin();
	while(striter != std::str.end()){
		cpos = std::str.find(" ", pos);
		tmp = std::str.substr(pos, cpos - pos);
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
	std::string::iterator striter = std::str.begin();
	while(striter != std::str.end()){
		cpos = std::str.find(" ", pos);
		tmp = std::str.substr(pos, cpos - pos);
		element = atof(tmp.c_str());
		striter = std::str.begin();
		striter = striter + (cpos+1);
		pos = cpos + 1;
		if(cpos == -1) break;
	}
	return element;
}

std::vector<std::vector<double>> ReadFromFile(char *filename){
	ifstream matrix;
	std::vector<double> tm;
	std::vector<vector<double>> A;
	std::vector<double>::iterator iter = tm.begin();
	std::string str;
	matrix.open(filename);
	if(matrix.is_open()){
		while(!matrix.eof()){
			getline(matrix, str);
			tm = GetDoubleRow(str);
			A.push_back(tm);
		}
	}
	return A;
}

std::vector<double>ReadFromFile(char *filename, int size){
	ifstream matrix;
	std::vector<double> tm;
	std::string str;
	matrix.open(filename);
	if(matrix.is_open()){
		while(!matrix.eof()){
			getline(matrix, str);
			tm.push_back(GetDoubleElement(str));
		}
	}
	return tm;
}

void show(std::vector<std::vector<double>>A)
{
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            cout <<" "<< A[i][j] << " ";
        }
        cout << endl;
    }
}

void show(std::vector<double>A)
{
	std::vector<double>::iterator iter = A.begin();
	while(iter != A.end()){
		cout << " " << *iter << "\n";
		iter++;
	}
	cout << endl;
}