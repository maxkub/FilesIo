#ifndef FILESIO_INCLUDED
#define FILESIO_INCLUDED


#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace FilesIo
{
	

	// read function
	__declspec(dllexport) std::vector<std::vector<double>> read(std::string path, int skip = 0, bool onscreen = false);

	// write function
	__declspec(dllexport) std::vector<std::vector<double>> write(std::string path);


	
	

}

#endif

