#include "WebApp.h"
#include "Tools.h"
#include "Sorts.h"
using namespace Tools;
const std::string API = "e7c0bce5516c376f0d980ddc956bb225";
int main() {
	setlocale(LC_ALL, "RUS");
	using json = nlohmann::json;
	std::string city;
	std::cout << "¬ведите город: ";
	std::cin >> city;
	showMenu();
	int tmp;std::cin >> tmp;
	int choice = tmp;
	if (tmp > 1) {
		tmp = 1;
	}
	int q = 0;
	int* arr = new int[q];
		while (tmp) {
		int* arr = new int[q];
		WebApp app("http://api.openweathermap.org", API, city);
		json data;
		switch (choice) {
		case 1:
			data = app.getCurrentWeather();
			showCurrentWeather(data);
			arr[q] = data["main"]["temp"] - 273;
			showMenu();
			std::cin >> choice;
			q++;
			break;
		case 2:
			data = app.getFiveDaysForecast();
			showFiveDaysForecast(data);
			showMenu();
			std::cin >> choice;
			break;
		case 3:
			std::cout << "¬ведите город: ";
			std::cin >> city;
			app.setCityName(city);
			showMenu();
			std::cin >> choice;
			break;
		case 0:
			std::cout << "программма завершила работу!" << std::endl;
			tmp = 0;
			break;
			
		case 4:
			data = app.getFiveDaysForecastAVG();
			showFiveDaysForecastAVG(data);
			showMenu();
			std::cin >> choice;
			break;
		}
	}
		Sorts::showMenuSort();
		int choiceSort;std::cin >> choiceSort;
		switch (choiceSort) {
		case 0:
			std::cout << "программма завершила работу!" << std::endl;
		case 1:
			Sorts::bubleSort(arr, q);
			Tools::printArrSort(arr, q);
		case 2:
			Sorts::choicesSort(arr, q);
			Tools::printArrSort(arr, q);
		case 3:
			Sorts::pasteSort(arr, q);
			Tools::printArrSort(arr, q);
		case 4:
			Sorts::countingSort(arr, q);
			Tools::printArrSort(arr, q);
		}
		return 0;
}