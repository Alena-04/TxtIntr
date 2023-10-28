#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

double calculateAverage(const vector<double>& numbers) {
	double sum = 0;

	for (double number : numbers) {
		sum += number;
	}

	return sum / numbers.size();
}

double calculateMedian(const vector<double>& numbers) {
	vector<double> sortedNumbers = numbers;
	sort(sortedNumbers.begin(), sortedNumbers.end());

	if (sortedNumbers.size() % 2 == 0) {
		size_t mid = sortedNumbers.size() / 2;
		return (sortedNumbers[mid - 1] + sortedNumbers[mid]) / 2;
	} else {
		return sortedNumbers[sortedNumbers.size() / 2];
	}
}

void printUsage() {
	cout << "Программа-калькулятор. Вычисляет среднее арифметическое и медиану." << endl;
	cout << "Использование: calculator —operation=<операция> число1 число2 число3 ..." << endl;
	cout << endl;
	cout << "Параметры:" << endl;
	cout << "--operation=summa Выполняет операцию сложения и выводит сумму чисел." << endl;
	cout << "--operation=median Выполняет операцию нахождения медианы и выводит результат." << endl;
	cout << " Пример: calculator —operation=median 1 2 3" << endl;
}

int main(int argc, char* argv[]) {
	string operation;
	vector<double> numbers;

	int option;
	while ((option = getopt(argc, argv, "o:")) != -1) {
		switch (option) {
			case 'o':
				operation = optarg;
				break;
			default:
				printUsage();
				return 1;
		}
	}

	if (operation.empty() || optind == argc) {
		printUsage();
		return 1;
	}

	if (operation != "summa" && operation != "median") {
		cout << "Неподдерживаемая операция: " << operation << endl;
		return 1;
	}

	for (int i = optind; i < argc; ++i) {
		double number = stod(argv[i]);
		numbers.push_back(number);
	}
		if(numbers.size()<7 or
			numbers.size()>9){
			cout << "Неверное число операндов" << endl;
			return 1;
		}
	if (operation == "summa") {
		double average = calculateAverage(numbers);
		cout << "Среднее арифметическое: " << average << endl;
	} else if (operation == "median") {
		double median = calculateMedian(numbers);
		cout << "Медиана: " << median << endl;
	}

	return 0;
}
