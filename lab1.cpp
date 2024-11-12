#include <iostream>
#include <fstream>
#include <sstream>

struct student
{
    std::string name_inits;
    std::string group_num;
    short marks[5];
};

void filling_from_keyboard(student *data, int N)
{

    for (int i = 0; i < N; i++)
    {
        std::cout << "enter name: ";
        std::getline(std::cin >> std::ws, data[i].name_inits);
        std::cout << "enter group: ";
        std::cin >> data[i].group_num;
        std::cout << "enter five marks: ";
        for (int j = 0; j < sizeof(data[i].marks) / sizeof(short); j++)
        {
            std::cin >> data[i].marks[j];
        }
    }
}
student *filling_from_file(std::string file_name, int &n)
{
    std::ifstream in;
    in.open(file_name);
    if (!in.is_open())
    {
        std::cout << "Can not open file " + file_name; // Конкатенация строк
        return 0;
    }

    std::stringstream obj; // Создаем поток в оперативной памяти для ввода/вывода строк

    std::string str;
    int count = 0;

    while (std::getline(in, str))
    {
        obj << str + "\n";
        count++;
    }
    in.close();

    n = count;
    student *array = new student[n];
    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::getline(obj, str);
        int index = str.find(' ');
        array[i].name_inits = str.substr(0, index);
        str = str.substr(index + 1);
        index = str.find(' ');
        array[i].group_num = str.substr(0, index);
        str = str.substr(index + 1);
        for (int j = 0; j < 5; j++)
        {
            index = str.find(' ');
            array[i].marks[j] = stoi(str.substr(0, index));
            str = str.substr(index + 1);
        }
    }
    return array;
}
void printing_alphabetic_order(student *data, int N)
{
    std::cout << "students sorted by group number: " << std::endl;
    for (int i = 0; i < N - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < N; ++j)
        {
            if (data[j].group_num < data[min_idx].group_num)
            {
                min_idx = j;
            }
        }
        student tmp = data[i];
        data[i] = data[min_idx];
        data[min_idx] = tmp;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << "student " << i + 1 << std::endl;
        std::cout << data[i].name_inits << std::endl;
        std::cout << data[i].group_num << std::endl;
        for (int j = 0; j < sizeof(data[i].marks) / sizeof(short); j++)
        {
            std::cout << data[i].marks[j] << " ";
        }
        std::cout << std::endl;
    }
}

void simple_printing(student data)
{
    std::cout << data.name_inits << std::endl;
    std::cout << data.group_num << std::endl;
    for (int j = 0; j < sizeof(data.marks) / sizeof(short); j++)
    {
        std::cout << data.marks[j] << " ";
    }
    std::cout << std::endl;
}

void printing_ab_perfomance(student *data, int N)
{
    std::cout << "high perfomance students: " << std::endl;

    bool no_high_perf = true;

    for (int i = 0; i < N; i++)
    {
        int average = 0;
        for (int j = 0; j < sizeof(data[i].marks) / sizeof(short); j++)
        {
            average += data[i].marks[j];
        }
        if (average / (sizeof(data[i].marks) / sizeof(short)) >= 4)
        {
            no_high_perf = false;
            simple_printing(data[i]);
        }
        // std::cout << std::endl;
    }
    if (no_high_perf)
        std::cout << "all the students have bad perfomance" << std::endl;
}

int main()
{
    /*int N; // заполнять 10 структур руками каждый раз для проверки я бы сошел с ума
    std::cout << "enter the number of students: ";
    std::cin >> N;
    student *info = new student[N];
    filling_from_keyboard(info, N); // ввод студентов с клавиатуры
    printing_alphabetic_order(info, N);
    printing_ab_perfomance(info, N);*/

    /*int n;
    student *file_info = filling_from_file("text.txt", n); // другой массив для студентов из файла
    printing_alphabetic_order(file_info, n);
    printing_ab_perfomance(file_info, n);*/

    return 0;
}