#include "Red.h"
#include <algorithm> // Para std::transform
#include <cctype>    // Para std::toupper

using namespace std;

Red::Red() {}

void Red:: setCargaDatos(int opcion){
    this->cargaDatos = opcion;
}

//Metodo para cargar los datos de la red
void Red:: cargarDatos(){
    //Leo el archivo linea a linea
    string nombreArchivo = "./../../Enrutadores.txt";
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //Enrutadores
    vector<string> nombresEnrutador;
    string linea;
    if(getline(archivo, linea)){
        int posicion = linea.find(';');
        //Leo cada nombre en la linea
        while(posicion != string::npos){
            nombresEnrutador.push_back(linea.substr(0,posicion));
            linea.erase(0, posicion + 1);
            posicion = linea.find(";");
        }
        nombresEnrutador.push_back(linea);
    }
    //Creo el enrutador en la red
    for(string& nombre : nombresEnrutador){
        Enrutador nuevo(nombre);//Objeto de Enrutador
        this->enrutadores.push_back(nuevo);
    }
    //Costos
    int fila = 0;
    while (getline(archivo, linea) && fila < (int)nombresEnrutador.size()){
        int posicion = linea.find(';');
        int columna = 0;
        //Leo cada costo en la fila
        while (posicion != string::npos){
            string costoStr = linea.substr(0, posicion);
            if(columna > 0){
                int costo = stoi(costoStr);
                if(costo > 0){
                    agregarEnlaceLectura(nombresEnrutador[fila], nombresEnrutador[columna - 1], costo);
                }
            }
            linea.erase(0, posicion + 1);
            posicion = linea.find(";");
            columna++;
        }
        fila++;
    }
    archivo.close();
}

void Red:: cargarDatosSimulacion(){
    //Leo el archivo linea a linea del csv
    string nombreArchivo = "./../../simulacion.csv";
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //Enrutadores
    vector<string> nombresEnrutador;
    string linea;
    if(getline(archivo, linea)){
        linea.erase(0, 1);
        int posicion = linea.find(';');
        //Leo cada nombre en la linea
        while(posicion != string::npos){
            nombresEnrutador.push_back(linea.substr(0,posicion));
            linea.erase(0, posicion + 1);
            posicion = linea.find(";");
        }
        nombresEnrutador.push_back(linea);
    }
    //Creo el enrutador en la red
    for(string& nombre : nombresEnrutador){
        Enrutador nuevo(nombre);//Objeto de Enrutador
        this->enrutadores.push_back(nuevo);
    }
    //Costos
    int fila = 0;
    while (getline(archivo, linea) && fila < (int)nombresEnrutador.size()){
        int posicion = linea.find(';');
        int columna = 0;
        //Leo cada costo en la fila
        while (posicion != string::npos){
            string costoStr = linea.substr(0, posicion);
            if(columna > 0){
                int costo = stoi(costoStr);
                if(costo > 0){
                    agregarEnlaceLectura(nombresEnrutador[fila], nombresEnrutador[columna - 1], costo);
                }
            }
            linea.erase(0, posicion + 1);
            posicion = linea.find(";");
            columna++;
        }
        fila++;
    }
    archivo.close();
}

//Metodo para crear o agregar un enalce entre dos enrutadores en la lectura del archivo
void Red:: agregarEnlaceLectura(string enrutador1, string enrutador2, int costo){
    //Referencia a los enrutadores
    Enrutador& routerOrigen = obtenerEnrutador(enrutador1);
    Enrutador& routerDestino = obtenerEnrutador(enrutador2);
    //Actualizo enlaces
    routerOrigen.agregarVecino(enrutador1, enrutador2,costo);
    routerDestino.agregarVecino(enrutador2, enrutador1,costo);
}

