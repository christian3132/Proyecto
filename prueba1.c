#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define F_WHITE "\x1B[37m"
#define F_RED "\x1b[31m"
#define F_GREEN "\x1b[32m"
#define F_YELLOW "\x1b[33m"
#define F_BLUE "\x1b[34m"
#define F_MAGENTA "\x1b[35m"
#define F_CYAN "\x1b[36m"
#define F_ORANGE "\x1B[38;2;255;128;0m"
#define F_ROSE "\x1B[38;2;255;151;203m"
#define F_LBLUE "\x1B[38;2;53;149;240m"
#define F_LGREEN "\x1B[38;2;17;245;120m"
#define F_GRAY "\x1B[38;2;176;174;174m"

#define RESET "\x1b[0m"

// Colores para el fondo de las letras en sistemas windows OS
#define B_BLACK "\x1B[40m"
#define B_RED "\x1B[41m"
#define B_GREEN "\x1B[42m"
#define B_YELLOW "\x1B[43m"
#define B_BLUE "\x1B[44m"
#define B_MAGENTA "\x1B[45m"
#define B_CYAN "\x1B[46m"
#define B_WHITE "\x1B[47m"
#define B_ORANGE "\x1B[48;2;255;128;0m"
#define B_LBLUE "\x1B[48;2;53;149;240m"
#define B_LGREEN "\x1B[48;2;17;245;120m"
#define B_GRAY "\x1B[48;2;176;174;174m"
#define B_ROSE "\x1B[48;2;255;151;203m"


int gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBox(int width, int height, int x, int y, WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < width; j++) {
            printf(" ");
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

//Ingreso
void boxc() {
    system("cls");
    drawBox(60, 20, 20, 3, BACKGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_GREEN);
    drawBox(60, 20, 18, 4, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);

    gotoxy(40, 6);
    printf(F_WHITE "INGRESO AL SISTEMA\n\n");
}

int Ingreso() {
    boxc();

    char nombre[5][20] = {"Admin", "Dummy", "Christopher", "Christian", "Roberto"};
    int password[5] = {123456, 654321, 38222, 24905, 12233};
    char usuario[20];
    int contra = 0;
    char term;
    int opc = 0;

    do {
        gotoxy(40, 8);
        printf("Usuario: ");

        fgets(usuario, sizeof(usuario), stdin);

        usuario[strcspn(usuario, "\n")] = 0;

        int esLetra = 1;
        for (int i = 0; i < strlen(usuario); i++) {
            if (!((usuario[i] >= 'a' && usuario[i] <= 'z') || (usuario[i] >= 'A' && usuario[i] <= 'Z'))) {
                esLetra = 0;
                break;
            }
        }

        if (esLetra) {
            opc = 1;
        } else {
            gotoxy(20, 9);
            printf("Entrada invalida\n");
            system("pause");
            Ingreso();
        }
    } while (opc != 1);
    opc = 0;

    do {
        gotoxy(40, 10);
        printf("Contrasena: ");

        if (scanf("%i%c", &contra, &term) != 2) {
            gotoxy(40, 11);
            printf("Entrada invalida\n");
            while (getchar() != '\n');
            opc = 0;
            _getch();
            Ingreso();
        } else {
            opc = 1;
        }
    } while (opc != 1);

    int usuarioValido = -1;

    for (int i = 0; i < 5; i++) {
        if (strcmp(usuario, nombre[i]) == 0 && contra == password[i]) {
            usuarioValido = i;
            break;
        }
    }

    if (usuarioValido != -1) {
        gotoxy(40, 12);
        printf("Bienvenido, %s\n", nombre[usuarioValido]);
        if (strcmp(usuario, "Admin") == 0 && contra == 123456) {
            gotoxy(40, 13);
            def_menu();
            return 0;
        } else {
            gotoxy(40, 13);
            printf(F_GREEN "Ventas\n" RESET);
            return 0;

        }
    } else {
        gotoxy(20, 13);
        printf("Usuario o contrasena incorrectos. Acceso denegado.\n");
        system("pause");
        Ingreso();
    }

    return 0;
}

//Def-menu
void c1(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    drawBox(60, 20, 20, 3, BACKGROUND_RED);
    drawBox(60, 20, 18, 4,  BACKGROUND_BLUE);
}

void opcmenuad(int cont, int x, int y, int* opc2) {

    if (cont == 1) {
        gotoxy(x+2, y - 2);
        printf(F_WHITE "ADMINISTRACION\n\n" RESET);
        gotoxy(x, y + 1);
        printf("1- Empleados <---\n");
        gotoxy(x, y + 2);
        printf(B_BLUE "2- Venta\n");
        gotoxy(x, y + 3);
        printf( "3- Empresa\n");
        gotoxy(x, y + 4);
        printf("4- Productos\n");
        gotoxy(x, y + 5);
        printf("5- Regresar\n");
        gotoxy(x - 3, y + 7);
        printf("Que accion desea realizar? | |\n");
    } else if (cont == 2) {
        gotoxy(x+2, y - 2);
        printf(F_WHITE "ADMINISTRACION\n\n" RESET);
        gotoxy(x, y + 1);
        printf(B_BLUE "1- Empleados\n" RESET);
        gotoxy(x, y + 2);
        printf("2- Venta     <---\n");
        gotoxy(x, y + 3);
        printf(B_BLUE "3- Empresa\n");
        gotoxy(x, y + 4);
        printf("4- Productos\n");
        gotoxy(x, y + 5);
        printf("5- Regresar\n");
        gotoxy(x - 3, y + 7);
        printf("Que accion desea realizar? | |\n");
    } else if (cont == 3) {
        gotoxy(x+2, y - 2);
        printf(F_WHITE "ADMINISTRACION\n\n" RESET);
        gotoxy(x, y + 1);
        printf(B_BLUE "1- Empleados\n");
        gotoxy(x, y + 2);
        printf("2- Venta\n" RESET);
        gotoxy(x, y + 3);
        printf("3- Empresa   <---\n");
        gotoxy(x, y + 4);
        printf(B_BLUE "4- Productos\n");
        gotoxy(x, y + 5);
        printf("5- Regresar\n");
        gotoxy(x - 3, y + 7);
        printf("Que accion desea realizar? | |\n");
    } else if (cont == 4) {
        gotoxy(x+2, y - 2);
        printf(F_WHITE "ADMINISTRACION\n\n" RESET);
        gotoxy(x, y + 1);
        printf(B_BLUE "1- Empleados\n");
        gotoxy(x, y + 2);
        printf("2- Venta\n");
        gotoxy(x, y + 3);
        printf("3- Empresa\n" RESET);
        gotoxy(x, y + 4);
        printf("4- Productos <---\n");
        gotoxy(x, y + 5);
        printf(B_BLUE "5- Regresar\n");
        gotoxy(x - 3, y + 7);
        printf("Que accion desea realizar? | |\n");
    } else if (cont == 5) {
        gotoxy(x+2, y - 2);
        printf(F_WHITE "ADMINISTRACION\n\n" RESET);
        gotoxy(x, y + 1);
        printf(B_BLUE "1- Empleados\n");
        gotoxy(x, y + 2);
        printf("2- Venta\n");
        gotoxy(x, y + 3);
        printf("3- Empresa\n");
        gotoxy(x, y + 4);
        printf("4- Productos\n" RESET);
        gotoxy(x, y + 5);
        printf("5- Regresar  <---\n");
        gotoxy(x - 3, y + 7);
        printf(B_BLUE "Que accion desea realizar? | |\n");
    }

    if (*opc2 >= 1 && *opc2 <= 5) {

    }
}

void def_menu(char nombreEmpresa, int telEmpres, char correEmpres, float dcaja,char nombre[500][20], int id[500], float precio[500], int piezas[500], int *nProducto) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int cont = 1, opc2 = 0;
    char opc;

    while (1) {
        system("cls");
        c1();
        opcmenuad(cont, 35, 10, &opc2);
        // Funci n con flechitas
        opc = _getch();
        if (opc == 72 && cont > 1) {
            cont--;
            SetConsoleTextAttribute(hConsole, 7);
        } else if (opc == 80 && cont < 5) {
            cont++;
            SetConsoleTextAttribute(hConsole, 7);
        } else if (opc == 13) {
            if (cont == 1) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola");
                break;
            } else if (cont == 2) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola 2");
                break;
            } else if (cont == 3) {
                SetConsoleTextAttribute(hConsole, 7);
                menempres(nombreEmpresa,telEmpres,correEmpres, dcaja);
                break;
            } else if (cont == 4) {
                SetConsoleTextAttribute(hConsole, 7);
                menproduc(nombre[500][20],id[500], precio[500],piezas[500], *nProducto);
                break;
            } else if (cont == 5) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                Ingreso();
                break;
            }
        } else if (isdigit(opc)) {
            // Si se ingres  un n mero, actualiza opc2
            opc2 = opc - '0'; // Convierte el car cter num rico a entero
        }

        if (opc2 >= 1 && opc2 <= 5) {
            if (opc2 == 1) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola");
                break;
            } else if (opc2 == 2) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola 2");
                break;
            } else if (opc2 == 3) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola 3");
                break;
            } else if (opc2 == 4) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                printf("Hola 4");
                break;
            } else if (opc2 == 5) {
                SetConsoleTextAttribute(hConsole, 7);
                system("cls");
                Ingreso();
                return 0;
                break;
            }
        }
    }

    SetConsoleTextAttribute(hConsole, 7);
}

