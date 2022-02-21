#include <iostream>
#include <vector>
using namespace std;

class TrainStation
{
	int number;
	int hours;
	int minutes;
	string station;
public:
	TrainStation()
	{
		number = hours = minutes = 0;
		station = "Pushkinskaya";
	}
	TrainStation(int number, int hours, int minutes, string station) : number{number},hours{hours},minutes{minutes},station{station}{}
	int& GetNumber()
	{
		return number;
	}
	int& GetHours()
	{
		return hours;
	}
	int& GetMinutes()
	{
		return minutes;
	}
	string& GetStation()
	{
		return station;
	}
	void Print()
	{
		cout << "Номер поезда: " << number << "\n";
		cout << "Поезд припывает в " << hours << ":" << minutes << "\n";
		cout << "На станцию " << station << "\n";
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	vector<TrainStation> vect;
	vect.resize(1, {});
	int counttrain = 0;
	while (1)
	{
		counttrain++;
		cout << "Введите номер поезда ";
		int number;
		cin >> number;
		int hours, minutes;
		while (1)
		{
			cout << "Введите время прибытия поезда (в формате ЧЧ:ММ) ";
			cin >> hours;
			cin.ignore(1);
			cin >> minutes;
			if (hours < 24 and hours >= 0 and minutes < 60 and minutes >= 0)
				break;
		}
		cout << "Введите название станции, на которую прибывает поезд ";
		string station;
		cin >> station;
		vector<TrainStation>::iterator i_iterator = vect.end();
		vect.insert(i_iterator - 1, 1, {number, hours, minutes, station});
		bool a;
		cout << "Хотите продолжить вводить поезда или вывести их всех (0 - продолжать, 1 - вывести) ";
	    cin >> a;
		if (a)
			break;
	}
	for (int i = 0; i < vect.size() - 1; i++)
	{
		vect[i].Print();
		cout << "\n";
	}
}