//Metodo para agregar un enrutador a la red
void Red:: agregarEnrutador(){
    cout << "\n\n*****AGREGAR ENRUTADOR*****\n\n" << endl;
    string nombre;
    cout << "Ingrese el nombre del nuevo enrutador (Un solo caracter): ";
    cin >> nombre;
    //Verifico que si sea un solo caracter
    while(nombre.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del nuevo enrutador (Un solo caracter): ";
        cin >> nombre;
    }
    nombre[0] = toupper(nombre[0]);
    //Verifico que no exista
    for(const auto& enrutador : enrutadores){
        while(nombre == enrutador.getNombre()){
            cout << "El enrutador " << nombre << " ya existe en la red." << endl;
            cout << "Ingrese el nombre del nuevo enrutador (Un solo caracter): ";
            cin >> nombre;
            while(nombre.length() != 1){
                cout << "El nombre del enrutador debe ser un solo caracter." << endl;
                cout << "Ingrese el nombre del nuevo enrutador (Un solo caracter): ";
                cin >> nombre;
            }
            nombre[0] = toupper(nombre[0]);
        }
    }
    //Si no existe creo el nuevo enrutador
    Enrutador nuevo(nombre);
    //pido las conexiones para cada enrutador en la red
    for(auto& enrutador : enrutadores){
        int costo;
        cout << "Costo de " << nombre << "-" << enrutador.getNombre() << ": ";
        cin >> costo;
        while(costo != -1 && costo < 0){
            cout << "El costo debe ser mayor o igual a cero." << endl;
            cout << "Costo de " << nombre << "-" << enrutador.getNombre() << ": ";
            cin >> costo;
        }
        nuevo.agregarVecino(nombre,enrutador.getNombre(), costo);//Costo nuevo a existente
        enrutador.agregarVecino(enrutador.getNombre(), nombre, costo);//Costo existente a nuevo
    }
    enrutadores.push_back(nuevo);
    //Actualiza la tabla de enrutamiento
    actualizarRed();
    cout << "\n\n******Enrutador " << nombre << " agregado existosamente******\n\n" << endl;
    system("pause");
}

//Metodo para eliminar un enrutador de la red
void Red:: removerEnrutador(){
    cout << "\n\n*****ELIMINAR ENRUTADOR*****\n\n" << endl;
    string nombre;
    cout << "Ingrese el nombre del enrutador que desea eliminar(Un solo caracter): ";
    cin >> nombre;
    //Verifico que si sea un solo caracter
    while(nombre.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador que desea eliminar(Un solo caracter): ";
        cin >> nombre;
    }
    nombre[0] = toupper(nombre[0]);
    //Verifico que exista
    bool existe = false;
    int posicion = 0;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == nombre){
            existe = true;
            posicion = i;
            break;
        }
    }
    if(existe){
        for(auto& enrutador : enrutadores){
            if(enrutador.getNombre() != nombre){
                enrutador.eliminarVecino(nombre);
            }
        }
        enrutadores.erase(enrutadores.begin() + posicion);
        actualizarRed();
        cout << "Enrutador " << nombre << " y sus relaciones eliminados con exito." << endl;
    }
    else{
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        system("pause");
        return;
    }
    system("pause");
}

//Metodo para obtener el nombre de un enrutador
Enrutador& Red:: obtenerEnrutador(const string& enrutador){
    for (auto& router : enrutadores){
        if (router.getNombre() == enrutador){
            return router;
        }
    }
    cout << "Enrutador no encontrado." << endl;
    system("pause");
}

//Metodo para obtener el costo entre dos enrutadores
int Red:: obtenerCosto(const string& enrutador1, const string& enrutador2){
    Enrutador& routerOrigen = obtenerEnrutador(enrutador1);
    return routerOrigen.obtenerCosto(enrutador1,enrutador2);
}

//Metodo para actualizar la red
void Red:: actualizarRed(){
    // Abrir el archivo en modo escritura
    string nombreArchivo;
    if(this->cargaDatos == 1){
        nombreArchivo = "./../../Enrutadores.txt";
    }
    else if (this->cargaDatos == 2){
        nombreArchivo = "./../../simulacion.csv";
    }
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //Nombres de los enrutadores
    for (int i = 0; i < (int)enrutadores.size(); i++) {
        archivo << enrutadores[i].getNombre();
        if (i < (int)enrutadores.size() - 1) archivo << ";";
    }
    archivo << endl;
    //Costos
    for (int i = 0; i < (int)enrutadores.size(); i++) {
        // Escribir el nombre del enrutador en la primera columna
        archivo << enrutadores[i].getNombre() << ";";
        for (int j = 0; j < (int)enrutadores.size(); j++) {
            int costo;
            if (i == j){
                costo = 0;
            }
            else{
                costo = obtenerCosto(string(1,enrutadores[i].getNombre()[0]), string(1,enrutadores[j].getNombre()[0]));
            }
            archivo << costo;
            //Punto y coma entre valores excepto al final de la fila
            if (j < (int)enrutadores.size() - 1) archivo << ";";
        }
        archivo << endl;
    }
    archivo.close();
}

