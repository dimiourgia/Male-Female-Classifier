//SexNet Classifier
#include<iostream>
#include<cstdio>
#include<math.h>
#include<fstream>
using namespace std;

#define n_nodes 33*39
char f_name[20];
float inputData[n_nodes];
float weights[n_nodes];

float appx_sigmoid(float x){
	float y=1/(1+exp(-x));
	return y;
}

int main(){
    ofstream result;
    result.open("result.txt");
	ifstream weightFile;
	//read weight file////////////////////////
	weightFile.open("final.w");
	float bias;
	
	float x;
	weightFile >> x;
	bias = x;
	cout << bias << endl ;
	for(int i=0;i<n_nodes;i++){
		weightFile >> x;
		weights[i]=x;
	} 
	//cout << weights[0] << endl << weights[1] << endl;
	//////////////////////////////////////
	ifstream input;
	
	int x2=0;
	while(x2<172){
		
	sprintf(f_name,"File/data%04d.dat",x2);
	input.open(f_name);
	
	float x1;
	for(int i=0;i<n_nodes;i++){
		input >> x1; 
		inputData[i]=x1; 
	}

	float D=bias;
	for(int i=0;i<n_nodes;i++) D=D+(weights[i]*inputData[i])*.2;
   	if(appx_sigmoid(D)>.5){
   	 cout << endl << "Male" << " " << appx_sigmoid(D);
   	 result << endl << "Male";
   	}
   	else{
   	 cout << endl << "Female" << " " << appx_sigmoid(D);
   	 result << endl << "Female";
   	}
   	x2++;
   	input.close();
   }
   
   return 0;	
}
