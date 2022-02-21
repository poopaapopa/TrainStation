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
		cout << "����� ������: " << number << "\n";
		cout << "����� ��������� � " << hours << ":" << minutes << "\n";
		cout << "�� ������� " << station << "\n";
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
		cout << "������� ����� ������ ";
		int number;
		cin >> number;
		int hours, minutes;
		while (1)
		{
			cout << "������� ����� �������� ������ (� ������� ��:��) ";
			cin >> hours;
			cin.ignore(1);
			cin >> minutes;
			if (hours < 24 and hours >= 0 and minutes < 60 and minutes >= 0)
				break;
		}
		cout << "������� �������� �������, �� ������� ��������� ����� ";
		string station;
		cin >> station;
		vector<TrainStation>::iterator i_iterator = vect.end();
		vect.insert(i_iterator - 1, 1, {number, hours, minutes, station});
		bool a;
		cout << "������ ���������� ������� ������ ��� ������� �� ���� (0 - ����������, 1 - �������) ";
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