//productos
int esNumeroValido(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i]) && entrada[i] != '.') {
            return 0;
        }
    }
    return 1;
}

float ingresarNumeroValidado() {
    char entrada[20];
    while (1) {
        scanf("%s", entrada);
        if (esNumeroValido(entrada)) {
            // Convierte la entrada a un n mero flotante
            return atof(entrada);
        } else {
            gotoxy(25, 25);
            printf(B_RED "Error: No puede haber letras en este apartado " RESET);
            gotoxy(30, 28);
            system("pause");
        }
    }
}

int buscarProducto(int id[500], int nProducto, int idBuscado) {
    for (int i = 0; i < nProducto; i++) {
        if (idBuscado == id[i]) {
            return i;
        }
    }
    return -1;
}

void cproduc() {
    system("cls");
    drawBox(60, 20, 20, 3, BACKGROUND_GREEN);
    drawBox(60, 20, 18, 4, BACKGROUND_RED  |  BACKGROUND_BLUE );
}

void opcproduc(int x, int y, int cont3){
    if (cont3==1){
        gotoxy(x+12,y);
        printf(F_WHITE "PRODUCTOS");
        gotoxy(x+8,y+3);
        printf(B_LBLUE "Alta de productos" RESET);
        gotoxy(x+8,y+4);
        printf("Baja de productos");
        gotoxy(x+10,y+6);
        printf("Ver productos");
        gotoxy(x+12,y+8);
        printf("Regresar");
    }else if(cont3==2){
        gotoxy(x+12,y);
        printf(F_WHITE "PRODUCTOS");
        gotoxy(x+8,y+3);
        printf("Alta de productos");
        gotoxy(x+8,y+4);
        printf(B_LBLUE "Baja de productos" RESET);
        gotoxy(x+10,y+6);
        printf("Ver productos");
        gotoxy(x+12,y+8);
        printf("Regresar");
    }else if(cont3==3){
        gotoxy(x+12,y);
        printf(F_WHITE "PRODUCTOS");
        gotoxy(x+8,y+3);
        printf("Alta de productos");
        gotoxy(x+8,y+4);
        printf("Baja de productos");
        gotoxy(x+10,y+6);
        printf(B_LBLUE "Ver productos" RESET);
        gotoxy(x+12,y+8);
        printf("Regresar");
    }else if(cont3==4){
        gotoxy(x+12,y);
        printf(F_WHITE "PRODUCTOS");
        gotoxy(x+8,y+3);
        printf("Alta de productos");
        gotoxy(x+8,y+4);
        printf("Baja de productos");
        gotoxy(x+10,y+6);
        printf("Ver productos");
        gotoxy(x+12,y+8);
        printf(B_LBLUE "Regresar" RESET);
    }

}

