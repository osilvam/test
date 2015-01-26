#ifndef MOTOR_TEST_CPP
#define MOTOR_TEST_CPP

#include "motor_test.hpp"

int main(int argc, char* argv[])
{	
	CM700 * cm700 = new CM700(9,2);
	Joint * joint = new Joint(cm700,(char*)"AX", 5, 90*RAD, -90*RAD, (char*)"DEG",0);

	string line;
	double cposition;
	ifstream ifile (argv[1]);
	ofstream ofile ("output.txt");
	if (ifile.is_open() && ofile.is_open())
	{
		while (getline(ifile,line))
		{
			double pos = atof(line.c_str());
			joint->setJointPosition(pos);
			cm700->moveAll();
			cm700->refreshAll();
			cposition = joint->getJointCurrentPosition();
			clog << "moving to position: " << line << "\t";
			clog << "arriving to position: " << cposition << endl;
			ofile << cposition << endl;	

			usleep(1000);
		}

		ifile.close();
		ofile.close();
	}
	else clog << "Unable to open some file" << endl;	
	
	delete(cm700);

	return(0);
}

#endif
