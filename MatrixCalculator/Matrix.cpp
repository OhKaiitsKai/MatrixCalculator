#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std; //Declaración de bibliotecas

int fila, col, f_ma, f_mb, c_ma, c_mb;
float matrizA[20][20], matrizB[20][20], matrizC[20][20], matrizD[20][20], matrizE[20][20];
unsigned int opc, auxopc;
const int MAX_COLUMNAS = 20;

void quaternion(float& p1, float& p2, float& p3, float g, float v[]) {
	float c;
	float r[4];
	float R[4];
	float u;
	double PI = 3.14159;
	u = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);
	u = sqrt(u);
	v[0] = v[0] / u;
	v[1] = v[1] / u;
	v[2] = v[2] / u;
	r[0] = (cos(g * PI / 360));
	r[1] = (v[0] * sin(g * PI / 360));
	r[2] = (v[1] * sin(g * PI / 360));
	r[3] = (v[2] * sin(g * PI / 360));
	R[0] = -(r[1] * p1) - (r[2] * p2) - (r[3] * p3);
	R[1] = (r[0] * p1) + (r[2] * p3) - (r[3] * p2);
	R[2] = (r[0] * p2) + (r[3] * p1) - (r[1] * p3);
	R[3] = (r[0] * p3) + (r[1] * p2) - (r[2] * p1);
	r[1] = -1 * r[1];
	r[2] = -1 * r[2];
	r[3] = -1 * r[3];
	c = -(R[1] * r[1]) - (r[2] * R[2]) - (r[3] * R[3]) + (r[0] * R[0]);
	p1 = (R[0] * r[1]) - (r[2] * R[3]) + (r[2] * R[2]) + (r[0] * R[1]);
	if (p1 < 0.01 && p1>0 || p1<0 && p1>-.01) {
		p1 = 0;
	}
	p2 = (R[0] * r[2]) + (r[1] * R[3]) - (r[3] * R[1]) + (r[0] * R[2]);
	if (p2 < 0.01 && p2>0 || p2<0 && p2>-.01) {
		p2 = 0;
	}
	p3 = (R[0] * r[3]) + (r[2] * R[1]) - (r[1] * R[2]) + (r[0] * R[3]);
	if (p3 < 0.01 && p3>0 || p3<0 && p3>-.01) {
		p3 = 0;
	}
	cout << "-Puntos generados-" << endl;
	cout << "x" << ":\t " << p1 << endl;
	cout << "y" << ":\t " << p2 << endl;
	cout << "z" << ":\t " << p3 << endl;
}

void quat() {
	float p1;
	float p2;
	float p3;
	float ang;
	float vector[3];
	cout << "Ingrese X:\t";
	cin >> p1;
	cout << "Ingrese Y:\t";
	cin >> p2;
	cout << "Ingrese Z:\t";
	cin >> p3;
	cout << "-Valor de vectores-" << endl;
	cout << "Vector X:\t";
	cin >> vector[0];
	cout << "Vector Y:\t";
	cin >> vector[1];
	cout << "Vector Z:\t";
	cin >> vector[2];
	cout << "Angulo:\t";
	cin >> ang;
	quaternion(p1, p2, p3, ang, vector);
	system("pause");
}

void rotacionuwu() {
	float R = 0;
	char OP2 = '0';
	cout << "Elegir un eje:" << endl;
	cout << "1. X." << endl;
	cout << "2. Y." << endl;
	cout << "3. Z." << endl;
	cout << "Opcion:";
	cin >> OP2;
	cout << "Angulo de rotacion:\t";
	cin >> R;
	float PI_r = 3.14159 / 180;
	float CosR = cos(R * PI_r), SenR = sin(R * PI_r), senr = sin(R * PI_r) * -1;
	if (OP2 == '1') {
		matrizB[0][0] = CosR, matrizB[0][1] = SenR, matrizB[0][2] = 0, matrizB[0][3] = 0;
		matrizB[1][0] = senr, matrizB[1][1] = CosR, matrizB[1][2] = 0, matrizB[1][3] = 0;
		matrizB[2][0] = 0, matrizB[2][1] = 0, matrizB[2][2] = 1, matrizB[2][3] = 0;
		matrizB[3][0] = 0, matrizB[3][1] = 0, matrizB[3][2] = 0, matrizB[3][3] = 1;
	}
	if (OP2 == '2') {
		matrizB[0][0] = CosR, matrizB[0][1] = 0, matrizB[0][2] = senr, matrizB[0][3] = 0;
		matrizB[1][0] = 0, matrizB[1][1] = 1, matrizB[1][2] = 0, matrizB[1][3] = 0;
		matrizB[2][0] = SenR, matrizB[2][1] = 0, matrizB[2][2] = CosR, matrizB[2][3] = 0;
		matrizB[3][0] = 0, matrizB[3][1] = 0, matrizB[3][2] = 0, matrizB[3][3] = 1;
	}
	if (OP2 == '3') {
		matrizB[0][0] = 1, matrizB[0][1] = 0, matrizB[0][2] = 0, matrizB[0][3] = 0;
		matrizB[1][0] = 0, matrizB[1][1] = CosR, matrizB[1][2] = SenR, matrizB[1][3] = 0;
		matrizB[2][0] = 0, matrizB[2][1] = senr, matrizB[2][2] = CosR, matrizB[2][3] = 0;
		matrizB[3][0] = 0, matrizB[3][1] = 0, matrizB[3][2] = 0, matrizB[3][3] = 1;
	}
}