void AltaProducto(char nombre[500][20], int id[500], float precio[500], int piezas[500], int *nProducto) {
    int i = *nProducto;
    int opc;

    while (1) {
        system("cls");
        cproduc();
        gotoxy(41, 6);
        printf(F_WHITE "NUEVO PRODUCTO");
        gotoxy(35, 8);
        printf("Inserte el nombre:");
        gotoxy(39, 9);
        scanf("%s", nombre[i]);
        gotoxy(35, 11);
        printf("Inserte el ID:");
        gotoxy(39, 12);
        scanf("%i", &id[i]);
        gotoxy(35, 14);
        printf("Inserte el precio:");
        gotoxy(39, 15);
        precio[i] = ingresarNumeroValidado();
        gotoxy(35, 17);
        printf("Inserte cantidad inicial:");
        gotoxy(39, 18);
        piezas[i] = ingresarNumeroValidado();
        system("cls");
        cproduc();
        gotoxy(35, 10);
        printf(F_WHITE B_GREEN "Producto agregado con exito!" RESET);
        gotoxy(39, 12);
        printf("Desea agregar otro?:");
        gotoxy(42, 13);
        printf("1-SI     2-NO");
        gotoxy(39, 15);
        scanf("%d", &opc);

        (*nProducto)++;
        if (opc == 1) {
            i = *nProducto;  // Incrementar i solo si se va a agregar otro producto
        } else if (opc == 2) {
            break;
        }
    }

}

void bajaProducto(char nombre[500][20], int id[500], float precio[500], int piezas[500], int *nProducto) {
    int idbaja;

    while (1) {
        system("cls");
        cproduc();
        gotoxy(41, 8);
        printf(F_WHITE "BAJA DE PRODUCTO");
        gotoxy(28, 13);
        printf("Ingrese el ID del producto: ");
        gotoxy(41, 14);
        scanf("%i", &idbaja);

        int indice = buscarProducto(id, *nProducto, idbaja);

        if (indice != -1) {
            for (int i = indice; i < *nProducto - 1; i++) {
                id[i] = id[i + 1];
                strcpy(nombre[i], nombre[i + 1]);
                precio[i] = precio[i + 1];
                piezas[i] = piezas[i + 1];
            }
            (*nProducto)--;
            gotoxy(35, 16);
            printf(B_GREEN "Producto dado de baja con  xito.\n" RESET);
            gotoxy(30, 18);
            system("pause");
            break;
        } else {
            gotoxy(30, 16);
            printf(B_RED "El producto no existe en la base de datos.\n" RESET);
            gotoxy(30, 18);
            system("pause");
        }
    }
}

void mostrarproducto(char nombre[500][20], int id[500], float precio[500], int piezas[500], int *nProducto) {
    system("cls");
    cproduc();
    gotoxy(40, 6);
    printf(F_WHITE "MOSTRAR PRODUCTOS");
    gotoxy(36, 8);
    printf("Lista de productos:\n");

    for (int i = 0; i < *nProducto; i++) {
        gotoxy(25, 10);
        printf(B_BLUE "Nombre:" RESET);
        gotoxy(25, 12 + i);
        printf("%s", nombre[i]);
        gotoxy(38, 10);
        printf(B_BLUE "Id:" RESET);
        gotoxy(38, 12 + i);
        printf("%i", id[i]);
        gotoxy(48, 10 );
        printf(B_BLUE "Precio:" RESET);
        gotoxy(48, 12 + i);
        printf("%.2f", precio[i]);
        gotoxy(63, 10 );
        printf(B_BLUE "Piezas:" RESET);
        gotoxy(63, 12 + i);
        printf("%i", piezas[i]);
    }
    gotoxy(30, 28);
    system("pause");
}