//Metodo para agregar enlace
void Red:: agregarEnlaces(){
    cout << "\n\n*****AGREGAR DE ENLACE*****\n\n" << endl;
    string enrutador1, enrutador2;
    int costo;
    cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
    cin >> enrutador1;
    //Verifico que si sea un solo caracter
    while(enrutador1.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> enrutador1;
    }
    enrutador1[0] = toupper(enrutador1[0]);

    //Verifico que exista
    bool existe1 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == enrutador1){
            existe1 = true;
            break;
        }
    }
    while(!existe1){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> enrutador1;
        //Verifico que si sea un solo caracter
        while(enrutador1.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
            cin >> enrutador1;
        }
        enrutador1[0] = toupper(enrutador1[0]);

        //Verifico que exista
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == enrutador1){
                existe1 = true;
                break;
            }
        }
    }

    cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
    cin >> enrutador2;
    //Verifico que si sea un solo caracter
    while(enrutador2.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> enrutador2;
    }
    enrutador2[0] = toupper(enrutador2[0]);

    //Verifico que exista
    bool existe2 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == enrutador1){
            existe2 = true;
            break;
        }
    }
    while(!existe2){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> enrutador2;
        //Verifico que si sea un solo caracter
        while(enrutador2.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador destino (Un solo caracer): ";
            cin >> enrutador2;
        }
        enrutador2[0] = toupper(enrutador2[0]);

        //Verifico que exista
        existe2 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == enrutador1){
                existe2 = true;
                break;
            }
        }
    }

    cout << "Ingrese el costo de " << enrutador1 << "-" << enrutador2 << ": ";
    cin >> costo;
    while(costo != -1 && costo < 0){
        cout << "El costo debe ser mayor o igual a cero." << endl;
        cout << "Ingrese el costo de " << enrutador1 << "-" << enrutador2 << ": ";
        cin >> costo;
    }
    //Referencia a los enrutadores
    Enrutador& routerOrigen = obtenerEnrutador(enrutador1);
    Enrutador& routerDestino = obtenerEnrutador(enrutador2);
    //Actualizo enlaces
    routerOrigen.agregarVecino(enrutador1, enrutador2, costo);
    routerDestino.agregarVecino(enrutador2, enrutador1, costo);
    cout << "\n\nEnlace agregado existosamente.\n\n" << endl;
    actualizarRed();            //Actualizo la tabla de enrutamiento
    system("pause");
}

//Metodo para eliminar enlace
void Red:: eliminarEnlacesRed(){
    cout << "\n\n*****ELIMINAR DE ENLACE*****\n\n" << endl;
    string enrutador1, enrutador2;
    cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
    cin >> enrutador1;
    //Verifico que si sea un solo caracter
    while(enrutador1.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> enrutador1;
    }
    enrutador1[0] = toupper(enrutador1[0]);

    //Verifico que exista
    bool existe1 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == enrutador1){
            existe1 = true;
            break;
        }
    }
    while(!existe1){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> enrutador1;
        //Verifico que si sea un solo caracter
        while(enrutador1.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
            cin >> enrutador1;
        }
        enrutador1[0] = toupper(enrutador1[0]);

        //Verifico que exista
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == enrutador1){
                existe1 = true;
                break;
            }
        }
    }

    cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
    cin >> enrutador2;
    //Verifico que si sea un solo caracter
    while(enrutador2.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> enrutador2;
    }
    enrutador2[0] = toupper(enrutador2[0]);

    //Verifico que exista
    bool existe2 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == enrutador1){
            existe2 = true;
            break;
        }
    }
    while(!existe2){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> enrutador2;
        //Verifico que si sea un solo caracter
        while(enrutador2.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador destino (Un solo caracer): ";
            cin >> enrutador2;
        }
        enrutador2[0] = toupper(enrutador2[0]);

        //Verifico que exista
        existe2 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == enrutador1){
                existe2 = true;
                break;
            }
        }
    }
    //Referencia a los enrutadores
    Enrutador& routerOrigen = obtenerEnrutador(enrutador1);
    Enrutador& routerDestino = obtenerEnrutador(enrutador2);

    //elimina enlaces
    routerOrigen.eliminarEnlaceEnrutador(enrutador1, enrutador2);
    routerDestino.eliminarEnlaceEnrutador(enrutador2, enrutador1);

    cout << "\n\nEnlace eliminado existosamente.\n\n" << endl;
    actualizarRed();            //Actualizo la tabla de enrutamiento
    system("pause");
}

