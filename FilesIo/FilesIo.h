#ifndef FILESIO_INCLUDED
#define FILESIO_INCLUDED


#include <vector>
#include <fstream>
#include <sstream>
#include <string>
//#include <ostream>

namespace FilesIo
{
	
	//data types
	struct typeA
	{
		int I;
		double D;
		std::string S;

		int type;

		friend std::ostream& operator <<(std::ostream& os, typeA const& a)
		{
			switch (a.type)
			{
			case 1:
				return os << a.I << "\n";
				break;
			case 2:
				return os << a.D << "\n";
				break;
			case 3:
				return os << a.S << "\n";
				break;
			default:
				return os << "..." << "\n";
				break;
			}
			
		}




		/*friend std::ostream& operator >>(std::ostream& os, typeA const& a)
		{
			switch (a.type)
			{
			case 1:
				return os << a.I << "\n";
				break;
			case 2:
				return os << a.D << "\n";
				break;
			case 3:
				return os << a.S << "\n";
				break;
			default:
				return os << "..." << "\n";
				break;
			}

		}*/

	};



	

	// read function

	__declspec(dllexport) std::vector<std::vector<double>> importD(std::string path, int skip = 0, int toline=0, char delim = ' ', bool onscreen = false);

	__declspec(dllexport) std::vector<std::vector<signed long long>> importI_hex(std::string path, int skip = 0, int toline = 0, char delim = ' ', bool onscreen = false);

	__declspec(dllexport) std::vector<std::vector<typeA>> import_multi(std::string path, int skip = 0, int toline=0, char delim = ' ', bool onscreen = false);

	// write function
	__declspec(dllexport) void write(std::vector<std::vector<double>> arr, std::string path);


	
	

}

#endif

