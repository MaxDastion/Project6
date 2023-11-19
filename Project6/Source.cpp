#include <iostream>
#include <vector>

class Data {
public:
    int i;
    int j;
};

template<typename T, typename Predicate>
int count_if(const std::vector<T>& vec, Predicate pred) {
    int count = 0;
    for (const auto& elem : vec) {
        if (pred(elem)) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::vector<Data> datas = { {7, 9}, {7, 9}, {5, 9}, {7, 8} };

    int count = count_if(datas, [](const Data& elem) {
        return elem.i == 7 && elem.j == 9;
        });

    std::cout << "Count: " << count << std::endl;

    return 0;
}