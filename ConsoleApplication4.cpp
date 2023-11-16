#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

//генерим массив из 10 элементов от 1 до 100
vector<int> generateVector() {
    vector<int> numbers(10);
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;
    }
    return numbers;
}

//добавляем массив в файл
void pushNumbers(vector<int> numbers) {
    ofstream out("numbers.txt");
    for (int i = 0; i < 10; i++) {
        out << numbers[i] << ' ';
    }
    out.close();
}

//читаем массив из файла
vector<int> readNumbers() {
    vector<int> numbers(10);
    ifstream in("numbers.txt");
    for (int i = 0; i < 10; i++) {
        in >> numbers[i];
    }
    in.close();
    return numbers;
}

//сортируем массив и добавляем его в новый файл
void sorting(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    ofstream sorted_out("sorted_numbers.txt");
    for (int i = 0; i < 10; i++) {
        sorted_out << numbers[i] << ' ';
    }
    sorted_out.close();
}

int main() {
    srand(time(0));
    vector<int> numbers = generateVector();
    pushNumbers(numbers);
    numbers = readNumbers();
    sorting(numbers);
}