//Metodo para mostrar la tabla de enrutamiento
void Red:: mostrarRed(){
    cout << "\n\n*****TABLA DE ENRUTAMIENTO*****\n\n" << endl;
    for(auto& enrutador : enrutadores){
        enrutador.mostrarTabla();
    }
    system("pause");
}

//Metodo para calcular el costo de un enrutador a otro
void Red:: calcularCosto(){
    cout << "*****CALCULO DE COSTOS DE ENVIO*****" << endl;
    string origen, destino;
    cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
    cin >> origen;
    //Verifico que si sea un solo caracter
    while(origen.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> origen;
    }
    origen[0] = toupper(origen[0]);
    //Verifico que exista
    bool existe1 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == origen){
            existe1 = true;
            break;
        }
    }
    while(!existe1){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> origen;
        //Verifico que si sea un solo caracter
        while(origen.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
            cin >> origen;
        }
        origen[0] = toupper(origen[0]);
        //Verifico que exista
        existe1 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == origen){
                existe1 = true;
                break;
            }
        }
    }


    cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
    cin >> destino;
    //Verifico que si sea un solo caracter
    while(destino.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> destino;
    }
    destino[0] = toupper(destino[0]);
    //Verifico que exista
    bool existe2 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == destino){
            existe2 = true;
            break;
        }
    }
    while(!existe2){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> destino;
        //Verifico que si sea un solo caracter
        while(destino.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
            cin >> destino;
        }
        destino[0] = toupper(destino[0]);
        //Verifico que exista
        existe2 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == destino){
                existe2 = true;
                break;
            }
        }
    }

    //Si son iguales
    if(origen == destino){
        cout << "Origen y destino son iguales no hay costo para enviar el paquete." << endl;
        system("pause");
        return;
    }
    //Obtengo el costo
    int costo = obtenerCosto(origen, destino);
    if (costo == 0){
        cout << "No existe una ruta directa entre " << origen << " y " << destino << endl;
        cout << "Puede dirigirse a la seccion de calcular la mejor ruta." << endl;
    }
    else{
        cout << "Costo de " << origen << "-" << destino << ": " << costo << endl;
    }
    system("pause");
}