void generacionmatriz() {
	unsigned int genmc;
	cout << "1. TRS" << endl;//ABC
	cout << "2. TSR" << endl;//ACB
	cout << "3. RST" << endl;//BCA
	cout << "4. RTS" << endl;//BAC
	cout << "5. STR" << endl;//CAB
	cout << "6. SRT" << endl;//CBA
	cout << "Opcion:\t";
	cin >> genmc;
	switch (genmc) {
	case 1:
		system("cls"); //Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizA[i][k] * matrizB[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizC[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	case 2:
		system("cls"); //Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizA[i][k] * matrizC[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizB[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	case 3:
		system("cls"); //Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizB[i][k] * matrizC[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizA[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	case 4:
		system("cls"); //Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizB[i][k] * matrizA[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizC[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	case 5:
		system("cls"); //Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizC[i][k] * matrizA[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizB[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	case 6:
		system("cls");//Limpieza de pantalla
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizD[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizD[i][j] = matrizD[i][j] + matrizC[i][k] * matrizB[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizE[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					matrizE[i][j] = matrizE[i][j] + matrizD[i][k] * matrizA[k][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << "\n";
			for (int j = 0; j < 4; j++) {
				cout << "\t[ " << matrizE[i][j] << " ] \t";
			}
		}
		break;
	default: break;
	}
	system("PAUSE");
	//clearallMatrices();
}

void clear(float matrizA[][MAX_COLUMNAS], float matrizB[][MAX_COLUMNAS], float matrizC[][MAX_COLUMNAS], 
	int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matrizA[i][j] = 0.0f;
			matrizB[i][j] = 0.0f;
			matrizC[i][j] = 0.0f;
		}
	}
}

void clearforM_A(float matrizA[][MAX_COLUMNAS], int f_ma, int c_ma) {
	for (int i = 0; i < f_ma; i++) {
		for (int j = 0; j < c_ma; j++) {
			matrizA[i][j] = 0.0f;
		}
	}
}

void clearforM_B(float matrizB[][MAX_COLUMNAS], int f_mb, int c_mb) {
	for (int i = 0; i < f_mb; i++) {
		for (int j = 0; j < c_mb; j++) {
			matrizB[i][j] = 0.0f;
		}
	}
}

void clearforM_C(float matrizC[][MAX_COLUMNAS], int f_ma, int c_mb) {
	for (int i = 0; i < f_ma; i++) {
		for (int j = 0; j < c_mb; j++) {
			matrizC[i][j] = 0.0f;
		}
	}
}

void clearallMatrices() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrizA[i][j] = 0.0f;
			matrizB[i][j] = 0.0f;
			matrizC[i][j] = 0.0f;
			matrizD[i][j] = 0.0f;
			matrizE[i][j] = 0.0f;
		}
	}
}

