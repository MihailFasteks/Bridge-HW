#include <iostream>
#include <string>
using namespace std;

/*
 ������� Bridge ��������� �������� ���������� �� �� ���������� ���,
 ����� �� � ������ ����� ���� �������� ����������.

������ ������� ������������ �����:
- ����� �������� ���������� �������� ���������� � ����������.
���, ��������, ������, ����� ���������� ���������� �������� �� ����� ���������� ���������.
- � ����������, � ���������� ������ ����������� ������ �����������.
� ����� ������ ������� ���� ��������� ������������� ������ ���������� � ���������� � �������� �� ����������;
- ��������� � ���������� ���������� �� ������ ����������� �� ��������, �� ���� ���������� ��� �� ������ �������������������;

����������:
- ��������� ���������� �� ����������;
- ��������� ������� �������������;
- �������� ������� ���������� �� ��������.
*/

/*
Implementor(ILanguage) - ���������� ���������� ��������� ��� ������� ����������.
*/
class Device abstract
{
protected:
	string name;
	string type;
	float cost;
	string manufacture;	
public:
	Device(string n, string t, float c, string m) : name(n), type(t), cost(c), manufacture(m) {}

	string GetName() const {
		return name;
	}

	string GetType() const {
		return type;
	}

	float GetCost() const {
		return cost;
	}

	string GetManuf() const {
		return manufacture;
	}
};

// Concretelmplementor (CPPLanguage)  - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.
class RAM : public Device {
public:
	RAM(string t, string m, float c) : Device("RAM", t, c, m) {}
};

class HDD : public Device {
public:
	HDD(string t, string m, float c) : Device("HDD", t, c, m) {}
};

class VGA : public Device {
public:
	VGA(string t, string m, float c) : Device("VGA", t, c, m) {}
};

// Concretelmplementor (CSharpLanguage) - ���������� ����������  �������� ���������� ���������� ���������� ������ Implementor.


// Abstraction (Programmer) - ���������� ��������� ���������� � ������ ������ �� ������ ���������� ���� Implementor
class IPrint 
{
protected:
	Device* device;
public:
	Device* GetDevice()
	{
		return device;
	}
	void SetDevice(Device* device)
	{
		this->device = device;
	}
	 void Print()
	{
		cout << "Device: " << " Model: " << device->GetType() << " Cost: " << device->GetCost() << " Manufacture: " << device->GetManuf() << endl;
	}
	
};

// RefinedAbstraction (FreelanceProgrammer)  - ���������� ���������� ��������� ���������, ������������ ����������� Abstraction


void client(Device* d, IPrint* pr)
{
	pr->SetDevice(d);
	// ������ Abstraction (Programmer) �������������� ������ ������� Implementor ������� �������.
	pr->Print();
	
}

int main()
{
	Device* device = new RAM("AM-7854", "Lenovo", 4500);
	IPrint* print = new IPrint();
	client(device, print);
delete device;

	//ILanguage* lang = new CPPLanguage();
	//Programmer* programmer = new FreelanceProgrammer();
	//client(lang, programmer);
	//delete lang;

	//lang = new CSharpLanguage();
	//client(lang, programmer);
	//delete lang;
	//delete programmer;

	//lang = new CPPLanguage();
	//programmer = new CorporateProgrammer();
	//client(lang, programmer);
	//delete lang;

	//lang = new CSharpLanguage();
	//client(lang, programmer);
	//delete lang;
	//delete programmer;

	//system("pause");
	//return 0;
}