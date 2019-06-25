#include <iostream>

using namespace std;
int a[400][400];
int m, n, r;
int i, j;
int buffer, buffer1;
int highR = 0;
int lowR;
int highC;
int lowC = 0;

void top() {
  buffer = a[highR][lowC];
  for (i = lowC; i < highC; i++) {
    a[highR][i] = a[highR][i + 1];
  }
}

void left() {
  buffer1 = a[lowR][lowC];
  for (i = lowR; i > highR + 1; i--) {
    a[i][lowC] = a[i - 1][lowC];
  }
  a[i][lowC] = buffer;
  buffer = buffer1;
}

void bottom() {
  buffer1 = a[lowR][highC];
  for (i = highC; i > lowC + 1; i--)
    a[lowR][i] = a[lowR][i - 1];
  a[lowR][i] = buffer;
  buffer = buffer1;
}

void right() {
  for (i = highR; i < lowR - 1; i++)
    a[i][highC] = a[i + 1][highC];
  a[i][highC] = buffer;
}
void rotate_m() {
  lowR = m - 1;
  highC = n - 1;
  highR = 0;
  lowC = 0;
  while (highR <= lowR && lowC <= highC) {
    top();
    left();
    bottom();
    right();
    highR++;
    lowR--;
    highC--;
    lowC++;
  }
}

int main() {
  cin >> m >> n >> r;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  i = 0;
  j = 0;

j=0;
int backr=r;
        lowR = m - 1;
      highC = n - 1;
      highR = 0;
      lowC = 0;
      int x;
while(highR <= lowR && lowC <= highC)
  {
      x=((lowR+1)-(highR))*((highC+1)-lowC)-((((lowR+1)-(highR))-2)*(((highC+1)-lowC)-2));
      r=backr%x;
      for(int k=0;k<r;k++)
      {

      top();
        left();
        bottom();
        right();

      }
      highR++;
    lowR--;
    highC--;
    lowC++;

  }





 cout<<"\n\n\n\n"<<r<<endl;
  cout<<"\n\n\n\n";
   cout<<"\n\n\n\n";
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}
