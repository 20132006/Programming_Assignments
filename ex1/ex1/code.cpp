#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */
#include <math.h>  
#include <string>
#include <vector>
using namespace std;
int main ()
{
	ifstream fin("data.txt");
	double sum=0,d,a,b,t1=0,t2=0;
	std::vector<double> X,y;
	int i,j,m=0;
	string s;
	while (!fin.eof())
	{
		fin>>a>>b;
		
		sum = sum + (b*b);
		
		X.push_back(a);
		y.push_back(b);
		cout<<a<<" "<<b<<endl;
		m++;
	}
	for (i=0;i<1500;i++)
	{
		double temp1=0.0;
		double temp2=0.0;
		
		for (j=0;j<m;j++)
		{
			temp1 = temp1 +   t1 + ( t2*X[j] ) - y[j];
        	temp2 = temp2 + ( t1 + ( t2*X[j] ) - y[j] ) * X[j];
		}

		temp1 = t1 - (0.01 * ( 1.0 / double(m) ) * temp1);
    	temp2 = t2 - (0.01 * ( 1.0 / double(m) ) * temp2);

    	cout<<temp1<<" "<<temp2<<" => ";

    	t1=temp1;
    	t2=temp2;

    	double J=0;

    	for (j=0;j<m;j++)
    	{
        	J = J + ( ( t1 + ( t2*X[j] ) ) - y[j] ) * ( ( t1 + ( t2 * X[j] ) ) - y[j] );
		}

		J = J / ( 2.0 * double(m) );
		cout<<J<<endl;
	}
	sum = sum/(2*m);
	cout<<sum<<endl;
}