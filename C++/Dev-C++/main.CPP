#include<iostream>
using namespace std;

#include<cstdlib>
#include<time.h>
#include"G_C.h"

int x, y, x_new, y_new, conditional_break;

int** ArrayCreation_2D(int size) {
	int i, j, **array;
	array=new int* [size];
	for (i=0; i<size; i++) {
		array[i] = new int[size];
	}
	
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			array[i][j]=0;
		}
	}
	
	return(array);
}

void surround_check(int x1, int y1, int** arr) {
	conditional_break=0;
	
	if ((arr[x1-1][y1]==1) || (arr[x1+1][y1]==1) || (arr[x1][y1-1]==1) || (arr[x1][y1+1]==1)) {
		conditional_break=1;
	}
}

void CreateObject(int n, int** arr) {
	x=(n-1)/2;
	y=x;
	
	x_new=x;
	y_new=y;
	
	arr[x][y]=1;
	
	surround_check(x, y, arr);
}

void draw(int n, int** arr)
{
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout<<arr[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void move(int n, int** arr) {
	srand(time(0));
	int flag, selection;
	
	while (1) {
		flag=rand()%2;
		selection=rand()%19 - (+9);
		
		if (flag==0) {
			if (selection<0) {
				x_new=x-1;
			}
			if (selection>0) {
				x_new=x+1;
			}
		}
		else {
			if (selection<0) {
				y_new=y-1;
			}
			if (selection>0){
				y_new=y+1;
			}
		}
		
		/*system("cls");
		cout<<"\n\t\tflag="<<flag<<"  Selec="<<selection<<"\n";
		draw(n, arr);
		Sleep(900);*/
		
		if ((x_new==0) || (x_new==(n-1)) || (y_new==0) || (y_new==(n-1))) {
			arr[x_new][y_new]=1;
			arr[x][y]=0;
			
			CreateObject(n, arr);
		}
		else {
			arr[x][y]=0;
			arr[x_new][y_new]=1;
			
			surround_check(x_new, y_new, arr);
			
			if (conditional_break==1) {
				CreateObject(n, arr);
			}
			else {
				x=x_new;
				y=y_new;
			}
		}
		
		if (conditional_break==1)
			break;
	}
}


void pause() {
	cin.ignore();
	cin.get();
}

int main() {
	windowsize(50, 30);
	console_color(LIGHTGREEN);
	hidecursor(false);
	
	int n, flag=0;
	
	while(1) {
		system("CLS");
		cout<<"* Enter Grid Size: ";
		cin>>n;
		if ((n%2)==0) {
			cout<<"\n\n\t-> Grid Value Is Even!";
			pause();
		}
		else
			break;
	}
	
	int** A=ArrayCreation_2D(n);
	
	CreateObject(n, A);
	
	move(n, A);
	
	display(n, A);
	
	//cout<<"\n\n";
	//draw(n, A);
	
	
	pause();
	return(0);
}
