/** Uniform initialization syntax (curly braces '{}')
 *
 */
#include <iostream>
#include <vector>

struct Point
{
    int x, y;
};

struct Point3D
{
    int _x, _y, _z;
    const int data[3];

    Point3D(int x, int y, int z)
    : _x{x}, _y{y}, _z{z}, data{100,200,300}
    //  ^      ^      ^        ^ 
    //                       array using the uniform initialization (also could be a const) 
    {}
};


void func(const std::vector<int>& v)
{
}


Point createPoint()
{
    return {0,0};
        // ~~~~~
        // Usyng syntax as return value to call constructor and create Point
}

int main()
{   
    // You can use {} to initializw all kinds of values
    //
    // primitives
    const int val1{5};

    // arrays     
    int a[]{1,2,val1};     // int a[] = {1, 2, val1 } 
                           //         ^
                           //     We tradiationally have done with arrays is to assing. It is not using Uniform initialization


    // structs and classes
    const Point p1{10,20};
    //              ^  ^
    //      It will be initialized in the order that member variables were declared -> x and then y
    
    
    const Point3D p3d{10,20,30};
    //                It will invoke the constructor anyway
    

    func( {100,200,300} ); 
    //    ~~~~~~~~~~~~
    // Use this syntax to populate a vector using std::initializer_list (This works because there is a constructor 
    // using std::initializer_list)
    //
    //    vector::vector(std::initializer_list<T> l);
    // 
    // The old c+++ way was:
    //
    // std::vector<int> temp;
    // temp.push_back(1);
    // temp.push_back(2);
    // temp.push_back(3);
    // func( temp ); 
    
    std::vector v{100,200,300};

    // multi-elemt insertion
    v.insert(v.end(), {3,12,19,1,2,7} );

    // assigment
    v = {25, 12};


    return 0;
}