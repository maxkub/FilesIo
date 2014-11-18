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
	vector<vector<double>> import(string path, int skip, bool onscreen)
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

				while (ss >> x)
				{
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


}