void menproduc(char nombre[500][20], int id[500], float precio[500], int piezas[500], int *nProducto){
    int cont3=1, opc4, opc5;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while(1){
        cproduc();
        opcproduc(30,9, cont3);
        opc4= _getch();
        if (opc4==72 && cont3 > 1){
            cont3--;
            SetConsoleTextAttribute(hConsole, 7);
        }else if (opc4 == 80 && cont3 < 4) {
            cont3++;
            SetConsoleTextAttribute(hConsole, 7);
        }else if (opc4 == 13) {
            if(cont3==1){
                AltaProducto(nombre, id, precio, piezas, &nProducto);
            }else if(cont3==2){
                bajaProducto(nombre, id, precio, piezas, &nProducto);
            }else if(cont3==3){
                mostrarproducto(nombre,id,precio,piezas, &nProducto);
            }else if(cont3==4){
                //def_menu(nombreEmpresa,telEmpres,correEmpres,dcaja,nombre,id,precio,piezas,nProducto);
            }

        }else if(isdigit(opc4)) {
            // Si se ingres  un n mero, actualiza opc2
            opc5 = opc4 - '0'; // Convierte el car cter num rico a entero
        }

    }

}


//Empresa
void cempres() {
    system("cls");
    drawBox(60, 20, 20, 3, BACKGROUND_GREEN|BACKGROUND_BLUE);
    drawBox(60, 20, 18, 4,  BACKGROUND_GREEN);
}

void opcempres(int cont5, int x, int y){
    if(cont5==1){
        gotoxy(x+2,y-2);
        printf(F_WHITE "EMPRESA");
        gotoxy(x,y+1);
        printf(B_BLACK "Edicion         <--" RESET);
        gotoxy(x,y+2);
        printf("Dinero en caja");
        gotoxy(x,y+3);
        printf("Regresar");
    }else if(cont5==2){
        gotoxy(x+2,y-2);
        printf(F_WHITE "EMPRESA");
        gotoxy(x,y+1);
        printf("Edicion");
        gotoxy(x,y+2);
        printf(B_BLACK "Dinero en caja  <--" RESET);
        gotoxy(x,y+3);
        printf("Regresar");
    }else if(cont5==3){
        gotoxy(x+2,y-2);
        printf(F_WHITE "EMPRESA");
        gotoxy(x,y+1);
        printf("Edicion");
        gotoxy(x,y+2);
        printf("Dinero en caja");
        gotoxy(x,y+3);
        printf(B_BLACK "Regresar       <--" RESET);
    }

}

void DCaja(float *dcaja) {
    int opc;
    float nfondo;

    while (1) {
        system("cls");
        cempres();
        gotoxy(40, 10);
        printf(F_WHITE "DINERO EN CAJA");
        gotoxy(30, 13);
        printf("El dinero en caja actual es de: %.2f", *dcaja);
        gotoxy(38, 15);
        printf("Desea cambiarlo?");
        gotoxy(40, 17);
        printf("1-SI     2-NO");
        gotoxy(47, 18);
        scanf("%i", &opc);

        if (opc == 1 || opc == 2) {
            break;
        } else {
            gotoxy(30, 20);
            printf(B_RED "Entrada no valida. Por favor ingrese 1 o 2" RESET);
            Sleep(1000);
            gotoxy(47, 18);
            printf(B_GREEN "                                 " RESET);
            gotoxy(30, 20);
            printf(B_GREEN "                                 " RESET);
            while (getchar() != '\n');
        }
    }

        if (opc == 1) {
            system("cls");
            cempres();
            gotoxy(30, 15);
            printf("Inserte el nuevo fondo de caja: ");
            gotoxy(35, 16);
            scanf("%f", &nfondo);
            *dcaja = nfondo;
            return;

        } else if (opc == 2) {
           // menempres(nombreEmpresa,telEmpres,correEmpres, dcaja);
        }

}

