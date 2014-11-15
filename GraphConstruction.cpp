# include "GraphConstruction.hpp"
# include "StringUtilities.hpp"
# include "sort.h"
# include <sstream> 
# include<iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <vector>
# include <stdlib.h>
# include <algorithm>
# include <iterator>
# include <cstdlib>
# include <cmath>
# include <iterator>
#include <ctime>  
# include <queue>
using namespace std;
GraphConstruction::GraphConstruction()
{

}

void GraphConstruction::setEpsilon(double eVal){
this->eValue=eVal;
}

void GraphConstruction::setK(int kVal){
this->kValue=kVal;
}

void GraphConstruction::setSigma(double sigma){
this->sigma=sigma;
}

double  GraphConstruction::getEpsilon(){
return this->eValue;
}

int GraphConstruction::getK(){
return this->kValue;
}

double  GraphConstruction::getSigma(){
return this->sigma;
}


void GraphConstruction::LoadData()
{

StringUtilities su;
fstream datafile(&filename[0]);
mydata = new double* [rows];
for(int i = 0; i < rows; ++i) {
    mydata[i] = new double[coloumns];
}
string str;
double dummy=0.0;
int nr=0;
while(getline(datafile,str)){
   double  *p;
   p= su.SplitString(str,dummy); 
   for ( int i = 0; i < coloumns; i++ ) {
        mydata[nr][i]=*(p+i);
   }
  nr++;
  delete p;

}

}

void GraphConstruction::DisplayData(){
for (int i=0;i<rows;i++){

  for (int j=0;j<coloumns;j++){
      cout<< mydata[i][j]<<" ";
  }
cout<<"\n";
}
}



void GraphConstruction::DistanceMatrixCal(){

DistanceMatrix = new double* [rows];
for(int i = 0; i < rows; i++) {
    DistanceMatrix[i] = new double[rows];
}

int dchoice=0;
if(strcmp(&distanceChoice[0],"ed")==0)
dchoice=1;
if (strcmp(&distanceChoice[0],"gk")==0)
dchoice=2;
cout<< "choice"<< dchoice;
switch(dchoice)
{
case 1:DistanceMatrixED();
       break; 
case 2:DistanceMatrixGK();
       break; 
default:break;

}


}

void GraphConstruction::DistanceMatrixED(){

for (int i=0;i<rows;i++)
{   for (int j=i;j<rows;j++)
     {
       if(i!=j) {
        DistanceMatrix[i][j]=SimilarityMeasureED(i,j);
        DistanceMatrix[j][i]=DistanceMatrix[i][j];  }
       else 
       
        DistanceMatrix[i][j]=0.0;
}
}


}

void GraphConstruction::DistanceMatrixGK(){

for (int i=0;i<rows;i++)
{   for (int j=i;j<rows;j++)
     {
       if(i!=j) {
        DistanceMatrix[i][j]=SimilarityMeasureGK(i,j);
        DistanceMatrix[j][i]=DistanceMatrix[i][j];  }
       else 
       
        DistanceMatrix[i][j]=0.0;
}
}

}


void GraphConstruction::WeightMatrixCal(){

// Declaration  of WeightMatrix
WeightMatrix = new double* [rows];
for(int i = 0; i < rows; i++) {
    WeightMatrix[i] = new double[rows];
}

// Intialization of WeightMatrix to zeros
for (int i=0;i<rows;i++)
{   for (int j=0;j<rows;j++)
     {
        WeightMatrix[i][j]=0.0;
}
 }

// Method (kNN or eNN )Calling using switch
int mchoice=0;
if(strcmp(&methodChoice[0],"knn")==0)
mchoice=1;
 if (strcmp(&methodChoice[0],"enn")==0)
mchoice=2;

switch(mchoice)
{
case 1: WeightMatrixkNN();
        break;
case 2: WeightMatrixeNN();
        break;
default: break;
}


} // end of WeightMatrixCal

void GraphConstruction::WeightMatrixkNN(){



  for (int j=0;j<rows;j++)
     {
 
        FindkNN(j); 

    }


}

void GraphConstruction::WriteWeightMatrixtoFile()
{

ofstream ofile;
ofile.open(&outfile[0]);

cout<< "Started writing to file"<< endl;

for(int i=0;i<rows;i++){

    for (int j=0;j<rows;j++){

          ofile<< WeightMatrix[i][j]<<" ";



 }
ofile<< "\n";

}

cout<< "Ended writing to file"<< endl;
}

void GraphConstruction::WriteDistanceMatrixtoFile()
{

ofstream ofile1;
ofile1.open(&distfile[0]);

cout<< "Started writing Distances to file"<< endl;

for(int i=0;i<rows;i++){

    for (int j=0;j<rows;j++){

          ofile1<< DistanceMatrix[i][j]<<" ";



 }
ofile1<< "\n";

}

cout<< "Ended writing Distances to file"<< endl;
}
void GraphConstruction::DisplayWeightMatrix()
{


cout<< "Displaying WeightMatrix"<< endl;

for(int i=0;i<rows;i++){

    for (int j=0;j<rows;j++){

          cout<< WeightMatrix[i][j]<<"\t";



 }
cout<< "\n";

}

}




void GraphConstruction::DisplayDistanceMatrix()
{


cout<< "Displaying DistancetMatrix"<< endl;

for(int i=0;i<rows;i++){

    for (int j=0;j<rows;j++){

          cout<< DistanceMatrix[i][j]<<"\t";



 }
cout<< "\n";

}

}



void   GraphConstruction::FindkNN(int r)
{

vector<double> distances;     
vector<size_t> indices;
   for (int c=0; c<rows;c++) {
           distances.push_back(DistanceMatrix[r][c]);
        }   

         sort(distances, distances,indices);
         int k=0;
         int z=0;
         int actualk=getK();
	 while (k<actualk) {
           if(r!=indices[z]){
          WeightMatrix[r][indices[z]]=DistanceMatrix[r][indices[z]];
          WeightMatrix[indices[z]][r]=DistanceMatrix[r][indices[z]];
         k++;
          }
         z++;
         }
      distances.clear();
      indices.clear();



}


void GraphConstruction::WeightMatrixeNN(){

for (int i=0;i<rows;i++)
{   for (int j=0;j<rows;j++)
     {
       if(i!=j)
        WeightMatrix[i][j]=(DistanceMatrix[i][j]>=getEpsilon()) ? DistanceMatrix[i][j]:0.0 ;
       else
        WeightMatrix[i][j]=DistanceMatrix[i][j];
    }
}

}

double  GraphConstruction::SimilarityMeasureED(int exi,int exj){
double  dist=0.0;

   for(int m=0;m<coloumns;m++)
     {
         dist=dist+pow(mydata[exi][m]-mydata[exj][m],2.0);
      }

  return sqrt(dist);


}
double  GraphConstruction::SimilarityMeasureGK(int exi,int exj){
double  dist=0.0;

   for(int m=0;m<coloumns;m++)
     {
          dist=dist+pow(mydata[exi][m]-mydata[exj][m],2.0);
      }


  return exp(-1*(dist/ (2* sigma *sigma)));


}
