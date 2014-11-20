#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "FilesIo.h"

using namespace std;

namespace FilesIo
{

	// read function
	vector<vector<double>> import(string path, int skip, char delim, bool onscreen)
	{
		vector<vector<double>> arr = {};
		vector<double> line = {};

		ifstream file(path.c_str());

		if (file)
		{
			double x;
			string input;

			// Skip rows
			for (int i = 0; i < skip; ++i)
			{
				getline(file, input);
			}

			// read lines and build the output array
			while (getline(file, input))
			{
				stringstream ss(input);
				line.clear();

				//while (ss >> x)
				//{
				//	line.push_back(x);
				//}

				string field;
				while (getline(ss, field, delim))
				{
					stringstream fs(field);

					fs >> x;					
					line.push_back(x);
				}

				// print curent line on screen
				if (onscreen)
				{
					for (auto c : line)
					{
						cout << c << " ";
					}
					cout << endl;
				}

				arr.push_back(line);
			}
		}
		else
		{
			cout << "ERROR in files_io.read : can't open file : " << path.c_str() << endl;
			exit(1);
		}


		return arr;
	}








	// read multiple types
	vector<vector<typeA>> import_multi(string path, int skip, char delim, bool onscreen)
	{

		vector<vector<typeA>> arr = {};
		vector<typeA> line = {};

		ifstream file(path.c_str());

		if (file)
		{
			typeA x;
			string input;

			// Skip rows
			for (int i = 0; i < skip; ++i)
			{
				getline(file, input);
			}

			// read lines and build the output array
			while (getline(file, input))
			{
				stringstream ss(input);
				line.clear();

				string field;
				while (getline(ss, field, delim))
				{
					stringstream fs(field);

					try
					{
						fs >> x.I;
						x.type = 1;
					}
					catch (...){}

					try
					{
						fs >> x.D;
						x.type = 2;
					}
					catch (...){}

					try
					{
						fs >> x.S;
						x.type = 3;
					}
					catch (...){}

					line.push_back(x);
				}

				// print curent line on screen
				if (onscreen)
				{
					for (size_t i = 0; i < line.size(); ++i)
					{
						cout << line[i] << " ";
					}
					cout << endl;
				}

				arr.push_back(line);
			}
		}
		else
		{
			cout << "ERROR in files_io.read : can't open file : " << path.c_str() << endl;
			exit(1);
		}

		return arr;
	}


}

