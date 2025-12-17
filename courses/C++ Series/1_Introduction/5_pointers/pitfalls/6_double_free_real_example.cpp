/** Pointer pitfalls: Double free
 */

#include <iostream>


// $ g++ -std=c++17 main.cpp -o prog 
// $ ./prog
// free(): double free detected in tcache 2
// Program terminated with signal: SIGSEGV
  
struct Sensor
{
    public:
        Sensor()
        : _data{new int}
        {
        }    
        ~Sensor()
        {
            delete _data;
        }
        Sensor(const Sensor&) = delete;
        Sensor& operator=(const Sensor&) = delete;

        int* data() const
        {
            return _data;
        }

    private:
        int* _data;
};

int main()
{
    Sensor s;

    // Gets the sensor data
    int* px = s.data();
    
    // do stuff...
    
    // delete px by mistake
    delete px;
      
    return 0;
} 