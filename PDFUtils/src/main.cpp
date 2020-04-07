#include "Core/Log.h"

#include <iostream>

int main(int argc, char* argv[]) 
{
	Log::Init();
	LOG_INFO("Hello World!");

	std::cin.get();
}