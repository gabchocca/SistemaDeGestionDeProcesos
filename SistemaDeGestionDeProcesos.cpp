#include <iostream>
#include <string>
using namespace std;

int ID = 0;
struct Tarea {
  int id = ID;
  string nombre;
  string prioridad;
};

struct NodoCola {
  Tarea tarea;
  NodoCola *siguiente;
  NodoCola(Tarea t) {
    tarea = t;
    siguiente = NULL;
  }
};

struct NodoLista {
  Tarea tarea;
  NodoLista *siguiente;
  NodoLista(Tarea t) {
    tarea = t;
    siguiente = NULL;
  };
};

struct NodoTareaAsignada {
  Tarea tarea;
  NodoTareaAsignada *siguiente;
  NodoTareaAsignada(Tarea t) {
    tarea = t;
    siguiente = NULL;
  };
};

struct NodoPila {
  Tarea tarea;
  NodoPila *siguiente;
  NodoPila(Tarea t) {
    tarea = t;
    siguiente = NULL;
  }
};

NodoTareaAsignada *tareasAsignadas = NULL;
string textoTareasCompletadas = "=====================================\n";

// LISTAS  ------------------------------------------------------------
string Prioridades[3] = {"baja", "media", "alta"};

void insertarNuevaTarea(NodoLista *inicio) {
  string nombre;
  string prioridad;
  cout << "Ingrese el nombre de la nueva tarea: ";
  cin >> nombre;
  do {
    cout << "Ingrese la prioridad de la nueva tarea: (baja, media o alta) ";
    cin >> prioridad;
  } while (prioridad != "baja" && prioridad != "media" && prioridad != "alta");
  cout << "Tarea " << nombre << " añadida" << endl;
  cout << "-------------------------------------" << endl;
  cout << "Id: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Prioridad: " << prioridad << endl;

  Tarea nuevaTarea = Tarea();
  nuevaTarea.nombre = nombre;
  nuevaTarea.prioridad = prioridad;

  NodoLista *nuevoNodoLista = new NodoLista(nuevaTarea);
  if (inicio == NULL) {
    inicio = nuevoNodoLista;
  } else {
    NodoLista *temp = inicio;
    while (temp->siguiente != NULL) {
      temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodoLista;
  }

  ID++;
};

void buscarTarea(NodoLista *inicio, string modo = "id") {
  if (modo == "id") {
    int id;
    do {
      cout << "Ingrese el id de la tarea a buscar: ";
      cin >> id;
    } while (id < 0);
    NodoLista *temp = inicio;
    while (temp->siguiente != NULL) {
      if (temp->tarea.id == id) {
        cout << "Tarea encontrada" << endl;
        cout << "Id: " << temp->tarea.id << endl;
        cout << "Nombre: " << temp->tarea.nombre << endl;
        cout << "Prioridad: " << temp->tarea.prioridad << endl;
        return;
      } else
        temp = temp->siguiente;
    };
    cout << "Tarea no encontrada";

  } else if (modo == "prioridad") {
    string prioridad;
    do {
      cout << "Ingrese la prioridad de la tarea a buscar: ";
      cin >> prioridad;
    } while (prioridad != "baja" && prioridad != "media" &&
             prioridad != "alta");

    NodoLista *temp = inicio;
    while (temp->siguiente != NULL) {
      if (temp->tarea.prioridad == prioridad) {
        cout << "Tarea encontrada" << endl;
        cout << "Id: " << temp->tarea.id << endl;
        cout << "Nombre: " << temp->tarea.nombre << endl;
        cout << "Prioridad: " << temp->tarea.prioridad << endl;
        return;
      } else
        temp = temp->siguiente;
    };

    cout << "Tarea no encontrada";

  } else
    cout << "ERROR: Modo de busqueda invalido";
};

// ORDENAMIENTO DE LA LISTA
int valorDePrioridad(string &p) {
  if (p == "alta")
    return 3;
  if (p == "media")
    return 2;
  if (p == "baja")
    return 1;
}
void ordenarTareasPrioritarias(NodoLista *inicio) {
  if (inicio == NULL || inicio->siguiente == NULL)
    return;

  bool cambiado;
  do {
    cambiado = false;
    NodoLista **ptr = &inicio; // puntero doble al nodo actual

    while ((*ptr)->siguiente != NULL) {
      NodoLista *actual = *ptr;
      NodoLista *siguiente = actual->siguiente;

      if (valorDePrioridad(actual->tarea.prioridad) <
          valorDePrioridad(siguiente->tarea.prioridad)) {

        // Intercambiar punteros
        actual->siguiente = siguiente->siguiente;
        siguiente->siguiente = actual;
        *ptr = siguiente;
        cambiado = true;
      }
      ptr = &((*ptr)->siguiente);
    }
  } while (cambiado);
}

void mostrarTareas(NodoLista *inicio) {
  NodoLista *temp = inicio;
  cout << "====Tareas en la lista====" << endl;
  while (temp != NULL) {
    cout << "=========================================" << endl;
    cout << "Id: " << temp->tarea.id << endl;
    cout << "Nombre: " << temp->tarea.nombre << endl;
    cout << "Prioridad: " << temp->tarea.prioridad << endl;
    cout << "=========================================" << endl;
    temp = temp->siguiente;
  }
}
// COLA----------------------------------------------------------------
void encolar(NodoCola *&frente, NodoCola *&fin) {
  string nombre;
  string prioridad;
  cout << "Ingrese el nombre de la nueva tarea: ";
  cin >> nombre;
  do {
    cout << "Ingrese la prioridad de la nueva tarea: (baja, media o alta) ";
    cin >> prioridad;
  } while (prioridad != "baja" && prioridad != "media" && prioridad != "alta");
  cout << "Tarea " << nombre << " añadida a la cola (encolado)" << endl;
  cout << "==========================================" << endl;
  cout << "Id: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Prioridad: " << prioridad << endl;

  Tarea nuevaTarea = Tarea();
  nuevaTarea.nombre = nombre;
  nuevaTarea.prioridad = prioridad;
  NodoCola *nuevoNodo = new NodoCola(nuevaTarea);

  if (frente == NULL) {
    frente = fin;
  } else {
    fin->siguiente = nuevoNodo;
    fin = nuevoNodo;
  }
}

void desencolar(NodoCola *&frente, NodoCola *&fin) {
  if (frente == NULL) {
    cout << "No hay tareas en la cola, no se puede eliminar\n" << endl;
    return;
  }
  NodoCola *temp = frente;

  // asignando tarea a desarollador
  NodoTareaAsignada *nuevoNodoLista = new NodoTareaAsignada(temp->tarea);
  if (tareasAsignadas == NULL) {
    tareasAsignadas = nuevoNodoLista;
  } else {
    NodoTareaAsignada *temporal = tareasAsignadas;
    while (temporal->siguiente != NULL) {
      temporal = temporal->siguiente;
    }
    temporal->siguiente = nuevoNodoLista;
  }
  //
  frente = frente->siguiente;
  cout << "Tarea " << temp->tarea.nombre << " eliminada (desencolada)" << endl;

  if (frente == NULL) {
    fin = NULL;
  };
  delete temp;
}

void mostrarCola(NodoCola *frente) {
  if (frente == NULL) {
    cout << "No hay tareas en la cola\n" << endl;
    return;
  }

  cout << "\n====Tareas en la cola====\n" << endl;
  NodoCola *temp = frente;

  while (temp != NULL) {
    cout << "==================================" << endl;
    cout << "Id: " << temp->tarea.id << endl;
    cout << "Nombre: " << temp->tarea.nombre << endl;
    cout << "Prioridad: " << temp->tarea.prioridad << endl;
    cout << "==================================" << endl;
    temp = temp->siguiente;
  }
}

// PILAS -------------------------------------------------------------

void apilarTarea(NodoPila *&pilaTope) {

  NodoTareaAsignada *temp = tareasAsignadas;
  if (temp == NULL) {
    cout << "No hay tareas asignadas (aun no se ha desencolado)" << endl;
    return;
  } else {
    cout << "===== Tareas en =====" << endl;
    while (temp != NULL) {
      cout << "=========================================" << endl;
      cout << "Id: " << temp->tarea.id << endl;
      cout << "Nombre: " << temp->tarea.nombre << endl;
      cout << "Prioridad: " << temp->tarea.prioridad << endl;
      cout << "=========================================" << endl;
      temp = temp->siguiente;
    }
    int id;
    do {
      cout << "Ingrese el id de la tarea que desee mover a revision: ";
      cin >> id;
    } while (id < 0);

    // nodo anterior, para poder eliminar el nodo de la lista de tareas
    // asignadas
    NodoTareaAsignada *anterior = NULL;

    temp = tareasAsignadas;
    while (temp != NULL) {
      if (temp->tarea.id == id) {
        // codigo de apilacion
        NodoPila *nuevoNodo = new NodoPila(temp->tarea);
        nuevoNodo->siguiente = pilaTope;
        pilaTope = nuevoNodo;
        cout << "Tarea " << temp->tarea.nombre << " movida a revision(pila)"
             << endl;

        // quitando tarea de la lista de tareas asignadas
        if (anterior == NULL)
          tareasAsignadas = temp->siguiente;
        else
          anterior->siguiente = temp->siguiente;
        delete temp;
        return;

      } else {
        anterior = temp;
        temp = temp->siguiente;
      };
    };
    cout << "Tarea no encontrada";
  };
};

void desapilarTarea(NodoPila *&pilaTope) {
  if (pilaTope == NULL) {
    cout << "la pila esta vacia, no hay tareas para desapilar" << endl;
  } else {
    cout << "Desapilando y completando tarea============================"
         << endl;
    NodoPila *temp = pilaTope;
    pilaTope = pilaTope->siguiente;

    textoTareasCompletadas += "Id: " + to_string(temp->tarea.id) +
                              "\n Nombre: " + temp->tarea.nombre +
                              "\n Prioridad: " + temp->tarea.prioridad +
                              "=====================================\n";

    delete temp;
    cout << "Tarea " << temp->tarea.nombre << " desapilada y completada"
         << endl;
  };
};

void mostrarTareasCompletadas(NodoPila *pilaTope) {

  cout << "==================Tareas en revision=========================\n";
  if (pilaTope == NULL) {
    cout << "No hay tareas en revision" << endl;
  };
  NodoPila *temp = pilaTope;
  while (temp != NULL) {
    cout << "=========================================" << endl;
    cout << "Id: " << temp->tarea.id << endl;
    cout << "Nombre: " << temp->tarea.nombre << endl;
    cout << "Prioridad: " << temp->tarea.prioridad << endl;
    cout << "=========================================" << endl;
    temp = temp->siguiente;
  };
  cout << "\n==================Tareas completadas=========================\n";
  cout << textoTareasCompletadas;
};

int main() {
  // Inicializando la lista, cola y pila.
  NodoLista *inicio = NULL;
  NodoCola *frente = NULL;
  NodoCola *fin = NULL;
  NodoPila *pilaTope = NULL;

  do {
    cout << "\n=====Menu de Tareas=====\n";
    cout << "1. Agregar tarea\n";
    cout << "2. Mostrar tareas\n";
    cout << "3. Eliminar tarea\n";
    cout << "4. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      cout << "Ingrese el nombre de la tarea: ";
      getline(cin, nombre);
      cout << "Ingrese la prioridad de la tarea: ";
      getline(cin, prioridad);
      encolar(tareas, id, nombre, prioridad);
      break;
    case 2:
      mostrarCola(tareas);
      break;
    case 3:
      desencolar(tareas);
      break;
    case 4:
      cout << "Saliendo del programa...\n";
      break;
    default:
      cout << "Opcion invalida. Intente de nuevo.\n";
    }
  } while (opcion != 4);

  return 0;
}
