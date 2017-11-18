#include "DebugDelete.h"
#include <memory>

int main() {
	{
		std::unique_ptr<int, DebugDelete> up(new int(2), DebugDelete());
	}
	{
		std::unique_ptr<std::string, DebugDelete> up(new std::string ("Hello"), DebugDelete());
	}
	return 0;
}