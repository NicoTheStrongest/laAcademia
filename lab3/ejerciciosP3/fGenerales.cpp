#include <iostream>
#include <fGenerales.h>
#include <fstream>
#include <string>
#include <bitset>
#include <random>
#include <cstdlib> // Para srand() y rand()
#include <cctype> //para el toupper

using namespace std;

void desencriptar(string**& arreglo, int* size, int* semillaMain){
    //Desencripta el archivo del binario y lo guarda en la estructura dinamica.
    string nombreArchivo = "./../../sudo.txt";
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    int indice = 0;
    string contenido;
    string linea;
    int semilla;
    bool banderaLinea1 = true;

    while (getline(archivo, linea)){
        string lineaDesencriptada = "";
        if (banderaLinea1){
            contenido = linea;
            bitset<8> bits(contenido); //guarda en binario cada caracter
            semilla = static_cast<int>(bits.to_ulong()); //convierte a int el binario
            *semillaMain = semilla;
            banderaLinea1 = false;
        }
        else {
            if (indice >= *size){
                expandirArreglo(arreglo, *size); // aumenta la memoria cuando se exceden las 10 lineas.
            }
            contenido = linea;
            bool banderaBloque1 = true;
            int cont0Anterior, cont1Anterior;
            for (int i = 0; i < (int)linea.size(); i += semilla) {
                string bloque = "";
                int cont0 = 0, cont1 = 0;
                for (int j = i; j < i+semilla; ++j) {
                    //if(contenido[j] == '0'){cont0++;}
                    //if(contenido[j] == '1'){cont1++;}
                    bloque += contenido[j];
                }
                if (banderaBloque1){
                    for (int i = 0; i < semilla; ++i) {
                        if (bloque[i] == '1'){bloque[i]='0'; cont0++;}
                        else if (bloque[i] == '0'){bloque[i]='1'; cont1++;}
                    }
                    lineaDesencriptada += bloque;
                    cont0Anterior = cont0; cont1Anterior = cont1;
                    banderaBloque1 = false;
                }
                //aca ya tenemos el bloque para aplicar las reglas de encriptacion
                else if (cont0Anterior == cont1Anterior){
                    for (int i = 0; i < semilla; ++i) {
                        if (bloque[i] == '1'){bloque[i]='0';cont0++;}
                        else if (bloque[i] == '0'){bloque[i]='1'; cont1++;}
                    }
                    lineaDesencriptada += bloque;
                    cont0Anterior = cont0; cont1Anterior = cont1;
                }
                else if(cont0Anterior > cont1Anterior){

                    for (int i = 1; i < semilla; i+=2) {
                        if (bloque[i] == '1'){bloque[i]='0'; cont0++;}
                        else if (bloque[i] == '0'){bloque[i]='1'; cont1++;}
                        if (bloque[i-1] == '0'){cont0++;}
                        else if (bloque[i-1] == '1'){cont1++;}
                    }
                    lineaDesencriptada += bloque;
                    cont0Anterior = cont0; cont1Anterior = cont1;
                }
                else if (cont1Anterior > cont0Anterior){
                    /*
                    for (int i = 1; i < semilla; i+=2) {
                        if (bloque[i] == '1'){bloque[i]='0'; cont0++;}
                        else if (bloque[i] == '0'){bloque[i]='1';}
                    }
                    */
                    for (int i = 2; i < semilla; i += 3) {
                        if (bloque[i] == '1'){bloque[i]='0';}
                        else if (bloque[i] == '0'){bloque[i]='1';}
                    }
                    for (int i = 0; i < semilla; ++i) {
                        if (bloque[i] == '0'){cont0++;}
                        else if (bloque[i] == '1'){cont1++;}
                    }
                    lineaDesencriptada += bloque;
                    cont0Anterior = cont0; cont1Anterior = cont1;
                }
            }
        }
        //acá ya puedo trabajar sobre la linea desencriptada
        if (lineaDesencriptada != ""){
            string lineaCaracteres = "";
            for (int i = 0; i < (int)lineaDesencriptada.size(); i+=8) {
                string ascii = "";
                for (int j = i; j < i+8; ++j) {
                    ascii += lineaDesencriptada[j];
                }
                bitset<8> bits(ascii);  // Convertir a bitset de 8 bits
                char caracterASCII = static_cast<char>(bits.to_ulong());
                lineaCaracteres += caracterASCII;
            }
            string posicion = "";
            int contPosicion = 0;
            for (int i = 1; i < ((int)lineaCaracteres.size()-1); ++i) {
                if (lineaCaracteres[i] == ';'){
                    arreglo[indice][contPosicion] = posicion; // agrega las posiciones del arreglo
                    contPosicion++;
                    posicion = "";
                }
                else{posicion += lineaCaracteres[i];}
            }
            if (posicion != ""){arreglo[indice][contPosicion] = posicion;} // agrega la ultima posicion del arreglo
            indice++;
        }
    }
    archivo.close();
    return;
}

