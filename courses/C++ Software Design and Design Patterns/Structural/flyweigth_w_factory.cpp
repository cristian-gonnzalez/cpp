#include <iostream>
#include <map>
#include <memory>


// This is our class that will have many objects
struct Tree
{
    // Extrinsic state
    float _x, _y, _z;

    Tree(float x, float y, float z)
    :_x{x}, _y{y}, _z{z}
    {
    }
};

// 'Flyweight' - This is what we want to share
struct Model
{
    // Intrinsic (i.e. 'shared state') with all instances of Tree
    int mesh_data;
    int _leaves;

    // operation
    void draw_operation( const Tree& extrnsic_state)
    {
        std::cout << extrnsic_state._x << " " 
                  << extrnsic_state._y << " " 
                  << extrnsic_state._z << std::endl; 
    }
};

enum class ModelType 
{
    Flyweigth1,
    Flyweigth2
};


// Note: we could also 'template' our factory on the 'value'
struct FlyweigthFactory
{
    std::map<ModelType, std::shared_ptr<Model> > _flyweigths;

    std::shared_ptr<Model> get_flyweigth(ModelType type)
    {
        if( _flyweigths.contains( type ))
        {   
            std::cout << "reusing : \n"; 
            return _flyweigths[type];
        }
         
        _flyweigths[type] = std::make_shared<Model>();
        return _flyweigths[type];
    }
};

int main()
{
    Tree t1{1.0f, 7.0f, 3.0f};
    Tree t2{5.0f, 6.0f, 7.0f};
    Tree t3{8.0f, 9.0f, 10.0f};

    Model m;

    m.draw_operation(t1);
    m.draw_operation(t2);

    std::cout << "\tusing factory\n";

    FlyweigthFactory factory;
    factory.get_flyweigth(ModelType::Flyweigth1)->draw_operation(t1);
    factory.get_flyweigth(ModelType::Flyweigth2)->draw_operation(t2);
    factory.get_flyweigth(ModelType::Flyweigth1)->draw_operation(t3);

    return 0;
}