#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream input_file("command.inp");
	ofstream output_file("command.out");

	int n = 0;
	input_file >> n;
	string command;
	string ux[] = { "ls", "mkdir", "rmdir", "rm", "cp", "mv", "clear", "pwd", "cat", "man", "date", "find",
	"grep", "more", "diff", "ed", "sort", "lsattr", "pushd", "popd", "ps", "kill", "halt", "ifconfig", "fsck",
	"free", "debugfs", "lpr" };

	string ds[] = { "dir", "md", "rd", "del", "copy", "rename", "cls", "cd", "type", "help", "time", "find",
	"findstr", "more", "comp", "edlin", "sort", "attrib", "pushd", "popd", "taskmgr", "tskill", "shutdown", "ipconfig", "chkdsk",
	"mem", "scandisk", "print" };

	for (int i = 0; i < n; i++) {
		input_file >> command;
		for (int k = 0; k < 28; k++) {
			if (command == ux[k]) {
				output_file << command << " -> " << ds[k] << endl;
			}
			else if (command == ds[k]) {
				output_file << command << " -> " << ux[k] << endl;
			}
			else {

			}
		}
	}


	input_file.close();
	output_file.close();

	return 0;
}