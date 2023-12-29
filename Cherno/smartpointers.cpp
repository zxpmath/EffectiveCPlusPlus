#include<iostream>
#include<string>
#include<memory>

class Entity
{
  public:
     Entity()
     {
        std::cout << "Create Entity!" << std::endl;
     }

     ~Entity()
     {
        std::cout << "Destroyed Entity!" << std::endl;
     }

};

int main()
{
    {
        std::unique_ptr<Entity> entity= std::make_unique<Entity>();
        // the unique ptr cannot by copied.
    }
    std::shared_ptr<Entity> e0;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        e0 = sharedEntity;
    }
    // the shared ptr will create controll
    
    return 0;
}