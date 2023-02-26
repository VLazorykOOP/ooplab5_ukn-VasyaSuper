#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "Lab5Exmaple.h"
using namespace std;

//Задача 1.3.
//Створити клас машина, що має поля : марка авто, число цилiндрiв,потужнiсть.
//Визначити конструктори, деструктор i функцiю друку.
//Створити похiдний клас - вантажiвки, що має поле вантажопiдйомнiсть кузова.
//Визначити конструктори за замовчуванням та iз рiзним числом параметрiв, деструктори, функцiю друку.
//Визначити функцiї перепризначення марки та вантажопiдйомностi.
//Написати програму тестування всiх можливостей цього класу.

class Car 
{
protected:
	string CarBrand;
	int NumberCylinders;
	double Power;
public:
	Car() 
	{
		CarBrand = "None";
		NumberCylinders = 0;
		Power = 0;
		std::cout << " Default constructor Car \n";
	}
	Car(string carBrand)
	{
		CarBrand = carBrand;
		NumberCylinders = 0;
		Power = 0;
		cout << " Constructor Car(int carBrand) \n";
	}
	Car(string carBrand, int numberCylinders)
	{
		CarBrand = carBrand;
		NumberCylinders = numberCylinders;
		Power = 0;
		cout << " Constructor Car(char carBrand, int numberCylinders) \n";
	}
	Car(string carBrand, int numberCylinders, double power)
	{
		CarBrand = carBrand;
		NumberCylinders = numberCylinders;
		Power = power;
		cout << " Constructor Car(char carBrand, int numberCylinders, double power) \n";
	}
	~Car()
	{
		cout << "\tDestructor Car\n";
	}
	void setCarBrand(string carBrand) 
	{
		CarBrand = carBrand;
	}
	void setNumberCylinders(int numberCylinders)
	{
		if (numberCylinders >= 0 && numberCylinders <= 32)
			NumberCylinders = numberCylinders;
		else
			cout << "NumberCylinders " << numberCylinders << " not exist,  weight is " << NumberCylinders << endl;;
	}
	void setPower(double power)
	{
		if (power >= 0 && power <= 2000)
			Power = power;
		else
			cout << "NumberCylinders " << power << " not exist,  weight is " << Power << endl;;
	}
	void Input() {
		cout << "Input CarBrand: "; cin >> CarBrand;
		cout << "Input numberCylinders: ";  while (!(cin >> NumberCylinders) || (NumberCylinders < 0 || NumberCylinders > 32)) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << "Bad  input NumberCylinders is 1 to 32 !!! \n";
		};
		cout << "Input Power: ";  while (!(cin >> Power) || (Power < 0 || Power > 2000)) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << "Bad  input weight is 1 to 2000 !!! \n";
		};
	}
	string toString() 
	{
		string carBrand = " CarBrand: " +  CarBrand;
		string numberCylinders = to_string (NumberCylinders);
		string power = to_string(Power);
		string res = carBrand + " NumberCylinders: " + numberCylinders + " Power: " + power;

		return res;
	}
};
class Truck : public Car 
{
	double MaxWeight;
public:
	Truck() {
		MaxWeight = 0;
		cout << " Default constructor Truck() \n";
	}
	Truck(string carBrand, int numberCylinders, double power, double maxWeight) :
		Car(carBrand, numberCylinders, power) {
		MaxWeight = maxWeight;
		cout << " Constructor  Truck(char carBrand, int numberCylinders, double power, double maxWeight) \n";
	}
	~Truck() {
		cout << "\tDestructor Truck\n";
	}
	void setMaxWeight(double maxWeight) {
		if (maxWeight > 0) MaxWeight = maxWeight;
		else MaxWeight = 0;
	}
	void Input() {
		Car::Input();
		cout << "Input MaxWeight: ";
		while (!(cin >> MaxWeight) || MaxWeight < 0) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << "Bad  input MaxWeight!!! \n";
		};
	}
	string toString() {
		string maxWeight = to_string(MaxWeight);
		string result = Car::toString() + " MaxWeight: " + maxWeight + ".\n ";
		return result;
	}
	void Output() {
		cout << toString() << endl;
	}
};

