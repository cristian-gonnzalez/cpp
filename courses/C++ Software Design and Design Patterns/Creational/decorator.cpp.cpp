#include <iostream>
#include <memory>

/*
//
//   Inheritance-based polymorphims
// 
//          ----------------------
//          |      IEnemy        |
//          |--------------------|
//          |+ compute_damage()  |
//          |                    |
//          |                    |
//          ----------------------
//                    ^
//             _______|______________________
//            |                              |
//  ----------------------          ----------------------
//  |      Orc           |          |      Goblin        |
//  |--------------------|          |--------------------|
//  |+ compute_damage()  |          |+ compute_damage()  |
//  |                    |          |                    |
//  ----------------------          ----------------------
//
//
*/

struct IEnemy
{
    virtual void compute_damage() = 0;
};

struct Orc : public IEnemy
{
    void compute_damage()
    {
        std::cout << "Orc::compute_damage()\n";
    }
};

struct Goblin : public IEnemy
{
    void compute_damage()
    {
        std::cout << "Goblin::compute_damage()\n";
    }
};

/*
// 
// 
//          ----------------------
//          |      IEnemy        |
//          |--------------------|
//          |+ compute_damage()  |
//          |                    |
//          |                    |
//          ----------------------
//                    ^
//             _______|______________________________________________________________________
//            |                              |                                               |
//  ----------------------          ----------------------                         ----------------------------
//  |      Orc           |          |      Goblin        |                         |  IEnemyDecorator         |
//  |--------------------|          |--------------------|                         |--------------------------|
//  |+ compute_damage()  |          |+ compute_damage()  |                         |+ IEnemyDecorator(enemy)  |
//  |                    |          |                    |                         |                          |
//  ----------------------          ----------------------                         |+ compute_damage()        | --> virtual void compute_damage() 
//  ----------------------          ----------------------                         |                          |     {
//                                                                                 |- _enemy:IEnemy           |     }
//                                                                                 ----------------------------
//                                                                                           ^
//                                                            _______________________________|
//                                                           |                               |
//                                              ----------------------          ----------------------             
//                                              |  HelmetDecorator   |          |  ArmourDecorator   | 
//                                              |--------------------|          |--------------------| 
//                                              |+ compute_damage()  |          |+ compute_damage()  | --> def compute_damage() {     
//                                              |                    |          |                    |       _enemy.compute_damage()  
//                                              |                    |          |                    |     }
//                                              ----------------------          ----------------------  
//
*/

struct IEnemyDecorator : public IEnemy
{
    std::shared_ptr<IEnemy> _enemy;
    IEnemyDecorator(std::shared_ptr<IEnemy> enemy)
    :_enemy{enemy}
    {
    }
    virtual void compute_damage()
    {
        std::cout << "IEnemyDecorator::compute_damage()\n";
        _enemy->compute_damage();
    }
};

struct HelmetDecorator : public IEnemyDecorator
{
    HelmetDecorator(std::shared_ptr<IEnemy> enemy)
    :IEnemyDecorator{enemy}
    {
    }
    void compute_damage()
    {
        std::cout << "HelmetDecorator::compute_damage()\n";
        _enemy->compute_damage();
    
    }
};

struct ArmourDecorator : public IEnemyDecorator
{
    ArmourDecorator(std::shared_ptr<IEnemy> enemy)
    :IEnemyDecorator{enemy}
    {
    }
    void compute_damage()
    {
        std::cout << "ArmourDecorator::compute_damage()\n";
        _enemy->compute_damage();
    
    }
};

int main(int argc, char* argv[])
{
    std::shared_ptr<IEnemy> goblin = std::make_shared<Goblin>();
    std::shared_ptr<IEnemyDecorator> goblin_w_helmet = std::make_shared<HelmetDecorator>(goblin);
    std::shared_ptr<IEnemyDecorator> goblin_w_helmet_armor = std::make_shared<ArmourDecorator>(goblin_w_helmet);

    goblin_w_helmet_armor->compute_damage();    

    return 0;
}