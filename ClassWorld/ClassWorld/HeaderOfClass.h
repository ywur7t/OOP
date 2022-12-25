#pragma once
namespace program
{
	class basic_parameters
	{
	public:
		std::string name;
		double age;
		std::string world;
		double weight;
		double growth;
		double power;
		virtual void NamePrint(std::string name)
		{
			std::cout << "|name       | " << name << "\n";
		}
	};
	class anthropomorthic :public basic_parameters
	{
	public:		
		bool mind;
		bool magic;
		std::string profession;
	};	
	class triton :public anthropomorthic
	{
	public:
		double tail_length;
	};
	class elf :public anthropomorthic
	{
	public:	
		bool light;
	};
	class animals :public basic_parameters
	{
	public:		
		std::string zone;		
		double dangerCheck(anthropomorthic obj1, animals obj2)
		{
			if (obj1.power > obj2.power)
				return danger = 0;
			else
			{
				if (obj1.power > obj2.power / 2)
					return danger = 1;
				else return danger = 2;
			}
		}
	private:
		int danger;
	};

	class wolf :public animals
	{
	public:
		bool one;
	};	
	class bird :public animals
	{
	public:
		friend bool size(bird &);
		friend void printfunc(bird&);
		bool fly;
	private:
		bool size;
	};

	bool size(bird& obj)
	{
		obj.fly == true && obj.weight < 5 ? obj.size = true : obj.size = false;
		return obj.size;
	}
	void printfunc(bird& obj)
	{
		std::cout << "+--------bird---------+\n";
		std::cout  << obj.name << " size is ";
		if (obj.size) std::cout << "small\n";
		else std::cout << "medeum\n";
	}
	class creature :public animals
	{
	public:
		bool real;
		creature operator+(creature& obj1)
		{
			creature obj2;
			obj2.power =  power+obj1.power;
			return obj2;
		}
		creature operator=(const creature& obj1)
		{
			this->power = obj1.power;
			return *this;
		}
		bool operator==(const creature& obj1)
		{
			return (power == obj1.power) && (name == obj1.name);
		 }
		bool operator>(const creature& obj1)
		{
			return (age > obj1.age) && (power>obj1.power);
		}
		bool operator<(const creature& obj1)
		{
			return !((age > obj1.age) && (power > obj1.power));
		}
	};
	class ghost :public creature
	{
	public:
		std::string fear;
	};
	class mimc :public creature
	{
	public:
		double speed;	
		program::mimc( program::elf&& w)
		{
			age = w.age; 
			power = w.power; 
			growth = w.growth; 
			weight = w.weight; 
			w.age = 0; w.power = 0; w.growth = 0; w.weight = 0;
		}
	};
}