void EEmpres(char nombreEmpresa[], int telEmpres, char correEmpres[]) {
    int opc, ntelefono;
    char ncorreo[100], nnombre[100];

    system("cls");
    while (1) {
        cempres();
        gotoxy(40, 8);
        printf(F_WHITE "EDITAR EMPRESA");
        gotoxy(30, 12);
        printf("Nombre actual: %s", nombreEmpresa);
        gotoxy(30, 14);
        printf("Telefono actual: %d", telEmpres);
        gotoxy(30, 16);
        printf("Correo actual: %s", correEmpres);
        gotoxy(40, 18);
        printf("Desea cambiarlo?");
        gotoxy(40, 19);
        printf("1-SI     2-NO");
        gotoxy(47, 20);
        scanf("%i", &opc);

        if (opc == 1 || opc == 2) {
            break;
        } else {
            gotoxy(30, 22);
            printf(B_RED "Entrada no valida. Por favor ingrese 1 o 2" RESET);
            Sleep(1000);
            gotoxy(47, 20);
            printf(B_GREEN "                                 " RESET);
            gotoxy(30, 22);
            printf(B_GREEN "                                 " RESET);
            while (getchar() != '\n');
        }
    }

    if (opc == 1) {
        system("cls");
        cempres();
        gotoxy(30, 8);
        printf(F_WHITE "Nuevo Nombre: ");
        gotoxy(30, 9);
        fflush(stdin); // Limpiar el buffer del teclado antes de leer
        fgets(nnombre, sizeof(nnombre), stdin);
        nnombre[strcspn(nnombre, "\n")] = '\0'; // Eliminar el carácter de nueva línea

        strcpy(nombreEmpresa, nnombre);

        // Restricciones para el teléfono
        while (1) {
            gotoxy(30, 11);
            printf("Nuevo Telefono:");
            gotoxy(25, 12);
            printf(B_GREEN "(33) " RESET);
            gotoxy(30, 12);

            if (scanf("%8d", &ntelefono) != 1 || getchar() != '\n' || ntelefono < 0) {
                gotoxy(20, 14);
                printf(B_RED "Ingrese un numero de telefono valido de hasta 8 digitos." RESET);
                Sleep(2000);
                gotoxy(20, 14);
                printf(B_GREEN "                                                        " RESET);
                gotoxy(25, 12);
                printf(B_GREEN "                                                " RESET);
                while (getchar() != '\n');  // Limpiar el buffer del teclado
            } else {
                telEmpres = ntelefono;
                break;
            }
        }

        // Restricciones para el correo
        while (1) {
            gotoxy(30, 14);
            printf("Nuevo Correo: ");
            gotoxy(30, 15);
            scanf("%s", ncorreo);

            if (strchr(ncorreo, '@') == NULL) {
                gotoxy(30, 16);
                printf(B_RED "Entrada no valida. El correo debe incluir @." RESET);
                Sleep(2000);
                gotoxy(30,16);
                printf(B_GREEN "                                            " RESET);
                gotoxy(25,15);
                printf(B_GREEN "                                            " RESET);
                while (getchar() != '\n');
            } else {
                strcpy(correEmpres, ncorreo);
                break;
            }
        }
    } else if (opc == 2) {
        menempres();
    }
}

void menempres(char nombreEmpresa[], int telEmpres, char correEmpres[], float dcaja) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int cont5 = 1, opc6 = 0;
    char op7;

    while (1) {
        //system("cls");
        cempres();
        opcempres(cont5, 35, 10);
        opc6 = _getch();
        if (opc6 == 72 && cont5 > 1) {
            cont5--;
            //SetConsoleTextAttribute(hConsole, 7);
        } else if (opc6 == 80 && cont5 < 3) {
            cont5++;
            //SetConsoleTextAttribute(hConsole, 7);
        } else if (opc6 == 13) {
            if (cont5 == 1) {
                SetConsoleTextAttribute(hConsole, 7);
                EEmpres(nombreEmpresa, telEmpres, correEmpres);
            } else if (cont5 == 2) {
                SetConsoleTextAttribute(hConsole, 7);
                DCaja(&dcaja);
            } else if (cont5 == 3) {
                SetConsoleTextAttribute(hConsole, 7);
                //vmain();
            }
        }
    }
}



int main() {
    char nombreEmpresa[] = "Ferreteria Tumbada", correEmpres[] = "papusexixd@outlook.com", telEmpres[] = "23988";
    float dcaja;
    char nombre[500][20];
    int id[500], piezas[500], nProducto = 0;
    float precio[500];

    dcaja=1000;

    def_menu(nombreEmpresa, telEmpres, correEmpres, dcaja, nombre, id, precio, piezas, &nProducto);
}

