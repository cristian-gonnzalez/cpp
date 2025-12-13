#include <iostream>
#include <memory>
#include <map>

/*
// Monolotic GameObject (coupling components)

struct TextureComponent{};
struct CollisionBoxComponent{};
struct TransformComponent{};
struct StateComponent{};
struct InputComponent{};
struct UserInterface2DComponent{};
struct AIBehaviourComponent{};

struct GameObject
{
    TextureComponent*         _texture{nullptr};
    CollisionBoxComponent*    _collision{nullptr};
    TransformComponent*       _transform{nullptr};
    StateComponent*           _state{nullptr};
    InputComponent*           _input{nullptr};
    UserInterface2DComponent* _user_interface{nullptr};
    AIBehaviourComponent*     _ai{nullptr};
};

 */


enum class ComponentType
{
    Texture,
    CollisionBox,
    Transform,
    Position,
    State,
    Input,
    UserInterface2D,
    AIBehaviour
};

struct IComponent
{
    // must be 
    virtual void update() = 0;

    ComponentType get_type()
    {
        return _type;
    }

    protected:
        IComponent(ComponentType type)
        :_type{type}
        {
        }
        ~IComponent()
        {
        }

        const ComponentType _type;
};


struct TextureComponent : public IComponent
{
    TextureComponent()
    :IComponent(ComponentType::Texture)
    {
    }

    void update() override
    {
        std::cout << "TextureComponent::update()\n";
    }

    private:
        // texture data
        uint32_t _width, _height;
};


struct CollisionComponent : public IComponent
{
    CollisionComponent()
    :IComponent(ComponentType::CollisionBox)
    {
    }

    void update() override
    {
        std::cout << "CollisionComponent::update()\n";
    }
};


struct PositionComponent : public IComponent
{
    PositionComponent()
    :IComponent(ComponentType::Position)
    {
    }

    void update() override
    {
        std::cout << "PositionComponent::update()\n";
    }
};

// GameObject base type
struct GameObject
{
    
    void update()
    {
        std::cout << "GameObject::update()\n";
        for(auto& [_, c]: _components)
            c->update();
    }

    void add_component(std::shared_ptr<IComponent> c)
    {
        _components[c->get_type()] = c;
    }

    std::shared_ptr<IComponent> get_component(ComponentType t)
    {
        if( !_components.contains(t) )
            return nullptr;

        return _components[t];
    }
    
    private:
        // Note: this could be another container type such as std::vector
        // Note: May consider using std::unique_ptr instead of std::shared_ptr
        //       to not share
        std::map< ComponentType, 
                  std::shared_ptr<IComponent> > _components;
};


int main()
{
    std::unique_ptr<GameObject> Mario = std::make_unique<GameObject>();

    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>();
    std::shared_ptr<CollisionComponent> collision = std::make_shared<CollisionComponent>();
    std::shared_ptr<PositionComponent> position = std::make_shared<PositionComponent>();

    Mario->add_component(texture);
    Mario->add_component(collision);
    Mario->add_component(position);

    Mario->update();

    std::shared_ptr<IComponent> myComponent = Mario->get_component(ComponentType::Texture);
    myComponent->update();

    return 0;
}