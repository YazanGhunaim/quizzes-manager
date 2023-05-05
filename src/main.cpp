#include <iostream>
#include "headers/manager/CManager.hpp"

int main()
{
    std::vector<std::string> filePaths{"src/xml/main.xml", "src/xml/temp.xml"};
    CManager manager{filePaths};
    manager.display();
    return 0;
}
