//
//  main.cpp
//  c++ Basics
//  Sample program to demostate encapsulation.
//  Created by Anusha Ghali on 23/12/24.
//

#include <iostream>
#include <string>
#include <map>
class FruitInv
{
public:
    FruitInv()
    {
        fruitsPresent.insert(std::pair("Orange", 10));
        fruitsPresent.insert(std::pair("Apple", 10));
    }
    std::map<std::string,uint32_t> fruitsPresent;
    
    void addFruittoInv(std::string fruitName, size_t noOfFruits);
    void removeFruitFromInv(std::string fruitName, size_t noOfFruits);
    void displayAllFruits();
};

void FruitInv::addFruittoInv(std::string fruitName, size_t noOfFruits)
{
    // Check if fruits are exsisting
    bool fruitExsit = false;
    std::map<std::string,uint32_t>::iterator it = fruitsPresent.begin();
    while (it != fruitsPresent.end())
    {
        if (it->first == fruitName)
        {
            it->second += noOfFruits;
            fruitExsit = true;
            break;
        }
        it++;
    }
    if (fruitExsit == false)
    {
        fruitsPresent.insert(std::pair(fruitName,noOfFruits));
    }
}

void FruitInv::removeFruitFromInv(std::string fruitName, size_t noOfFruits)
{
    // Check if fruits are exsisting
    bool fruitExsit = false;
    std::map<std::string,uint32_t>::iterator it = fruitsPresent.begin();
    while (it != fruitsPresent.end())
    {
        if (fruitName == it->first)
        {
            it->second -= noOfFruits;
            fruitExsit = true;
        }
        it++;
    }
    if (fruitExsit == false)
    {
        std::cout << "Fruit not found" << std::endl;
    }
}

void FruitInv::displayAllFruits()
{
    std::map<std::string,uint32_t>::iterator it = fruitsPresent.begin();
    while (it != fruitsPresent.end())
    {
        std::cout << "Fruits -> " << it->first << " : " << it-> second << std::endl;
        it++;
    }
}

int main(int argc, const char * argv[]) {
    
    FruitInv f1;
    
    // Display default fruits
    std::cout << "Display default fruits" << std::endl;
    f1.displayAllFruits();
    
    f1.addFruittoInv("Orange", 10);
    f1.addFruittoInv("Apple", 10);
    f1.addFruittoInv("Kiwi", 10);
    f1.addFruittoInv("Banana", 10);
    
    // Display after adding the fruits
    std::cout << "Display after adding the fruits" << std::endl;
    f1.displayAllFruits();
    
    f1.removeFruitFromInv("Banana", 5);
    f1.removeFruitFromInv("Apple", 5);
    f1.removeFruitFromInv("Car", 5);
    //Display after Removing the fruits
    std::cout << "Display after adding the fruits" << std::endl;
    f1.displayAllFruits();
    return 0;
}
