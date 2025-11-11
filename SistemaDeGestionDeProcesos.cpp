#include <iostream>
#include <string>
using namespace std;

int ID = 0;
struct Tarea {
  int id = ID;
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
  string prioridad;
  cout << "Ingrese el nombre de la nueva tarea: ";
  cin >> nombre;
  do {
    cout << "Ingrese la prioridad de la nueva tarea: (baja, media o alta) ";
    cin >> prioridad;
  } while (prioridad != "baja" && prioridad != "media" && prioridad != "alta");
  cout << "Tarea " << nombre << " a�adida" << endl;
  do {
    cout << "Ingrese la prioridad de la nueva tarea: (baja, media o alta) ";
    cin >> prioridad;
  } while (prioridad != "baja" && prioridad != "media" && prioridad != "alta");
  cout << "Tarea " << nombre << " a�adida" << endl;
  cout << "-------------------------------------" << endl;
  cout << "Id: " << ID << endl;
  cout << "Id: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Prioridad: " << prioridad << endl;

  Tarea nuevaTarea = Tarea();
  nuevaTarea.nombre = nombre;
  nuevaTarea.prioridad = prioridad;
  Tarea nuevaTarea = Tarea();
  nuevaTarea.nombre = nombre;
  nuevaTarea.prioridad = prioridad;

  NodoLista *nuevoNodoLista = new NodoLista(nuevaTarea);
  NodoLista *nuevoNodoLista = new NodoLista(nuevaTarea);
  if (inicio == NULL) {
    inicio = nuevoNodoLista;
    inicio = nuevoNodoLista;
  } else {
    NodoLista *temp = inicio;
    NodoLista *temp = inicio;
    while (temp->siguiente != NULL) {
      temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodoLista;
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
  cout << "Tarea " << nombre << " a�adida a la cola (encolado)" << endl;
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
  cout << "Tarea " << nombre << " a�adida a la cola (encolado)" << endl;
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
    cout << "====Tareas en ====" << endl;
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

  int opcionPrincipal, opcionSub;
  do {
    cout << "-------------------------------\n";
    cout << "        MEN� PRINCIPAL         \n";
    cout << "-------------------------------\n";
    cout << "1. Gesti�n de Tareas Pendientes\n";
    cout << "2. Gesti�n de Tareas Completadas\n";
    cout << "3. Gesti�n de Tareas Prioritarias\n";
    cout << "4. Buscar Tareas\n";
    cout << "5. Salir\n";
    cout << "-------------------------------\n";
    cout << "Seleccione una opci�n (1-5): ";
    cin >> opcionPrincipal;

    switch (opcionPrincipal) {
    case 1:
      do {
        cout << "\n-------------------------------\n";
        cout << "   GESTI�N DE TAREAS PENDIENTES\n";
        cout << "-------------------------------\n";
        cout << "1. A�adir tarea pendiente a la cola\n";
        cout << "2. Asignar tarea (desencolar)\n";
        cout << "3. Ver tareas pendientes en la cola\n";
        cout << "4. Regresar al Men� Principal\n";
        cout << "-------------------------------\n";
        cout << "Seleccione una opci�n (1-4): ";
        cin >> opcionSub;

        switch (opcionSub) {
        case 1:
          encolar(frente, fin);
          break;
        case 2:
          desencolar(frente, fin);
          break;
        case 3:
          mostrarCola(frente);
          break;
        case 4:
          cout << "Regresando al Men� Principal...\n";
          break;
        default:
          cout << "Opci�n inv�lida.\n";
        }
      } while (opcionSub != 4);
      break;

    case 2:
      do {
        cout << "\n-------------------------------\n";
        cout << "   GESTI�N DE TAREAS COMPLETADAS\n";
        cout << "-------------------------------\n";
        cout << "1. Mover tarea a revisi�n (apilar)\n";
        cout << "2. Revisar tarea (desapilar)\n";
        cout << "3. Ver tareas completadas\n";
        cout << "4. Regresar al Men� Principal\n";
        cout << "-------------------------------\n";
        cout << "Seleccione una opci�n (1-4): ";
        cin >> opcionSub;

        switch (opcionSub) {
        case 1:
          apilarTarea(pilaTope);
          break;
        case 2:
          desapilarTarea(pilaTope);
          break;
        case 3:
          mostrarTareasCompletadas(pilaTope);
          break;
        case 4:
          cout << "Regresando al Men� Principal...\n";
          break;
        default:
          cout << "Opci�n inv�lida.\n";
        }
      } while (opcionSub != 4);
      break;

    case 3:
      do {
        cout << "\n-------------------------------\n";
        cout << "   GESTI�N DE TAREAS PRIORITARIAS\n";
        cout << "-------------------------------\n";
        cout << "1. A�adir tarea prioritaria\n";
        cout << "2. Ordenar tareas prioritarias\n";
        cout << "3. Ver tareas prioritarias\n";
        cout << "4. Regresar al Men� Principal\n";
        cout << "-------------------------------\n";
        cout << "Seleccione una opci�n (1-4): ";
        cin >> opcionSub;

        switch (opcionSub) {
        case 1:
          insertarNuevaTarea(inicio);
          break;
        case 2:
          ordenarTareasPrioritarias(inicio);
          break;
        case 3:
          mostrarTareas(inicio);
          break;
        case 4:
          cout << "Regresando al Men� Principal...\n";
          break;
        default:
          cout << "Opci�n inv�lida.\n";
        }
      } while (opcionSub != 4);
      break;

    case 4:
      do {
        cout << "\n-------------------------------\n";
        cout << "          BUSCAR TAREAS         \n";
        cout << "-------------------------------\n";
        cout << "1. Buscar tarea por ID\n";
        cout << "2. Buscar tarea por prioridad\n";
        cout << "3. Regresar al Men� Principal\n";
        cout << "-------------------------------\n";
        cout << "Seleccione una opci�n (1-3): ";
        cin >> opcionSub;

        switch (opcionSub) {
        case 1:
          buscarTarea(inicio, "id");
          break;
        case 2:
          buscarTarea(inicio, "prioridad");
          break;
        case 3:
          cout << "Regresando al Men� Principal...\n";
          break;
        default:
          cout << "Opci�n inv�lida.\n";
        }
      } while (opcionSub != 3);
      break;

    case 5:
      cout << "\n-------------------------------\n";
      cout << " �Regresa pronto! \n";
      cout << "-------------------------------\n";
      break;

    default:
      cout << "Opci�n inv�lida.\n";
    }

  } while (opcionPrincipal != 5);

  return 0;
}