int Exrcise1Main()
{
	setlocale(LC_CTYPE, "ukr");
	cout << " Задача 1.3 \n";
	cout << " Створити клас машина, що має поля : марка авто, число цилiндрiв,потужнiсть. \n";
	cout << " Визначити конструктори, деструктор i функцiю друку. \n";
	cout << " Створити похiдний клас - вантажiвки, що має поле вантажопiдйомнiсть кузова. \n";
	cout << " Визначити конструктори за замовчуванням та iз рiзним числом параметрiв, деструктори, функцiю друку. \n";
	cout << " Визначити функцiї перепризначення марки та вантажопiдйомностi.\n";
	cout << " Написати програму тестування всiх можливостей цього класу. \n";

	char Choice = 'n';
	do
	{
		cout << "\n\n\n Main menu \n";
		cout << "1 - Default constructor Truck \n";
		cout << "2 - Default constructor Truck - input  \n";
		cout << "3 - Constructor Truck  Truck(string carBrand, int numberCylinders, double power, double maxWeight)   \n";
		cout << "4 - Set carBrand   \n";
		cout << "5 - Set maxWeight   \n";
		cout << "q - Quit  \n";
		cout << "You choice: ";
		cin >> Choice;

		switch (Choice)
		{
		case '1': {
			Truck test;
			cout << test.toString() << " \n";
		}
				break;
		case '2': {
			Truck test;
			cout << " Введiть : Марку автомобiля (English), кiлькiсть цилiндрiв, потужнiсть та вантажопiдйомнiсть кузова: \n";
			test.Input();
			cout << " Введено " << test.toString() << " \n";
		}
				break;
		case '3': {
			Truck test("Maserati", 12, 1000, 500);
			string rez = test.toString();
			cout << rez;
		}
				break;
		case '4': {
			Truck test("Maserati", 12, 1000, 500);
			test.toString();
			cout << test.toString() << endl;
			cout << " Input new CarBrand Maserati: ";
			string NewCarBrand;
			cin >> NewCarBrand;
			test.setCarBrand(NewCarBrand);
			cout << " Renovated: " << test.toString() << endl;
		}
				break;
		case '5': {
			Truck test("Maserati", 12, 1000, 500);
			test.toString();
			cout << test.toString() << endl;
			cout << " Input new MaxWeight Maserati: ";
			double NewMaxWeight;
			cin >> NewMaxWeight;
			test.setMaxWeight(NewMaxWeight);
			cout << " Renovated: " << test.toString() << endl;
		}
				break;
		case 'q': break;
		default:
			cout << " ???  Choice {1,2, ..., 7 or q}  \n";
		}

	} while (Choice != 'q');

	return 0;
}

//Задача 2.3.
//Створити клас двигун, що має потужнiсть.
//Визначити конструктори й метод доступу.
//Створити клас машинa, що мiстить клас двигун.Додатково є марка (вказiвник на рядок), цiна.
//Визначити конструктори й деструктор.
//Визначити public - похiдний клас вантажiвка, що має додатково вантажопiдйомнiсть.
//Визначити конструктори, деструктори й функцiю друку.
//Написати програму тестування всiх можливостей цього класу.

class Engine {
private:
	double Power;
public:
	Engine() {
		Power = 0.0;
		cout << " Default constructor Engine: \n";
	}
	Engine(int power) {
		Power = power;
		cout << " Default constructor Engine(double power): \n";
	}
	~Engine() {
		cout << "\tDestructor Engine\n";
	}
	int getPower() {
		return Power;
	}
	string toString() {
		string power = to_string(Power);
		string res = " Power: " + power;

		return res;
	}
	void Input() {
		cout << " Input Power: "; cin >> Power;
	}
};
class Car1{
protected:
	char* Brand;
	double Price;
	Engine Engine;
public:
	Car1() {
		Brand = NULL;
		Price = 0;
		Engine = 0;
		std::cout << " Default constructor Car1() \n";
	}
	Car1(const char* brand, double price, double enginePower) : Brand(new char[strlen(brand) + 1]), Price(price), Engine(enginePower) {
		strcpy(this->Brand, brand);
	}
	~Car1() {
		delete[] Brand;
		cout << "\tDestructor Car1\n";
	}
	const char* getBrand() {
		return Brand;
	}
	int getPrice() {
		return Price;
	}
	int getEnginePower() {
		return Engine.getPower();
	}
	string toString() {
		string brand = Brand;
		string price = to_string(Price);
		string res = Engine.toString() + " Brand: " + brand + " Price: " + price;

		return res;
	}
	void Input() {
		Engine.Input();
		cout << "Input Brand: "; cin >> Brand;
		cout << "Input Price: "; cin >> Price;
	}
};
class Truck1 : public Car1 {
private:
	double CargoCapacity;
public:
	Truck1() {
		CargoCapacity = 0.0;
		cout << " Default constructor Truck1() \n";
	}
	Truck1(const char* brand, double price, double enginePower, double cargoCapacity) : Car1(brand, price, enginePower), CargoCapacity(cargoCapacity) {}
	int getCargoCapacity() const { 
		return CargoCapacity; 
	}
	~Truck1() {
		cout << "\tDestructor Truck\n";
	}
	int getCargoCapacity() {
		return CargoCapacity;
	}
	string toString() {
		string cargoCapacity = to_string(CargoCapacity);
		string res = Car1::toString() + " CargoCapacity: " + cargoCapacity;

		return res;
	}
	void Input() {
		Car1::Input();
		cout << "Input CargoCapacity: "; cin >> CargoCapacity;
	}
};

