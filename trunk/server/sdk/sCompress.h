#ifndef _SCOMPARESS_H__
#define _SCOMPARESS_H__
#include "lz4.h"
class sCompress
{
	public:
		bool Init();
		bool LoadConfig();
		int Compress(const char* source, char* dest, int sourceSize, int maxDestSize);
		int Decompress (const char* source, char* dest, int compressedSize, int maxDecompressedSize);
	private:

		bool _using{true};
			



};




#endif
