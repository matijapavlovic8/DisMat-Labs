#include<iostream>
#include<fstream>
#include<string>
#include<cmath>


using namespace std;

bool contains(int a[], int n, int g){
    bool cont = false;
    for(int i = 0; i < n; i++){
        if(a[i] == g)
            cont = true;
    }
    return cont;
}

int cromaticNumber(int n, int ns, int *s){
   int graph[n][n] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j)
                graph[i][j] = 0;
            if(contains(s, ns, abs(i - j)))
                graph[i][j] = 1;
            else
                graph[i][j] = 0;
            graph[j][i] = graph[i][j];
        }
    }

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cout << graph[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;

   int *colors = new int[n];
   int *colorsPom = new int[n];
   int clr = 1;
   for(int i = 0; i < n; i++){ 
      colors[i] = -1;
      colorsPom[i] = -1;
   }
   int k = 0;
   colors[0] = clr;

   for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
         if(graph[i][j] == 1)
            colorsPom[k++] = colors[j];
      }
      while(contains(colorsPom, n, clr)){
         clr++;
      }
      colors[i] = clr;
      k = 0; 
      clr = 1;
   }
   int max = 0;
   for(int i = 0; i < n; i++){
      cout << colors[i] << " ";
      if(colors[i] > max)
         max = colors[i];
   }
   cout << endl;
   return max;
   
   
}

int main(void){
   string file;
   cout << "Unesite ime datoteke: ";
   cin >> file;
   string str;
   fstream f(file);
   int n, ns;
   getline(f, str);
   n = stoi(str);
   getline(f, str);
   ns = stoi(str);
   int *s = new int[ns];
   int j = 0, num;
   while(getline(f, str, ' ')){
      try{
         num = stoi(str);
      } catch(exception){}
      s[j++] = num;
   }
   
   
   for(int i = 0; i < ns; i++){
      cout << s[i] << " ";
   }
   cout << endl;

   cout << cromaticNumber(n, ns, s) << endl;

   return 0;
    
}