int Exrcise2Main() {
	setlocale(LC_CTYPE, "ukr");
	cout << " Задача 2.3 \n";
	cout << " Створити клас двигун, що має потужнiсть. \n";
	cout << " Визначити конструктори й метод доступу. \n";
	cout << " Створити клас машинa, що мiстить клас двигун.Додатково є марка (вказiвник на рядок), цiна. \n";
	cout << " Визначити конструктори й деструктор. \n";
	cout << " Визначити public - похiдний клас вантажiвка, що має додатково вантажопiдйомнiсть.\n";
	cout << " Визначити конструктори, деструктори й функцiю друку. \n";
	cout << " Написати програму тестування всiх можливостей цього класу. \n\n";
	char* auto1 = (char*)"Maserati";
	
	Engine engine;
	cout << engine.toString() << " \n";

	engine.Input();
	cout << engine.toString() << " \n";

	//Car1 car ("Toyota ", 20000, 150);
	//cout << car.toString() << " \n";

	//car.Input();
	//cout << car.toString() << " \n";

	//Truck1 truck("Volvo ", 5000.0, 300.0, 5000.0);
	//cout << truck.toString() << " \n";

	//truck.Input();
	//cout << truck.toString() << " \n";

	return 0;
}

//Задача 3.3.
//Створити iєрархiю класiв меблi й стiл.
//Визначити конструктори й метод доступу.
//Перевизначити вивiд у потiк i введення з потоку, конструктор копiювання, оператор присвоювання через вiдповiднi функцiї базового класу.

// Базовий клас "Меблi"
class Furniture {
protected:
	string m_material;  // Матерiал
	string m_color;     // Колiр
public:
	Furniture(string material = "", string color = "") { 
		m_material = material; 
		m_color = color; 
	}
	~Furniture() { cout << "\tDestructor Furniture\n"; }

	// Перевизначення виводу у потiк
	friend ostream& operator<<(ostream& os, const Furniture& furniture) {
		os << "Material: " << furniture.m_material << ", Color: " << furniture.m_color;
		return os;
	}

	// Перевизначення вводу з потоку
	friend istream& operator>>(istream& is, Furniture& furniture) {
		is >> furniture.m_material >> furniture.m_color;
		return is;
	}

	// Конструктор копiювання
	Furniture(const Furniture& other) {
		m_material = other.m_material;
		m_color = other.m_color;
	}

	// Оператор присвоювання
	Furniture& operator=(const Furniture& other) {
		if (this != &other) {
			m_material = other.m_material;
			m_color = other.m_color;
		}
		return *this;
	}
};

// Похiдний клас "Стiл"
class Table : public Furniture {
public:
	int m_height;   // Висота столу
	int m_width;    // Ширина столу
	int m_length;   // Довжина столу
public:
	Table(int height = 0, int width = 0, int length = 0,
		string material = "", string color = "") :
		Furniture(material, color), m_height(height), m_width(width), m_length(length) {}

	~Table() { cout << "\tDestructor Table\n"; }

	// Перевизначення виводу у потiк
	friend ostream& operator<<(ostream& os, const Table& table) {
		os << "Table [Height: " << table.m_height << ", Width: " << table.m_width << ", Length: " << table.m_length << ", " << static_cast<const Furniture&>(table) << "]";
		return os;
	}

	// Перевизначення вводу з потоку
	friend istream& operator>>(istream& is, Table& table) {
		is >> table.m_height >> table.m_width >> table.m_length;
		is >> static_cast<Furniture&>(table);
		return is;
	}

	// Конструктор копiювання
	Table(const Table& other) :
		Furniture(other), m_height(other.m_height), m_width(other.m_width), m_length(other.m_length) {}

	// Оператор присвоювання
	Table& operator=(const Table& other) {
		if (this != &other) {
			Furniture::operator=(other);
			m_height = other.m_height;
			m_width = other.m_width;
			m_length = other.m_length;
		}
		return *this;
	}
};

int Exrcise3Main() {

	// Створення об'єкту меблiв та вивiд у потiк
	Furniture furniture("дерево", "коричневий");
	cout << furniture << endl;

	// Створення об'єкту столу та вивiд у потiк
	Table table(80, 120, 60, "скло", "бiлий");
	cout << table << endl;

	// Зчитування даних меблiв з потоку
	string furnitureStr = "метал чорний";
	stringstream ss(furnitureStr);
	Furniture furniture2;
	ss >> furniture2;
	cout << furniture2 << endl;

	// Зчитування даних столу з потоку
	string tableStr = "90 140 70 дерево бiлий";
	stringstream ss2(tableStr);
	Table table2;
	ss2 >> table2;
	cout << table2 << endl;

	// Тест конструктора копiювання та оператора присвоєння
	Table table3 = table2;
	Table table4(table2);
	table3.m_height = 100;
	table4.m_height = 110;
	cout << table2 << endl;
	cout << table3 << endl;
	cout << table4 << endl;

	return 0;
}
