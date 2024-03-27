#include "Tools.h"
#include "Sorts.h"
void Tools::showMenu() {
	std::cout << "1 - ���������� ������." << std::endl;
	std::cout << "2 - ���������� ������� �� 5 ����." << std::endl;
	std::cout << "3 - ������ ����� �����." << std::endl;
	std::cout << "4 - ���������� ������� �� 5 ���� �� ������� ������������." << std::endl;
	std::cout << "0 - �����" << std::endl;

}
void Tools::showCurrentWeather(nlohmann::json data) {
	std::cout << "������: " << data["weather"][0]["main"] << std::endl;
	std::cout << "�����������: " << data["main"]["temp"] - 273 << std::endl;
	
}
void Tools::showFiveDaysForecast(nlohmann::json data) {
	for (int i = 0; i < data["list"].size(); i++) {
		std::cout << data["list"][i]["dt_txt"];
		std::cout << " " << data["list"][i]["weather"][0]["main"];
		std::cout << " Temp: " << data["list"][i]["main"]["temp"] - 273 << std::endl;
	}
}
void Tools::showFiveDaysForecastAVG(nlohmann::json data) {
	int i = 0;
	int j = i + 1;
	std::string dateDay;
	std::string dateDayJ;
	int counter = 0;
	double sum = 0;
	while (i < data["list"].size()) {
		dateDay = data["list"][i]["dt_txt"].get<std::string>().substr(8, 2);
		counter = 1;
		sum = data["list"][i]["main"]["temp"].get<double>() - 273.15;
		if (j < data["list"].size()) {
			dateDayJ = data["list"][j]["dt_txt"].get<std::string>().substr(8, 2);
			while (dateDay == dateDayJ && j < data["list"].size()) {
				counter++;
				sum += data["list"][j]["main"]["temp"].get<double>() - 273.15;
				j++;
				dateDayJ = data["list"][j]["dt_txt"].get<std::string>().substr(8, 2);
			}
		}
		std::cout << data["list"][i]["dt_txt"].get<std::string>().substr(0, 10);
		std::cout << " " << data["list"][i]["weather"][0]["main"];
		std::cout << " Average Temp: " << (int)(sum / counter) << std::endl;
		i = j;
		j = i + 1;
	}
}
void Tools::printArrSort(int*& arr, int& len) {
	for (int i = 0;i < len;i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}




