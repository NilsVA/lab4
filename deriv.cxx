#include <iostream>
#include <cmath>
#include <fstream> 
using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void f(double* p, const int N, const double dx, const double xmin){

	for(int i = 0 ; i < N ; i++)
		p[i] = exp( - pow(i*dx + xmin , 2));
}

void deriv(double* p, const int N, const double dx)
{	
	double a = p[0];
	double b = p[1];
	p[0] = p[0]/(2*dx);
	for(int i = 1 ; i < N-1 ; i++)
	{ 
		b = p[i];	
		//double a = p[i-1];
		//double b = p[i];
		p[i] = (p[i+1]-a)/(2*dx);
		a = b;
		//double b = p[i+1];
		
	}
	p[N-1] = - 1 * p[N-2] / (2 * dx);
}

int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  f(p,N,dx,xmin); // call to function which fills array p here
  deriv(p,N,dx);// call to functio which calculates the derivative
	ofstream out ("data.dat");
 print(p,N,dx,xmin);
	out.close();	
  return 0;
}