int main() {

	do {//Inicio de ciclo
		system("color a");
		system("cls"); //Limpieza de pantalla
		cout << "\t\t-Menu principal-\t\t" << endl; //Opciones de menú principal
		cout << "\t1. Suma de matrices." << endl;
		cout << "\t2. Resta de matrices." << endl;
		cout << "\t3. Multiplicacion de matrices." << endl;
		cout << "\t4. Matriz por vector" << endl;
		cout << "\t5. Generacion de nuevas coordenadas por cuaterniones." << endl;
		cout << "\t6. Matriz compuesta." << endl;
		cout << "\t7. Salir." << endl;
		cout << endl;
		cout << "\nOpcion:\t";
		cin >> opc; //Ingresar número
		switch (opc) {
		case 1:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Suma de matrices-\t" << endl;
			cout << endl;
			cout << "Inserte el numero de filas:\t";
			cin >> fila;
			cout << "Inserte el numero de columnas:\t";
			cin >> col;
			cout << endl;

			cout << "Matriz A" << endl;
			for (int i = 0; i < fila; i++) {
				for (int j = 0; j < col; j++) {
					cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
					cin >> matrizA[i][j];
				}
			}

			cout << endl;
			cout << "Matriz B" << endl;
			for (int i = 0; i < fila; i++) {
				for (int j = 0; j < col; j++) {
					cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
					cin >> matrizB[i][j];
				}
			}

			cout << endl;
			cout << "Matriz C" << endl;
			for (int i = 0; i < fila; i++) { //Operación y resultado
				cout << endl;
				for (int j = 0; j < col; j++) {
					matrizC[i][j] = matrizA[i][j] + matrizB[i][j]; //Hace operación de suma
					cout << "\t[" << matrizC[i][j] << "]\t"; //Desplega los resultados
				}
			}
			system("PAUSE");
			clear(matrizA, matrizB, matrizC, fila, col);
			break;
		case 2:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Resta de matrices-\t" << endl;
			cout << endl;
			cout << "Inserte el numero de filas:\t";
			cin >> fila;
			cout << "Inserte el numero de columnas:\t";
			cin >> col;
			cout << endl;

			cout << "Matriz A" << endl;
			for (int i = 0; i < fila; i++) {
				for (int j = 0; j < col; j++) {
					cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
					cin >> matrizA[i][j];
				}
			}

			cout << endl;
			cout << "Matriz B" << endl;
			for (int i = 0; i < fila; i++) {
				for (int j = 0; j < col; j++) {
					cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
					cin >> matrizB[i][j];
				}
			}

			cout << endl;
			cout << "Matriz C" << endl;
			for (int i = 0; i < fila; i++) { // Operación y resultado
				cout << endl;
				for (int j = 0; j < col; j++) {
					matrizC[i][j] = matrizA[i][j] - matrizB[i][j]; // Hace operación de resta
					cout << "\t[" << matrizC[i][j] << "]\t"; // Desplega los resultados
				}
			}
			system("PAUSE");
			clear(matrizA, matrizB, matrizC, fila, col);
			break;

		case 3:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Multiplicacion de matrices-\t" << endl;
			cout << endl;

				cout << "Matriz A" << endl;
				cout << "Inserte el numero de filas:\t";
				cin >> f_ma;
				cout << "Inserte el numero de columnas:\t";
				cin >> c_ma;
				for (int i = 0; i < f_ma; i++) {
					for (int j = 0; j < c_ma; j++) {
						cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
						cin >> matrizA[i][j];
					}
				}


				cout << "Matriz B" << endl;
				cout << "Inserte el numero de filas:\t";
				cin >> f_mb;
				cout << "Inserte el numero de columnas:\t";
				cin >> c_mb;
				for (int i = 0; i < f_mb; i++) {
					for (int j = 0; j < c_mb; j++) {
						cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
						cin >> matrizB[i][j];
					}
				}
	
			if (c_ma == f_mb) { //Condición para multiplicación
				for (int i = 0; i < f_ma; i++) {
					for (int j = 0; j < c_mb; j++) {
						matrizC[i][j] = 0;
						for (int k = 0; k < c_ma; k++) {
							matrizC[i][j] = matrizC[i][j] + matrizA[i][k] * matrizB[k][j];
						}
					}
				}
				for (int i = 0; i < f_ma; i++) {
					cout << "\n";
					for (int j = 0; j < c_mb; j++) {
						cout << "\t[ " << matrizC[i][j] << " ] \t";
					}
				}
			}
			else {
				cout << "ERROR" << endl;
			}
			system("PAUSE");
			clearforM_A(matrizA, f_ma, c_ma);
			clearforM_B(matrizB, f_mb, c_mb);
			clearforM_C(matrizC, f_ma, c_mb);
			break;
		case 4:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Matriz por vector-\t" << endl;
			cout << endl;
			cout << "*El numero de filas y columnas predeterminado es: 4*" << endl;
			cout << endl;
			
				cout << "Matriz A" << endl;
				cout << "Inserte el numero de filas:\t";
				f_ma = 4;
				cout << f_ma << endl;
				cout << "Inserte el numero de columnas:\t";
				c_ma = 4;
				cout << c_ma << endl;
				for (int i = 0; i < f_ma; i++) {
					for (int j = 0; j < c_ma; j++) {
						cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
						cin >> matrizA[i][j];
					}
				}
			cout << endl;
			
				cout << "Matriz B" << endl;
				cout << "Inserte el numero de filas:\t";
				f_mb = 4;
				cout << f_mb << endl;
				cout << "Inserte el numero de columnas:\t";
				c_mb = 1;
				cout << c_mb << endl;
				for (int i = 0; i < f_mb; i++) {
					for (int j = 0; j < c_mb; j++) {
						cout << "Numero insertado en coordenada " << i << "," << j << ":\t";
						cin >> matrizB[i][j];
					}
				}
			if (c_ma == f_mb) { //Condición para multiplicación
				//matrizB[3][0] = 1;
				for (int i = 0; i < f_ma; i++) {
					for (int j = 0; j < c_mb; j++) {
						matrizC[i][j] = 0;
						for (int k = 0; k < c_ma; k++) {
							matrizC[i][j] = matrizC[i][j] + matrizA[i][k] * matrizB[k][j];
						}
					}
				}
				for (int i = 0; i < f_ma; i++) {
					cout << "\n";
					for (int j = 0; j < c_mb; j++) {
						cout << "\t[ " << matrizC[i][j] << " ] \t";
					}
				}
			}
			else {
				cout << "ERROR" << endl;
			}
			system("PAUSE");
			clearforM_A(matrizA, f_ma, c_ma);
			clearforM_B(matrizB, f_mb, c_mb);
			clearforM_C(matrizC, f_ma, c_mb);
			break;
		case 5:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Generacion de nuevas coordenadas por cuaterniones-\t" << endl;
			cout << endl;
			quat();
			break;
		case 6:
			do {
				//fila = 4;
				//col = 4;
				system("cls"); //Limpieza de pantalla
				cout << "\t-Matriz Compuesta-\t" << endl;
				cout << "1. Agregar Traslacion" << endl; //MatrizA
				cout << "2. Agregar Rotacion" << endl; //MatrizB
				cout << "3. Agregar Escalamiento" << endl; //MatrizC
				cout << "4. Salir" << endl; //Generación Matriz Compuesta
				cout << "Opcion:\t";
				cin >> auxopc;
				switch (auxopc) {
				case 1:
					system("cls");//Limpieza de Pantalla
					cout << "-Traslacion-" << endl;
					matrizA[0][0] = 1;
					matrizA[1][1] = 1;
					matrizA[2][2] = 1;
					matrizA[3][3] = 1;
					matrizA[0][1] = 0;
					matrizA[0][2] = 0;
					matrizA[1][0] = 0;
					matrizA[1][2] = 0;
					matrizA[2][0] = 0;
					matrizA[2][1] = 0;
					matrizA[3][0] = 0;
					matrizA[3][1] = 0;
					matrizA[3][2] = 0;
					cout << "Tx:\t";
					cin >> matrizA[0][3];
					cout << "Ty:\t";
					cin >> matrizA[1][3];
					cout << "Tz:\t";
					cin >> matrizA[2][3];
					break;
				case 2:
					system("cls");//Limpieza de pantalla
					cout << "-Rotacion-" << endl;
					rotacionuwu();
					break;
				case 3:
					system("cls");//Limpieza de pantalla
					cout << "-Escalamiento-" << endl;
					cout << "Sx:\t";
					cin >> matrizC[0][0];
					cout << "Sy:\t";
					cin >> matrizC[1][1];
					cout << "Sz:\t";
					cin >> matrizC[2][2];
					matrizC[0][1] = 0, matrizC[0][2] = 0, matrizC[0][3] = 0;
					matrizC[1][0] = 0, matrizC[1][2] = 0, matrizC[1][3] = 0;
					matrizC[2][0] = 0, matrizC[2][1] = 0, matrizC[2][3] = 0;
					matrizC[3][0] = 0, matrizC[3][1] = 0, matrizC[3][2] = 0, matrizC[3][3] = 1;
					break;
				case 4:
					system("cls"); //Limpieza de pantalla
					cout << "-Salir-" << endl;
					generacionmatriz();
					break;
				default: break;
				}
			} while (auxopc != 4);
			clearallMatrices();
			break;
		case 7:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Salir-\t" << endl;
			break;
		default:
			system("cls"); //Limpieza de pantalla
			cout << "\t-Error-\t" << endl;
			system("PAUSE");
			break;
		}

	} while (opc != 7);
	return 0;
}