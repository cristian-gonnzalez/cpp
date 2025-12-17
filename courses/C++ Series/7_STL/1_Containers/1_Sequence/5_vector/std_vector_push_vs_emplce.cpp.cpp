#include <iostream>
#include <vector>

static int allocation_count = 0;
static int copy_count = 0;
static int move_count = 0;

void init_counters()
{
    allocation_count = 0;
    copy_count = 0;
    move_count = 0;
}

void print_counters()
{
    std::cout << "\tAllocations: " << allocation_count << std::endl;
    std::cout << "\tCopies     : " << copy_count << std::endl;
    std::cout << "\tMoves      : " << move_count << std::endl;
}

// Note: this oveerides the new opeator that std::vector will use internally
//       to allocate memory
void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes.\n";
    allocation_count++;
    return malloc(size);
}

struct UDT
{
    int _data;

    UDT()
    {
        //std::cout << "Calling constructor UDT()\n";
    }
    UDT(const UDT& other)
    {
        copy_count++;
        //std::cout << "Calling copy constructor UDT(const UDT& other)\n";
    }
    // if we have a move constructor, push_back/emplace_back will chosse
    // this instead of copy constructor
    // NOTE: you have to add the move constructor. There is no default move
    //       constructor added by the compiler
    UDT(UDT&& rvalue)
    {
        move_count++;
        //std::cout << "Calling move constructor UDT(UDT&& rvalue)\n";
    }
    UDT& operator=(const UDT& rhs)
    {
        //std::cout << "Calling copy assigment operator\n";
        return *this;
    }
    UDT& operator=(UDT&& rvalue)
    {
        //std::cout << "Calling copy assigment move operator\n";
        return *this;
    }
    ~UDT()
    {
        //std::cout << "Calling desstructor ~UDT()\n";
    }
};


void std_vector_push_back()
{
    std::cout << "\t----- push_back ----- \n";
    
    init_counters();

    std::vector<UDT> v;
    // reserve memory to avoid copying evertyme std_vector needs to resize
    v.reserve(5);    
    
    // we are creating UDT object and 
    // then copying into the vector
    v.push_back(UDT());
    v.push_back(UDT());
    v.push_back(UDT());
    v.push_back(UDT());
    
    print_counters();
}

void std_vector_emplace_back_w_constructor()
{
    std::cout << "\t----- emplace_back(object) ----- \n";
    
    init_counters();

    std::vector<UDT> v;
    // reserve memory to avoid copying evertyme std_vector needs to resize
    v.reserve(5);    
    
    // we are constructing the object by calling the UDT constructor
    // so , there is no different with push back
    v.emplace_back(UDT());
    v.emplace_back(UDT());
    v.emplace_back(UDT());
    v.emplace_back(UDT());

    print_counters();
}

void std_vector_emplace_back()
{
    std::cout << "\t----- emplace_back ----- \n";
    
    init_counters();

    std::vector<UDT> v;
    // reserve memory to avoid copying evertyme std_vector needs to resize
    v.reserve(5);    
 
    // Emplace: 
    //       Instead of giving to the vector the actual object, 
    //       we just give it the parameters of the object we want 
    //       to construct and it will do the construct for us 
    //       inside its own memory
    //       We construct in-place.
    v.emplace_back();
    v.emplace_back();
    v.emplace_back();
    v.emplace_back();
    
    print_counters();

}

int main()
{
    std_vector_push_back();
    std_vector_emplace_back_w_constructor();
    std_vector_emplace_back();

    /*
    	----- push_back ----- 
Allocating 20 bytes.
	Allocations: 1
	Copies     : 0
	Moves      : 4
	----- emplace_back(object) ----- 
Allocating 20 bytes.
	Allocations: 1
	Copies     : 0
	Moves      : 4
	----- emplace_back ----- 
Allocating 20 bytes.
	Allocations: 1
	Copies     : 0
	Moves      : 0
    
    */
    return 0;
}