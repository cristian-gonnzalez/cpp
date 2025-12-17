/** RAII (Resource Acquisition Is Initialization)
 */

#include <iostream>
#include <mutex>

class Collection
{
    public:
        Collection()
        : _data(new int[10]) // RAII: Acquire the resource
        {
            //   If something happens while this object is being constructed,
            // such as an exception being thrown, the destructor of this object
            // is NOT called, because the object itself is not considered fully 
            // constructed.
            //
            //   However, any members that were fully constructed before the 
            // exception are destroyed automatically by calling their own 
            // destructors (stack unwinding -- variables go out of scope).
            //
            //   In this case, _data is just a built-in type (int*), which has 
            // no destructor. So the heap memory it points to is NOT automatically 
            // freed — this would cause a memory leak unless we use a RAII type 
            // like std::unique_ptr.    
        }
        ~Collection()
        {
            // A destructor should not let an exception occurs here
            // Use try-catch
            delete[] _data; // RAII: Release the resource
        }

        // Copy semantics
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;


        // subscript	a[idx]	
        int& operator[](size_t idx)
        {
            return _data[idx];
        }
        // subscript	a[idx]	
        const int& operator[](size_t idx) const
        {
            return _data[idx];
        }

    private:
        int* _data; // nontrivial type -> rule of 3
};


int main()
{
    {
        int* collection = new int[3];

        collection[0] = 1;
        collection[0] = 2;
        collection[0] = 3;
    } // Forgot to delete collection -> Memory leak

    {
        Collection c;
        
        c[0] = 1;
        c[0] = 2;
        c[0] = 3;
        

    } // The resource is release here

    return 0;
}
