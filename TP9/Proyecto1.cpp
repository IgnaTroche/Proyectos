#include <iostream>
#include <string>

using namespace std;

struct transaction {
    string tipo;
    string producto;
    int cantidad;
    float precio;
    float total;

};

//prototipos de las funciones
  //etapa 1
void registerTransaction (transaction);//etapa 1
void viewTransactions(void);
  //etapa 2
void buscarTransaccion(void);
void actualizarTransaccion(void);
  //etapa 3
void calcularGananciasT(void);
void calcularGananciasP(void);

//variables globales
const int MAX_TRANSACCION = 100;
int cont_transaccion = 0;

//Arreglo en donde ingresamos las transacciones
transaction transacciones [MAX_TRANSACCION];

int main() {
    transaction t;
    int opcion;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Registrar Transaccion" << endl;
        cout << "2. Ver Detalles de las Transacciones" << endl;
        cout << "3. Buscar Transaccion" << endl;
        cout << "4. Actualizar Transaccion" << endl;
        cout << "5. Calcular Ganancias o Pérdidas Totales" << endl;
        cout << "6. Calcular Ganancias o Pérdidas Por Producto" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registerTransaction(t);
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                buscarTransaccion();
                break;
            case 4:
                actualizarTransaccion();
                break;
            case 5:
                calcularGananciasT();
                break;
            case 6:
                calcularGananciasP();
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}

//Definicion de las funciones 
  //Funciones de la etapa 1
void registerTransaction (transaction t){
    cout << "Ingrese el tipo de transaccion (compra/venta): "<<endl;
    cin >> t.tipo;
    while (t.tipo != "compra" && t.tipo != "venta"){
        cout << "Tipo de transaccion invalido. Ingrese 'compra' o 'venta': "<<endl;
        cin >> t.tipo;
    }
    cout << "Ingrese el nombre del producto: "<<endl;
    cin >> t.producto;
    cout << "Ingrese la cantidad comprada/vendida: "<<endl;
    cin >> t.cantidad;
    cout << "Ingrese el precio unitario: "<<endl;
    cin >> t.precio;

    t.total=t.cantidad*t.precio;
    transacciones[cont_transaccion] = t;
    cont_transaccion++;

};

void viewTransactions(){
    for (int i = 0; i < cont_transaccion; i++){
        cout << "Tipo de transaccion: "<< transacciones [i].tipo << endl;
        cout << "Producto: "<< transacciones [i].producto << endl;
        cout << "Cantidad: "<< transacciones [i].cantidad << endl;
        cout << "Precio unitario: "<< transacciones [i].precio << endl;
        cout << "Total: "<< transacciones [i].total << endl;

    }

};

  //Funcionesz de la etapa 2
void buscarTransaccion(){
    string producto;
    cout << "Ingrese el nombre del producto a buscar: "<<endl;
    cin >> producto;
    bool encontrado = false;
    for (int i = 0; i < cont_transaccion; i++){
        if (transacciones [i].producto == producto){
            cout << "Tipo de transaccion: "<< transacciones [i].tipo << endl;
            cout << "Producto: "<< transacciones [i].producto << endl;
            cout << "Cantidad: "<< transacciones [i].cantidad << endl;
            cout << "Precio unitario: "<< transacciones [i].precio << endl;
            cout << "Total: "<< transacciones [i].total << endl;
            encontrado = true;
        }
    }
    if (!encontrado){
        cout << "No se encontraron transacciones para el producto "<< producto << endl;
    }
};

void actualizarTransaccion(){
    string producto;
    if (cont_transaccion == 0){
        cout << "No hay transacciones registradas para actualizar." << endl;
        break;
    }
    cout << "Ingrese el nombre del producto a actualizar: "<<endl;
    cin >> producto;
    bool encontrado = false;
    for (int i = 0; i < cont_transaccion; i++){
        if (transacciones [i].producto == producto){
            cout << "Ingrese el nuevo tipo de transaccion (compra/venta): "<<endl;
            cin >> transacciones [i].tipo;
            while (transacciones [i].tipo != "compra" && transacciones [i].tipo != "venta"){
                cout << "Tipo de transaccion invalido. Ingrese 'compra' o 'venta': "<<endl;
                cin >> transacciones [i].tipo;
            }
            cout << "Ingrese el nuevo nombre del producto: "<<endl;
            cin >> transacciones [i].producto;
            cout << "Ingrese la nueva cantidad comprada/vendida: "<<endl;
            cin >> transacciones [i].cantidad;
            cout << "Ingrese el nuevo precio unitario: "<<endl;
            cin >> transacciones [i].precio;
            transacciones [i].total=transacciones [i].cantidad*transacciones [i].precio;
            cout << "Transaccion actualizada correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado){
        cout << "No se encontro la transaccion para el producto "<< producto << endl;
    }
};

  //Funciones de la etapa 3
void calcularGananciasT(){
    float ganancias = 0;
    float perdidas = 0;
    for (int i = 0; i < cont_transaccion; i++){
        if (transacciones [i].tipo == "compra"){
            perdidas += transacciones [i].total;
        }else{
            ganancias += transacciones [i].total;
        }
    }
    cout << "Ganancias totales: "<< ganancias << endl;
    cout << "Perdidas totales: "<< perdidas << endl;
    float total = ganancias - perdidas;
    if (total > 0){
        cout << "La empresa ha ganado $" << total << endl;
    }else if (total < 0){
        cout << "La empresa ha perdido $" << -total << endl;
    }else{
        cout << "La empresa no ha ganado ni perdido dinero." << endl;
    }
}

//perdida y ganancia por producto
void calcularGananciasP(){
    string producto;
    float ganancias = 0;
    float perdidas = 0;
    cout << "Ingrese el nombre del producto para calcular las ganancias y perdidas: "<<endl;
    cin >> producto;
    bool encontrado = false;
    for (int i = 0; i < cont_transaccion; i++){
        if (transacciones [i].producto == producto){
            if (transacciones [i].tipo == "compra"){
                perdidas += transacciones [i].total;
            }else{
                ganancias += transacciones [i].total;
            }
            encontrado = true;
        }
    }
    if (!encontrado){
        cout << "No se encontro la transaccion para el producto "<< producto << endl;
        return;
    }
    cout << "Ganancias para el producto "<< producto << ": "<< ganancias << endl;
    cout << "Perdidas para el producto "<< producto << ": "<< perdidas << endl;
    float total = ganancias - perdidas;
    if (total > 0){
        cout << "La empresa ha ganado $" << total << " para el producto "<< producto << endl;
    }else if (total < 0){
        cout << "La empresa ha perdido $" << -total << " para el producto "<< producto << endl;
    }else{
        cout << "La empresa no ha ganado ni perdido dinero para el producto "<< producto << endl;
    }
}