void encriptar(string**& arreglo, int* size, int* semilla){
    string nombreArchivo = "./../../sudo.txt";
    fstream archivo;
    archivo.open(nombreArchivo, ios::out | ios::trunc);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    //agregar semilla
    string writeSemilla;
    bitset<8> bits(*semilla);
    writeSemilla = bits.to_string();
    archivo << writeSemilla << endl;

    for (int i = 0; i < (*size); ++i) {
        string linea = "<";
        for (int j = 0; j < 4; ++j) {
            linea += arreglo[i][j] + ";";
        }
        linea += ">";
        string binarios = "";
        for (int j2 = 0; j2 < (int)linea.size(); j2++){
            bitset<8> bits(linea[j2]);
            binarios += bits.to_string();
        }
        bool banderaBloque1 = true;
        int cont0Anterior, cont1Anterior;
        string lineaEncriptada = "";
        for (int i2 = 0; i2 < (int)binarios.size(); i2 += *semilla) {
            string bloque = "";
            int cont0 = 0, cont1 = 0;
            for (int j = i2; j < i2+(*semilla); ++j) {
                if(binarios[j] == '0'){cont0++;}
                if(binarios[j] == '1'){cont1++;}
                bloque += binarios[j];
            }
            if (banderaBloque1){
                for (int j = 0; j < (*semilla); ++j) {
                    if (bloque[j] == '1'){bloque[j]='0';}
                    else if (bloque[j] == '0'){bloque[j]='1';}
                }
                lineaEncriptada += bloque;
                cont0Anterior = cont0; cont1Anterior = cont1;
                banderaBloque1 = false;
            }
            //aca ya tenemos el bloque para aplicar las reglas de encriptacion
            else if (cont0Anterior == cont1Anterior){
                for (int j = 0; j < (*semilla); ++j) {
                    if (bloque[j] == '1'){bloque[j]='0';}
                    else if (bloque[j] == '0'){bloque[j]='1';}
                }
                lineaEncriptada += bloque;
                cont0Anterior = cont0; cont1Anterior = cont1;
            }
            else if(cont0Anterior > cont1Anterior){
                for (int j = 1; j < (*semilla); j+=2) {
                    if (bloque[j] == '1'){bloque[j]='0';}
                    else if (bloque[j] == '0'){bloque[j]='1';}
                }
                lineaEncriptada += bloque;
                cont0Anterior = cont0; cont1Anterior = cont1;
            }
            else if (cont1Anterior > cont0Anterior){
                for (int j = 2; j < (*semilla); j += 3) {
                    if (bloque[j] == '1'){bloque[j]='0';}
                    else if (bloque[j] == '0'){bloque[j]='1';}
                }
                lineaEncriptada += bloque;
                cont0Anterior = cont0; cont1Anterior = cont1;
            }
        }
        archivo << lineaEncriptada << endl;
    }
    // -----------------------------------------------------
    /*
    string cadena = "AbCd";
    string binarios = "";
    for (int i = 0; i < (int)cadena.size(); i++){
        bitset<8> bits(cadena[i]);
        binarios += bits.to_string();
    }
    bool banderaBloque1 = true;
    int cont0Anterior, cont1Anterior;
    string lineaEncriptada = "";
    for (int i = 0; i < (int)binarios.size(); i += *semilla) {
        string bloque = "";
        int cont0 = 0, cont1 = 0;
        for (int j = i; j < i+(*semilla); ++j) {
            if(binarios[j] == '0'){cont0++;}
            if(binarios[j] == '1'){cont1++;}
            bloque += binarios[j];
        }
        if (banderaBloque1){
            for (int i = 0; i < (*semilla); ++i) {
                if (bloque[i] == '1'){bloque[i]='0';}
                else if (bloque[i] == '0'){bloque[i]='1';}
            }
            lineaEncriptada += bloque;
            cont0Anterior = cont0; cont1Anterior = cont1;
            banderaBloque1 = false;
        }
        //aca ya tenemos el bloque para aplicar las reglas de encriptacion
        else if (cont0Anterior == cont1Anterior){
            for (int i = 0; i < (*semilla); ++i) {
                if (bloque[i] == '1'){bloque[i]='0';}
                else if (bloque[i] == '0'){bloque[i]='1';}
            }
            lineaEncriptada += bloque;
            cont0Anterior = cont0; cont1Anterior = cont1;
        }
        else if(cont0Anterior > cont1Anterior){
            for (int i = 1; i < (*semilla); i+=2) {
                if (bloque[i] == '1'){bloque[i]='0';}
                else if (bloque[i] == '0'){bloque[i]='1';}
            }
            lineaEncriptada += bloque;
            cont0Anterior = cont0; cont1Anterior = cont1;
        }
        else if (cont1Anterior > cont0Anterior){
            for (int i = 2; i < (*semilla); i += 3) {
                if (bloque[i] == '1'){bloque[i]='0';}
                else if (bloque[i] == '0'){bloque[i]='1';}
            }
            for (int i = 1; i < semilla; i+=2) {
                if (bloque[i] == '1'){bloque[i]='0';}
                else if (bloque[i] == '0'){bloque[i]='1';}
            }
            lineaEncriptada += bloque;
            cont0Anterior = cont0; cont1Anterior = cont1;
        }
    }
    cout<<lineaEncriptada<<endl;
    */
}



