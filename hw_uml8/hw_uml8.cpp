// hw_uml8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Спроектируйте библиотеку вывода отчета о характеристиках устройств настольного компьютера, используя паттерн «Bridge».
//Отчет должен выводить информацию об одном из следующих устройств :
//? Видеокарта
//? Процессор
//? Жесткий диск
//Спроектируйте библиотеку таким образом, чтобы абстракция была отделена от реализации.
//После окончания проектирования добавьте в библиотеку функциональность, позволяющую выводить информацию об устройстве оперативной памяти.

#include <iostream>
using namespace std;

class Device abstract //реализация
{
public:
	int price;
	string name;
	string producer;
	string type;
	virtual void Print() abstract;
};



class RAM : public Device //конкретный реализатор
{
	int volume;
public:

	RAM() {
		name = "Corsair Vengeance LPX";
		price = 100;
		producer = "Corsair";
		type = "DDR4";
		volume = 8096;


	}

	void Print() override {
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "producer: " << producer << endl;
		cout << "type: " << type << endl;
		cout << "volume: " << volume << endl;
	}

	

};

class HDD : public Device { //конкретный реализатор
public:
	HDD() {
		name = "Seagate Barracuda";
		price = 80;
		producer = "Seagate";
		type = "SATA 3.5";

	}

	void Print() override {
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "producer: " << producer << endl;
		cout << "type: " << type << endl;
	}
};

class VGA : public Device { //конкретный реализатор
public:
	VGA() {
		name = "Sapphire Radeon RX 6700 XT Nitro+";
		price = 500;
		producer = "Sapphire";
		type = "PCIe 4.0";

	}

	void Print() override {
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "producer: " << producer << endl;
		cout << "type: " << type << endl;
	}
};


class iPrint abstract //абстракция
{
protected:
	Device* device;
public:
	Device* getDevice()
	{
		return device;
	}
	void setDevice(Device* device)
	{
		this->device = device;
	}

	virtual void PrintInfo() abstract;
	

};

class Print : public iPrint {
public:
	void PrintInfo() override{
		device->Print();
	}
};

void client(iPrint* print, Device* device) //клиент
{
	print->setDevice(device);
}

int main()
{
	Device* device = new RAM();
	iPrint* print = new Print();
	client(print, device);
	print->PrintInfo();
	delete print;
}

