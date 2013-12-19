#include "stdafx.h"
#include "Data.h"

vector<double> GetDoubleElement(string str)
{
	vector<double> row;
	int cpos = 0, pos = 0;
	string tmp;
	string::iterator striter = str.begin();
	while(striter != str.end())
	{
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

vector<vector<double>> ReadFromFile(char *filename)
{
	ifstream matrix;
	vector<double> tm;
	vector<vector<double>> A;
	vector<double>::iterator iter = tm.begin();
	string str;
	matrix.open(filename);
	if(matrix.is_open())
	{
		while(!matrix.eof())
		{
			getline(matrix, str);
			tm = GetDoubleElement(str);
			A.push_back(tm);
		}
	}
	return A;
}

<<<<<<< HEAD

=======
>>>>>>> 33ca11a1b3617ed3bdcbba7c97b0be6b1d6c0b54
void show(vector <vector <double>> A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            cout <<" "<< A[i][j] << " ";
        }
        cout << endl;
    }
}
<<<<<<< HEAD
=======

void show(vector<double>A)
{
	vector<double>::iterator iter = A.begin();
	while(iter != A.end())
	{
		cout << " " << *iter << " ";
		iter++;
	}
	cout << endl;
}

void Audio1()
{
	char szPath[] = "E:\\01 Born To Die.mp3";
    GetShortPathName(szPath,szPath,strlen(szPath));
    char mciStr[MAX_PATH] = {0};
    sprintf(mciStr,"play %s wait",szPath);
    if(!mciSendString(mciStr, NULL, 0, NULL))
        printf("mciSendString - PLAY\n");
    else
        printf("mciSendString - ERROR %s\n",strerror(GetLastError()));
}
>>>>>>> 33ca11a1b3617ed3bdcbba7c97b0be6b1d6c0b54
