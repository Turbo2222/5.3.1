#include <iostream>
#include <stdexcept>

class smart_array{
    int* arr;
    int num;
    int count;
    public:
    smart_array(int init_size):num(init_size),count(0) {
        arr = new int(num);


    }
    ~smart_array() {
        delete [] arr;
    }

    int add_element(int value) {
        if (count>=num) {
            int* new_arr = new int[num * 2];
            for (int i = 0; i < num; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            num *= 2;
        }
        arr[count++] = value;
        return count - 1;
    }


    int get_element(int index){
        if (index < 0 || index >= count) {
            throw std::out_of_range("Индекс вне диапозона");
        }
       return arr[index];
    }

};




int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout<<arr.get_element(2) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}