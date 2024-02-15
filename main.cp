#include <stdlib.h>
using namespace std;
#include <libsumo/libtraci.h>
#include <libsumo/libsumo.h> 

using namespace libtraci;

int main(int argc, char* argv[])
{

	//start Sumo simulation
	// "sumo-guiD", "-c" is the neccesary parameters to activate SUMO GUI
	Simulation::start({ "sumo-guiD", "-c", "<location of test.sumocfg (under example folder)>" });
	for (int i = 0; i < 5; i++) {
		Simulation::step();
		std::cout << "Simulating..." << std::endl;
	}
	Simulation::close();

	return 0;
}
