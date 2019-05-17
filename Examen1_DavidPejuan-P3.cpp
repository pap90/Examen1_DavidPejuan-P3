#include <iostream>
using namespace std;

char** armarmatriz(char**);
void imprimirmat(char**);
int comprobarN(int,int,char**);
int comprobarV(int,char**,int,int);
int comprobarH(int,char**,int,int);
int convertir(char);
char** mover(char**);
char** moverVN(int,char**,int,int);
char** moverHN(int,char**,int,int);
int main(){
	int vive=1;
	int turno=1;
	char** matrix=NULL;
	matrix=armarmatriz(matrix);
        imprimirmat(matrix);
	while(vive==1){
		if(turno=1){
ingresarN:
			char letra;
			int numero;
			cout<<"Ingrese letra de la pieza a mover: ";
			cin>>letra;
			cout<<endl;
			cout<<"Ingrese el numero de la pieza a mover: ";
			cin>>numero;
			int desde=convertir(letra);
			int comprobar=comprobarN(desde,numero,matrix);
			if(comprobar==1){
				goto ingresarN;
			}
moverN:
			cout<<"desea movr la pieza horizontal[H] o verticalmente[V]?: ";
			char como;
			cin>>como;
			cout<< endl;
			if(como=='V'||como=='v'){
				char hacialetra;
				cout << "ingrese la letra a donde desea mover la pieza: ";
				cin >> hacialetra;
				cout <<endl;
				int hacia=convertir(hacialetra);
				int compro=comprobarV(hacia,matrix,desde,numero);
				if(compro==1){
					goto moverN;
				}else{
					//cout<<"QUE PUTAS!"<<endl;
					matrix=moverVN(hacia, matrix, desde, numero);
					imprimirmat(matrix);
					turno=2;

				}

			}else if(como=='H'||como=='h'){
				int hacia;
				cout<<"Ingrese hacia donde desea mover la pieza: ";
				cin>>hacia;
				cout<<endl;
				
				int compro=comprobarH(hacia,matrix,numero,desde);
				if(compro==1){
					goto moverN;

				}else{
					matrix=moverHN(hacia,matrix,numero,desde);
					imprimirmat(matrix);
					turno=2;
				}
			}

		}else if(turno==2){
				turno=1;
		} 
		
	}
}
char** armarmatriz(char** matrix){
	matrix=new char* [11];
        for(int i=0;i<11;i++){
                matrix[i]=new char[11];
        }
	matrix[5][5]='W';
	matrix[0][0]='X';
	matrix[0][10]='X';
	matrix[10][0]='X';
	matrix[10][10]='X';
	matrix[3][5]='B';
	matrix[4][4]='B';
	matrix[4][5]='B';
	matrix[4][6]='B';
	matrix[5][3]='B';
	matrix[5][4]='B';
	matrix[5][6]='B';
	matrix[5][7]='B';
	matrix[6][4]='B';
	matrix[6][5]='B';
	matrix[6][6]='B';
	matrix[7][5]='B';
	matrix[0][4]='N';
	matrix[0][5]='N';
	matrix[0][6]='N';
	matrix[1][4]='N';
	matrix[1][6]='N';
	matrix[2][5]='N';
	matrix[4][0]='N';
	matrix[5][0]='N';
	matrix[6][0]='N';
	matrix[4][1]='N';
	matrix[6][1]='N';
	matrix[5][2]='N';
	matrix[8][5]='N';
	matrix[9][4]='N';
	matrix[9][6]='N';
	matrix[10][4]='N';
	matrix[10][5]='N';
	matrix[10][6]='N';
	matrix[4][9]='N';
	matrix[4][10]='N';
	matrix[5][8]='N';
	matrix[5][10]='N';
	matrix[6][9]='N';
	matrix[6][10]='N';
	return matrix;
}
void imprimirmat(char** mat){
	for(int i=0;i<11;i++){
                for(int j=0;j<11;j++){
			if(mat[i][j]=='B'||mat[i][j]=='N'||mat[i][j]=='X'||mat[i][j]=='W'){
                        	cout<<"["<<mat[i][j]<<"]";
			}else{
				cout <<"[ ]";
			}

                }
                cout<<endl;
        }

}
int convertir(char letra){
	int num1;
        if(letra=='A'||letra=='a'){
                num1=0;
        }else if(letra=='B'||letra=='b'){
                num1=1;
        }else if(letra=='C'||letra=='c'){
                num1=2;
        }else if(letra=='D'||letra=='d'){
                num1=3;
        }else if(letra=='E'||letra=='e'){
                num1=4;
        }else if(letra=='F'||letra=='f'){
                num1=5;
        }else if(letra=='G'||letra=='g'){
                num1=6;
        }else if(letra=='H'||letra=='h'){
                num1=7;
        }else if(letra=='I'||letra=='i'){
                num1=8;
        }else if(letra=='J'||letra=='j'){
                num1=9;
        }else if(letra=='K'||letra=='k'){
                num1=10;
        }
	return num1;
	
}
int comprobarN(int num1, int numero, char** mat){
	/*int num1;
	num1=convertir(letra);
	if(letra=='A'||letra=='a'){
		num1=0;
	}else if(letra=='B'||letra=='b'){
		num1=1;
	}else if(letra=='C'||letra=='c'){
		num1=2;
	}else if(letra=='D'||letra=='d'){
		num1=3;
	}else if(letra=='E'||letra=='e'){
		num1=4;
	}else if(letra=='F'||letra=='f'){
		num1=5;
	}else if(letra=='G'||letra=='g'){
		num1=6;
        }else if(letra=='H'||letra=='h'){
                num1=7;
        }else if(letra=='I'||letra=='i'){
                num1=8;
        }else if(letra=='J'||letra=='j'){
                num1=9;
        }else if(letra=='K'||letra=='k'){
                num1=10;
        }*/
	if(mat[num1][numero]!='N'){
		return 1;
	}else{
		return 0;
	}
}
int comprobarV(int hacia, char** matrix, int desde, int numero){
	if(desde<hacia){
		int cont=0;
		for(int i=desde+1;i<=hacia;i++){
			if(matrix[i][numero]=='N'||matrix[i][numero]=='B'||matrix[i][numero]=='W'){
				cont++;
			}
		}
		if(cont>0){
			return 1;
		}else{
			return 0;
		}
	}else if(hacia<desde){
		int cont=0;
		for(int i=hacia+1;i<=desde;i++){
			if(matrix[i][numero]=='N'||matrix[i][numero]=='B'||matrix[i][numero]=='W'){
                                cont++;
                        }
			if(cont>0){
                        return 1;
                }else{
                        return 0;
                }

			
		}
	}

}
char** moverVN(int hacia,char** matrix,int desde,int numero){
	matrix[desde][numero]=' ';
	matrix[hacia][numero]='N';
	return matrix;
}
char** moverHN(int hacia,char** matrix,int desde,int numero){
	matrix[desde][numero]=' ';
	matrix[hacia][numero]='N';
	return matrix;
}
int comprobarH(int hacia, char** matrix, int desde, int numero){
        if(desde<hacia){
                int cont=0;
                for(int i=desde+1;i<=hacia;i++){
                        if(matrix[numero][i]=='N'||matrix[numero][i]=='B'||matrix[numero][i]=='W'){
                                cont++;
                        }
                }
                if(cont>0){
                        return 1;
                }else{
                        return 0;
                }
        }else if(hacia<desde){
                int cont=0;
                for(int i=hacia+1;i<=desde;i++){
                        if(matrix[numero][i]=='N'||matrix[numero][i]=='B'||matrix[numero][i]=='W'){
                                cont++;
                        }
                        if(cont>0){
                        return 1;
                }else{
                        return 0;
                }


                }
        }

}

