#include <iostream>

/*
Associative containers:
----------------------

Key uniqueness (std::set/std::map):
----------------------------------

    Keys are considered equivalent if neither compares less than the other.
    Formally:

        !comp(a, b) && !comp(b, a)

	If keys are equivalent, set/map will reject the second insertion.
*/


int main()
{
	return 0;
}
