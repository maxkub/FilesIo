#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "FilesIo.h"

using namespace std;

namespace FilesIo
{

	// read function : import array of double
	vector<vector<double>> importD(string path, int skip, int toline, char delim, bool onscreen)
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
			int compt = 0;
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

				++compt;

				if (toline != 0)
				{
					if (compt == toline){ break; }
				}
			}
		}
		else
		{
			cout << "ERROR in FilesIo.importD : can't open file : " << path.c_str() << endl;
			exit(1);
		}


		return arr;
	}




	// read function
	vector<vector<signed long long>> importI_hex(string path, int skip, int toline, char delim, bool onscreen)
	{
		vector<vector<signed long long>> arr = {};
		vector<signed long long> line = {};

		ifstream file(path.c_str());

		if (file)
		{
			signed long long x = 0;
			string input;

			// Skip rows
			for (int i = 0; i < skip; ++i)
			{
				getline(file, input);
			}

			// read lines and build the output array
			int compt = 0;
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

					fs >> std::hex >> x;
					line.push_back(x);
				}

				// print curent line on screen
				if (onscreen)
				{
					cout << setw(5) << compt;

					for (auto c : line)
					{
						cout << std::setw(5) << c << " ";
					}
					cout << endl;
				}

				arr.push_back(line);

				++compt;

				if (toline != 0)
				{
					if (compt == toline){ break; }
				}
			}
		}
		else
		{
			cout << "ERROR in FilesIo.importI_hex : can't open file : " << path.c_str() << endl;
			exit(1);
		}


		return arr;
	}




	// read multiple types
	vector<vector<typeA>> import_multi(string path, int skip, int toline, char delim, bool onscreen)
	{

		vector<vector<typeA>> arr = {};
		vector<typeA> line = {};

		ifstream file(path.c_str());

		if (file)
		{
			
			string input;

			// Skip rows
			for (int i = 0; i < skip; ++i)
			{
				getline(file, input);
			}

			// read lines and build the output array
			int compt = 0;
			while ( getline(file, input) )
			{
				stringstream ss(input);
				line.clear();

				string field;
				while (getline(ss, field, delim))
				{
					stringstream fs(field);
					
					typeA x;
					try
					{
						fs >> x.I;
						x.type = 1;
						cout << "... int " << x.I << "\n";
					}
					catch (...){}

					try
					{
						fs >> x.D;
						x.type = 2;
						cout << "... double " << x.D << " \n";
					}
					catch (...){}

					try
					{
						fs >> x.S;
						x.type = 3;
						cout << "... string " << x.S << " \n";
					}
					catch (...){}

					line.push_back(x);
				}

				// print curent line on screen
				if (onscreen)
				{
					for (size_t i = 0; i < line.size(); ++i)
					{
						cout << i << " : " << line[i] << " ";
					}
					cout << endl;
				}

				arr.push_back(line);

				++compt;

				if (toline != 0)
				{
					if (compt == toline){ break; }
				}
			}
		}
		else
		{
			cout << "ERROR in FilesIo.import : can't open file : " << path.c_str() << endl;
			exit(1);
		}

		return arr;
	}










	// write function
	void write(vector<vector<double>> arr, string path)
	{

		ofstream file(path.c_str());

		if (file)
		{

			for (size_t i = 0; i < arr.size(); ++i)
			{
				for (size_t j = 0; j < arr[i].size(); ++j)
				{
					file << arr[i][j] << " ";
				}
				file << endl;
			}

		}
		else
		{
			cout << "ERROR in FilesIo.write : can't open file : " << path.c_str() << endl;
			exit(1);
		}

	}

}

