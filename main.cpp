#include <application.h>

int main(int argc, char** argv) {
	Application app{ "Austin Palmer", 800, 600 };

	app.Run();

	return 0;
}