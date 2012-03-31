#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

#include "ITape.h"
#include "Tape.h"
#include "IMachine.h"
#include "Machine.h"

using namespace std;

string readBandFromStdin() {
	string line;
	cout << "Geben sie die Werte ein, mit denen das Band initialisiert werden soll:" << endl;
	getline(cin, line);
	return line;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "Parameter erwartet: Datei mit den Regeln!" << endl;
		return 1;
	}

	ifstream rules(argv[1]);
	Machine m;
	m.loadRules(&rules);

	istream* bandInitStream;

	if (argc < 3) {
		string tapeInit = readBandFromStdin();
		bandInitStream = new istringstream(tapeInit);
	} else {
		bandInitStream = new ifstream(argv[2]);
	}

	Tape t(bandInitStream);
	m.setTape(&t);

	std::cout << "\033[?25l";
	std::cout << "\033[s";

	do {
		std::cout << "\033[u";
		t.dump(cout);
		std::cout << std::endl;
		std::cout << "State: " << m.getState() << std::endl;
		std::cout.flush();
		usleep(250000 * 2);
	} while (m.step());

	std::cout << "\033[?25h" << std::endl;
	delete bandInitStream;
}
