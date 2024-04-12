#include <iostream>
#include <string>
using namespace std;

/*
 Паттерн Bridge позволяет отделить абстракцию от ее реализации так,
 чтобы то и другое можно было изменять независимо.

Данный паттерн используется когда:
- нужно избежать постоянной привязки абстракции к реализации.
Так, например, бывает, когда реализацию необходимо выбирать во время выполнения программы.
- и абстракции, и реализации должны расширяться новыми подклассами.
В таком случае паттерн мост позволяет комбинировать разные абстракции и реализации и изменять их независимо;
- изменения в реализации абстракции не должны сказываться на клиентах, то есть клиентский код не должен перекомпилироваться;

Результаты:
- отделение реализации от интерфейса;
- повышение степени расширяемости;
- сокрытие деталей реализации от клиентов.
*/

/*
Implementor(ILanguage) - реализатор определяет интерфейс для классов реализации.
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

// Concretelmplementor (CPPLanguage)  - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
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

// Concretelmplementor (CSharpLanguage) - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.


// Abstraction (Programmer) - определяет интерфейс абстракции и хранит ссылку на объект реализации типа Implementor
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

// RefinedAbstraction (FreelanceProgrammer)  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction


void client(Device* d, IPrint* pr)
{
	pr->SetDevice(d);
	// Объект Abstraction (Programmer) перенаправляет своему объекту Implementor запросы клиента.
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