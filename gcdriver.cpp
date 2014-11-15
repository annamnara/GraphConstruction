# include <sstream> 
# include<iostream>
# include <fstream>
# include <string>
# include <vector>
# include <stdlib.h>
# include <algorithm>
# include <iterator>
# include <cstdlib>
# include <math.h>
# include <iterator>
#include <ctime> 
#include <cstring> 
#include <stdio.h> 
# include "GraphConstruction.hpp"
using namespace std;
int main(int argc, char* argv[])
{


GraphConstruction gc;
FILE* fp;
fp=fopen(argv[1],"r");
char  paramName[50];
char  paramType[50];
char  paramValue[50];
char  line[100];

while (fgets(line,500,fp) != NULL) {
if(line[0]!='#')
{
sscanf(line,"%s %s %s",paramName,paramType,paramValue);

if(strcmp(paramName,"kValue")==0)
gc.setK(atoi(paramValue));

if(strcmp(paramName,"eValue")==0)
gc.setEpsilon(atof(paramValue));

if(strcmp(paramName,"sigma")==0)
gc.setSigma(atof(paramValue));


if(strcmp(paramName,"rows")==0)
gc.rows=atoi(paramValue);

if(strcmp(paramName,"coloumns")==0)
gc.coloumns=atoi(paramValue);

if(strcmp(paramName,"filename")==0)
gc.filename=paramValue;

if(strcmp(paramName,"outputfile")==0)
gc.outfile=paramValue;

if(strcmp(paramName,"distfile")==0)
gc.distfile=paramValue;
if(strcmp(paramName,"methodchoice")==0)
gc.methodChoice=paramValue;

if(strcmp(paramName,"distancechoice")==0)
gc.distanceChoice=paramValue;

}
 
}
cout << "Data Parameters are :"<< "rows= " <<gc.rows<< " \t " << "coloumns= "<<gc.coloumns << "\t"<< "file name="<<gc.filename<<endl;
cout<< "Construction Parameters are:" <<"method= "<<gc.methodChoice << "\t" <<"distance= "<< gc.distanceChoice<<endl;

clock_t t; 
t=clock();
gc.LoadData();
//gc.DisplayData();
gc.DistanceMatrixCal();
gc.WeightMatrixCal();

//gc.DisplayWeightMatrix();
//gc.DisplayDistanceMatrix();

gc.WriteWeightMatrixtoFile();
t=clock()-t;
cout<< "TIME TAKEN " << ((float)t)/CLOCKS_PER_SEC<<"\n";
//gc.WriteDistanceMatrixtoFile();

}

