#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"

int main() {

    FileCacheManager manager;
    StringReverser stringReverser;
    MyTestClientHandler myTestClientHandler(&manager, &stringReverser);
    MySerialServer s;
    s.open(5400, &myTestClientHandler);
    while (true) {}
    //manager.saveToFile();

}