#include <iostream>
#include<string>
#include "HeaderOfClass.h"

int main()
{
    std::cout << "+--------------------+\n";
    program::elf person;
    person.name = "Stive";             std::cout << "|name       | " << person.name <<"\n";
    person.world = "c1";                 std::cout << "|world      | " << person.world <<"\n";
    person.age = 20;                        std::cout << "|age        | " << person.age <<"\n";
    person.mind = true;                  std::cout << "|mind       | " << person.mind <<"\n";
    person.magic = true;                 std::cout << "|magic      | " << person.magic <<"\n";
    person.profession = "hunter"; std::cout << "|profession | " << person.profession <<"\n";
    person.light = true;                   std::cout << "|light      | " << person.light << "\n";
    person.power = 1247;              std::cout << "|power      | " << person.power <<"\n";
    person.growth = 177;               std::cout << "|growth     | " << person.growth <<"\n";
    person.weight = 57;                  std::cout << "|weight     | " << person.weight <<"\n";
    
    std::cout << "+-------animal-------+\n";
    program::wolf wolf;
    wolf.name = "Wolf";                      std::cout << "|name       | " << wolf.name << "\n";
    wolf.world = "c1";                          std::cout << "|world      | " << wolf.world << "\n";
    wolf.zone = "forest";                     std::cout << "|zone       | " << wolf.zone << "\n";
    wolf.power = 1444;                       std::cout << "|power      | " << wolf.power << "\n";
     std::cout << "|danger     | " << wolf.dangerCheck(person, wolf) << "\n";
    wolf.one = true;                             std::cout << "|one        | " << wolf.one << "\n";
    wolf.growth = 244;                        std::cout << "|growth     | " << wolf.growth << "\n";
    wolf.weight = 289;                        std::cout << "|weight     | " << wolf.weight << "\n";
    
    
    std::cout << "+--------------------+\n";
    program::ghost phantom;
    phantom.name = "Phantom";                                         std::cout << "|name       | " << phantom.name << "\n";
    phantom.age = 629;                                                          std::cout << "|age        | " << phantom.age << "\n";
    phantom.power = 5000;                                                   std::cout << "|power      | " << phantom.power << "\n";
                                                                                                  std::cout << "|danger     | " << phantom.dangerCheck(person, phantom) << "\n";
    phantom.fear = "incense";                                               std::cout << "|fear       | " << phantom.fear << "\n";
    phantom.real = false;                                                         std::cout << "|real       | " << phantom.real << "\n";
        
    
    std::cout << "+--------group--------+\n";
    program::ghost phantom1;    phantom1.power = 4000; phantom1.name = "Phantom"; phantom1.age = 300;

    program::creature group;
    group.name = "phantom + phantom1";                                  std::cout << "|name       | " << group.name << "\n";
    group = phantom + phantom1;      std::cout << "|power      | " << group.power << "\n";
    std::cout << "|danger     | " << group.dangerCheck(person, phantom) << "\n";

    phantom == phantom1 ? std::cout << "phantom = phantom1" : std::cout << "phantom != phantom1";

    phantom>phantom1? std::cout << "\nphantom older&powerful then phantom1\n" : std::cout << "\nphantom !(older&powerful then) phantom1\n";
    
    phantom < phantom1 ? std::cout << "\nphantom !(older&powerful then) phantom1\n" : std::cout << "\nphantom older&powerful then phantom1\n";

    program::bird bird;
    
    bird.fly = true;
    bird.weight = 2;
    program::size(bird);
    program::printfunc(bird);

    return 0;
}
