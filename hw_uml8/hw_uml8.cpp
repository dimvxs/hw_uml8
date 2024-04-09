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
	virtual void setName() abstract;
	virtual void setPrice() abstract;
	virtual void setProducer() abstract;
	virtual void setType() abstract;

};



class RAM : public Device //���������� ����������
{
public:

	/*void setName() override{}
	void setPrice() override {}
	void setProducer() override {}
	void setType() override {}*/

	void setName() override {
		name = "Corsair Vengeance LPX";
	}
	void setPrice() override {
		price = 100;
	}
	void setProducer() override {
		producer = "Corsair";
	}
	void setType() override {
		type = "DDR4";
	}


	void Print() override {
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "producer: " << producer << endl;
		cout << "type: " << type << endl;
	}

	

};

class HDD : public Device { //���������� ����������
public:

	void setName() override {
		name = "Seagate Barracuda";
	}
	void setPrice() override {
		price = 80;
	}
	void setProducer() override {
		producer = "Seagate";
	}
	void setType() override {
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


	void setName() override {
		name = "Sapphire Radeon RX 6700 XT Nitro+";
	}
	void setPrice() override {
		price = 500;
	}
	void setProducer() override {
		producer = "Sapphire";
	}
	void setType() override {
		type = "PCIe 4.0";
	}


	void Print() override {
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "producer: " << producer << endl;
		cout << "type: " << type << endl;
	}
};


class iPrint //����������
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
		device->setName();
		device->setPrice();
		device->setProducer();
		device->setType();
	}

		void PrintInfo() {
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
	iPrint* print = new iPrint();
	client(print, device);
	print->PrintInfo();
	cout << endl;

	device = new HDD();
	client(print, device);
	print->PrintInfo();
	cout << endl;

	device = new VGA();
	client(print, device);
	print->PrintInfo();
	delete device;
	delete print;
}