//Metodo para calcular la mejor ruta para enviar un paquete
void Red:: calcularRuta(){
    cout << "*****MEJOR RUTA DE ENVIO*****" << endl;
    string origen, destino;
    cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
    cin >> origen;
    //Verifico que si sea un solo caracter
    while(origen.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> origen;
    }
    origen[0] = toupper(origen[0]);
    //Verifico que exista
    bool existe1 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == origen){
            existe1 = true;
            break;
        }
    }
    while(!existe1){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
        cin >> origen;
        //Verifico que si sea un solo caracter
        while(origen.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador origen (Un solo caracter): ";
            cin >> origen;
        }
        origen[0] = toupper(origen[0]);
        //Verifico que exista
        existe1 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == origen){
                existe1 = true;
                break;
            }
        }
    }


    cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
    cin >> destino;
    //Verifico que si sea un solo caracter
    while(destino.length() != 1){
        cout << "El nombre del enrutador debe ser un solo caracter." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> destino;
    }
    destino[0] = toupper(destino[0]);
    //Verifico que exista
    bool existe2 = false;
    for(int i = 0; i < (int)enrutadores.size(); i++){
        if(enrutadores[i].getNombre() == destino){
            existe2 = true;
            break;
        }
    }
    while(!existe2){
        cout << "El enrutador no se encuentra registrado en la red." << endl;
        cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
        cin >> destino;
        //Verifico que si sea un solo caracter
        while(destino.length() != 1){
            cout << "El nombre del enrutador debe ser un solo caracter." << endl;
            cout << "Ingrese el nombre del enrutador destino (Un solo caracter): ";
            cin >> destino;
        }
        destino[0] = toupper(destino[0]);
        //Verifico que exista
        existe2 = false;
        for(int i = 0; i < (int)enrutadores.size(); i++){
            if(enrutadores[i].getNombre() == destino){
                existe2 = true;
                break;
            }
        }
    }

    string ruta;
    map<string,int> costoMinimo;
    map<string, string> anterior;
    vector<string> enrutadoresCalculados;

    for(const auto& enrutador : enrutadores){
        costoMinimo[enrutador.getNombre()] = 999999;//No se ha encontrado costo minimo
    }
    costoMinimo[origen] = 0;//Costo a si mismo
    enrutadoresCalculados.push_back(origen);
    while (!enrutadoresCalculados.empty()){
        string actual = enrutadoresCalculados[0];
        for (const string& enrutador : enrutadoresCalculados) {
            if (costoMinimo[enrutador] < costoMinimo[actual]) {
                actual = enrutador; //Actualizar el enrutador con el costo minimo
            }
        }
        //Eliminar el enrutador con el costo minimo de la lista
        enrutadoresCalculados.erase(remove(enrutadoresCalculados.begin(), enrutadoresCalculados.end(), actual), enrutadoresCalculados.end());

        //LLega al destino
        if (actual == destino){
            break;
        }
        // Obtener las rutas del enrutador actual
        Enrutador& enrutadorActual = obtenerEnrutador(actual);
        map<string,map<string, int>> rutas = enrutadorActual.getRutas();

        //Explorar los vecinos
        for (const auto& vecino : rutas[actual]) {
            const string& vecinoNombre = vecino.first;
            int costo = vecino.second;

            //Calcular el nuevo costo hasta el vecino
            int nuevoCosto = costoMinimo[actual] + costo;

            //Si encuentro un costo menor, actualizar
            if (nuevoCosto < costoMinimo[vecinoNombre]) {
                costoMinimo[vecinoNombre] = nuevoCosto;
                anterior[vecinoNombre] = actual; //Guardar el anterior
                //Añadir el vecino a la lista de enrutadores calculados
                if (find(enrutadoresCalculados.begin(), enrutadoresCalculados.end(), vecinoNombre) == enrutadoresCalculados.end()) {
                    enrutadoresCalculados.push_back(vecinoNombre);
                }
            }
        }
    }

    //Reconstruir la ruta
    ruta.clear();
    string paso = destino;
    while (anterior.find(paso) != anterior.end()) {
        ruta = paso + " -> " + ruta; //Añadir el enrutador al principio de la ruta
        paso = anterior[paso]; // Mover al anterior
    }
    ruta = origen + " -> " + ruta + destino; //Añadir el origen al principio
    //Muestro el resultado
    if(costoMinimo[destino] == 999999){
        cout << "No existe una relacion entre " << origen << " y " << destino << endl;
    }
    else
    {
        cout << "La mejor ruta de " << origen << "-" << destino << ": " << ruta << endl;
        cout << "Costo: " << costoMinimo[destino] << endl;
    }
    system("pause");
}

//Metodo para generar una red
void Red:: generarRedAleatoria(){
    string nombres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(static_cast<unsigned>(time(0)));
    int cantEnrutadores = 1 + rand() % nombres.size();
    string enrutadores[cantEnrutadores];
    for (int i = 0; i < cantEnrutadores; ++i) {
        enrutadores[i] = nombres[i];
    }
    int costoAleatorio;
    int contNull = 0;;
    int enlaces[cantEnrutadores][cantEnrutadores];
    for (int i = 0; i < cantEnrutadores; ++i) {
        for (int j = 0; j < cantEnrutadores; ++j) {
            if(j == i){enlaces[i][j] = 0;}
            else if (contNull%4 == 0){enlaces[i][j] = -1;}
            else{
                costoAleatorio = 1 + rand() % 30;
                enlaces[i][j] = costoAleatorio;
            }
            contNull++;
        }
    }

    // Abrir el archivo en modo escritura
    string nombreArchivo = "./../../simulacion.csv";
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //Nombres de los enrutadores
    for (int i = 0; i < cantEnrutadores; i++) {
        if(i == 0){archivo<<";";}
        archivo << enrutadores[i];
        if (i < cantEnrutadores - 1){archivo << ";";}
    }
    archivo << endl;
    //Costos
    for (int i = 0; i < cantEnrutadores; i++) {
        // Escribir el nombre del enrutador en la primera columna
        archivo << enrutadores[i] << ";";
        for (int j = 0; j < cantEnrutadores; j++) {
            archivo << enlaces[i][j];
            //Punto y coma entre valores excepto al final de la fila
            if (j < cantEnrutadores - 1) archivo << ";";
        }
        archivo << endl;
    }
    archivo.close();

    cout<<"\n\n*****La nueva red ha sido guardada en el archivo simulacion.txt del directorio del proyecto*****\n\n";
    system("pause");
}