void expandirArreglo(string**& arr, int& size) {
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    string** nuevoArr = new string*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new string[4];
    }

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            nuevoArr[i][j] = arr[i][j];
        }
    }

    // Liberar la memoria del arreglo original
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    // Actualizar el puntero para que apunte al nuevo arreglo
    arr = nuevoArr;

    // Aumentar el tamaño
    size += 1;
}

void menuGeneral(const string& fileName) {
    // Función que abre un archivo, lo imprime y lo cierra
    ifstream archivo(fileName);

    // Comprobar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
        return;
    }

    // Leer el archivo línea por línea y mostrar el contenido
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    // Cerrar el archivo
    archivo.close();
}

int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size) {
    string opcion;
    // Bucle infinito hasta que se reciba una opción válida
    while (true) {
        cout << mensaje1;
        cin >> opcion;
        // Verificar si la opción ingresada está en el arreglo de opciones válidas
        bool esValida = false;
        for (int i = 0; i < size; ++i) {
            if (opcionesValidas[i] == opcion) {
                esValida = true;
                break;
            }
        }
        // Si la opción es válida, convertirla a entero y retornarla
        if (esValida) {
            return stoi(opcion);  // Convertir la opción válida a entero y retornarla
        } else {
            cout << mensaje2 << endl;  // Mensaje de opción incorrecta
        }
    }
}



