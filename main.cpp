#include <iostream>

void print_left_or_right(int* arr, int number, double count, int identificate){
    if(identificate == 0) {
        std::cout << ceil(log2(count + 1)) << " root " << arr[number] << "\n";
    }else if(identificate == 1){

        std::cout << ceil(log2(count + 1)) << " left(" <<  arr[number] << ") " << arr[(number * 2) + 1] << "\n";
    }else if(identificate == 2){

        std::cout << ceil(log2(count + 1)) << " right(" <<  arr[(number)] << ") " << arr[(number * 2) + 2] << "\n";
    //деление на право при движении выводит другое значение ceil(log2(count + 1))
    }

}
int piramide_left(int* arr, int size, int number, int count){

    if((number * 2) + 1 >= size) return arr[number];
    print_left_or_right(arr, (number), count, 1);

    if((number * 2) + 2 >= size) return arr[number];
    print_left_or_right(arr, (number), count, 2);

    return piramide_left(arr, size, number + 1, count + 1);
}

void print_pyramid(int* array, int size){//

    std::cout << "0 root " << array[0] << "\n";

    piramide_left(array, size, 0, 1);

}

bool step_right(int size, int* parent){
    if((*parent * 2 + 2) > size - 1) {
        return false;
    }else std::cout << "Ok!\n";
    *parent = *parent * 2 + 2;
    return true;
}

bool step_left(int size, int* parent){
    if((*parent * 2 + 1) > size - 1) {
        return false;
    }else std::cout << "Ok!\n";
    *parent = *parent * 2 + 1;
    return true;
}

bool step_up(int* parent){
    if(*parent == 0){
        return false;
    }else if(*parent % 2 == 0){
        *parent = *parent / 2 - 1;
        std::cout << "Ok!\n";
    }else if(*parent % 2 != 0){
        *parent = (*parent / 2);
        std::cout << "Ok!\n";
    }
    return true;
}



int main() {
    int parent = 0;
    //int children_right = 0;
    //int children_left = 0;
    std::string input = "";
    int array[] = {1, 3, 6, 5, 9, 8};
    //int array[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size = sizeof(array) / sizeof(array[0]);

    print_pyramid(array, size);

    while(true){
        std::cout << "Вы находитесь здесь: ";
        if(parent == 0){
            print_left_or_right(array, parent, parent, 0);
        }else if(parent % 2 == 0) { //right
            print_left_or_right(array, ceil(parent / 2) - 1, ceil(parent / 2), 2);
        }else if(parent % 2 !=0){// left
            print_left_or_right(array, ceil(parent / 2), ceil(parent / 2) + 1, 1);
        }

        std::cout << "Введите команду: ";
        std::cin >> input;
        if(input == "right"){//right
            if(!step_right(size, &parent)){
                std::cout << "Ошибка! Отсутствует правый потомок\n";
            }
        }else if(input == "left"){//left
            if(!step_left( size, &parent)){
                std::cout << "Ошибка! Отсутствует левый потомок\n";
            }
        }else if(input == "up"){
            if(!step_up(&parent)){
                std::cout << "Ошибка! Отсутствует родитель\n";
            }
        }

        if(input == "exit") break;
    }


    return 0;
}
