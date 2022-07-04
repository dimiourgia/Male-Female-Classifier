//SexNet trainer 
#include<iostream>
#include<cstdio>
#include<math.h>
#include<fstream>
#include<string>
using namespace std;

#define n_input 172
#define n_nodes 33*39
#define approx_sigmoid(x) 1/(1+abs(x))

float appx_sigmoid(float x){
	float y;
	y=1/(1+exp(-x));
	return y;
}

float weights[n_nodes]={0};
float bias=0;
float lrning_rate=.0003;
int output_class[n_input]={0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0};
float generated_output_class[n_input];
int main(){
	ifstream dataFile;
	ofstream output;
	ofstream mfDataFile;
	output.open("final.w");
	dataFile.open("data.dat");
	
	float data[n_input][n_nodes];
	char s;
	int x;
	for(int i=0;i<n_input;i++){
		for(int j=0;j<n_nodes;j++){
		dataFile >> x;
		data[i][j]=x;
	   }
	}
	double error=50;
	int it=1;
	cout <<"  Iteration " << "  bias"<<"     w0"<<"      w1" << "     w3"<<  "         error"<< endl;
	cout << "----------------------------------------------------------------------------" << endl;
	int temp=0;
	while(temp<200){
	for(int j=0;j<n_input;j++){
		float D=bias;
		for(int i=0;i<n_nodes;i++) D=D+data[j][i]*weights[i];
		generated_output_class[j]=appx_sigmoid(D);
		
		bias = bias+lrning_rate*(output_class[j]-generated_output_class[j]);
		for(int i=0;i<n_nodes;i++){
			weights[i]=weights[i]+lrning_rate*(output_class[j]-generated_output_class[j])*data[j][i];
		}
    
	}
	error=0;
	for(int i=0;i<n_input;i++) error=error+abs(output_class[i]-generated_output_class[i]);  
	error=error/n_input;
	cout << "  "<<temp<<"    "<<bias<<"      "<<weights[0]<<"       "<<weights[1]<<"       " << weights[3]<< "      "<<error<<endl;
	temp++;
}
	output << bias << endl;
    for(int i=0;i<n_nodes;i++) output << weights[i] << endl;
	dataFile.close();
	output.close();
	cout << endl << endl;
	for(int i=0;i<n_nodes; i++){
	//	cout << i <<"::" << weights[i] << endl ;
	}
	return 0;
	
}