bool menuSalida(){
    //muestra menu salida y devulve false si quiere salir y true si quiere ir al menu unicial
    limpiarPantalla();
    string nombre = "./../../prints/MenuSalida.txt";
    menuGeneral(nombre);
    string mensaje1 = "Elige una opcion (1, 2): ";
    string mensaje2 = "Opcion no valida, intenta de nuevo.";
    const int size = 2;
    string opcionesValidas[size] = {"1", "2"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    if(opcionElegida == 1){return false;}
    else if (opcionElegida == 2){return true;}
}

void agregarUsuario(string**& arreglo, int* size){
    limpiarPantalla();
    string nombre = "./../../prints/MenuAdministrador.txt";
    menuGeneral(nombre);
    string documento;
    cout<<"\nDocumento: ";
    getline(cin, documento);
    formatoDocumento(&documento);
    string clave;
    cout<<"\nClave (Si contine algun espacio se lo quito): ";
    getline(cin, clave);
    clave = quitarEspacios(clave);
    string saldo;
    cout<<"\nSaldo Inicial (solo numeros): $";
    getline(cin, saldo);
    validarSaldo(&saldo);
    int role;
    cout<<"\nElija un rol\n - Administrador -> 1 \n - Usuario -> 2\nRol : ";
    cin>>role;
    string rol;
    rol = validarRol(role);
    expandirArreglo(arreglo, *size);
    arreglo[*size-1][0] = documento;
    arreglo[*size-1][1] = clave;
    arreglo[*size-1][2] = saldo;
    arreglo[*size-1][3] = rol;
}

int iniciarSesion(string** arreglo, int size, string* docUsuario){
    //inicia sesion como usuario o administrador.
    limpiarPantalla();
    string nombre = "./../../prints/MenuPrincipal.txt";
    menuGeneral(nombre);
    int rol;
    int* ptrRol = &rol;
    string documento;
    cout<<"Documento: ";
    getline(cin, documento);
    if (documento != "0"){
        //validar formato documento
        bool documentoSi = validarDocumento(arreglo, size, documento);
        while (documentoSi == false){
            cout<<"Documento no registrado.\n";
            cout<<"Documento: ";
            getline(cin, documento);
            documentoSi = validarDocumento(arreglo, size, documento);
        }
        //Validar Contraseña registrada.
        string contrasena;
        cout<<"Contrasena: ";
        getline(cin, contrasena);
        bool contra = validarContrasena(arreglo, size, documento, contrasena, ptrRol);
        if(contra){
            *docUsuario = documento;
            return rol;
        }
        else{return 0;}
    }
    return 0;
}

bool validarContrasena(string** arreglo, int size, string documento, string contrasena, int* rol){
    //valida que la contrasena sea la registrada.
    for (int i = 0; i < size; ++i) {
        if(arreglo[i][0] == documento){
            if(contrasena == arreglo[i][1]){
                if(arreglo[i][3] == "Administrador"){*rol = 1;}
                if(arreglo[i][3] == "Usuario"){*rol = 2;}
                return true;
            }
            else{
                int a;
                limpiarPantalla();
                cout<<"\nContrasena incorrecta rufian\n";
                cout<<"\nIngrese un numero para continuar\n";
                cin>>a;
                return false;
            }
        }
    }
    return false;
}

bool validarDocumento(string** arreglo, int size, string documento){
    //validar que solo el documento esté registrado.
    for (int i = 0; i < size; ++i) {
        if(arreglo[i][0] == documento){
            return true;}
    }
    return false;
}

int menuUsuario(){
    //imprimer el menu de usuario y retorna un int relacionado a la actividiad para realizar
    limpiarPantalla();
    string nombre = "./../../prints/MenuUsuario.txt";
    menuGeneral(nombre);
    string mensaje1 = "Elige una opcion (1, 2, 0): ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";

    // Opciones válidas en un arreglo
    const int size = 3;
    string opcionesValidas[size] = {"1", "2", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

void retirarDinero(string** arreglo, int size, string documento){
    //Retira dinero especifico del documento actual y actualiza su saldo.
    limpiarPantalla();
    int retiro;
    cout<<"Cuanto dinero desea retirar: ";
    cin>>retiro;
    for (int i = 0; i < size; ++i) {
        if(arreglo[i][0] == documento){
            int saldoActual = stoi(arreglo[i][2]);
            if (retiro>saldoActual){cout<<"No se pudo realizar el retiro\n"; return;}
            else{
                saldoActual = saldoActual - retiro - 1000;
                arreglo[i][2] = to_string(saldoActual);
                return;
            }
        }
    }
}

void consultarSaldo(string** arreglo, int size, string documento, bool descontar){
    //muestra saldo de la persona ingresada.
    limpiarPantalla();
    for (int i = 0; i < size; ++i) {
        if(arreglo[i][0] == documento){
            int saldo = stoi(arreglo[i][2]);
            if (saldo<-5000){cout<<"\nNo se puede realizar consulta (saldo inferio a -5000)\n";}
            else {
                cout<<"Su saldo actual es: "<<arreglo[i][2]<<endl;
                if (descontar == true){
                    saldo = saldo - 1000;
                    arreglo[i][2] = to_string(saldo);
                    int a;
                    cout<<"Presione 1 para continuar: ";
                    cin>>a;
                }
            }
            break;
        }
    }
}

void mensajeSalida(){
    //Imprime el mensaje cuando sale del programa.
    limpiarPantalla();
    string nombre = "./../../prints/MensajeSalida.txt";
    menuGeneral(nombre);
}



void limpiarPantalla(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}

int pedirNumEntero(){
    int numero;
    while (!(std::cin >> numero)) {
        // Si la entrada no es un número, std::cin entra en un estado de error
        std::cin.clear(); // Limpia el estado de error de std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada inválida
        std::cout << "Entrada no valida. Por favor, ingresa un numero entero: ";
    }
    return numero;
}

bool validarNumeros(string cadena){
    //valida que una cadena solo contenga numeros
    for (int i = 0; i < (int)cadena.size(); ++i) {
        if (!(cadena[i]>=48  && cadena[i]<=57)){return false;}
    }
    return true;
}

void formatoDocumento(string* documento){
    //Valida que una cadena solo tengo numero y que tengo size 10;
    string documento2;
    bool docValido = validarNumeros(*documento);
    if ((int)(*documento).size() != 10){docValido = false;}
    while (docValido == false){
        cout<<"Documento Invalido\n";
        cout<<"Documento: ";
        getline(cin, documento2);
        docValido = validarNumeros(documento2);
        if ((int)documento2.size() != 10){docValido = false;}
        if (docValido == true){*documento = documento2;}
    }
}

string quitarEspacios(string cadena){
    //Toma una cadena de string y si tiene espacios se los quita y retorna la cadena sin espacios
    string cadenaClear = "";
    int tamano;
    tamano = cadena.size();
    for (int i = 0; i < tamano; ++i) {
        if (cadena[i]==' '){
            cadenaClear = cadenaClear;
        }
        else {
            cadenaClear = cadenaClear + cadena[i];
        }
    }
    return cadenaClear;
}

void validarSaldo(string *saldo){
    bool saldoOk = validarNumeros(*saldo);
    string saldo2;
    while(saldoOk == false){
        cout<<"Saldo Inicial (solo numeros): $";
        getline(cin, saldo2);
        saldoOk = validarNumeros(saldo2);
        if (saldoOk == true){*saldo = saldo2;}
    }
}

string validarRol(int rol){
    //valida que el rol sea 1 O 2.
    bool rolOk = false;
    string rolVerdadero;
    int rol2;
    if(rol == 1){return rolVerdadero = "Administrador";}
    if(rol == 2){return rolVerdadero = "Usuario";}
    while (rolOk == false){
        cout<<"\nElija un rol\n - 1 -> Administrador\n - 2 -> Usuario\nRol : ";
        cin>>rol2;
        if(rol2 == 1){return rolVerdadero = "Administrador";}
        if(rol2 == 2){return rolVerdadero = "Usuario";}
    }
}























//                          FUNCIONES DEL PROFESOR



void escribirArchivo(string nombreArchivo, string texto, bool limpiar = false){
    fstream archivo;
    if (limpiar){ // Si limpiar es verdadero, se sobreescribe el archivo
        archivo.open(nombreArchivo, ios::out | ios::trunc); // trunc para borrar y escribir
    }
    else{ // Si limpiar es falso, se agrega contenido al final del archivo
        archivo.open(nombreArchivo, ios::out | ios::app); // app para agregar en la ultima linea
    }

    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo << texto << endl;
    archivo.close();
}

string leerArchivoPorLinea(string nombreArchivo){
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    string linea;
    while (getline(archivo, linea)){
        contenido += linea + "\n";
    }
    archivo.close();

    return contenido;
}

string leerArchivoPorCaracter(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    char c;
    while (archivo.get(c)){
        contenido += c;
    }
    cout<<contenido;
    archivo.close();

    return contenido;
}

string char2binario(string nombreArchivo){
    //convierte el texto de un archivo en binario.
    ifstream archivo;
    try{
        archivo.open(nombreArchivo);
        if (!archivo.is_open())
        {
            cout << "Error al abrir el archivo\n";
            return "";
        }
    }
    catch (const std::exception &e){
        cerr << e.what() << '\n';
    }

    char caracter;
    string str_binario;

    while (archivo.get(caracter)){
        bitset<8> binario(caracter); //guarda en binario cada caracter
        str_binario += binario.to_string(); //convierte a string el binario
    }
    archivo.close();

    return str_binario;
}















