/** C++ Safety part 1 of n - Language Level Safety
 *  Run-Time
 */

#include <iostream>
#include <fstream>
/*
Safety in C++ Programming: Language Level Features -- run-time

RAII:
    - Resource Allocation Is Initialization
    - Incredibly useful for handling the proper use of resources:
        * files (open/close), memory allocation, locks, etc.
        * Guaranteed to be called, even if an exceptipon is thrown -- so program can 'clean up'
        resources
    - Notes:
        - A good guideline is to 'wrap' only one resource
        - RAII may not always be a good solution of your resources are shared amoings devices
        (e.g. CPU and GPU -- in that case you may want explicit control of acquiring/releasing
        resources)

*/

struct FileScoped
{
    FileScoped(const char* filename)
    {
        _file.open(filename);
    }
    ~FileScoped()
    {
        _file.close();
    }

    std::fstream _file{};
};


struct HeapIntScoped
{
    HeapIntScoped()
    : _data{new int}
    {
    }
    ~HeapIntScoped()
    {
        delete _data;
    }
    
    int* _data{nullptr};
};


int main()
{   
    {
        FileScoped fs{"datra.txt"};
        HeapIntScoped ptr;
    } // File closed and heap memory freed

   return 0;
}