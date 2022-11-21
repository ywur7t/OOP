#include <iostream>
#include<string>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

struct notebook 
{
	std::string model;
	int frequency;
	struct size 	
	{		
		float x;		
		float y;		
		float z;	
	};
	size size;
	float w;
	int price;
};

bool compare(notebook note1, notebook note2)
{
	return note1.frequency < note2.frequency;
}

void rewrite(std::vector <notebook> first)
{
	std::ofstream fob("C:\\Users\\Владислав Алексеевич\\Desktop\\C\\C++\\ООП\\readFile\\bin.bin",  std::ios_base::binary | std::ios_base::app); 
	
	
	
	fob << std::endl;
	std::sort(first.begin(), first.end(),compare);
	for (auto i = 0; i < first.size(); ++i)
	{
		/*fob << *& first[i].model << std::endl;
		fob << *&first[i].frequency << std::endl;
		fob << *&first[i].size.x << std::endl;
		fob << *&first[i].size.y << std::endl;
		fob << *&first[i].size.z << std::endl;
		fob << *&first[i].w << std::endl;
		fob << *&first[i].price << std::endl;
		fob << std::endl;*/
		
		/*fob << first[i].model << std::endl;
		fob <<  first[i].frequency << std::endl;
		fob <<  first[i].size.x << std::endl;
		fob <<  first[i].size.y << std::endl;
		fob <<  first[i].size.z << std::endl;
		fob <<  first[i].w << std::endl;
		fob <<  first[i].price << std::endl;
		fob << std::endl;*/


		fob.write((char*)&(first[i].model), sizeof(first[i].model)); fob << std::endl;
		fob.write((char*)&(first[i].frequency), sizeof(first[i].frequency)); fob << std::endl;
		fob.write((char*)&(first[i].size.x), sizeof(first[i].size.x)); fob << std::endl;
		fob.write((char*)&(first[i].size.y), sizeof(first[i].size.y)); fob << std::endl;
		fob.write((char*)&(first[i].size.z), sizeof(first[i].size.z)); fob << std::endl;
		fob.write((char*)&(first[i].w), sizeof(first[i].w)); fob << std::endl;
		fob.write((char*)&(first[i].price), sizeof(first[i].price)); fob << std::endl;
		
	}
	fob.close();
}

void readfile(std::vector <notebook> &first)
{
	int number; std::string str; float num; notebook note;
	std::ifstream fos("C:\\Users\\Владислав Алексеевич\\Desktop\\C\\C++\\ООП\\readFile\\note.txt");
	
	if (fos.is_open())
	{
		int cout;		fos >> cout;
		std::ofstream fob("C:\\Users\\Владислав Алексеевич\\Desktop\\C\\C++\\ООП\\readFile\\bin.bin",std::ios_base::binary);
		fob.write((char*)&(cout), sizeof(cout)); 
		fob.close();
		for (auto i = 0; i < cout; ++i)
		{
			fos >> str;	note.model = str;
			fos >> number;	
			
				note.frequency = number;
				fos >> num;	note.size.x = num;
				fos >> num;	note.size.y = num;
				fos >> num;	note.size.z = num;
				fos >> num;	note.w = num;
				fos >> number;	note.price = number;
				
					if(note.frequency>=120) first.push_back(note);
		}
		rewrite(first);

	}
	else
	{
		std::cout << "file does not found\n";
	}





	fos.close();
}


int main()
{
	std::vector <notebook> first;
    
	readfile(first);
	first.clear();
	return 0;
}