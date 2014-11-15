# include <iostream>
# include <string>
using namespace std;
class  GraphConstruction
{

private: 
int 	kValue;
double 	eValue;
double 	sigma;

public:
double 	**mydata;
double 	**DistanceMatrix;
double 	**WeightMatrix;
int 	rows;
int  	coloumns;
string 	filename;
string 	outfile;
string 	distfile;
string 	methodChoice;
string 	distanceChoice;
void  	setK(int kValue);
int  	getK();
void 	setEpsilon(double eValue);
double 	getEpsilon();
void	setSigma(double sigma);
double	getSigma();
	GraphConstruction();
void 	LoadData();
void 	DisplayData();
void	DistanceMatrixCal();
void	DistanceMatrixED();
void	DistanceMatrixGK();
void	WeightMatrixCal();
void	WeightMatrixkNN();
void	WeightMatrixeNN();
double	SimilarityMeasureED(int exi,int exj);
double 	SimilarityMeasureGK(int ex1,int ex2);
void	WriteWeightMatrixtoFile();
void	WriteDistanceMatrixtoFile();
void 	FindkNN(int r);
void	DisplayDistanceMatrix();
void	DisplayWeightMatrix();
};

  
