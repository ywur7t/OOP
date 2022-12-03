//предметная область - астрономия
//boost=G*M/R^2
//солнечная система
//планеты и солнце
#include <iostream>
#include<string>
#include<vector>
#include<cmath>
enum planetkind{terrestrial,giant};
enum spectrum{O,B,A,F,G,K,M};
class options
{
public:
    double weight;
    double radius;
    std::string name;
    
    double boost()
    {
         return (6.67e-11 * this->weight / std::pow(this->radius, 2));
    }
};



class stars:public options
{
public:
    double luminosity;//светимость 
    double temperature;//температура
    spectrum spectral_class;//спектральный класс
};

class planets:public options
{
public:
    planetkind kind;//вид планеты(земная, гигант)
};


bool operator >(planets obj1,int a)
{
    return obj1.weight > a;
}

bool operator <(planets obj1, int a)
{
    return obj1.weight < a;
}

bool operator ==(planets obj1, int a)
{
    return obj1.weight == a;
}

bool operator !=(planets obj1, int a)
{
    return obj1.weight != a;
}






class solar_system
{
public:
    std::vector<stars> star;//звезды
    std::vector<planets> planet;//планеты
};


//сделать перегрузку операторов на сравнение планеты по массе гигант или земной тип



int main()
{
    solar_system system;
    stars starelement;  planets planetelement;
    
    starelement.name = "Sonne";
    starelement.luminosity = 3.828e+26;
    starelement.radius = 6.95e+8;
    starelement.spectral_class = G;
    starelement.temperature = 5780;
    starelement.weight = 1.988e+30;
    system.star.push_back(starelement);

    planetelement.name = "merkur";
    planetelement.kind = terrestrial;
    planetelement.radius = 2439.7e+3 ;
    planetelement.weight = 3.33e+23 ;
    system.planet.push_back(planetelement);

    planetelement.name = "venus";
    planetelement.kind = terrestrial;
    planetelement.radius = 6051.8e+3;
    planetelement.weight = 4.867e+24;
    system.planet.push_back(planetelement);

    planetelement.name = "erde";
    planetelement.kind = terrestrial;
    planetelement.radius = 6378.1e+3;
    planetelement.weight = 5.9726e+24;
    system.planet.push_back(planetelement);

    planetelement.name = "mars";
    planetelement.kind = terrestrial;
    planetelement.radius = 3396.2e+3;
    planetelement.weight = 6.4171e+23;
    system.planet.push_back(planetelement);
    ///////////////////////////////////////////////////////
    planetelement.name = "Jupiter";
    planetelement.kind =giant;
    planetelement.radius = 71492e+3;
    planetelement.weight = 1.8986e+27;
    system.planet.push_back(planetelement);

    planetelement.name = "Satur";
    planetelement.kind = giant;
    planetelement.radius = 60268e+3;
    planetelement.weight = 5.6846e+26;
    system.planet.push_back(planetelement);

    planetelement.name = "Uran";
    planetelement.kind = giant;
    planetelement.radius = 25559e+3;
    planetelement.weight = 8.6813e+25;
    system.planet.push_back(planetelement);

    planetelement.name = "Neptun";
    planetelement.kind = giant;
    planetelement.radius = 24764e+3;
    planetelement.weight = 1.0243e+26;
    system.planet.push_back(planetelement);



    std::cout << "         stars";
    std::cout << "\n+---------------------+\n";
    std::cout << "|  " << system.star[0].name << "     ";    std::cout << system.star[0].spectral_class << "        \n";
    std::cout << "|  " << system.star[0].luminosity << "     ";    std::cout << system.star[0].temperature << " \n";
    std::cout << "|  " << system.star[0].radius << "  ";    std::cout << system.star[0].weight << "\n";
    std::cout << "|  " << system.star[0].boost() << "\n";
    std::cout << "\n+---------------------+\n";

    std::cout << "         planet"; int i = 0;
    while (i<system.planet.size())
    {
        std::cout << "\n+---------------------+\n";
        std::cout << "|  " << system.planet[i].name << "\n";
        std::cout << "|  " << system.planet[i].kind << "\n";
        std::cout << "|  " << system.planet[i].radius << "\n";
        std::cout << "|  " << system.planet[i].weight << "\n";
        std::cout << "|  " << system.planet[i].boost() << "\n";
        i++;
    }
    std::cout << "\n+---------------------+\n";
    

    return 0;
}

