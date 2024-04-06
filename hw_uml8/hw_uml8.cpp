// hw_uml8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//������������� ���������� ������ ������ � ��������������� ��������� ����������� ����������, ��������� ������� �Bridge�.
//����� ������ �������� ���������� �� ����� �� ��������� ��������� :
//? ����������
//? ���������
//? ������� ����
//������������� ���������� ����� �������, ����� ���������� ���� �������� �� ����������.
//����� ��������� �������������� �������� � ���������� ����������������, ����������� �������� ���������� �� ���������� ����������� ������.

#include <iostream>
using namespace std;

class Device abstract //����������
{
public:
	int price;
	string name;
	string producer;
	string type;
	virtual void Print() abstract;
};



class RAM : public Device //���������� ����������
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

class HDD : public Device { //���������� ����������
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

class VGA : public Device { //���������� ����������
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


class iPrint abstract //����������
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

void client(iPrint* print, Device* device) //������
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

