#include <iostream>
#include <search.hpp>

int main() {  
        size_t length = 0;
        std::cin >> length;
        std::vector<int> cont(length);
        for (int i = 0; i < length; i++){
            std::cin >> cont[i]; 
        }
        

        auto result = search(cont);
        std::cout << result << std::endl;
        return 0;
    }
