#include<iostream>
using namespace std;
int n = 10;

int identifica(int v[10]){
	int i = n-1;	 
	while(i>0 && (v[i-1] > v[i]))
	{ 
	 i--;
	}
	return i;
}

int afis(int v[10])
{
	 for(int i = 0; i<n; i++)
	 {
	  cout<<"v["<<i<<"]="<<v[i]<<endl;
	 }
	cout<<endl;
}

int minim(int v[10], int i){
 int j, min;
  min = v[i+1];
 
  for(j=i; j<n;j++)
  {
	if(min>v[j])
	{	 
	  min = j;   
	}
  }
  return min;
}

void sorteaza(int v[10], int max, int min){
 int i, aux; 
	
 bool sortat = true;

 while(sortat){
  sortat = false;
  
   for(i = min; i<max; i++)
   {
     if(v[i] > v[i+1]){ 
		aux = v[i];
		v[i] = v[i+1];
		v[i+1] = aux;
		sortat = true;
     }
   }
 }
 
}

int maximGrup(int v[10], int imin,int imax,int vecin){
 int j,k=imin;
  sorteaza(v,imax,imin+1);
  
  for(j=imin+1; j<imax;j++)
  {
	if(vecin<v[j])
	{	 
          return j;
	}
  }
 return k;
}

void succesor(int v[10]){
int aux,  pozitieElement, pozitieMinimGrup, vecin;

	if(identifica(v) == 0) cout<<"Nu exista succesor";
	else{
		pozitieElement = identifica(v);
		pozitieMinimGrup = minim(v,pozitieElement);
		vecin = v[pozitieElement-1];

		int pozitieMaxGroup = maximGrup(v,pozitieElement,pozitieMinimGrup,vecin);
		
		if(pozitieMaxGroup == pozitieElement){
			aux = vecin;
			vecin = v[pozitieElement];
			v[pozitieElement]=aux;
		}else{
			aux = vecin;
			cout<<v[pozitieMaxGroup]<<' ';
			v[pozitieElement-1] = v[pozitieMaxGroup];
			v[pozitieMaxGroup]=aux;
		}
		sorteaza(v,pozitieMinimGrup,pozitieElement);
    }
}

int main(){
	int i, v[10];

	for(i=0;i<10;i++)
	 cin>>v[i];
	 
	 succesor(v);
	 
	 afis(v);
     return 0;
}
