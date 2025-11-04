#include <iostream>
#include <string>
using namespace std;

struct Proceso {
  string nombre;
  int Id;
  int prioridad;
  bool estado;
};

struct Nodo {
  Proceso proceso;
  Nodo *siguiente;
  Nodo(Proceso p) {
    proceso = p;
    siguiente = NULL;
  };
};

void insertarNuevoProceso(Nodo *&inicio) {
  string nombre;
  int Id;
  int prioridad;
  bool estado;
  cout << "Ingrese el nombre del proceso: ";
  cin >> nombre;
  cout << "Ingrese el id del proceso: ";
  cin >> Id;
  cout << "Ingrese la prioridad del proceso: ";
  cin >> prioridad;
  cout << "Ingrese el estado del proceso: ";
  cin >> estado;
  cout << "Proceso " << nombre << " añadido" << endl;
  cout << "-------------------------------------" << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Id: " << Id << endl;
  cout << "Prioridad: " << prioridad << endl;
  cout << "Estado: " << estado << endl;

  Proceso proceso = {nombre, Id, prioridad, estado};

  Nodo *nuevoNodo = new Nodo(proceso);
  if (inicio == NULL) {
    inicio = nuevoNodo;
  } else {
    Nodo *temp = inicio;
    while (temp->siguiente != NULL) {
      temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
  }
};

int buscarProcesoPorId(Nodo *inicio, int idProceso) {
  Nodo *temp = inicio;
  int pocision = 0;
  while (temp != NULL) {
    if (temp->proceso.Id == idProceso) {
      return pocision;
    };
    temp = temp->siguiente;
    pocision++;
  };
  return -1;
};

int buscarProcesoPorNombre(Nodo *inicio, string nombreProceso) {

  Nodo *temp = inicio;
  int pocision = 0;
  while (temp != NULL) {
    if (temp->proceso.nombre == nombreProceso) {
      return pocision;
    };
    temp = temp->siguiente;
    pocision++;
  };
  return -1;
};

void buscarProceso(Nodo *inicio) {
  int opcion, idProceso;
  cout << "Desea buscar por id o por nombre?";
  cout << "1. Id";
  cout << "2. Nombre";
  cin >> opcion;

  switch (opcion) {
  case 1: {

    cout << "Ingrese el id del proceso a buscar: ";
    cin >> idProceso;
    int pocision = buscarProcesoPorId(inicio, idProceso);
    cout << "El proceso se encuentra en la pocision: " << pocision;
    if (pocision == -1) {
      cout << "Ese Proceso No Existe" << endl;
    };
    break;
  };
  case 2: {
    string nombreProceso;
    cout << "Ingrese el nombre del proceso a buscar: ";
    cin >> nombreProceso;
    int pocision = buscarProcesoPorNombre(inicio, nombreProceso);
    cout << "El proceso se encuentra en la pocision: " << pocision;
    if (pocision == -1) {
      cout << "Ese Proceso No Existe" << endl;
    };
    break;
  };

  default: {
    cout << "Opcion invalida" << endl;
    int idABuscar = buscarProcesoPorId(inicio, idProceso);
  };
  };
};

void eliminarProceso(Nodo *&inicio) {
  int idProceso;
  cout << "Ingrese el id del proceso a buscar: ";
  cin >> idProceso;
  int pocision = buscarProcesoPorId(inicio, idProceso);
  if (pocision == -1) {
    cout << "Ese Proceso No Existe" << endl;
    return;
  };

  if (inicio == NULL) {
    cout << "No hay procesos en la lista" << endl;
    return;
  };
  if (inicio->proceso.Id == idProceso) {
    Nodo *temp = inicio;
    inicio = inicio->siguiente;
    delete temp;
    cout << "Proceso eliminado" << endl;
    return;
  };

  Nodo *anterior = inicio;
  Nodo *actual = inicio->siguiente;
  while (actual != NULL && actual->proceso.Id != idProceso) {
    anterior = actual;
    actual = actual->siguiente;
  };
  if (actual == NULL) {
    cout << "Proceso no encontrado" << endl;
  } else {
    anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "Proceso eliminado" << endl;
  };
};

void modificarPrioridadProceso(Nodo *inicio, int nuevaPrioridad) {

  int idProceso;
  cout << "Ingrese el id del proceso a buscar: ";
  cin >> idProceso;

  Nodo *temp = inicio;
  int pocision = buscarProcesoPorId(inicio, idProceso);
  if (pocision == -1) {
    cout << "Ese Proceso No Existe" << endl;
  } else {
    for (int i = 0; i < pocision; i++) {
      temp = temp->siguiente;
    }
    temp->proceso.prioridad = nuevaPrioridad;
    cout << "Prioridad del proceso " << temp->proceso.nombre << " modificada a"
         << temp->proceso.prioridad << endl;
  };
};

int main() {
  int op;
  Nodo *listaDeProcesos = NULL;

  do {
    cout << "-----Administrador de archivos----- " << endl;
    cout << "1. Añadir nuevo proceso";
    cout << "2. Eliminar proceso";
    cout << "3. Buscar proceso";
    cout << "4. Modificar prioridad de proceso";
    cin >> op;

    switch (op) {
    case 1:
      insertarNuevoProceso(listaDeProcesos);
      break;
    case 2:
      eliminarProceso(listaDeProcesos);
      break;
    case 3:
      buscarProceso(listaDeProcesos);
      break;
    case 4:
      modificarPrioridadProceso(listaDeProcesos, 1);
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  } while (op != 4);
};
