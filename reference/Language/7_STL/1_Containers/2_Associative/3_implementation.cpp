#include <iostream>

/*
Associative containers:
----------------------

Implementation:
--------------

    Associative containers are typically implemented as a Red–black trees. Those are self-balancing trees.
                                                                                          ~~~~~~~~~
                                                                                            ^
       |     |    | [5]|                                            Meaning I can divide into sections        
       |     |  / |    | \                                      that allow to drag down the nodes in a 
       |  [3]|    |    | [6]                                    sorted order
       |/    |\   |    |    
    [1]|     | [4]|    |                  
       |     |    |    |                
     1    3     4    5    6   

    Self-balancing trees keep operations efficient by ensuring the height remains logarithmic. 
Therefore: 

        Search, insertion, and removal all have O(log n) complexity.

*/


int main()
{
	return 0;
}
